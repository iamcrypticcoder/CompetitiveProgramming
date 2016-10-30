/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :		0.288
    Rank :		841
    Complexity:
*/

import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	
	public static BigInteger[] cats = new BigInteger[1001];
	
	public static void generateCatalans() {
		cats[0] = BigInteger.ONE;
		for(int i = 1; i <= 1000; i++) {
			int n = i-1;
			cats[i] = BigInteger.valueOf(2 * (2*n + 1));
			cats[i] = cats[i].multiply(cats[n]);
			cats[i] = cats[i].divide(BigInteger.valueOf(n+2));
		}
	}
	
	public static void main(String args[]) {
		Scanner scr = new Scanner(System.in);
		
		generateCatalans();
		
		while(scr.hasNextInt()) {
			int n = scr.nextInt();
			System.out.println(cats[n].toString());
		}
	}

    
    
}