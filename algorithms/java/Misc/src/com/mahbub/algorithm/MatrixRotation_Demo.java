package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MatrixRotation_Demo {

    static int[][] generateSquareMat(int n) {
        int[][] mat = new int[n][n];
        int val = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = val++;
            }
        }
        return mat;
    }

    /**
     * Complexity: O(2 * n^2)
     * This is first technique of rotating a matrix.
     * 1. First make transpose of the matrix
     * 2. Reverse columns to rotate clockwise
     * 3. Reverse rows to rotate anti-clockwise
     * @param mat
     * @param isClockwise
     */
    static void rotateMatMethod1(int[][] mat, boolean isClockwise) {
        int n = mat.length;
        // Make transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int t = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = t;
            }
        }

        if (isClockwise) {
            // Rotate right
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n / 2; j++) {
                    int t = mat[i][j];
                    mat[i][j] = mat[i][n - 1 - j];
                    mat[i][n - 1 - j] = t;
                }
            }
        } else {
            // Rotate left
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n; j++) {
                    int t = mat[i][j];
                    mat[i][j] = mat[n - 1 - i][j];
                    mat[n - 1 - i][j] = t;
                }
            }
        }
    }

    /**
     * Complexity: O(n^2)
     * Swap elements of each layers. See method 3 for same implementation in easy way.
     * @param mat
     * @param isClockwise
     */
    static void rotateMatMethod2(int[][] mat, boolean isClockwise) {
        int n = mat.length;
        for (int layer = 0; layer < n/2; layer++) {
            int first = layer;
            int last = n - 1 - layer;
            for (int i = first; i < last; i++) {
                int offset = i - first;
                if (isClockwise) {
                    int t = mat[first][i];
                    mat[first][i] = mat[last - offset][first];
                    mat[last - offset][first] = mat[last][last - offset];
                    mat[last][last - offset] = mat[i][last];
                    mat[i][last] = t;
                } else {
                    int t = mat[first][i];
                    mat[first][i] = mat[i][last];
                    mat[i][last] = mat[last][last - offset];
                    mat[last][last - offset] = mat[last - offset][first];
                    mat[last - offset][first] = t;
                }
            }
        }
    }

    /**
     * Complexity: O(N^2)
     * Space: (size of one element)
     * Swap elements of each layers. This is easiest implement by swapping elements
     * Explanation:
     * Suppose N = 5
     * Total layers will be 5/2 = 2. Consider layer = 0, 1
     * For layer 0, following elements should be swapped:
     * (0, 0) -> (0, N-1) -> (N-1, N-1) -> (N-1, 0)
     * (0, 1) -> (1, N-1) -> (N-1, 3)   -> (3, 0)
     * (0, 2) -> (2, N-1) -> (N-1, 2)   -> (2, 0)
     * (0, 3) -> (3, N-1) -> (N-1, 1)   -> (1, 0)
     *
     * For layer 1, following elements should be swapped:
     * (1, 1) -> (1, N-1-1) -> (N-1-1, N-1-1) -> (N-1-1, 1)
     * ....
     *
     * In general: For each layer "layer" and each "i" where i = layer to N-1-layer
     * (layer, i) -> (i, N-1-layer) -> (N-1-layer, N-1-i) -> (N-1-i, layer)
     *
     * @param mat
     * @param isClockwise
     */
    static void rotateMatMethod3(int[][] mat, boolean isClockwise) {
        int n = mat.length;
        for (int layer = 0; layer < n/2; layer++) {
            for (int i = layer; i < n-1-layer; i++) {
                if (isClockwise) {
                    int t = mat[layer][i];
                    mat[layer][i] = mat[n - 1 - i][layer];
                    mat[n - 1 - i][layer] = mat[n - 1 - layer][n - 1 - i];
                    mat[n - 1 - layer][n - 1 - i] = mat[i][n - 1 - layer];
                    mat[i][n - 1 - layer] = t;
                } else {
                    int t = mat[layer][i];
                    mat[layer][i] = mat[i][n - 1 - layer];
                    mat[i][n - 1 - layer] = mat[n - 1 - layer][n - 1 - i];
                    mat[n - 1 - layer][n - 1 - i] = mat[n - 1 - i][layer];
                    mat[n - 1 - i][layer] = t;
                }
            }
        }
    }

    static void printMat(int[][] mat) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%4d", mat[i][j]);
            }
            System.out.println("");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int n = 5;

        System.out.println("Using method 1:");
        int[][] mat = generateSquareMat(n);
        rotateMatMethod1(mat, true);
        printMat(mat);

        System.out.println("Using method 2:");
        mat = generateSquareMat(n);
        rotateMatMethod2(mat, true);
        printMat(mat);

        System.out.println("Using method 1:");
        mat = generateSquareMat(n);
        rotateMatMethod1(mat, false);
        printMat(mat);

        System.out.println("Using method 2:");
        mat = generateSquareMat(n);
        rotateMatMethod2(mat, false);
        printMat(mat);

        System.out.println("Using method 3:");
        mat = generateSquareMat(n);
        rotateMatMethod3(mat, true);
        printMat(mat);

        System.out.println("Using method 3:");
        mat = generateSquareMat(n);
        rotateMatMethod3(mat, false);
        printMat(mat);
    }

    static Scanner inputFromFile() {
        try { return new Scanner(new FileInputStream("input.txt")); }
        catch (FileNotFoundException e) { e.printStackTrace(); }
        return null;
    }

    static Scanner inputFromSystem() {
        return new Scanner(System.in);
    }
}
