package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Dijkstra_Demo {

    static int NODES, EDGES;
    static List<Node>[] G;
    static int source;

    static int[] dist, parent;
    static PriorityQueue<Node> pq;

    static class Node implements Comparable<Node> {
        int label, dist;

        public Node(int label, int dist) {
            this.label = label;
            this.dist = dist;
        }

        @Override
        public int compareTo(Node o) {
            return (this.dist - o.dist);
        }
    }

    static void dijkstra() {
        dist = new int[NODES+1];
        parent = new int[NODES+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);

        Node u, v;

        pq = new PriorityQueue<>();
        dist[source] = 0;
        u = new Node(source, 0);
        pq.offer(u);

        while (!pq.isEmpty()) {
            u = pq.poll();

            for (int i = 0; i < G[u.label].size(); i++) {
                Node p = G[u.label].get(i);
                v = new Node(p.label, 0);

                if (dist[u.label] + p.dist < dist[p.label]) {
                    dist[p.label] = v.dist = dist[u.label] + p.dist;
                    parent[v.label] = u.label;
                    pq.offer(v);
                }
            }
        }
    }

    static void printDist() {
        System.out.println("Dist: ");
        for (int i = 1; i < dist.length; i++) System.out.print(dist[i] + " ");
        System.out.println();
    }

    static void printParent() {
        System.out.println("Parent: ");
        for (int i = 1; i < parent.length; i++) System.out.print(parent[i] + " ");
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
            int c = scanner.nextInt();

            G[u].add(new Node(v, c));
            G[v].add(new Node(u, c));
        }

        source = scanner.nextInt();

        dijkstra();

        printDist();
        printParent();
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
 6 8
 1 2 1
 1 3 5
 1 4 2
 1 5 5
 2 3 1
 3 6 2
 4 5 2
 5 6 1
 1

 OUTPUT:
 Dist:
 0 1 2 2 4 4
 Parent:
 -1 1 2 1 4 3 
 **/