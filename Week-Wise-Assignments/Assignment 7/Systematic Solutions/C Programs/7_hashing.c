#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_STRING_LENGTH 50

// Structure for hash table entry
struct HashEntry {
    int key;
    char value[MAX_STRING_LENGTH];
    int isOccupied;
    int isDeleted;
};

// Hash table structure
struct HashTable {
    struct HashEntry* table;
    int size;
    int count;
};

// Initialize hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->size = TABLE_SIZE;
    hashTable->count = 0;
    hashTable->table = (struct HashEntry*)calloc(TABLE_SIZE, sizeof(struct HashEntry));
    
    // Initialize all entries
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i].isOccupied = 0;
        hashTable->table[i].isDeleted = 0;
    }
    
    return hashTable;
}

// Hash function 1: Division method
int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

// Hash function 2: Multiplication method
int hashFunction2(int key) {
    double A = 0.6180339887; // (sqrt(5) - 1) / 2
    double temp = key * A;
    temp = temp - (int)temp; // Get fractional part
    return (int)(TABLE_SIZE * temp);
}

// Hash function 3: Mid-square method
int hashFunction3(int key) {
    int squared = key * key;
    // Extract middle digits (simplified version)
    return (squared / 10) % TABLE_SIZE;
}

// Display hash table
void displayHashTable(struct HashTable* hashTable) {
    printf("\n=== Hash Table Contents ===\n");
    printf("Index | Key  | Value           | Status\n");
    printf("------|------|-----------------|--------\n");
    
    for (int i = 0; i < hashTable->size; i++) {
        printf("%5d | ", i);
        
        if (hashTable->table[i].isOccupied && !hashTable->table[i].isDeleted) {
            printf("%4d | %-15s | Active\n", 
                   hashTable->table[i].key, hashTable->table[i].value);
        } else if (hashTable->table[i].isDeleted) {
            printf("---- | %-15s | Deleted\n", "---");
        } else {
            printf("---- | %-15s | Empty\n", "---");
        }
    }
    
    printf("\nTable Statistics:\n");
    printf("Size: %d, Occupied: %d, Load Factor: %.2f\n", 
           hashTable->size, hashTable->count, 
           (float)hashTable->count / hashTable->size);
}

// Linear probing for collision resolution
int linearProbing(struct HashTable* hashTable, int key, int hashValue, int isInsertion) {
    int originalHash = hashValue;
    int probeCount = 0;
    
    if (isInsertion) {
        printf("  Linear probing for insertion:\n");
    } else {
        printf("  Linear probing for search:\n");
    }
    
    while (probeCount < hashTable->size) {
        printf("    Probe %d: Checking index %d", probeCount + 1, hashValue);
        
        if (!hashTable->table[hashValue].isOccupied || 
            hashTable->table[hashValue].isDeleted) {
            if (isInsertion) {
                printf(" -> Empty slot found\n");
                return hashValue;
            } else {
                printf(" -> Empty slot, key not found\n");
                return -1;
            }
        } else if (hashTable->table[hashValue].key == key && 
                   !hashTable->table[hashValue].isDeleted) {
            if (isInsertion) {
                printf(" -> Key already exists\n");
                return -2; // Key already exists
            } else {
                printf(" -> Key found\n");
                return hashValue;
            }
        } else {
            printf(" -> Collision, continue probing\n");
        }
        
        hashValue = (hashValue + 1) % hashTable->size;
        probeCount++;
        
        // Avoid infinite loop
        if (hashValue == originalHash) {
            break;
        }
    }
    
    if (isInsertion) {
        printf("    Hash table is full!\n");
    } else {
        printf("    Key not found after full table scan\n");
    }
    return -1;
}

// Quadratic probing for collision resolution
int quadraticProbing(struct HashTable* hashTable, int key, int hashValue, int isInsertion) {
    int originalHash = hashValue;
    int probeCount = 0;
    
    if (isInsertion) {
        printf("  Quadratic probing for insertion:\n");
    } else {
        printf("  Quadratic probing for search:\n");
    }
    
    while (probeCount < hashTable->size) {
        int currentIndex = (originalHash + probeCount * probeCount) % hashTable->size;
        
        printf("    Probe %d: Checking index %d (h + %d²)", 
               probeCount + 1, currentIndex, probeCount);
        
        if (!hashTable->table[currentIndex].isOccupied || 
            hashTable->table[currentIndex].isDeleted) {
            if (isInsertion) {
                printf(" -> Empty slot found\n");
                return currentIndex;
            } else {
                printf(" -> Empty slot, key not found\n");
                return -1;
            }
        } else if (hashTable->table[currentIndex].key == key && 
                   !hashTable->table[currentIndex].isDeleted) {
            if (isInsertion) {
                printf(" -> Key already exists\n");
                return -2;
            } else {
                printf(" -> Key found\n");
                return currentIndex;
            }
        } else {
            printf(" -> Collision, continue probing\n");
        }
        
        probeCount++;
    }
    
    return -1;
}

// Insert key-value pair into hash table
void insert(struct HashTable* hashTable, int key, char* value, int hashFunc, int probeMethod) {
    printf("\n=== Inserting Key: %d, Value: %s ===\n", key, value);
    
    if (hashTable->count >= hashTable->size) {
        printf("Hash table is full! Cannot insert.\n");
        return;
    }
    
    // Calculate hash value using selected hash function
    int hashValue;
    switch (hashFunc) {
        case 1:
            hashValue = hashFunction1(key);
            printf("Using Division Method: h(%d) = %d %% %d = %d\n", 
                   key, key, TABLE_SIZE, hashValue);
            break;
        case 2:
            hashValue = hashFunction2(key);
            printf("Using Multiplication Method: h(%d) = %d\n", key, hashValue);
            break;
        case 3:
            hashValue = hashFunction3(key);
            printf("Using Mid-Square Method: h(%d) = %d\n", key, hashValue);
            break;
        default:
            hashValue = hashFunction1(key);
    }
    
    // Handle collision using selected probing method
    int finalIndex;
    if (probeMethod == 1) {
        finalIndex = linearProbing(hashTable, key, hashValue, 1);
    } else {
        finalIndex = quadraticProbing(hashTable, key, hashValue, 1);
    }
    
    if (finalIndex == -2) {
        printf("Key %d already exists in the table!\n", key);
        return;
    } else if (finalIndex == -1) {
        printf("Failed to insert key %d\n", key);
        return;
    }
    
    // Insert the key-value pair
    hashTable->table[finalIndex].key = key;
    strcpy(hashTable->table[finalIndex].value, value);
    hashTable->table[finalIndex].isOccupied = 1;
    hashTable->table[finalIndex].isDeleted = 0;
    hashTable->count++;
    
    printf("Successfully inserted at index %d\n", finalIndex);
}

// Search for a key in hash table
int search(struct HashTable* hashTable, int key, int hashFunc, int probeMethod) {
    printf("\n=== Searching for Key: %d ===\n", key);
    
    // Calculate hash value
    int hashValue;
    switch (hashFunc) {
        case 1:
            hashValue = hashFunction1(key);
            printf("Using Division Method: h(%d) = %d\n", key, hashValue);
            break;
        case 2:
            hashValue = hashFunction2(key);
            printf("Using Multiplication Method: h(%d) = %d\n", key, hashValue);
            break;
        case 3:
            hashValue = hashFunction3(key);
            printf("Using Mid-Square Method: h(%d) = %d\n", key, hashValue);
            break;
        default:
            hashValue = hashFunction1(key);
    }
    
    // Search using selected probing method
    int foundIndex;
    if (probeMethod == 1) {
        foundIndex = linearProbing(hashTable, key, hashValue, 0);
    } else {
        foundIndex = quadraticProbing(hashTable, key, hashValue, 0);
    }
    
    if (foundIndex != -1) {
        printf("Key %d found at index %d with value: %s\n", 
               key, foundIndex, hashTable->table[foundIndex].value);
        return foundIndex;
    } else {
        printf("Key %d not found in the hash table\n", key);
        return -1;
    }
}

// Delete a key from hash table
void delete(struct HashTable* hashTable, int key, int hashFunc, int probeMethod) {
    printf("\n=== Deleting Key: %d ===\n", key);
    
    int foundIndex = search(hashTable, key, hashFunc, probeMethod);
    
    if (foundIndex != -1) {
        hashTable->table[foundIndex].isDeleted = 1;
        hashTable->count--;
        printf("Key %d marked as deleted\n", key);
    } else {
        printf("Cannot delete: Key %d not found\n", key);
    }
}

// Demonstrate different hash functions
void demonstrateHashFunctions() {
    printf("\n=== Hash Function Demonstration ===\n");
    
    int keys[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    int numKeys = sizeof(keys) / sizeof(keys[0]);
    
    printf("Key | Division | Multiplication | Mid-Square\n");
    printf("----|----------|----------------|------------\n");
    
    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int h1 = hashFunction1(key);
        int h2 = hashFunction2(key);
        int h3 = hashFunction3(key);
        
        printf("%3d | %8d | %14d | %10d\n", key, h1, h2, h3);
    }
}

// Performance analysis
void performanceAnalysis() {
    printf("\n=== Performance Analysis ===\n");
    
    printf("Hash Table Performance Characteristics:\n\n");
    
    printf("Load Factor Impact:\n");
    printf("Load Factor | Avg Probes (Linear) | Avg Probes (Quadratic)\n");
    printf("------------|---------------------|------------------------\n");
    printf("    0.5     |         1.5         |          1.4\n");
    printf("    0.7     |         2.2         |          1.8\n");
    printf("    0.9     |         5.5         |          2.6\n");
    printf("    0.95    |        10.5         |          3.2\n\n");
    
    printf("Time Complexity:\n");
    printf("Operation | Average Case | Worst Case\n");
    printf("----------|--------------|------------\n");
    printf("Insert    |     O(1)     |    O(n)\n");
    printf("Search    |     O(1)     |    O(n)\n");
    printf("Delete    |     O(1)     |    O(n)\n\n");
    
    printf("Space Complexity: O(n) where n is table size\n");
}

// Free hash table memory
void freeHashTable(struct HashTable* hashTable) {
    free(hashTable->table);
    free(hashTable);
}

int main() {
    struct HashTable* hashTable = createHashTable();
    int choice, key, hashFunc = 1, probeMethod = 1;
    char value[MAX_STRING_LENGTH];
    
    printf("=== Hash Table Implementation ===\n");
    printf("Hash Table: Data structure for fast key-value storage\n");
    printf("Features: Multiple hash functions and collision resolution methods\n");
    printf("Table Size: %d\n\n", TABLE_SIZE);
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert key-value pair\n");
        printf("2. Search for key\n");
        printf("3. Delete key\n");
        printf("4. Display hash table\n");
        printf("5. Change hash function\n");
        printf("6. Change collision resolution method\n");
        printf("7. Demonstrate hash functions\n");
        printf("8. Performance analysis\n");
        printf("9. Algorithm explanation\n");
        printf("10. Exit\n");
        
        printf("\nCurrent Settings:\n");
        printf("Hash Function: %s\n", 
               (hashFunc == 1) ? "Division Method" : 
               (hashFunc == 2) ? "Multiplication Method" : "Mid-Square Method");
        printf("Collision Resolution: %s\n", 
               (probeMethod == 1) ? "Linear Probing" : "Quadratic Probing");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key (integer): ");
                scanf("%d", &key);
                printf("Enter value (string): ");
                scanf("%s", value);
                insert(hashTable, key, value, hashFunc, probeMethod);
                break;
                
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(hashTable, key, hashFunc, probeMethod);
                break;
                
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(hashTable, key, hashFunc, probeMethod);
                break;
                
            case 4:
                displayHashTable(hashTable);
                break;
                
            case 5:
                printf("\nSelect hash function:\n");
                printf("1. Division Method (h(k) = k mod m)\n");
                printf("2. Multiplication Method\n");
                printf("3. Mid-Square Method\n");
                printf("Enter choice: ");
                scanf("%d", &hashFunc);
                
                if (hashFunc < 1 || hashFunc > 3) {
                    printf("Invalid choice! Using Division Method.\n");
                    hashFunc = 1;
                } else {
                    printf("Hash function changed successfully!\n");
                }
                break;
                
            case 6:
                printf("\nSelect collision resolution method:\n");
                printf("1. Linear Probing\n");
                printf("2. Quadratic Probing\n");
                printf("Enter choice: ");
                scanf("%d", &probeMethod);
                
                if (probeMethod < 1 || probeMethod > 2) {
                    printf("Invalid choice! Using Linear Probing.\n");
                    probeMethod = 1;
                } else {
                    printf("Collision resolution method changed successfully!\n");
                }
                break;
                
            case 7:
                demonstrateHashFunctions();
                break;
                
            case 8:
                performanceAnalysis();
                break;
                
            case 9:
                printf("\n=== Hashing Algorithm Explanation ===\n");
                printf("What is Hashing?\n");
                printf("• Technique to map keys to array indices using hash functions\n");
                printf("• Provides average O(1) time complexity for basic operations\n");
                printf("• Used in hash tables, hash maps, dictionaries, etc.\n\n");
                
                printf("Hash Functions:\n");
                printf("1. Division Method: h(k) = k mod m\n");
                printf("   - Simple and fast\n");
                printf("   - m should be prime for better distribution\n\n");
                
                printf("2. Multiplication Method: h(k) = floor(m * (k*A mod 1))\n");
                printf("   - A is constant (0 < A < 1)\n");
                printf("   - Good distribution for any value of m\n\n");
                
                printf("3. Mid-Square Method: h(k) = middle digits of k²\n");
                printf("   - Square the key and extract middle digits\n");
                printf("   - Works well when keys don't have patterns\n\n");
                
                printf("Collision Resolution:\n");
                printf("1. Linear Probing: h'(k) = (h(k) + i) mod m\n");
                printf("   - Simple but causes clustering\n");
                printf("   - Primary clustering problem\n\n");
                
                printf("2. Quadratic Probing: h'(k) = (h(k) + i²) mod m\n");
                printf("   - Reduces primary clustering\n");
                printf("   - May cause secondary clustering\n\n");
                
                printf("Load Factor:\n");
                printf("• α = n/m (n = elements, m = table size)\n");
                printf("• Keep α < 0.7 for good performance\n");
                printf("• Higher load factor increases collision probability\n\n");
                
                printf("Applications:\n");
                printf("• Database indexing\n");
                printf("• Compiler symbol tables\n");
                printf("• Caching systems\n");
                printf("• Password verification\n");
                break;
                
            case 10:
                printf("Exiting program...\n");
                freeHashTable(hashTable);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}