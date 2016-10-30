import java.util.Scanner;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[])
	{
		int TC, tc;
		Scanner scr = new Scanner(System.in);
		BigInteger big1;
		BigInteger sum;
		
		sum = BigInteger.ZERO;
		while(scr.hasNextBigInteger()) {
			big1 = scr.nextBigInteger();
			if(big1.compareTo(BigInteger.ZERO) == 0) break;
			sum = sum.add(big1);
		}
		
		System.out.println(sum);
	}
}
