package com.mahbub.algorithm;

public class StirlingNumber_Demo {

    static final int MAX = 1000;
    static final int MOD = 100000007;

    static int[][] stirling1 = new int[MAX+7][MAX+7];
    static int[][] stirling2 = new int[MAX+7][MAX+7];

    static void generateStirling2() {
        stirling2[0][1] = 1;

        for (int n = 1; n <= MAX; n++) {
            stirling2[n][0] = 0;
            stirling2[n][1] = 1;
            stirling2[n][n] = 1;
        }

        for (int n = 3; n <= MAX; n++)
            for (int k = 2; k < n; k++)
                stirling2[n][k] = (k * stirling2[n-1][k] + stirling2[n-1][k-1]) % MOD;
    }

    static void generateStirling1() {
        stirling1[0][1] = 1;

        for (int n = 1; n <= MAX; n++) {
            stirling1[n][0] = 0;
            stirling1[n][n] = 1;
        }

        for (int n = 2; n <= MAX; n++)
            for (int k = 1; k < n; k++)
                stirling1[n][k] = ((n-1) * stirling1[n-1][k] + stirling1[n-1][k-1]) % MOD;
    }

    static void printStirling2() {
        for (int n = 0; n <= 9; n++) {
            for (int k = 0; k <= n; k++)
                System.out.print(stirling2[n][k] + "  ");
            System.out.println();
        }
    }

    static void printStirling1() {
        for (int n = 0; n <= 9; n++) {
            for (int k = 0; k <= n; k++)
                System.out.print(stirling1[n][k] + "  ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        generateStirling1();
        generateStirling2();

        printStirling1();
        printStirling2();
    }
}
