#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
typedef struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode* next;
} PolyNode;

/*
ALGORITHM FOR POLYNOMIAL ADDITION USING LINKED LIST:

1. Create two polynomials as linked lists (sorted by exponent)
2. Initialize result polynomial as empty
3. Use two pointers to traverse both polynomials simultaneously
4. Compare exponents of current terms:
   a. If exponents are equal: Add coefficients, create new term
   b. If first exponent > second: Copy first term to result
   c. If second exponent > first: Copy second term to result
5. Move the appropriate pointer(s) forward
6. Continue until both polynomials are fully processed
7. Add any remaining terms from either polynomial

Time Complexity: O(m + n) where m and n are number of terms
Space Complexity: O(m + n) for the result polynomial
*/

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

// Function to insert term in polynomial (sorted by exponent in descending order)
PolyNode* insertTerm(PolyNode* head, int coeff, int exp) {
    // Skip zero coefficient terms
    if (coeff == 0) {
        printf("Skipping term with zero coefficient\n");
        return head;
    }
    
    PolyNode* newNode = createPolyNode(coeff, exp);
    if (newNode == NULL) return head;
    
    // If list is empty or new term has highest exponent
    if (head == NULL || head->exponent < exp) {
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
    
    // Find the correct position to insert
    PolyNode* temp = head;
    while (temp->next != NULL && temp->next->exponent > exp) {
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
    printf("Inserted term %dx^%d in descending order\n", coeff, exp);
    return head;
}

// Function to display polynomial
void displayPolynomial(PolyNode* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    
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

// Function to add two polynomials
PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    PolyNode* p1 = poly1;
    PolyNode* p2 = poly2;
    
    printf("Adding polynomials step by step:\n");
    
    // Process both polynomials
    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent == p2->exponent) {
            // Same exponent: add coefficients
            int sumCoeff = p1->coefficient + p2->coefficient;
            if (sumCoeff != 0) {
                result = insertTerm(result, sumCoeff, p1->exponent);
                printf("Added terms with exponent %d: %d + %d = %d\n", 
                       p1->exponent, p1->coefficient, p2->coefficient, sumCoeff);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exponent > p2->exponent) {
            // First polynomial has higher exponent
            result = insertTerm(result, p1->coefficient, p1->exponent);
            printf("Copied term from first polynomial: %dx^%d\n", 
                   p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else {
            // Second polynomial has higher exponent
            result = insertTerm(result, p2->coefficient, p2->exponent);
            printf("Copied term from second polynomial: %dx^%d\n", 
                   p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
    }
    
    // Add remaining terms from first polynomial
    while (p1 != NULL) {
        result = insertTerm(result, p1->coefficient, p1->exponent);
        printf("Added remaining term from first polynomial: %dx^%d\n", 
               p1->coefficient, p1->exponent);
        p1 = p1->next;
    }
    
    // Add remaining terms from second polynomial
    while (p2 != NULL) {
        result = insertTerm(result, p2->coefficient, p2->exponent);
        printf("Added remaining term from second polynomial: %dx^%d\n", 
               p2->coefficient, p2->exponent);
        p2 = p2->next;
    }
    
    printf("Polynomial addition completed!\n");
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
    return head->exponent; // First term has highest exponent
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

// Function to free polynomial
void freePolynomial(PolyNode* head) {
    PolyNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to create sample polynomials
void createSamplePolynomials(PolyNode** poly1, PolyNode** poly2) {
    // Create first polynomial: 3x^3 + 2x^2 + 5
    *poly1 = NULL;
    printf("Creating first polynomial: 3x^3 + 2x^2 + 5\n");
    *poly1 = insertTerm(*poly1, 3, 3);
    *poly1 = insertTerm(*poly1, 2, 2);
    *poly1 = insertTerm(*poly1, 5, 0);
    
    // Create second polynomial: 4x^3 - 2x^2 + x + 3
    *poly2 = NULL;
    printf("Creating second polynomial: 4x^3 - 2x^2 + x + 3\n");
    *poly2 = insertTerm(*poly2, 4, 3);
    *poly2 = insertTerm(*poly2, -2, 2);
    *poly2 = insertTerm(*poly2, 1, 1);
    *poly2 = insertTerm(*poly2, 3, 0);
}

int main() {
    PolyNode* poly1 = NULL;
    PolyNode* poly2 = NULL;
    PolyNode* result = NULL;
    int choice, coeff, exp;
    double x, value;
    
    printf("=== Polynomial Addition using Linked List ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert term in Polynomial 1\n");
        printf("2. Insert term in Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Display Result Polynomial\n");
        printf("6. Add Polynomials\n");
        printf("7. Evaluate Polynomials\n");
        printf("8. Polynomial Statistics\n");
        printf("9. Create Sample Polynomials\n");
        printf("10. Clear All Polynomials\n");
        printf("11. Exit\n");
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
                    poly1 = insertTerm(poly1, coeff, exp);
                }
                break;
                
            case 2:
                printf("Enter coefficient: ");
                scanf("%d", &coeff);
                printf("Enter exponent: ");
                scanf("%d", &exp);
                
                if (exp < 0) {
                    printf("Exponent should be non-negative!\n");
                } else {
                    poly2 = insertTerm(poly2, coeff, exp);
                }
                break;
                
            case 3:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;
                
            case 4:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;
                
            case 5:
                printf("Result Polynomial: ");
                displayPolynomial(result);
                break;
                
            case 6:
                printf("Adding polynomials:\n");
                printf("Polynomial 1: "); displayPolynomial(poly1);
                printf("Polynomial 2: "); displayPolynomial(poly2);
                
                if (result != NULL) {
                    freePolynomial(result);
                }
                result = addPolynomials(poly1, poly2);
                
                printf("Result: "); displayPolynomial(result);
                break;
                
            case 7:
                printf("Enter value of x: ");
                scanf("%lf", &x);
                
                if (poly1 != NULL) {
                    value = evaluatePolynomial(poly1, x);
                    printf("P1(%.2f) = %.2f\n", x, value);
                }
                
                if (poly2 != NULL) {
                    value = evaluatePolynomial(poly2, x);
                    printf("P2(%.2f) = %.2f\n", x, value);
                }
                
                if (result != NULL) {
                    value = evaluatePolynomial(result, x);
                    printf("Result(%.2f) = %.2f\n", x, value);
                }
                break;
                
            case 8:
                printf("Polynomial Statistics:\n");
                printf("Polynomial 1: Terms=%d, Degree=%d\n", 
                       countTerms(poly1), findDegree(poly1));
                printf("Polynomial 2: Terms=%d, Degree=%d\n", 
                       countTerms(poly2), findDegree(poly2));
                if (result != NULL) {
                    printf("Result: Terms=%d, Degree=%d\n", 
                           countTerms(result), findDegree(result));
                }
                break;
                
            case 9:
                if (poly1 != NULL) freePolynomial(poly1);
                if (poly2 != NULL) freePolynomial(poly2);
                if (result != NULL) freePolynomial(result);
                
                createSamplePolynomials(&poly1, &poly2);
                result = NULL;
                
                printf("Sample polynomials created!\n");
                printf("Polynomial 1: "); displayPolynomial(poly1);
                printf("Polynomial 2: "); displayPolynomial(poly2);
                break;
                
            case 10:
                if (poly1 != NULL) { freePolynomial(poly1); poly1 = NULL; }
                if (poly2 != NULL) { freePolynomial(poly2); poly2 = NULL; }
                if (result != NULL) { freePolynomial(result); result = NULL; }
                printf("All polynomials cleared!\n");
                break;
                
            case 11:
                printf("Exiting...\n");
                if (poly1 != NULL) freePolynomial(poly1);
                if (poly2 != NULL) freePolynomial(poly2);
                if (result != NULL) freePolynomial(result);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11);
    
    return 0;
}