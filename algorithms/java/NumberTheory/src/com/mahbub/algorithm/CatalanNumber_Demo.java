package com.mahbub.algorithm;

/**
 * Created by mahbub on 26/6/18.
 */
public class CatalanNumber_Demo {

    static final int MOD = 1000000007;

    static int[] fact, cat;

    static void generateCatalan(int N) {
        fact = new int[2*N+1];
        fact[0] = 1;
        for (int i = 1; i <= 2*N; i++) {
            fact[i] = (int) (((long)fact[i-1] * i) % MOD);
        }

        cat = new int[N+1];
        cat[0] = 1;
        for (int i = 1; i <= N; i++) {
            long deno = ((long)fact[i+1] * fact[i]) % MOD;
            long inv = bigMod(deno, MOD-2, MOD);
            cat[i] = (int) ((fact[2*i] * inv) % MOD);
        }
    }

    static void printCat(int N) {
        for (int i = 0; i <= N; i++) {
            System.out.print(cat[i] + " ");
        }
        System.out.println();
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

    public static void main(String args[]) {
        generateCatalan(20);
        printCat(20);
    }
}