/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :		0.202
    Rank :		2018
    Complexity:
*/

import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	
	public static BigInteger[] cats = new BigInteger[20];
	
	public static void generateCatalans() {
		cats[0] = BigInteger.ONE;
		for(int i = 1; i <= 19; i++) {
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
			BigInteger n = scr.nextBigInteger();
			for(int i=1; i<=19; i++) {
				if(cats[i].compareTo(n) == 0) {
					System.out.println(i);
					break;
				}
			}
		}
	}

    
    
}