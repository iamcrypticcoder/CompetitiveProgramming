// UVA ID - 10925 Krakovia

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[])
	{
		Scanner scr = new Scanner(System.in);
		
		int tc = 1;
				
		while(true) {
			int N = scr.nextInt();
			int F = scr.nextInt();
			
			if(N == 0 && F == 0) break;
			
			BigInteger Sum = BigInteger.ZERO;
			
			for(int i=1; i<= N; i++) {
				Sum = Sum.add(scr.nextBigInteger());
			}
			
			BigInteger P = Sum.divide(BigInteger.valueOf(F));
			
			System.out.println("Bill #" + (tc++) + " costs " + Sum + ": each friend should pay " + P + "\n");
			
		}
		
		
	}
	
}
