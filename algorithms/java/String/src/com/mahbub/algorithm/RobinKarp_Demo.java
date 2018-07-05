package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created by mahbub on 3/7/18.
 */
public class RobinKarp_Demo {

    static final int MOD = 101;

    static String P, T;
    static int m, n;
    static int b = 31;
    static int power;       // Hold b^(m-1)
    static int pHash, tHash;

    static List<Integer> search() {
        List<Integer> indices = new ArrayList<>();
        int m = P.length();
        int n = T.length();

        power = 1;
        for (int i = 0; i < m-1; i++) power = (power * b) % MOD;

        pHash = tHash = 0;
        for (int i = 0; i < m; i++) {
            pHash = ((pHash * b) + P.charAt(i)) % MOD;
            tHash = ((tHash * b) + T.charAt(i)) % MOD;
        }

        for (int i = 0; i <= n-m; i++) {
            if (tHash == pHash) {
                int j = 0;
                while (j < m) {
                    if (P.charAt(j) != T.charAt(i+j)) break;
                    j++;
                }
                if (j == m) indices.add(i);
            }
            if (i == n-m) break;

            tHash = ((tHash - T.charAt(i) * power) * b + T.charAt(i+m)) % MOD;
            tHash = (tHash + MOD) % MOD;
        }

        return indices;
    }

    public static void main(String args[]) {
        Scanner scanner = inputFromFile();

        P = "Samsung";
        T = "My name is Mahbub. I work at Samsung. Samsung is a very big company";

        List<Integer> list = search();
        for (int x : list) System.out.print(x + " ");
    }

    static Scanner inputFromSystem() {
        return new Scanner(System.in);
    }

    static Scanner inputFromFile() {
        Scanner scanner = null;
        try {
            scanner = new Scanner(new FileInputStream("input.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return scanner;
    }
}