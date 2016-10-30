// UVA ID - 10220 I Love Big Numbers

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[])
	{
		Scanner scr = new Scanner(System.in);
		
		BigInteger fact[] = new BigInteger[1001];
		fact[1] = BigInteger.ONE;
		
		for(int i=2; i<=1000; i++)
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));	
		
		while(scr.hasNextInt()) {
			int N = scr.nextInt();
			
			BigInteger F = fact[N];
			BigInteger sum = BigInteger.ZERO;
			
			while( ! F.equals(BigInteger.ZERO)) {
                            sum = sum.add(F.mod(BigInteger.TEN));
                            F = F.divide(BigInteger.TEN);
                        }

                        System.out.println(sum);
			
		}
	
	
		
		
	}
	
}
