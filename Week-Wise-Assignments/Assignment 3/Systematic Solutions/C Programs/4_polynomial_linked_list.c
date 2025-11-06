#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
typedef struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode* next;
} PolyNode;

// Function to create a new polynomial node
PolyNode* createPolyNode(int coeff, int exp) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert term in ascending order of exponents
PolyNode* insertTerm(PolyNode* head, int coeff, int exp) {
    // Skip zero coefficient terms
    if (coeff == 0) {
        printf("Skipping term with zero coefficient\n");
        return head;
    }
    
    PolyNode* newNode = createPolyNode(coeff, exp);
    if (newNode == NULL) return head;
    
    // If list is empty or new term has smallest exponent
    if (head == NULL || head->exponent > exp) {
        newNode->next = head;
        printf("Inserted term %dx^%d at the beginning\n", coeff, exp);
        return newNode;
    }
    
    // If term with same exponent exists, add coefficients
    if (head->exponent == exp) {
        head->coefficient += coeff;
        printf("Added coefficient to existing term: %dx^%d\n", head->coefficient, exp);
        free(newNode);
        
        // If resulting coefficient is zero, remove the term
        if (head->coefficient == 0) {
            PolyNode* temp = head;
            head = head->next;
            free(temp);
            printf("Removed term with zero coefficient\n");
        }
        return head;
    }
    
    // Find the correct position to insert (ascending order)
    PolyNode* temp = head;
    while (temp->next != NULL && temp->next->exponent < exp) {
        temp = temp->next;
    }
    
    // If term with same exponent exists
    if (temp->next != NULL && temp->next->exponent == exp) {
        temp->next->coefficient += coeff;
        printf("Added coefficient to existing term: %dx^%d\n", temp->next->coefficient, exp);
        free(newNode);
        
        // If resulting coefficient is zero, remove the term
        if (temp->next->coefficient == 0) {
            PolyNode* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
            printf("Removed term with zero coefficient\n");
        }
        return head;
    }
    
    // Insert the new term
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted term %dx^%d in ascending order\n", coeff, exp);
    return head;
}

// Function to display polynomial
void displayPolynomial(PolyNode* head) {
    if (head == NULL) {
        printf("Polynomial is empty (0)\n");
        return;
    }
    
    printf("Polynomial: ");
    PolyNode* temp = head;
    int isFirst = 1;
    
    while (temp != NULL) {
        // Handle sign
        if (!isFirst) {
            if (temp->coefficient > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        } else if (temp->coefficient < 0) {
            printf("-");
        }
        
        // Handle coefficient
        int absCoeff = abs(temp->coefficient);
        if (absCoeff != 1 || temp->exponent == 0) {
            printf("%d", absCoeff);
        }
        
        // Handle exponent
        if (temp->exponent > 1) {
            printf("x^%d", temp->exponent);
        } else if (temp->exponent == 1) {
            printf("x");
        }
        
        temp = temp->next;
        isFirst = 0;
    }
    printf("\n");
}

// Function to evaluate polynomial for a given value of x
double evaluatePolynomial(PolyNode* head, double x) {
    double result = 0.0;
    PolyNode* temp = head;
    
    while (temp != NULL) {
        double termValue = temp->coefficient;
        for (int i = 0; i < temp->exponent; i++) {
            termValue *= x;
        }
        result += termValue;
        temp = temp->next;
    }
    
    return result;
}

// Function to count terms in polynomial
int countTerms(PolyNode* head) {
    int count = 0;
    PolyNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to find degree of polynomial
int findDegree(PolyNode* head) {
    if (head == NULL) return -1;
    
    int maxDegree = head->exponent;
    PolyNode* temp = head;
    
    while (temp != NULL) {
        if (temp->exponent > maxDegree) {
            maxDegree = temp->exponent;
        }
        temp = temp->next;
    }
    
    return maxDegree;
}

// Function to free polynomial
void freePolynomial(PolyNode* head) {
    PolyNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Polynomial memory freed successfully!\n");
}

// Function to create sample polynomial
PolyNode* createSamplePolynomial() {
    PolyNode* poly = NULL;
    printf("Creating sample polynomial: 3x^2 + 5x^0 + 2x^1 + x^3\n");
    
    poly = insertTerm(poly, 3, 2);  // 3x^2
    poly = insertTerm(poly, 5, 0);  // 5x^0 (constant term)
    poly = insertTerm(poly, 2, 1);  // 2x^1
    poly = insertTerm(poly, 1, 3);  // x^3
    
    return poly;
}

int main() {
    PolyNode* polynomial = NULL;
    int choice, coeff, exp;
    double x, result;
    
    printf("=== Polynomial Storage using Linked List (Ascending Order) ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Term\n");
        printf("2. Display Polynomial\n");
        printf("3. Evaluate Polynomial\n");
        printf("4. Count Terms\n");
        printf("5. Find Degree\n");
        printf("6. Create Sample Polynomial\n");
        printf("7. Clear Polynomial\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter coefficient: ");
                scanf("%d", &coeff);
                printf("Enter exponent: ");
                scanf("%d", &exp);
                
                if (exp < 0) {
                    printf("Exponent should be non-negative!\n");
                } else {
                    polynomial = insertTerm(polynomial, coeff, exp);
                }
                break;
                
            case 2:
                displayPolynomial(polynomial);
                break;
                
            case 3:
                if (polynomial == NULL) {
                    printf("Polynomial is empty!\n");
                } else {
                    printf("Enter value of x: ");
                    scanf("%lf", &x);
                    result = evaluatePolynomial(polynomial, x);
                    printf("P(%.2f) = %.2f\n", x, result);
                }
                break;
                
            case 4:
                printf("Number of terms: %d\n", countTerms(polynomial));
                break;
                
            case 5:
                {
                    int degree = findDegree(polynomial);
                    if (degree == -1) {
                        printf("Polynomial is empty!\n");
                    } else {
                        printf("Degree of polynomial: %d\n", degree);
                    }
                }
                break;
                
            case 6:
                if (polynomial != NULL) {
                    freePolynomial(polynomial);
                }
                polynomial = createSamplePolynomial();
                displayPolynomial(polynomial);
                break;
                
            case 7:
                freePolynomial(polynomial);
                polynomial = NULL;
                printf("Polynomial cleared!\n");
                break;
                
            case 8:
                printf("Exiting...\n");
                if (polynomial != NULL) {
                    freePolynomial(polynomial);
                }
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);
    
    return 0;
}