package com.mahbub.algorithm;

public class EularNumber_Demo {

    static final int MAX = 50;
    static final int MOD = 100000007;

    static int[][] eular1 = new int[MAX+1][MAX+1];
    static int[][] eular2 = new int[MAX+1][MAX+1];

    static void generateEular1() {
        eular1[0][0] = 1;
        for (int n = 1; n <= MAX; n++) {
            eular1[n][0] = 1;
            eular1[n][n] = 0;
        }

        for (int n = 2; n <= 50; n++)
            for (int k = 1; k < n; k++)
                eular1[n][k] = ((k+1) * eular1[n-1][k] + (n-k) * eular1[n-1][k-1]) % MOD;
    }

    static void generateEular2() {
        eular2[0][0] = 1;
        for (int n = 1; n <= MAX; n++) {
            eular2[n][0] = 1;
            eular2[n][n] = 0;
        }

        for (int n = 2; n <= 50; n++)
            for (int k = 1; k < n; k++)
                eular2[n][k] = ((k+1) * eular2[n-1][k] + (2*n-1-k) * eular2[n-1][k-1]) % MOD;
    }

    public static void main(String[] args) {
        generateEular1();
        generateEular2();
    }
}
