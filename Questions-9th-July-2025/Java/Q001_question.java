import java.util.Scanner;

public class Q001_question {
    public static void main(String[] args) {
        // TODO: Implement solution here
        int num = new Scanner(System.in).nextInt();
        if(num%2==0)
            System.out.println(num + " is even");
        else
            System.out.println(num + " is odd");
    }
}
