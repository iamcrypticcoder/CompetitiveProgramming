package com.mahbub.algorithm;

import java.util.Scanner;

public class NthPermutation {

    static int MAX_SIZE = 20;
    static int ALPHABET_SIZE = 26;

    static int[] factTable = new int[MAX_SIZE];

    static void initFactTable() {
        factTable[0] = 1;
        for (int i = 1; i < MAX_SIZE; i++) {
            factTable[i] = factTable[i-1] * i;
        }
    }

    /**
     * Works for only distinct string
     * @param str
     * @param n
     * @return
     */
    static String nthPermutationDistinct(String str, int n) {
        if (n > factTable[str.length()]) return null;
        // Our algorithm works for 0 based index, So decreasing by one
        n = n - 1;

        StringBuilder sb1 = new StringBuilder(str);
        StringBuilder sb2 = new StringBuilder();
        for (int i = str.length()-1; i >= 0 ; i--) {
            if (n >= factTable[i]) {
                int q = n / factTable[i];
                n = n % factTable[i];
                sb2.append(sb1.charAt(q));
                sb1.deleteCharAt(q);
            } else {
                sb2.append(sb1.charAt(0));
                sb1.deleteCharAt(0);
            }
        }

        return sb2.toString();
    }

    /**
     * Works for string with repeated characters
     * @param str
     * @param n Value of n starts from 1
     * @return
     */
    static String nthPermutationRepitition(String str, int n) {
        int len = str.length();

        // Count frequencies
        int[] freq = new int[ALPHABET_SIZE];
        for (int i = 0; i < len; i++)
            freq[str.charAt(i) - 'a']++;

        StringBuilder sb = new StringBuilder();

        int sum = 0;
        while (sb.length() != str.length()) {
            sum = 0;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (freq[i] == 0) continue;

                freq[i]--;

                int tSum = factTable[len - 1 - sb.length()];
                for (int j = 0; j < ALPHABET_SIZE; j++) {
                    tSum /= factTable[freq[j]];
                }
                sum += tSum;

                if (n <= sum) {
                    sb.append((char)('a' + i));
                    n = n - (sum - tSum);
                    break;
                }

                freq[i]++;
            }
        }

        return sb.toString();
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        initFactTable();

        /*
        for (int i = 1; i <= 24; i++) {
            System.out.println(nthPermutationDistinct("abcd", i));
        }
        */

        for (int i = 1; i <= 12; i++) {
            System.out.println(nthPermutationRepitition("aabc", i));
        }
    }
}
