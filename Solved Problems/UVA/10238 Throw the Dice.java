
import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;

class Main {
	
	public static BigInteger[][] DP = new BigInteger[51][4001];
	public static int noThrows, faces, sum;

	public static BigInteger solve(int onThrows, int sum) {
            if(onThrows == 0 && sum == 0) return DP[0][0] = BigInteger.ONE;
            else if(onThrows <= 0 || sum <= 0) return BigInteger.ZERO;

            if( ! DP[onThrows][sum].equals(new BigInteger("-1")) ) return DP[onThrows][sum];
		
            BigInteger ret = BigInteger.ZERO;
            for(int f = 1; f <= faces; f++)
                ret = ret.add(solve(onThrows-1, sum-f));

            return DP[onThrows][sum] = ret;
	}
	
	public static void main(String args[])
	{
		int TC, tc;
		Scanner scr = new Scanner(System.in);
		
		
		while(scr.hasNextInt()) {
                    faces = scr.nextInt();
                    noThrows = scr.nextInt();
                    sum = scr.nextInt();
					
					for (BigInteger[] arr : DP)
                    	Arrays.fill(arr, new BigInteger("-1"));
                    
                    //System.out.println(solve(noThrows, sum).toString());
                    System.out.println(solve(noThrows, sum).toString() + "/" + new BigInteger(String.valueOf(faces)).pow(noThrows));
                }
		
	}
}