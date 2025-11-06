class PolyNode:
    """
    Node class for polynomial terms
    """
    def __init__(self, coefficient, exponent):
        self.coefficient = coefficient
        self.exponent = exponent
        self.next = None

class Polynomial:
    """
    Polynomial implementation using linked list (descending order of exponents)
    """
    
    def __init__(self):
        """
        Initialize empty polynomial
        """
        self.head = None
    
    def insertTerm(self, coefficient, exponent):
        """
        Insert a term in descending order of exponents
        
        Args:
            coefficient: Coefficient of the term
            exponent: Exponent of the term
        """
        # Skip zero coefficient terms
        if coefficient == 0:
            print("Skipping term with zero coefficient")
            return
        
        new_node = PolyNode(coefficient, exponent)
        
        # If list is empty or new term has highest exponent
        if self.head is None or self.head.exponent < exponent:
            new_node.next = self.head
            self.head = new_node
            print(f"Inserted term {coefficient}x^{exponent} at the beginning")
            return
        
        # If term with same exponent exists, add coefficients
        if self.head.exponent == exponent:
            self.head.coefficient += coefficient
            print(f"Added coefficient to existing term: {self.head.coefficient}x^{exponent}")
            
            # If resulting coefficient is zero, remove the term
            if self.head.coefficient == 0:
                self.head = self.head.next
                print("Removed term with zero coefficient")
            return
        
        # Find the correct position to insert (descending order)
        temp = self.head
        while temp.next is not None and temp.next.exponent > exponent:
            temp = temp.next
        
        # If term with same exponent exists
        if temp.next is not None and temp.next.exponent == exponent:
            temp.next.coefficient += coefficient
            print(f"Added coefficient to existing term: {temp.next.coefficient}x^{exponent}")
            
            # If resulting coefficient is zero, remove the term
            if temp.next.coefficient == 0:
                temp.next = temp.next.next
                print("Removed term with zero coefficient")
            return
        
        # Insert the new term
        new_node.next = temp.next
        temp.next = new_node
        print(f"Inserted term {coefficient}x^{exponent} in descending order")
    
    def displayPolynomial(self):
        """
        Display the polynomial
        """
        if self.head is None:
            print("Polynomial is empty (0)")
            return
        
        print("Polynomial: ", end="")
        temp = self.head
        is_first = True
        
        while temp is not None:
            # Handle sign
            if not is_first:
                if temp.coefficient > 0:
                    print(" + ", end="")
                else:
                    print(" - ", end="")
            elif temp.coefficient < 0:
                print("-", end="")
            
            # Handle coefficient
            abs_coeff = abs(temp.coefficient)
            if abs_coeff != 1 or temp.exponent == 0:
                print(abs_coeff, end="")
            
            # Handle exponent
            if temp.exponent > 1:
                print(f"x^{temp.exponent}", end="")
            elif temp.exponent == 1:
                print("x", end="")
            
            temp = temp.next
            is_first = False
        
        print()
    
    def evaluatePolynomial(self, x):
        """
        Evaluate polynomial for a given value of x
        
        Args:
            x: Value to substitute for x
            
        Returns:
            float: Result of polynomial evaluation
        """
        result = 0.0
        temp = self.head
        
        while temp is not None:
            term_value = temp.coefficient * (x ** temp.exponent)
            result += term_value
            temp = temp.next
        
        return result
    
    def countTerms(self):
        """
        Count the number of terms in polynomial
        
        Returns:
            int: Number of terms
        """
        count = 0
        temp = self.head
        while temp is not None:
            count += 1
            temp = temp.next
        return count
    
    def findDegree(self):
        """
        Find the degree of polynomial
        
        Returns:
            int: Degree of polynomial (-1 if empty)
        """
        if self.head is None:
            return -1
        
        # Since terms are in descending order, first term has highest degree
        return self.head.exponent
    
    def addPolynomial(self, other):
        """
        Add another polynomial to this polynomial
        
        Args:
            other: Another Polynomial object
            
        Returns:
            Polynomial: New polynomial representing the sum
        """
        result = Polynomial()
        
        # Add all terms from first polynomial
        temp1 = self.head
        while temp1 is not None:
            result.insertTerm(temp1.coefficient, temp1.exponent)
            temp1 = temp1.next
        
        # Add all terms from second polynomial
        temp2 = other.head
        while temp2 is not None:
            result.insertTerm(temp2.coefficient, temp2.exponent)
            temp2 = temp2.next
        
        return result
    
    def multiplyByConstant(self, constant):
        """
        Multiply polynomial by a constant
        
        Args:
            constant: Constant to multiply by
        """
        if constant == 0:
            self.head = None
            print("Polynomial multiplied by 0, result is 0")
            return
        
        temp = self.head
        while temp is not None:
            temp.coefficient *= constant
            temp = temp.next
        
        print(f"Polynomial multiplied by {constant}")
    
    def derivativePolynomial(self):
        """
        Find derivative of polynomial
        
        Returns:
            Polynomial: New polynomial representing the derivative
        """
        result = Polynomial()
        temp = self.head
        
        while temp is not None:
            if temp.exponent > 0:
                new_coeff = temp.coefficient * temp.exponent
                new_exp = temp.exponent - 1
                result.insertTerm(new_coeff, new_exp)
            temp = temp.next
        
        return result
    
    def clear(self):
        """
        Clear the polynomial
        """
        self.head = None
        print("Polynomial cleared")
    
    def isEmpty(self):
        """
        Check if polynomial is empty
        
        Returns:
            bool: True if empty, False otherwise
        """
        return self.head is None

def demonstrate_polynomial():
    """
    Demonstrate polynomial operations
    """
    print("=== Polynomial Linked List Demonstration ===")
    
    # Create polynomial: 3x^4 + 2x^2 - 5x + 7
    poly1 = Polynomial()
    print("\nCreating polynomial P1(x) = 3x^4 + 2x^2 - 5x + 7")
    poly1.insertTerm(3, 4)   # 3x^4
    poly1.insertTerm(2, 2)   # 2x^2
    poly1.insertTerm(-5, 1)  # -5x
    poly1.insertTerm(7, 0)   # 7
    poly1.displayPolynomial()
    
    # Create another polynomial: x^3 - 2x^2 + 4
    poly2 = Polynomial()
    print("\nCreating polynomial P2(x) = x^3 - 2x^2 + 4")
    poly2.insertTerm(1, 3)   # x^3
    poly2.insertTerm(-2, 2)  # -2x^2
    poly2.insertTerm(4, 0)   # 4
    poly2.displayPolynomial()
    
    # Test polynomial operations
    print(f"\nDegree of P1: {poly1.findDegree()}")
    print(f"Number of terms in P1: {poly1.countTerms()}")
    
    # Evaluate polynomial
    x_value = 2
    result = poly1.evaluatePolynomial(x_value)
    print(f"P1({x_value}) = {result}")
    
    # Add polynomials
    print("\nAdding P1 + P2:")
    poly_sum = poly1.addPolynomial(poly2)
    poly_sum.displayPolynomial()
    
    # Find derivative
    print("\nDerivative of P1:")
    poly_derivative = poly1.derivativePolynomial()
    poly_derivative.displayPolynomial()

def interactive_polynomial():
    """
    Interactive polynomial operations
    """
    print("\n=== Interactive Polynomial Operations ===")
    
    poly = Polynomial()
    
    while True:
        print("\n--- Menu ---")
        print("1. Insert Term")
        print("2. Display Polynomial")
        print("3. Evaluate Polynomial")
        print("4. Count Terms")
        print("5. Find Degree")
        print("6. Multiply by Constant")
        print("7. Find Derivative")
        print("8. Create Sample Polynomial")
        print("9. Clear Polynomial")
        print("10. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                coeff = float(input("Enter coefficient: "))
                exp = int(input("Enter exponent: "))
                
                if exp < 0:
                    print("Exponent should be non-negative!")
                else:
                    poly.insertTerm(coeff, exp)
            
            elif choice == 2:
                poly.displayPolynomial()
            
            elif choice == 3:
                if poly.isEmpty():
                    print("Polynomial is empty!")
                else:
                    x = float(input("Enter value of x: "))
                    result = poly.evaluatePolynomial(x)
                    print(f"P({x}) = {result}")
            
            elif choice == 4:
                print(f"Number of terms: {poly.countTerms()}")
            
            elif choice == 5:
                degree = poly.findDegree()
                if degree == -1:
                    print("Polynomial is empty!")
                else:
                    print(f"Degree of polynomial: {degree}")
            
            elif choice == 6:
                if poly.isEmpty():
                    print("Polynomial is empty!")
                else:
                    constant = float(input("Enter constant to multiply: "))
                    poly.multiplyByConstant(constant)
            
            elif choice == 7:
                if poly.isEmpty():
                    print("Polynomial is empty!")
                else:
                    derivative = poly.derivativePolynomial()
                    print("Derivative:")
                    derivative.displayPolynomial()
            
            elif choice == 8:
                poly.clear()
                print("Creating sample polynomial: 2x^3 - 4x^2 + 3x - 1")
                poly.insertTerm(2, 3)
                poly.insertTerm(-4, 2)
                poly.insertTerm(3, 1)
                poly.insertTerm(-1, 0)
                poly.displayPolynomial()
            
            elif choice == 9:
                poly.clear()
            
            elif choice == 10:
                print("Exiting...")
                break
            
            else:
                print("Invalid choice! Please try again.")
        
        except ValueError:
            print("Please enter valid numbers!")
        except Exception as e:
            print(f"Error: {e}")

def test_edge_cases():
    """
    Test edge cases for polynomial operations
    """
    print("\n=== Testing Edge Cases ===")
    
    # Test empty polynomial
    print("\n1. Empty polynomial:")
    empty_poly = Polynomial()
    empty_poly.displayPolynomial()
    print(f"Degree: {empty_poly.findDegree()}")
    print(f"Evaluation at x=5: {empty_poly.evaluatePolynomial(5)}")
    
    # Test zero coefficients
    print("\n2. Zero coefficients:")
    zero_poly = Polynomial()
    zero_poly.insertTerm(0, 2)  # Should be skipped
    zero_poly.insertTerm(3, 1)
    zero_poly.insertTerm(-3, 1) # Should cancel out
    zero_poly.displayPolynomial()
    
    # Test single term
    print("\n3. Single term polynomial:")
    single_poly = Polynomial()
    single_poly.insertTerm(5, 0)  # Constant polynomial
    single_poly.displayPolynomial()
    print(f"Degree: {single_poly.findDegree()}")

if __name__ == "__main__":
    # Run demonstration
    demonstrate_polynomial()
    
    # Test edge cases
    test_edge_cases()
    
    # Run interactive mode
    interactive_polynomial()