def main():
    # TODO: Implement solution here
    n = int(input("Enter a number : "))
    while(n<0) : n = int(input("INVALID VALUE ENTERED!! \nEnter a positive value : "))
    if n%2==0 : print(n, "is even")
    else : print(n, "is odd")


if __name__ == "__main__":
    main()
