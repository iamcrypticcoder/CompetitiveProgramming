// UVA ID - 10814 Simplifying Fractions

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[])
	{
		
		Scanner scr = new Scanner(System.in);
		
		int TC = scr.nextInt();

		while(TC-- > 0) {
			BigInteger nume = scr.nextBigInteger();
			scr.next();
			BigInteger deno = scr.nextBigInteger();
			
			BigInteger gcd = nume.gcd(deno);

            nume = nume.divide(gcd);
            deno = deno.divide(gcd);

            System.out.println(nume + " / " + deno);
			
		}	
	
		
		
	}
	
}
