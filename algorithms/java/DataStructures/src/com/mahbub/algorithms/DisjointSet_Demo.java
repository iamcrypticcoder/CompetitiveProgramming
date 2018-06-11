package com.mahbub.algorithms;

public class DisjointSet_Demo {

    static final int MAX = 10000;

    static int dset[] = new int[MAX+7];
    static int rank[] = new int[MAX+7];

    // Init without rakning
    static void initSet(int n) {
        for (int i = 0; i <= n; i++) dset[i] = i;
    }
    // Find with path compression
    static int findSet(int u) {
        return dset[u] == u ? u : (dset[u] = findSet(dset[u]));
    }
    // Union without ranking
    static void union(int u, int v) {
        dset[findSet(u)] = findSet(v);
    }

    static void initWithRank(int n) {
        for (int i = 0; i <= n; i++) {
            dset[i] = i;
            rank[i] = 0;
        }
    }

    static void unionByRank(int x, int y) {
        int xRoot = findSet(x);
        int yRoot = findSet(y);

        if (xRoot == yRoot) return;

        // Attach smaller rank tree under root of high rank tree
        if (rank[xRoot] > rank[yRoot]) {
            dset[yRoot] = xRoot;
        } else if (rank[xRoot] < rank[yRoot]) {
            dset[xRoot] = yRoot;
        } else {
            dset[xRoot] = yRoot;
            rank[yRoot]++;
        }
    }

    static void printSet(int n) {
        for (int i = 0; i <= n; i++)
            System.out.println(i + " " + dset[i]);
    }

    public static void main(String[] args) {
        /*
        initSet(100);

        union(1, 2);
        union(2, 3);
        //findSet(1);
        printSet(3);
        */

        initWithRank(100);
        unionByRank(1, 2);
        unionByRank(3, 4);
        unionByRank(2, 4);

        unionByRank(10, 11);
        unionByRank(11, 12);
        unionByRank(12, 13);

        unionByRank(4, 13);
        printSet(13);
    }
}
