package com.mahbub.algorithm;

import java.util.Arrays;
import java.util.Collections;

public class BinarySearch_Demo {

    static int binarySearch(int[] items, int x) {
        int l = 0, r = items.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (x > items[mid]) l = mid + 1;
            else if (x < items[mid]) r = mid - 1;
            else return mid;
        }
        return -1;
    }

    // AC Problem(s): UVA 957
    // Return  position of x to be inserted in most left side of the array
    static int lowerBound(int items[], int x) {
        int l = 0, r = items.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x > items[mid]) l = mid + 1;
            else r = mid;

        }
        if (x > items[l]) return l + 1;
        return l;
    }

    // AC Problem(s): UVA 957
    // Return position of x to be inserted in most right side of the array
    static int upperBound(int items[], int x) {
        int l = 0, r = items.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x < items[mid]) r = mid;
            else l = mid + 1;
        }
        if (x == items[l]) return l + 1;
        return l;
    }

    public static void main(String args[]) {
        int[] items = new int[] {2, 4, 6, 8, 10, 12, 14, 16, 16, 16, 18, 20};
        int[] itemsSame = new int[] {6, 6, 6, 6, 6, 6, 6};

        System.out.println(binarySearch(items, 20));

        System.out.println(lowerBound(items, 14));
        System.out.println(upperBound(items, 14));

    }
}
