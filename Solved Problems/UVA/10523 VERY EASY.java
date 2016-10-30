import java.util.Scanner;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[])
	{
		
		Scanner scr = new Scanner(System.in);
		
		while(scr.hasNext()) {
			
			int N = scr.nextInt();
			int A = scr.nextInt();
			
			BigInteger ans = BigInteger.ZERO;
			
			for(int i=1; i<= N; i++) {
				ans = ans.add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(A).pow(i)));
			}

                        System.out.println(ans);
		}
	
		
		
	}
	
}
