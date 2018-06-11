package com.mahbub.algorithm;

import java.util.Scanner;

public class BubbleSort_Demo {

    static void bubbleSort(int[] items) {
        int count = items.length;
        for (int i = count-1; i >= 0; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (items[j] > items[j+1]) {
                    int t = items[j];
                    items[j] = items[j+1];
                    items[j+1] = t;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] items = new int[n];
        for (int i = 0; i < n; i++) items[i] = scanner.nextInt();

        bubbleSort(items);

        for (int i = 0; i < n; i++)
            System.out.println(items[i] + " ");
    }
}
