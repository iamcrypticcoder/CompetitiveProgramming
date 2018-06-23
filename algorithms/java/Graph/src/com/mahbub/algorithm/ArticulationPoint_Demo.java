package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ArticulationPoint_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int NODES, EDGES;
    static List<Integer>[] G;
    static char[] color;
    static int[] parent;
    static int[] dfsNum, dfsLow;
    static boolean[] artNodes;
    static List<Edge> artBridges;

    static int dfsRoot, rootChildren, dfsNumberCount;

    static class Edge {
        int u, v;
        public Edge(int u, int v) {
            this.u = u;
            this.v = v;
        }
    }

    static void articulationPointAndBridge(int u) {
        dfsNum[u] = dfsLow[u] = dfsNumberCount++;
        color[u] = GRAY;

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == WHITE) {
                parent[v] = u;
                if (u == dfsRoot) rootChildren++;

                articulationPointAndBridge(v);

                if (dfsLow[v] >= dfsNum[u])
                    artNodes[u] = true;
                if (dfsLow[v] > dfsNum[u])
                    artBridges.add(new Edge(u, v));
                dfsLow[u] = Math.min(dfsLow[u], dfsLow[v]);
            }
            else if (v != parent[u]) {
                dfsLow[u] = Math.min(dfsLow[u], dfsNum[v]);
            }
        }
        color[u] = BLACK;
    }

    static void findArtPointAndBridges() {
        color = new char[NODES + 1];
        parent = new int[NODES + 1];
        dfsNum = new int[NODES + 1];
        dfsLow = new int[NODES + 1];

        artNodes = new boolean[NODES + 1];
        artBridges = new ArrayList<>();

        dfsNumberCount = 0;
        for (int i = 0; i < NODES; i++) {
            if (color[i] == WHITE) {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
                artNodes[dfsRoot] = (rootChildren > 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = inputFromFile();

        while (scanner.hasNext()) {
            NODES = scanner.nextInt();
            EDGES = scanner.nextInt();

            G = new List[NODES + 1];
            for (int i = 0; i < NODES; i++) G[i] = new ArrayList<>();

            for (int i = 0; i < EDGES; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();

                G[u].add(v);
                G[v].add(u);
            }

            findArtPointAndBridges();

            for (int i = 0; i < NODES; i++) {
                System.out.println(dfsNum[i] + " " + dfsLow[i]);
            }

            System.out.println("Articulation Points:");
            for (int i = 0; i < NODES; i++) {
                if (artNodes[i]) System.out.print(i + " ");
            }
            System.out.println();

            System.out.println("Articulation Bridge:");
            for (int i = 0; i < artBridges.size(); i++) {
                System.out.println(artBridges.get(i).u + " " + artBridges.get(i).v);
            }
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
