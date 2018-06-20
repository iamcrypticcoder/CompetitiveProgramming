package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class BFS_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int NODES, EDGES;
    static List<Integer>[] G;
    static int source;

    static int[] dist;          // Distance from source node
    static int[] color;         // State of a node
    static int[] parent;        // Parent of a node
    static List<Integer> path = new ArrayList<>();  // Desired Path

    static void bfs() {
        int u, v;
        Queue<Integer> Q = new LinkedList<>();

        dist = new int[NODES+1];
        color = new int[NODES+1];
        parent = new int[NODES+1];

        Q.offer(source);
        dist[source] = 0;
        parent[source] = -1;
        color[source] = GRAY;

        while (!Q.isEmpty()) {
            u = Q.poll();
            for (int i = 0; i < G[u].size(); i++) {
                v = G[u].get(i);
                if (color[v] == WHITE) {
                    color[v] = GRAY;
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    Q.offer(v);
                }
            }
            color[u] = BLACK;
        }
    }

    static void makePath(int sink) {
        if (parent[sink] == -1) {
            path.add(sink);
            return;
        }
        makePath(parent[sink]);
        path.add(sink);
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

        source = 1;
        bfs();

        path.clear();
        makePath(5);
        path.forEach(val -> System.out.print(val + " "));

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
 5 5
 1 2
 2 3
 3 4
 4 5
 1 3

 OUTPUT:
 1 3 4 5
 **/
