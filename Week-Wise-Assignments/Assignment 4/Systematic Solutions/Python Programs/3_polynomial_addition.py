class Node:
    """Node class for polynomial terms"""
    def __init__(self, coeff, exp):
        self.coeff = coeff  # Coefficient
        self.exp = exp      # Exponent
        self.next = None

class Polynomial:
    """Polynomial implementation using linked list"""
    def __init__(self):
        self.head = None
        self.terms = 0
    
    def insert_term(self, coeff, exp):
        """
        Insert term in descending order of exponents
        If term with same exponent exists, add coefficients
        """
        if coeff == 0:
            return  # Don't insert zero coefficient terms
        
        new_node = Node(coeff, exp)
        
        # If list is empty or new term has highest exponent
        if not self.head or self.head.exp < exp:
            new_node.next = self.head
            self.head = new_node
            self.terms += 1
            return
        
        # If term with same exponent exists at head
        if self.head.exp == exp:
            self.head.coeff += coeff
            if self.head.coeff == 0:  # Remove term if coefficient becomes zero
                self.head = self.head.next
                self.terms -= 1
            return
        
        # Find correct position to insert
        current = self.head
        while current.next and current.next.exp > exp:
            current = current.next
        
        # If term with same exponent found
        if current.next and current.next.exp == exp:
            current.next.coeff += coeff
            if current.next.coeff == 0:  # Remove term if coefficient becomes zero
                current.next = current.next.next
                self.terms -= 1
        else:
            new_node.next = current.next
            current.next = new_node
            self.terms += 1
    
    def display(self):
        """Display polynomial in standard mathematical form"""
        if not self.head:
            print("0")
            return
        
        current = self.head
        first_term = True
        
        while current:
            if current.coeff != 0:
                # Handle sign
                if not first_term:
                    if current.coeff > 0:
                        print(" + ", end="")
                    else:
                        print(" - ", end="")
                elif current.coeff < 0:
                    print("-", end="")
                
                # Handle coefficient
                coeff = abs(current.coeff)
                if current.exp == 0:
                    print(f"{coeff}", end="")
                elif current.exp == 1:
                    if coeff == 1:
                        print("x", end="")
                    else:
                        print(f"{coeff}x", end="")
                else:
                    if coeff == 1:
                        print(f"x^{current.exp}", end="")
                    else:
                        print(f"{coeff}x^{current.exp}", end="")
                
                first_term = False
            
            current = current.next
        print()
    
    def input_polynomial(self, poly_name):
        """Input polynomial from user"""
        print(f"\nEntering {poly_name}:")
        try:
            n = int(input("Enter number of terms: "))
            
            for i in range(n):
                print(f"Term {i + 1}:")
                coeff = int(input("  Coefficient: "))
                exp = int(input("  Exponent: "))
                self.insert_term(coeff, exp)
                
            print(f"{poly_name} entered successfully!")
            
        except ValueError:
            print("Invalid input! Please enter valid integers.")
    
    def get_terms_count(self):
        """Get number of terms in polynomial"""
        return self.terms

def add_polynomials(poly1, poly2):
    """
    Algorithm for Polynomial Addition:
    1. Create a new polynomial for result
    2. Traverse both polynomials simultaneously
    3. Compare exponents:
       - If exp1 > exp2: add term from poly1 to result
       - If exp1 < exp2: add term from poly2 to result  
       - If exp1 = exp2: add coefficients and add to result
    4. Add remaining terms from non-exhausted polynomial
    """
    print("\n=== Polynomial Addition Process ===")
    print("Algorithm: Compare exponents and add corresponding coefficients")
    
    result = Polynomial()
    p1 = poly1.head
    p2 = poly2.head
    step = 1
    
    print("\nStep-by-step addition process:")
    
    while p1 and p2:
        print(f"Step {step}: Comparing terms")
        print(f"         Poly1 term: {p1.coeff}x^{p1.exp}")
        print(f"         Poly2 term: {p2.coeff}x^{p2.exp}")
        
        if p1.exp > p2.exp:
            print(f"         Poly1 exponent higher, adding {p1.coeff}x^{p1.exp} to result")
            result.insert_term(p1.coeff, p1.exp)
            p1 = p1.next
        elif p1.exp < p2.exp:
            print(f"         Poly2 exponent higher, adding {p2.coeff}x^{p2.exp} to result")
            result.insert_term(p2.coeff, p2.exp)
            p2 = p2.next
        else:  # Same exponent
            sum_coeff = p1.coeff + p2.coeff
            print(f"         Same exponent, adding coefficients: {p1.coeff} + {p2.coeff} = {sum_coeff}")
            if sum_coeff != 0:
                result.insert_term(sum_coeff, p1.exp)
                print(f"         Added {sum_coeff}x^{p1.exp} to result")
            else:
                print(f"         Sum is zero, term cancelled out")
            p1 = p1.next
            p2 = p2.next
        
        step += 1
        print()
    
    # Add remaining terms
    while p1:
        print(f"Adding remaining term from Poly1: {p1.coeff}x^{p1.exp}")
        result.insert_term(p1.coeff, p1.exp)
        p1 = p1.next
    
    while p2:
        print(f"Adding remaining term from Poly2: {p2.coeff}x^{p2.exp}")
        result.insert_term(p2.coeff, p2.exp)
        p2 = p2.next
    
    print("Polynomial addition completed!")
    return result

def main():
    """Main function with interactive menu"""
    poly1 = Polynomial()
    poly2 = Polynomial()
    
    print("=== Polynomial Addition using Linked List ===")
    print("This program adds two polynomials represented as linked lists")
    print("Terms are stored in descending order of exponents\n")
    
    while True:
        print("\n--- Menu ---")
        print("1. Input first polynomial")
        print("2. Input second polynomial")
        print("3. Display polynomials")
        print("4. Add polynomials")
        print("5. Clear polynomials")
        print("6. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                poly1 = Polynomial()
                poly1.input_polynomial("First Polynomial")
                
            elif choice == 2:
                poly2 = Polynomial()
                poly2.input_polynomial("Second Polynomial")
                
            elif choice == 3:
                print("\nCurrent Polynomials:")
                print("First Polynomial:  ", end="")
                poly1.display()
                print("Second Polynomial: ", end="")
                poly2.display()
                print(f"First polynomial terms: {poly1.get_terms_count()}")
                print(f"Second polynomial terms: {poly2.get_terms_count()}")
                
            elif choice == 4:
                if not poly1.head and not poly2.head:
                    print("Both polynomials are empty!")
                else:
                    print("\n=== Polynomial Addition ===")
                    print("First Polynomial:  ", end="")
                    poly1.display()
                    print("Second Polynomial: ", end="")
                    poly2.display()
                    
                    result = add_polynomials(poly1, poly2)
                    
                    print("\nResult: ", end="")
                    result.display()
                    print(f"Result has {result.get_terms_count()} terms")
                    
            elif choice == 5:
                poly1 = Polynomial()
                poly2 = Polynomial()
                print("Both polynomials cleared!")
                
            elif choice == 6:
                print("Exiting program...")
                break
                
            else:
                print("Invalid choice! Please try again.")
                
        except ValueError:
            print("Invalid input! Please enter a valid number.")
        except Exception as e:
            print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()