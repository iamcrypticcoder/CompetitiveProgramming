package com.mahbub.algorithm;

import java.util.ArrayList;
import java.util.List;

public class SieveBitwise_Demo {

    static final int MAX_PRIME = 10000000;

    static long bitFlag[];
    static List<Integer> primes;

    static void sieveBitwise(int N) {
        bitFlag = new long[N / 64 + 7];
        primes = new ArrayList<>();

        for (int i = 3; i*i < N; i += 2) {
            if ((bitFlag[i/64] & (1L << (i%64))) == 0) {
                for (long j = i*i; j <= N; j += 2*i) {
                    bitFlag[(i/64)] |= (1L << (j%64));
                }
            }
        }

        primes.add(2);
        for (int i = 3; i <= N; i += 2)
            if ((bitFlag[i/64] & (1L << (i%64))) == 0) primes.add(i);
    }

    static boolean isPrime(long n) {
        if (n <= 1) return false;
        if ((n & 1) == 0) return false;
        if (n <= MAX_PRIME)
            return (bitFlag[(int)n/64] & (1L << (n%64))) == 0;
        int root = (int) Math.sqrt(n);
        for (int i = 0; primes.get(i) <= root; i++) {
            if (n % primes.get(i) == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        //sieveOptimized(20);
        sieveBitwise(MAX_PRIME);

        /*
        for (int i = 0; i < primes.size(); i++) {
            System.out.println(primes.get(i));
        }
        */

        System.out.println(isPrime(121));
    }
}
