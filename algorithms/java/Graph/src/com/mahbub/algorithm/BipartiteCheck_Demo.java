package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class BipartiteCheck_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int NODES, EDGES;
    static List<Integer>[] G;
    static char[] color;

    static int leftCount, rightCount;

    // Using DFS
    // Stop when any color conflict happen
    static boolean isBipartite1(int u, char c) {
        color[u] = c;
        c = (c == GRAY) ? BLACK : GRAY;

        boolean ret = true;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == color[u]) return false;
            if (color[v] == WHITE) ret = ret && isBipartite1(v, c);
        }
        return ret;
    }

    // Using DFS
    // Keep coloring the nodes until connected component ends
    static boolean isBipartite2(int u, char c) {
        color[u] = c;
        c = (c == GRAY) ? BLACK : GRAY;

        boolean ret = true;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == WHITE) ret = isBipartite2(v, c) && ret;
            else if (color[v] == color[u]) ret = false;
        }
        return ret;
    }

    // Using DFS.
    // Stop when any color conflict happen.
    // Count nodes in left and right sides.
    static boolean isBipartite3(int u, char c) {
        color[u] = c;
        if (c == GRAY) leftCount++;
        else rightCount++;
        c = (c == GRAY) ? BLACK : GRAY;

        boolean ret = true;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u].get(i);
            if (color[v] == color[u]) return false;
            if (color[v] == WHITE) ret = ret && isBipartite1(v, c);
        }
        return ret;
    }


    // Using BFS.
    // Stop when any color conflict happen.
    // Count nodes in left and right sides.
    static boolean isBipartite4(int s) {
        boolean ret = true;

        Queue<Integer> Q = new LinkedList<>();
        Q.offer(s);
        color[s] = GRAY;
        leftCount++;

        while (!Q.isEmpty()) {
            int u = Q.poll();
            for (int i = 0; i < G[u].size(); i++) {
                int v = G[u].get(i);
                if (color[v] == WHITE) {
                    color[v] = (color[u] == GRAY) ? BLACK : GRAY;
                    Q.offer(v);
                    if (color[v] == GRAY) leftCount++;
                    else rightCount++;
                } else if (color[v] == color[u])
                    return false;
            }
        }

        return ret;
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

            color = new char[NODES + 1];

            System.out.println(isBipartite1(0, GRAY));
            for (char ch : color) System.out.print((int)ch + " ");
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
