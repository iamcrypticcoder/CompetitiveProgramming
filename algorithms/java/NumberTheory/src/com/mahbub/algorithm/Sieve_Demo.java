package com.mahbub.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Sieve_Demo {

    static final int MAX_PRIME = 10000000;

    static boolean[] flag;
    static List<Integer> primes;

    static class PowerPrime {
        long p;
        int a;  // p^a
        PowerPrime(long p, int a) { this.p = p; this.a = a; };
    }

    // Generate prime up to N
    static void generatePrime(int N) {
        flag = new boolean[N + 7];
        primes = new ArrayList<>();
        int i = 2;
        while (i * i <= N) {
            for (int j = i*i; j <= N; j += i) flag[j] = true;
            while (flag[++i]);
        }
        primes.add(2);
        for (i = 3; i <= N; i += 2) {
            if (!flag[i]) primes.add(i);
        }
    }

    static boolean isPrime(long n) {
        if (n == 0 || n == 1) return false;
        if (n <= MAX_PRIME) return flag[(int)n];
        int root = (int) Math.sqrt(n);
        for (int i = 0; primes.get(i) <= root; i++) {
            if (n % primes.get(i) == 0) return false;
        }
        return true;
    }

    static List<Long> factorize(long n) {
        if (n == 1) return Arrays.asList(new Long[] {1L});

        List<Long> ret = new ArrayList<>();
        int root = (int)Math.sqrt(n);
        for (int i = 0; primes.get(i) <= root; i++) {
            int p = primes.get(i);
            while (n % p == 0) { n /= p; ret.add((long)p); }
        }
        if (n > 1) ret.add(n);
        return ret;
    }

    static List<PowerPrime> factorizeAsPower(long n) {
        if (n == 1) return Arrays.asList(new PowerPrime[] { new PowerPrime(1, 1) });

        List<PowerPrime> ret = new ArrayList<>();
        int root = (int)Math.sqrt(n);
        for (int i = 0; primes.get(i) <= root; i++) {
            int p = primes.get(i);
            int a = 0;
            while (n % p == 0) { n /= p; a++; }
            if (a > 0) ret.add(new PowerPrime(p, a));
        }

        if (n > 1) ret.add(new PowerPrime(n, 1));

        return ret;
    }

    static int countDivisors(long n) {
        int ret = 1;
        int root = (int)Math.sqrt(n);
        for (int i = 0; i < primes.size() && primes.get(i) <= root; i++) {
            int p = primes.get(i);
            if (n % p == 0) {
                int cnt = 0;
                while (n % p == 0) {
                    n /= p;
                    cnt++;
                }
                ret *= (cnt + 1);
            }
        }
        if (n > 1) ret = ret << 1;

        return ret;
    }
    
    public static void main(String args[]) {
        generatePrime(MAX_PRIME);
        System.out.println("Total Primes: " + primes.size());
        //for (int x : primes) System.out.println(x);

        System.out.println(isPrime(67280421310721L));
        System.out.println(isPrime(100000007));

        List<Long> factors = factorize(16);
        for (long x : factors) System.out.println(x);

        List<PowerPrime> pa = factorizeAsPower(100000007);
        for (PowerPrime x : pa) System.out.println(x.p + "^" + x.a);
    }


}
