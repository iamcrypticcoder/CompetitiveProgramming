package com.mahbub.algorithm;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Convex_Hull_AMC_Demo {

    static final double EPS = 1e-9;

    static class Point {
        double x, y;
        Point() {}
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static double sqr(double x) { return x*x; }

    static boolean isCCW(Point p, Point q, Point r) {
        // Cross Product
        double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
        // If cross product positive then r is on the left side of line pq
        //return (cross > 0) || (fabs(cross - 0.0) < EPS);       // Greater or equal to zero
        return cross > 0;
    }

    /**
     ** DESCRIPTION:
     ** Given a list of points, returns the points that of convex hull
     **
     ** COMPLEXITY:  N*lg(N) where N being the number of vertices of the polygon
     **
     ** INPUT:
     ** A list of points in 2D coordinates
     **
     ** OUTPUT:
     ** Points of convex hull
     ** http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
     **
     ** CONDITION(S):
     **
     ** RELIABILITY: 5
     **
     ** NOTE:
     **/
    static List<Point> convexHullAMC(Point[] pnts) {
        List<Point> hull = new ArrayList<>();
        int n = pnts.length;

        Arrays.sort(pnts, (Point a, Point b) -> {
            if (Math.abs(a.x - b.x) < EPS) return (int)(a.y - b.y);
            return (int)(a.x - b.x);
        });

        for (int i = 0; i < n; i++) {
            int size = hull.size();
            while (size >= 2 && !isCCW(hull.get(size - 2), hull.get(size - 1), pnts[i])) {
                hull.remove(size - 1);
                size = hull.size();
            }
            hull.add(pnts[i]);
        }

        int l = hull.size() + 1;
        for (int i = n-1; i >= 0; i--) {
            int size = hull.size();
            while (size >= l && !isCCW(hull.get(size - 2), hull.get(size - 1), pnts[i])) {
                hull.remove(size - 1);
                size = hull.size();
            }
            hull.add(pnts[i]);
        }

        return hull;
    }

    static void showPnts(Point[] pnts) {
        for (int i = 0; i < pnts.length; i++) {
            System.out.println(pnts[i].x + ", " + pnts[i].y);
        }
    }

    public static void main(String... args) {
        Scanner scanner = inputFromFile();

        int N;
        Point[] points;

        while (scanner.hasNextInt()) {
            N = scanner.nextInt();
            points = new Point[N];
            for (int i = 0; i < N; i++) {
                points[i] = new Point();
                points[i].x = scanner.nextDouble();
                points[i].y = scanner.nextDouble();
            }
            List<Point> hull = convexHullAMC(points);
            System.out.println("Convex Hull consists of following points:");

            Point[] p = new Point[hull.size()];
            showPnts(hull.toArray(p));
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
