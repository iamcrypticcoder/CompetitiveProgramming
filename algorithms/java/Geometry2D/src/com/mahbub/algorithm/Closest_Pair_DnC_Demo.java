package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Closest_Pair_DnC_Demo {

    static int N;
    static Point[] pnts;
    static Point minA, minB;
    static double minDist;

    static class Point {
        double x, y;
        Point() {}
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static double sqr(double x) { return x*x; }

    static void checkPair(Point a, Point b) {
        double d = sqr(b.x - a.x) + sqr(b.y - a.y);
        if (d < minDist) {
            minDist = d;
            minA = a; minB = b;
        }
    }

    static void divideAndConquer(Point p[], int n) {
        int i, j, cnt;
        List<Point> strip = new ArrayList<>();

        if (n == 2) checkPair(p[0], p[1]);
        if (n <= 2) return;

        int mid = n / 2;
        divideAndConquer(Arrays.copyOfRange(p, 0, mid+1), mid + 1);
        divideAndConquer(Arrays.copyOfRange(p, mid+1, p.length), p.length - 1 - mid);

        // Build an vector strip that contains points close (closer than min)
        // to the line passing through the middle point
        for(i = 1; i < n; i++)
            if(sqr(p[i].x - p[mid].x) < minDist) strip.add(p[i]);

        // Sorting by y-coordinate
        strip.sort((Point o1, Point o2) -> (int)(o1.y - o2.y));

        // Find the closest points in strip.
        for(i = 0; i < strip.size(); i++) {
            if(sqr(strip.get(i).x - p[mid].x) >= minDist) break;
            for(j = i+1; j < strip.size(); j++) {
                if(sqr(strip.get(i).y - strip.get(j).y) >= minDist) break;
                checkPair(strip.get(i), strip.get(j));
            }
        }
    }

    static double closestPair(Point[] p, int n) {
        minDist = Double.MAX_VALUE;
        Arrays.sort(p, (Point a, Point b) -> (int)(a.x - b.x));
        divideAndConquer(p, n);
        return minDist;
    }

    static void showPnts() {
        for (int i = 0; i < N; i++) {
            System.out.println(pnts[i].x + ", " + pnts[i].y);
        }
    }

    public static void main(String... args) {
        Scanner scanner = inputFromFile();

        while (scanner.hasNextInt()) {
            N = scanner.nextInt();
            pnts = new Point[N];
            for (int i = 0; i < N; i++) {
                pnts[i] = new Point();
                pnts[i].x = scanner.nextDouble();
                pnts[i].y = scanner.nextDouble();
            }

            closestPair(pnts, N);

            System.out.printf("Closest Points are (%.4f, %.4f) and (%.4f, %.4f)\n", minA.x, minA.y, minB.x, minB.y);
            System.out.printf("Closest Distance is: %.4f\n", Math.sqrt(minDist));
        }
    }

    static Scanner inputFromFile() {
        Scanner scanner = null;
        try {
            scanner = new Scanner(new FileInputStream("input.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return scanner;
    }
}