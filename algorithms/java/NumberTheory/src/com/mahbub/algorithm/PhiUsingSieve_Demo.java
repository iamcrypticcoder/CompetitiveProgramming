package com.mahbub.algorithm;

public class PhiUsingSieve_Demo {

    static final int MAX = 10000000;

    static int[] phi = new int[MAX + 1];

    static void generatePhiUsingSieve() {
        phi[1] = 0;
        for (int i = 2; i <= MAX; i++) {
            // If still not calculated
            if (phi[i] == 0) {
                phi[i] = i - 1;
                for (int j = (i << 1); j <= MAX; j += i) {
                    if (phi[j] == 0) phi[j] = j;
                    phi[j] = phi[j] * (i - 1) / i;
                }
            }
        }
    }

    public static void main(String args[]) {
        generatePhiUsingSieve();
        for (int i = 1; i <= 50; i++)
            System.out.println(i + " = " + phi[i]);
    }
}
