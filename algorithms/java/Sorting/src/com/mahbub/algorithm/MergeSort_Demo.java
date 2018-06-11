package com.mahbub.algorithm;

import java.util.Scanner;

public class MergeSort_Demo {

    static final int MAX = 100000;

    static final int[] tmp = new int[MAX];

    static void mergeSort(int items[], int l, int r) {
        if (l >= r) return;
        if (l + 1 == r) {
            if (items[l] > items[r]) {
                int t = items[l];
                items[l] = items[r];
                items[r] = t;
            }
            return;
        }

        int m = (l + r) / 2;

        mergeSort(items, l, m);
        mergeSort(items, m+1, r);

        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) {
            if (items[i] < items[j]) tmp[k++] = items[i++];
            else tmp[k++] = items[j++];
        }

        while (i <= m) tmp[k++] = items[i++];
        while (j <= r) tmp[k++] = items[j++];
        for (i = l; i <= r; i++) items[i] = tmp[i];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] items = new int[n];
        for (int i = 0; i < n; i++) items[i] = scanner.nextInt();

        mergeSort(items, 0, n-1);

        for (int i = 0; i < n; i++)
            System.out.println(items[i] + " ");
    }

}
