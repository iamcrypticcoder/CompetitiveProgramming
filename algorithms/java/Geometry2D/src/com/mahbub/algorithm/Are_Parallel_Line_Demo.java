package com.mahbub.algorithm;

public class Are_Parallel_Line_Demo {

    static double EPS = 1e-9;

    static class Point {
        double x, y;
        Point() {}
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    class Line {
        double a, b, c;
        Line() {}
        Line(double a, double b, double c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static boolean areParallelLine(Line l1, Line l2) {
        return (Math.abs(l1.a - l2.a) <= EPS && Math.abs(l1.b - l2.b) <= EPS);
    }

    public static void main(String... args) {
        //System.out.println();
    }
}
