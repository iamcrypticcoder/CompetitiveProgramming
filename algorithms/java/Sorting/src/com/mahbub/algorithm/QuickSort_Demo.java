package com.mahbub.algorithm;

import java.util.Scanner;

public class QuickSort_Demo {

    static void quickSort(int[] items, int low, int high) {
        if (low < high) {
            int p = partition(items, low, high);
            quickSort(items, low, p-1);
            quickSort(items, p, high);
        }
    }

    static int partition(int[] items, int low, int high) {
        int pivot = items[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (items[j] < pivot) {
                i = i + 1;
                swap(items, i, j);
            }
        }
        swap(items, i+1, high);
        return (i+1);
    }

    static void swap(int[] items, int i, int j) {
        int t = items[i];
        items[i] = items[j];
        items[j] = t;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] items = new int[n];
        for (int i = 0; i < n; i++) items[i] = scanner.nextInt();

        quickSort(items, 0, n-1);

        for (int i = 0; i < n; i++)
            System.out.println(items[i] + " ");
    }
}
