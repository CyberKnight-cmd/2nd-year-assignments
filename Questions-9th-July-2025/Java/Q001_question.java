import java.util.Scanner;

public class Q001_question {
    public static void main(String[] args) {
        // TODO: Implement solution here
        Scanner sc = new Scanner(System.in);
        int num;
        do{
            num = sc.nextInt();
            if(num < 0) System.out.println("NEGATIVE VALUE ENTERED!! TRY AGAIN");
        }while(num<0);
        
        if(num%2==0)
            System.out.println(num + " is even");
        else
            System.out.println(num + " is odd");
    }
}
