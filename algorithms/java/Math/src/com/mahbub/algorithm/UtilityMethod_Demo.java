package com.mahbub.algorithm;

/**
 * Created by mahbub on 6/21/17.
 */
public class UtilityMethod_Demo {

    public static void main(String[] args) {
        System.out.println(toBase(100, 16));
        System.out.println(toDecimal("101", 2));
        System.out.println(bigMod(5, 10053453, 7));
        System.out.println(phiFunc(36));

        System.out.println(countDivisors(13) + " == " + countDivisorsSimple(13));
        System.out.println(countDivisors(20) + " == " + countDivisorsSimple(20));

        System.out.println(sumDivisors(13) + " == " + sumDivisorsSimple(13));
        System.out.println(sumDivisors(20) + " == " + sumDivisorsSimple(20));
        System.out.println(sumDivisors(36) + " == " + sumDivisorsSimple(36));
    }

    // 10-BASE to ANY BASE
    // This function converts a 10 base number to any base and return the number as string
    // 10 = A, 11 = B, 12 = C ...... 25 = Z
    static String toBase(int n, int b) {
        if (n == 0) return "0";
        StringBuilder sb = new StringBuilder();
        while(n != 0) {
            sb.append(valueToChar(n % b));
            n /= b;
        }
        sb.reverse();
        return sb.toString();
    }
    static char valueToChar(int val) {
        if (val < 10) return (char)('0' + val);
        return (char)('A' + val - 10);
    }

    // ANY BASE to 10-base
    static long toDecimal(String val, int b) {
        if (val.length() == 0) return 0L;
        long ret = charToValue(val.charAt(0));
        for (int i = 1; i < val.length(); i++) ret = ret * b + charToValue(val.charAt(i));
        return ret;
    }
    static int charToValue(char ch) {
        if(ch >= '0' && ch <= '9') return ch - '0';
        if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
        if(ch >= 'a' && ch <= 'z') return ch - 'a' + 36;
        return Integer.MIN_VALUE;
    }

    // Compute (a^n) % m
    // Acceted UVA No: 10006
    static long bigMod(long a, long n, long m) {
        if (n == 0) return 1;
        if (n == 1) return a % m;
        long ret = bigMod(a, n/2, m);
        ret = (ret * ret) % m;
        if (n % 2 == 1) return (ret * a) % m;
        return ret;
    }

    // Calc eular totient function. Count number of relative primes to n which is smaller than n
    // Acceted UVA No : 10179, 10299, 10820
    static int phiFunc(int n) {
        if (n == 1) return 0;

        double ret = n;
        int root = (int)Math.sqrt(n);
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) ret *= (1 - (1.0 / i));
            while (n % i == 0) n /= i;
        }

        if (n > 1) ret *= (1 - (1.0/ n));
        return (int)ret;
    }


    // Using formula
    // Count number of divisors of n
    // Accepted UVA No: 11064
    // Complexity: O(sqrt(n))
    static int countDivisors(long n) {
        if (n == 1) return 1;
        int ret = 1;
        int root = (int)Math.sqrt(n);
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) {
                int power = 0;
                while (n % i== 0) { power++; n /= i; }
                ret *= (power + 1);
            }
            if (n == 1) break;
        }
        if (n > 1) ret *= 2;
        return ret;
    }

    // Using simple observation
    // Complexity: O(sqrt(n))
    static int countDivisorsSimple(long n) {
        if (n == 1) return 1;
        int ret = 2;
        int root = (int)Math.sqrt(n);
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) {
                if (i == (n / i)) ret++;
                else ret += 2;
            }
        }
        return ret;
    }

    // Using formula
    // Calculate sum of divisors of n
    // Complexity: O(sqrt(n))
    static long sumDivisors(long n) {
        if (n == 1) return 1;
        int ret = 1;
        int root = (int)Math.sqrt(n);
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) {
                int power = 0;
                while (n % i == 0) { power++; n /= i; }
                ret *= (int)((Math.pow(i, power + 1) - 1) / (i - 1));
            }
        }
        if (n > 1) ret *= (int)((Math.pow(n, 2) - 1) / (n - 1));
        return ret;
    }

    // Using simple observation
    // Complexity: O(sqrt(n))
    static long sumDivisorsSimple(long n) {
        if (n == 1) return 1;
        long ret = 1 + n;
        int root = (int)Math.sqrt(n);
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) {
                if (i == (n/i)) ret += i;
                else ret += (i + (n/i));
            }
        }
        return ret;
    }

    // This function tells us how many prime P we will get after factorizing n!.
    // count = floor(N/p) + floor(N/p^2) + floor(N/p^3) + floor(N/p^4)....
    int primeFreq(int p, int n) {
        int c = 0, power = 1;
        while (true) {
            int t = n / (int)Math.pow(p, power);
            if (t == 0) break;
            c += t; power++;
        }
        return c;
    }

    // Returns number of valid factorization of Any number N.
    // For N = 12 Ans is 3. (2 x 2 x 3), (2 x 6), (3 x 4).
    int countFactorization(int n, int m) {
        int ret = 0;
        for (int i = m; i*i <= n; i++) {
            if (n % i == 0) ret += countFactorization(n/i, i) + 1;
        }
        if (ret == 0) return 1;
        return ret;
    }


}
