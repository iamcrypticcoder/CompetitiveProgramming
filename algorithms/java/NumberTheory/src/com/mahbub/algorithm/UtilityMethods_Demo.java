package com.mahbub.algorithm;

import java.util.Arrays;

public class UtilityMethods_Demo {

    static final int MOD = 100000007;

    static long gcd(long a, long b) {
        if (a == 0) return b;
        return gcd(b%a, a);
    }

    // Function to find (1/a mod m).
    // This function can find mod inverse if m are prime
    static int modInverseFarmetsTheorem(long a, long m) {
        if (gcd(a, m) != 1) return -1;

        return (int)bigMod(a, m-2, m);
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

    // Function to find (1/a mod m).
    // This function can find mod inverse if a and m are coprime
    static long modInverseExtendedEuclid(long a, long m) {
        long[] xy = new long[2];
        long gcd = extendedEuclid(a, m, xy);

        if (gcd != 1) return -1;

        // in case xy[0] is negetive, adding m will make it positive
        long ret = (xy[0] % m + m) % m;

        return ret;
    }

    static long extendedEuclid(long a, long b, final long[] xy) {
        if (a == 0) {
            xy[0] = 0; xy[1] = 1;
            return b;
        }

        long[] xyPrev = new long[2];
        long gcd = extendedEuclid(b % a, a, xyPrev);

        xy[0] = xyPrev[1] - (b/a) * xyPrev[0];
        xy[1] = xyPrev[0];

        return gcd;
    }

    // This function finds ncr using modular multiplicative inverse
    static long ncr(long n, long r, long m) {
        if (n == r) return 1;
        if (r == 1) return n;

        long start = n - Math.min(r, n - r) + 1;

        long ret = 1;
        for (long i = start; i <= n; i++) ret = (ret * i) % m;

        long until = Math.min(r, n - r), denom = 1;
        for (long i = 1; i <= until; i++) denom = (denom * i)  % m;

        ret = (ret * modInverseFarmetsTheorem(denom, m)) % m;

        return ret;
    }

    // Another implementation of ncr
    static long ncr2(long n, long r, long m) {
        if (n == r) return 1;
        if (r == 1) return n;

        long[] fact = new long[(int)n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % m;

        long ret = fact[(int)n];
        ret = ret * modInverseFarmetsTheorem(fact[(int)r], m) % m;
        ret = ret * modInverseFarmetsTheorem(fact[(int)(n-r)], m) % m;

        return ret;
    }

    // Find Euler's totient phi function which is given a number N find of co-primes less N
    // Complexity: O(sqrt(N))
    static int phi(int n) {
        if (n == 1) return 0;
        int ret = n;

        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                while (n % p == 0) n /= p;
                ret = ret * (p - 1) / p;
            }
        }
        if (n > 1) ret = ret * (n-1) / n;

        return ret;
    }
    
    public static void main(String[] args) {
        long[] xy = new long[2];
        System.out.println(extendedEuclid(11, 3, xy));

        System.out.println(Arrays.toString(xy));

        System.out.println(modInverseExtendedEuclid(24, MOD));
        System.out.println(modInverseFarmetsTheorem(24, MOD));

        System.out.println(ncr(10, 4, 97) + " = " + ncr2(10, 4, 97));
        System.out.println(ncr(12345678, 123456, MOD) + " = " + ncr2(12345678, 123456, MOD));
        
        for (int i = 1; i < 144; i++) {
            System.out.println(i + ": " + phi(i));
        }
    }
}
