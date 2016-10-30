/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :		0.298
    Rank :		566
    Complexity:
*/
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	
	public static String toBinary(BigInteger N) {
		String ret = new String("");
		if(N.compareTo(BigInteger.ZERO) == 0) return "0";
		while(N.compareTo(BigInteger.ZERO) > 0)	{		// while N is greater than zero
			if(N.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0)
				ret = ret.concat("0");
			else ret = ret.concat("1");
			N = N.divide(BigInteger.valueOf(2));
		}
		//ret = new StringBuffer(ret).reverse().toString();
		return ret;
	} 
		
	public static void main(String args[]) {
		BigInteger[] powers = new BigInteger[65];			// N = 10^19. Then lg(10^19) = 63.1166
		powers[0] = BigInteger.ONE;
		for(int i=1; i <= 64; i++) {
			powers[i] = powers[i-1].multiply(BigInteger.valueOf(3));
		}
		
		Scanner scr = new Scanner(System.in);
		while(true) {
			BigInteger N = scr.nextBigInteger();
			if(N.compareTo(BigInteger.ZERO) == 0) break;
			
			N = N.subtract(BigInteger.ONE);
			
			String binary = toBinary(N);
			//System.out.println(binary.length());
			
			String output = new String("");

			output = "{";
			boolean isFirst = true;
			for(int i=0; i < binary.length(); i++) {
				if(binary.charAt(i) == '1') {
					if( !isFirst ) output = output.concat(",");
					output = output.concat(new String(" ").concat(powers[i].toString()));
					isFirst = false;
				}
			}
			output = output.concat(" }");

			System.out.println(output);
			
		}
		
	}
	
}