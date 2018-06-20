package com.mahbub.algorithm;

import java.util.Arrays;

public class SortedMatrixSearch_Demo {

    static int[][] inputMat = new int[][] {
            {0,   6,   8,   9,  11},
            {20, 22,  28,  29,  31},
            {36, 38,  50,  61,  63},
            {64, 66, 100, 122, 128}
    };

    static int binarySearch(int[] items, int x) {
        int l = 0, r = items.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (items[mid] < x) l = mid + 1;
            else if (items[mid] > x) r = mid - 1;
            else return mid;
        }
        return -1;
    }

    // Complexity: O(M * lgN)
    // Do binary search in every row
    static int[] searchElementNaive(int[][] mat, int x) {
        for (int r = 0; r < mat.length; r++) {
            int result = binarySearch(mat[r], x);
            if (result != -1) return new int[] {r, result};
        }
        return null;
    }

    // Complexity: O(M + N)
    // Return position of element in form of 2 element matrix, otherwise null
    static int[] searchElement(int[][] mat, int x) {
        int r = 0, c = 0;
        while (r < mat.length && c < mat[0].length) {
            if (mat[r][c] == x) return new int[] {r, c};

            if (r+1 < mat.length && c+1 < mat[0].length && mat[r+1][c+1] <= x) {
                r++; c++;
                continue;
            }

            if (r+1 < mat.length && mat[r+1][c] <= x) {
                r++;
                continue;
            }

            if (c+1 < mat[0].length && mat[r][c+1] <= x) {
                c++;
                continue;
            }
            return null;
        }
        return null;
    }

    public static void main(String args[]) {
        System.out.println(Arrays.toString(searchElementNaive(inputMat, 61)));
        System.out.println(Arrays.toString(searchElementNaive(inputMat, 11)));
        System.out.println(Arrays.toString(searchElement(inputMat, 61)));
        System.out.println(Arrays.toString(searchElement(inputMat, 11)));
    }
}
