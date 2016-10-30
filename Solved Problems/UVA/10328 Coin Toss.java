
import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;


class Main {

    static int noBits, weNeed;
    static BigInteger DP[][];

    public static BigInteger solve(int n, int s)
    {
    	if(n < 0 || s < 0) return BigInteger.ZERO;
    	else if(n < s) return BigInteger.ZERO;
    	else if(DP[n][s] != null) return DP[n][s];
        else if(s == 0) return DP[n][s] = new BigInteger("2").pow(n);
		
        BigInteger ret;
        ret = solve(n-1, weNeed).add(solve(n-1, s-1));
        return DP[n][s] = ret;
    }

    public static void main(String args[])
    {
        Scanner scr = new Scanner(System.in);

        while(scr.hasNextInt()) {
            noBits = scr.nextInt();
            weNeed = scr.nextInt();
			
			DP = new BigInteger[noBits+1][weNeed+1];
			
            System.out.println(solve(noBits, weNeed));
        }
    }
}
