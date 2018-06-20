package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DFS_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int NODES, EDGES;
    static List<Integer>[] G;

    static int[] discovered, finished, parent, path;
    static char[] color;
    static int dfsTime;

    static void dfs() {
        color = new char[NODES+1];
        parent = new int[NODES+1];
        discovered = new int[NODES+1];
        finished = new int[NODES+1];

        dfsTime = 0;

        for (int i = 1; i <= NODES; i++) {
            if (color[i] == WHITE) dfsVisit(i);
        }
    }

    static void dfsVisit(int u) {
        dfsTime = dfsTime + 1;
        discovered[u] = dfsTime;
        color[u] = GRAY;

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == WHITE) {
                parent[v] = u;
                dfsVisit(v);
            }
        }

        color[u] = BLACK;
        dfsTime = dfsTime + 1;
        finished[u] = dfsTime;
    }

    static void printDiscovered() {
        for (int x : discovered) System.out.print(x + " ");
        System.out.println();
    }

    static void printFinished() {
        for (int x : finished) System.out.print(x + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        Scanner scanner = inputFromFile();

        NODES = scanner.nextInt();
        EDGES = scanner.nextInt();

        G = new List[NODES+1];
        for (int i = 0; i <= NODES; i++) G[i] = new ArrayList<>();

        for (int i = 0; i < EDGES; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();

            G[u].add(v);
            G[v].add(u);
        }

        dfs();

        printDiscovered();
        printFinished();
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
 9 6
 1 2
 3 4
 4 5
 6 7
 7 8
 8 9

 **/