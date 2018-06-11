package com.mahbub.algorithm;

import java.util.Scanner;

public class InsertionSort_Demo {

    static void insertionSort(int[] items) {
        int i , j;
        int count = items.length;
        for (i = 1; i < count; i++) {
            int t = items[i];
            for (j = i-1; j >= 0; j--) {
                if (t > items[j]) break;
                items[j+1] = items[j];
            }
            items[j+1] = t;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] items = new int[n];
        for (int i = 0; i < n; i++) items[i] = scanner.nextInt();

        insertionSort(items);

        for (int i = 0; i < n; i++)
            System.out.println(items[i] + " ");
    }
}
