/*
	Critical input :
	
	0
	0
	
	1
	0
	
	0
	1
	
	Output :
	
	0
	
	1
	
	1 
 
*/

import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public BigInteger fib[] = new BigInteger[151];			// Generate 150 fibs cause the sum may be large

    public void GenerateFib()
    {
            fib[1] = BigInteger.ONE;
            fib[2] = BigInteger.valueOf(2);

            for(int i=3; i<=150; i++)
                    fib[i] = fib[i-1].add(fib[i-2]);
    }

    BigInteger fibToDec(String fibNum)
    {
        BigInteger ret = BigInteger.ZERO;
		
		int len = fibNum.length();
		
        for(int i=0; i<fibNum.length(); i++) {
            if(fibNum.charAt(i) == '1')
            	ret = ret.add(fib[len - i]);                                      // Since I generate fibs from index 1
        }

        return ret;
    }

    String decToFib(BigInteger decNum)
    {
        String ret = "";
        
        if(decNum.equals(BigInteger.ZERO)) return new String("0");

        for(int i = 150; i>=1; i--) {
            if(decNum.compareTo(fib[i]) >= 0) {
                decNum = decNum.subtract(fib[i]);
                ret += '1';
            }
            else {
                if( !ret.equals("")) 
                    ret += '0';
            }
        }

        return ret;
    }
	
    public Main()
    {
            GenerateFib();

            Scanner scr = new Scanner(System.in);

			int TC = 1;

            while(scr.hasNext()) {
                    String fibNum1 = scr.next();
                    String fibNum2 = scr.next();

//                    System.out.println(fibToDec(fibNum1));
//                    System.out.println(fibToDec(fibNum2));

                    BigInteger decNum1 = fibToDec(fibNum1);
                    BigInteger decNum2 = fibToDec(fibNum2);
                    BigInteger sum = decNum1.add(decNum2);

					if(TC >= 2) System.out.println();
					
//                    System.out.println(sum);					
                    System.out.println(decToFib(sum));
                    
                    TC++;

            }

    }

    public static void main(String args[])
    {
            new Main();

    }
	
	
}
