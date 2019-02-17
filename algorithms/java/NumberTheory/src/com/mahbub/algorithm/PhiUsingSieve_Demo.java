package com.mahbub.algorithm;

public class PhiUsingSieve_Demo {

    static final int MAX = 10000000;
    static int phi[];

    public static void main(String args[]) {
        generatePhi(MAX);
        printPhi(20);
    }

    public static void generatePhi(int N) {
        phi = new int[N + 1];
        phi[1] = 0;
        for (int i = 2; i <= N; i++) {
            if (phi[i] == 0) {
                phi[i] = i - 1;
                for (int j = (i << 1); j <= N; j += i) {
                    if(phi[j] == 0) phi[j] = j;
                    phi[j] = phi[j] / i * (i-1);
                }
            }
        }
    }

    static void printPhi(int n) {
        System.out.println("Printing \uD835\uDF11 values up to " + n + ":");
        System.out.println(" n   \uD835\uDF11(n)");
        System.out.println("====================");
        for (int i = 1; i <= n; i++) {
            System.out.printf("%2d    %d\n", i, phi[i]);
        }
    }
}
