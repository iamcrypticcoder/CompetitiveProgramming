/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/


import java.util.Scanner;
import java.math.BigInteger;

class Main623 {

    public static void main(String args[])
    {
	    Scanner scr = new Scanner(System.in);
	    
	    BigInteger fact[] = new BigInteger[1001];
		
		fact[0] = BigInteger.ONE;					// Because 0! = 1
        fact[1] = BigInteger.ONE;
        
        for(int i=2; i<=1000; i++) {
            fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        }
		
		while(scr.hasNextInt()) {
			
			int N = scr.nextInt();
			
			System.out.println( N + "!");
			System.out.println(fact[N]);		
			
		}		

    }

}