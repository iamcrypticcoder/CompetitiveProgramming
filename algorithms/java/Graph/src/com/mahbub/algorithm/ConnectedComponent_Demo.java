package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class ConnectedComponent_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int NODES, EDGES;
    static List<Integer>[] G;
    static List<Edge> edgeList;

    static char[] color;

    static int ccCount;
    static List<List<Integer>> ccList;

    static class Edge {
        int u, v;
        public Edge(int u, int v) { this.u = u; this.v = v; }
    }

    // Disjoint Set Data Structure
    static int dset[];
    static int rank[];

    static void initWithRank(int n) {
        dset = new int[n+1];
        rank = new int[n+1];
        for (int i = 0; i <= n; i++) {
            dset[i] = i;
            rank[i] = 0;
        }
    }
    // Find with path compression
    static int findSet(int u) {
        return dset[u] == u ? u : (dset[u] = findSet(dset[u]));
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
    // Disjoint Set Data Structure

    static void findCCUsingDFS() {
        ccCount = 0;
        ccList = new ArrayList<>();
        color = new char[NODES+1];
        for (int i = 1; i <= NODES; i++) {
            if (color[i] == WHITE) {
                List<Integer> list = new ArrayList<>();
                ccCount++;
                dfs(i, list);
                ccList.add(list);
            }
        }
    }

    static void dfs(int u, List<Integer> list) {
        list.add(u);
        color[u] = GRAY;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == WHITE) dfs(v, list);
        }
        color[u] = BLACK;
    }

    static void findCCUsingBFS() {
        ccCount = 0;
        ccList = new ArrayList<>();
        color = new char[NODES+1];
        for (int i = 1; i <= NODES; i++) {
            if (color[i] == WHITE) {
                List<Integer> list = new ArrayList<>();
                ccCount++;
                bfs(i, list);
                ccList.add(list);
            }
        }
    }

    static void bfs(int u, List<Integer> list) {
        Queue<Integer> Q = new LinkedList<>();

        color[u] = GRAY;
        Q.offer(u);
        list.add(u);

        while (!Q.isEmpty()) {
            u = Q.poll();
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u].get(i);
                if (color[v] == WHITE) {
                    color[v] = GRAY;
                    Q.offer(v);
                    list.add(v);
                }
            }
            color[u] = BLACK;
        }
    }

    static void findCCUsingDisjointSet() {
        initWithRank(NODES+1);
        for (int i = 0; i < edgeList.size(); i++) {
            Edge edge = edgeList.get(i);
            unionByRank(edge.u, edge.v);
        }

        ccCount = 0;
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 1; i <= NODES; i++) {
            if (dset[i] == i) {
                ccCount++;
                map.put(i, new ArrayList<>());
            }
        }

        ccList = new ArrayList<>(ccCount);
        for (int i = 1; i <= NODES; i++) {
            map.get(findSet(i)).add(i);
        }

        for (Map.Entry<Integer, List<Integer>> e : map.entrySet()) {
            ccList.add(e.getValue());
        }
    }

    public static void main(String args[]) {
        Scanner scanner = inputFromFile();

        NODES = scanner.nextInt();
        EDGES = scanner.nextInt();

        G = new List[NODES+1];
        edgeList = new ArrayList<>();
        for (int i = 0; i <= NODES; i++) G[i] = new ArrayList<>();

        for (int i = 0; i < EDGES; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();

            G[u].add(v);
            G[v].add(u);

            edgeList.add(new Edge(u, v));
        }

        findCCUsingDFS();

        System.out.println("Using DFS:");
        System.out.println("Number of connected components: " + ccCount);
        for (int i = 0; i < ccList.size(); i++) {
            ccList.get(i).forEach(val -> System.out.print(val + " "));
            System.out.println();
        }
        System.out.println();

        findCCUsingBFS();

        System.out.println("Using BFS:");
        System.out.println("Number of connected components: " + ccCount);
        for (int i = 0; i < ccList.size(); i++) {
            ccList.get(i).forEach(val -> System.out.print(val + " "));
            System.out.println();
        }
        System.out.println();

        findCCUsingDisjointSet();

        System.out.println("Using Disjoint Set:");
        System.out.println("Number of connected components: " + ccCount);
        for (int i = 0; i < ccList.size(); i++) {
            ccList.get(i).forEach(val -> System.out.print(val + " "));
            System.out.println();
        }
        System.out.println();

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


