package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * This is a self made simple problem. Given a grid and each of the element of the grid contains these 4 types of characters:
 * . -> blank space
 * X -> obstacle
 * S -> start point
 * E -> End point
 *
 * A robot can move into 4 directions only and staring form 'S' it wants to go to 'E'. Find minimum possible move required.
 */
public class BFS_OnGrid_Demo {

    static final char WHITE = 0;
    static final char GRAY = 1;
    static final char BLACK = 2;

    static int dx[] = {-1, 0, 1, 0, -1, 1,  1, -1};
    static int dy[] = { 0, 1, 0,-1,  1, 1, -1, -1};

    static int ROWS, COLS;
    static char[][] grid;
    static char[][] color;
    static int[][] dist;
    static Pair sPoint, ePoint;

    static class Pair {
        int x, y;
        Pair(int i, int j) {
            this.x = i;
            this.y = j;
        }
    }

    static boolean onGrid(Pair p) {
        return (p.x >= 0 && p.x < ROWS && p.y >= 0 && p.y < COLS);
    }

    static int BFS() {
        color = new char[ROWS][COLS];
        dist = new int[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
        Queue<Pair> Q = new LinkedList<>();

        dist[sPoint.x][sPoint.y] = 0;
        Q.offer(sPoint);
        color[sPoint.y][ePoint.y] = GRAY;

        while (!Q.isEmpty()) {
            Pair u = Q.poll();

            if (u ==  ePoint) break;

            int curDist = dist[u.x][u.y] + 1;

            for (int i = 0; i < 4; i++) {
                Pair v = new Pair(u.x + dx[i], u.y + dy[i]);
                if (!onGrid(v)) continue;
                if (curDist < dist[v.x][v.y]) {
                    Q.offer(v);
                    dist[v.x][v.y] = curDist;
                }
            }
        }

        return dist[ePoint.x][ePoint.y];
    }

    public static void main(String[] args) {
        Scanner scanner = inputFromFile();

        while (scanner.hasNext()) {
            ROWS = scanner.nextInt();
            COLS = scanner.nextInt();
            scanner.nextLine();

            grid = new char[ROWS][];
            for (int i = 0; i < ROWS; i++) {
                String line = scanner.nextLine();
                grid[i] = line.toCharArray();
                for (int j = 0; j < COLS; j++) {
                    if (grid[i][j] == 'S') sPoint = new Pair(i, j);
                    if (grid[i][j] == 'E') ePoint = new Pair(i, j);
                }
            }

            BFS();

            System.out.println(dist[ePoint.x][ePoint.y]);
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
 4 4
 ....
 ...E
 SX..
 ....

 OUTPUT:
 4
 **/