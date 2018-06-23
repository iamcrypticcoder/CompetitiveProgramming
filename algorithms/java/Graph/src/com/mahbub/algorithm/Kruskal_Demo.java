package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Kruskal_Demo {

    static int NODES, EDGES;
    static List<Edge> edges;
    static List<Edge> spanEdges;
    static int mstCost;

    // -------------------- Disjoint Set Structure --------------------------------------
    static int[] dset;
    static void initSet(int N) {
        dset = new int[N+1];
        for (int i = 0; i <= N; i++) dset[i] = i;
    }
    static int findSet(int u) {
        return dset[u] == u ? u : (dset[u] = findSet(dset[u]));
    }
    static void union(int u, int v) {
        dset[findSet(u)] = findSet(v);
    }
    // ----------------------------------------------------------------------------------

    static class Edge implements Comparable<Edge> {
        int u, v, c;
        Edge(int u, int v, int c) {
            this.u = u;
            this.v = v;
            this.c = c;
        }

        @Override
        public int compareTo(Edge o) {
            return this.c - o.c;
        }
    }

    static int kruskal() {
        int countSpanEdges = 0;
        mstCost = 0;

        Collections.sort(edges);
        initSet(NODES);
        spanEdges = new ArrayList<>();

        for (int i = 0; i < edges.size(); i++) {
            if (countSpanEdges == NODES - 1) break;
            Edge e = edges.get(i);
            if (findSet(e.u) != findSet(e.v)) {
                spanEdges.add(edges.get(i));
                union(edges.get(i).u, e.v);
                mstCost += e.c;
                countSpanEdges++;
            }
        }
        return mstCost;
    }
    
    public static void main(String[] args) {
        Scanner scanner = inputFromFile();

        while (scanner.hasNext()) {
            NODES = scanner.nextInt();
            EDGES = scanner.nextInt();

            edges = new ArrayList<>();

            for (int i = 0; i < EDGES; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();
                int c = scanner.nextInt();

                edges.add(new Edge(u, v, c));
            }

            System.out.println("MST Cost: " + kruskal());
            for (int i = 0; i < spanEdges.size(); i++) {
                Edge e = spanEdges.get(i);
                System.out.println(e.u + " " + e.v + " " + e.c);
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

/**
 INPUT:
 5 7
 0 1 4
 0 2 4
 0 3 6
 0 4 6
 1 2 2
 2 3 8
 3 4 9

 OUTPUT:
 MST Cost: 18
 1 2 2
 0 1 4
 0 3 6
 0 4 6
 **/