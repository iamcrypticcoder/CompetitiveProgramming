import java.util.Scanner;
import java.math.BigInteger;


class Main {

    public static void main(String args[])
    {
        BigInteger fib[] = new BigInteger[5001];
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        fib[2] = BigInteger.ONE;

        for(int i=3; i<=5000; i++) 
            fib[i] = fib[i-1].add(fib[i-2]);
        
        Scanner scr = new Scanner(System.in);

        while(scr.hasNextInt()) {
            int N = scr.nextInt();

            System.out.println("The Fibonacci number for " + N + " is " + fib[N]);

        }
    }
}
