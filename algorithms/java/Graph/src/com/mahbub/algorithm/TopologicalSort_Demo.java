package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class TopologicalSort_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int NODES, EDGES;
    static List<Integer>[] G;
    static char[] color;
    static List<Integer> topoOrder;

    static void topoSort() {
        color = new char[NODES+1];
        topoOrder = new ArrayList<>();
        for (int i = 1; i <= NODES; i++) {
            if (color[i] == WHITE) dfs(i);
        }
        Collections.reverse(topoOrder);
    }

    static void dfs(int u) {
        color[u] = GRAY;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == WHITE) dfs(v);
        }
        topoOrder.add(u);
        color[u] = BLACK;
    }

    public static void main(String[] args) {
        Scanner scanner = inputFromFile();

        while (scanner.hasNext()) {
            NODES = scanner.nextInt();
            EDGES = scanner.nextInt();

            G = new List[NODES + 1];
            for (int i = 1; i <= NODES; i++) G[i] = new ArrayList<>();

            for (int i = 0; i < EDGES; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();

                G[u].add(v);
            }

            topoSort();

            for (int x : topoOrder) System.out.print(x + " ");
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

 Input:
 4 5
 1 2
 1 3
 3 2
 2 4
 3 4

 9 9
 1 2
 2 3
 1 4
 4 3
 5 4
 6 5
 5 7
 6 7
 8 7

 Output:
 1 3 2 4
 9 8 6 5 7 1 4 2 3

 **/