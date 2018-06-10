package com.mahbub.algorithm;

public class PascalTriangle_Demo {

    static final int MAX = 1000;
    static final int MOD = 100000007;

    static int[][] ncr = new int[MAX+7][MAX+7];

    static void calcNCR() {
        ncr[0][0] = 1;
        for (int n = 1; n <= MAX; n++) {
            ncr[n][0] = 1;
            for (int k = 1; k <= n; k++)
                ncr[n][k] = (ncr[n-1][k] + ncr[n-1][k-1]) % MOD;
        }
    }

    public static void main(String args[]) {
        calcNCR();

        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j <= i; j++)
                System.out.print(ncr[i][j] + " ");
            System.out.println();
        }
    }
}
