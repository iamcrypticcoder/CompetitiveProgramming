package com.mahbub.algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Closest_Pair_DnC {


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

        if (n == 2) checkPair(p[1], p[2]);
        if (n <= 2) return;

        int mid = n / 2;
        divideAndConquer(p, mid);
        divideAndConquer(Arrays.copyOfRange(p, mid, p.length), n - mid);


    }
}
