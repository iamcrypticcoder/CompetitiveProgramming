package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class FloydWarshall_Demo {

    static int NODES, EDGES;
    static int[][] G;
    static int[][] p;

    static void floydWarshall() {
        for (int k = 0; k < NODES; k++) {
            for (int i = 0; i < NODES; i++) {
                for (int j = 0; j < NODES; j++) {
                    G[i][j] = G[i][k] + G[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    static void printPath(int i, int j) {
        if (i != j) printPath(i, p[i][j]);
        System.out.print(j + " ");
    }

    static void printMat() {
        for (int i = 0; i < NODES; i++) {
            for (int j = 0; j < NODES; j++) {
                System.out.print(G[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner scanner = inputFromFile();

        while (scanner.hasNext()) {
            NODES = scanner.nextInt();
            EDGES = scanner.nextInt();

            G = new int[NODES+1][NODES+1];
            p = new int[NODES+1][NODES+1];
            for (int i = 0; i <= NODES; i++) {
                Arrays.fill(G[i], Integer.MAX_VALUE);
            }
            for (int i = 0; i < EDGES; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();
                int c = scanner.nextInt();

                G[u][v] = G[v][u] = c;
            }

            floydWarshall();

            printMat();
        }
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
