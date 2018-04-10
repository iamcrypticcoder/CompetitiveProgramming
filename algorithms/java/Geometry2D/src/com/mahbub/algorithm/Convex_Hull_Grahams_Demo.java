package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Convex_Hull_Grahams_Demo {

    static final double EPS = 1e-9;

    static Point pivot;

    static class Point {
        double x, y;
        Point() {}
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static double sqr(double x) { return x*x; }

    static double dist2D(Point a, Point b) {
        return Math.sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    }

    static boolean isCCW(Point p, Point q, Point r)
    {
        // Cross Product
        double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
        // If cross product positive then r is on the left side of line pq
        return (cross > 0) || (Math.abs(cross - 0.0) < EPS);        // Greater or equal to zero
    }

    static int computeAngle(Point a, Point b) {
        double cross = (b.x - a.x) * (pivot.y - a.y) - (b.y - a.y) * (pivot.x - a.x);
        if(Math.abs(cross) < EPS) return (int)(dist2D(pivot, a) - dist2D(pivot, b));
        double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
        double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
        return (int)(Math.atan2(d1y, d1x) - Math.atan2(d2y, d2x));
    }

    static List<Point> grahamsScan(Point[] pnts) {
        List<Point> ret = new ArrayList<>();

        int n = (int) pnts.length;

        // Selecting the pivot point, most lowest and rightmost if tie
        int pIndex = 0;                 // Pivot Index
        for(int i = 1; i < n; i++)
            if(pnts[i].y < pnts[pIndex].y ||
                    (pnts[i].y == pnts[pIndex].y && pnts[i].x > pnts[pIndex].x)) pIndex = i;

        // Placing pivot point at the first of the array
        pivot = pnts[0];
        // Sorting w.r.t angle with pivot point
        Arrays.sort(pnts, (Point a, Point b) -> computeAngle(a, b));

        Point top1, top2;
        Stack<Point> S = new Stack<>();
        S.push(pnts[n-1]);
        S.push(pnts[0]);

        int i = 1;
        while (i < n) {
            top2 = S.pop();
            top1 = S.peek();
            S.push(top2);
            if (isCCW(top1, top2, pnts[i])) S.push(pnts[i++]);
            else S.pop();
        }

        while (!S.empty()) {
            ret.add(S.peek());
            S.pop();
        }

        return ret;
    }

    static void showPnts(Point[] pnts) {
        for (int i = 0; i < pnts.length; i++) {
            System.out.println(pnts[i].x + ", " + pnts[i].y);
        }
    }

    public static void main(String... args) {
        Scanner scanner = inputFromFile();

        int N;
        Point p;
        Point[] points;
        List<Point> hull;

        while (scanner.hasNextInt()) {
            N = scanner.nextInt();
            points = new Point[N];

            for (int i = 0; i < N; i++) {
                points[i] = new Point();
                points[i].x = scanner.nextDouble();
                points[i].y = scanner.nextDouble();
            }

            hull = grahamsScan(points);

            System.out.println("Convex Hull consists of following points:");
            showPnts(points);
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
