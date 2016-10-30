/*
	Here's a way to derive the formula without using any sequences, 
	just uses some elementary graph theory.
	
	The case n=0 and n=1 are special cases, but it turns out that for n=1 the formula is correct.
	
	For the cases n>1,
	Let v be the number of intersection points, 
	we know there are n(n-1) of them since there are n(n-1)/2 pairs of circles and 
	each pair has exactly 2 intersection points. These are the vertices of our graph. 
	Now v=n(n-1).
	
	We can now think of the arcs of the circles bounding the regions as edges between the vertices. 
	It is easy to see that the degree of each vertex is 4 (since exactly 2 circles intersect at each 
	intersection point), so by the handshaking lemma, the total number of edges, e = 4v/2 = 2v = 2n(n-1).
	
	We are asked to compute the number of regions f, so by Euler's formula,
	f = e - v + 2 = n (n - 1) + 2.

*/

/*
	I just count the number of intersection and add 2.
	That means F(N)=number_Of_Intersection + 2;
	
	How can we calculate number_Of_Intersection?
	Just think that........
	Using two circle we can make intersection.......
	--------------------------------------------------------------------------
	So select 2 circle from N circle= nC2.
	Every two circle make 2 intersection.
	so number_Of_Intersection=2 * nC2 .
	F(N)=2* N*(N-1)/2 + 2
	=>F(N) = N*(N-1)+2
	=>F(N) = N*N - N + 2.
*/

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	
	public static void main(String args[]) {
		
		Scanner scr = new Scanner(System.in);
		
		while(scr.hasNextBigInteger()) {
			BigInteger N = scr.nextBigInteger();
			
			if(N.equals(BigInteger.ZERO)) {
                            System.out.println("1");
                            continue;
                        }
			
			BigInteger ans;
			
			ans = N.multiply(N);
			
            ans = ans.subtract(N);
            ans = ans.add(BigInteger.valueOf(2));

			
			
			System.out.println(ans);
			
		}
		
	}
	
}
