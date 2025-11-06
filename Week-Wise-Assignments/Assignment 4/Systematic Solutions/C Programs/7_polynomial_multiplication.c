#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert term in descending order of exponents
void insertTerm(struct Node** head, int coeff, int exp) {
    if (coeff == 0) return; // Don't insert zero coefficient terms
    
    struct Node* newNode = createNode(coeff, exp);
    
    // If list is empty or new term has highest exponent
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    // If term with same exponent exists, add coefficients
    if ((*head)->exp == exp) {
        (*head)->coeff += coeff;
        free(newNode);
        return;
    }
    
    // Find correct position to insert
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }
    
    // If term with same exponent found
    if (temp->next != NULL && temp->next->exp == exp) {
        temp->next->coeff += coeff;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Algorithm for Polynomial Multiplication:
// 1. For each term in first polynomial
// 2. Multiply it with each term in second polynomial
// 3. Add coefficient and exponents: (a*x^m) * (b*x^n) = (a*b)*x^(m+n)
// 4. Insert the result term in the result polynomial
// 5. Combine like terms automatically during insertion
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }
    
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    
    printf("\nPolynomial Multiplication Process:\n");
    printf("Algorithm: Multiply each term of first polynomial with each term of second polynomial\n");
    printf("Rule: (a*x^m) * (b*x^n) = (a*b)*x^(m+n)\n\n");
    
    int step = 1;
    while (temp1 != NULL) {
        struct Node* temp2 = poly2;
        printf("Multiplying term %dx^%d with all terms of second polynomial:\n", 
               temp1->coeff, temp1->exp);
        
        while (temp2 != NULL) {
            int newCoeff = temp1->coeff * temp2->coeff;
            int newExp = temp1->exp + temp2->exp;
            
            printf("  Step %d: (%dx^%d) * (%dx^%d) = %dx^%d\n", 
                   step++, temp1->coeff, temp1->exp, temp2->coeff, temp2->exp, newCoeff, newExp);
            
            insertTerm(&result, newCoeff, newExp);
            temp2 = temp2->next;
        }
        printf("\n");
        temp1 = temp1->next;
    }
    
    return result;
}

// Function to display polynomial
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    
    struct Node* temp = head;
    int first = 1;
    
    while (temp != NULL) {
        if (temp->coeff != 0) {
            if (!first && temp->coeff > 0) {
                printf(" + ");
            } else if (temp->coeff < 0) {
                printf(" - ");
            }
            
            if (first) first = 0;
            
            int coeff = (temp->coeff < 0) ? -temp->coeff : temp->coeff;
            
            if (temp->exp == 0) {
                printf("%d", coeff);
            } else if (temp->exp == 1) {
                if (coeff == 1) {
                    printf("x");
                } else {
                    printf("%dx", coeff);
                }
            } else {
                if (coeff == 1) {
                    printf("x^%d", temp->exp);
                } else {
                    printf("%dx^%d", coeff, temp->exp);
                }
            }
        }
        temp = temp->next;
    }
}

// Function to input polynomial
void inputPolynomial(struct Node** head, int polyNum) {
    int n, coeff, exp;
    
    printf("Enter number of terms for polynomial %d: ", polyNum);
    scanf("%d", &n);
    
    printf("Enter terms (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d - Coefficient: ", i + 1);
        scanf("%d", &coeff);
        printf("Term %d - Exponent: ", i + 1);
        scanf("%d", &exp);
        insertTerm(head, coeff, exp);
    }
}

// Function to free memory
void freePolynomial(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    int choice;
    
    printf("=== Polynomial Multiplication using Linked List ===\n");
    printf("Algorithm: Multiply each term with every other term and combine like terms\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Input first polynomial\n");
        printf("2. Input second polynomial\n");
        printf("3. Display polynomials\n");
        printf("4. Multiply polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (poly1 != NULL) {
                    freePolynomial(poly1);
                    poly1 = NULL;
                }
                inputPolynomial(&poly1, 1);
                printf("First polynomial entered successfully!\n");
                break;
                
            case 2:
                if (poly2 != NULL) {
                    freePolynomial(poly2);
                    poly2 = NULL;
                }
                inputPolynomial(&poly2, 2);
                printf("Second polynomial entered successfully!\n");
                break;
                
            case 3:
                printf("\nFirst Polynomial: ");
                displayPolynomial(poly1);
                printf("\nSecond Polynomial: ");
                displayPolynomial(poly2);
                printf("\n");
                break;
                
            case 4:
                if (poly1 == NULL || poly2 == NULL) {
                    printf("Please input both polynomials first!\n");
                } else {
                    printf("\n=== Polynomial Multiplication ===\n");
                    printf("First Polynomial: ");
                    displayPolynomial(poly1);
                    printf("\nSecond Polynomial: ");
                    displayPolynomial(poly2);
                    printf("\n");
                    
                    if (result != NULL) {
                        freePolynomial(result);
                    }
                    result = multiplyPolynomials(poly1, poly2);
                    
                    printf("Result after multiplication: ");
                    displayPolynomial(result);
                    printf("\n");
                }
                break;
                
            case 5:
                printf("Exiting program...\n");
                freePolynomial(poly1);
                freePolynomial(poly2);
                freePolynomial(result);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}