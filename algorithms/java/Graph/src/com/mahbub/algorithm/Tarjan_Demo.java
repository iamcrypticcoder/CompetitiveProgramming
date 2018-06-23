package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Tarjan_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int NODES, EDGES;
    static List<Integer>[] G;
    static char[] color;

    static int[] dfsNum, dfsLow;
    static int dfsNumberCounter;
    static Stack<Integer> S;
    static boolean[] inStack;

    static void tarjanSSC() {
        color = new char[NODES + 1];
        dfsNum = new int[NODES + 1];
        dfsLow = new int[NODES + 1];
        S = new Stack<>();
        inStack = new boolean[NODES + 1];

        for (int i = 0; i < NODES; i++) {
            if (color[i] == WHITE) strongConnect(i);
        }
    }

    static void strongConnect(int u) {
        dfsNum[u] = dfsLow[u] = dfsNumberCounter++;
        color[u] = GRAY;
        S.push(u);
        inStack[u] = true;

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == WHITE) {
                strongConnect(v);
                dfsLow[u] = Math.min(dfsLow[u], dfsLow[v]);
            } else if(inStack[v] == true) {
                dfsLow[u] = Math.min(dfsLow[u], dfsNum[v]);
            }
        }

        if (dfsNum[u] == dfsLow[u]) {
            int v = -1;
            while (v != u) {
                v = S.pop();
                inStack[v] = false;
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = inputFromFile();

        while (scanner.hasNext()) {
            NODES = scanner.nextInt();
            EDGES = scanner.nextInt();

            G = new List[NODES + 1];
            for (int i = 0; i <= NODES; i++) G[i] = new ArrayList<>();

            for (int i = 0; i < EDGES; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();

                G[u].add(v);
            }

            tarjanSSC();
            System.out.println();
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

/**

 INPUT:
 8 9
 0 1
 1 3
 3 2
 2 1
 3 4
 4 5
 5 7
 7 6
 6 4

 OUTPUT:
 6 7 5 4
 2 3 1
 0

 */
