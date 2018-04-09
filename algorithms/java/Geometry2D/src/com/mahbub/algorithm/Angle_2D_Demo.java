package com.mahbub.algorithm;

import java.util.Scanner;

public class Angle_2D_Demo {

    static class Point {
        double x, y;
    }

    static double sqr(double x) { return x*x; }

    static double dist2D(Point a, Point b) {
        return Math.sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    }

    static double angle2D(Point A, Point B, Point C) {
        double a = dist2D(A, B), b = dist2D(B, C), c = dist2D(C, A);
        return Math.acos(sqr(c) - sqr(a) - sqr(b) / (-2.0 * a * b));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Point a = new Point();
        Point b = new Point();
        Point c = new Point();

        while (scanner.hasNextDouble()) {
            a.x = scanner.nextDouble();
            a.y = scanner.nextDouble();
            b.x = scanner.nextDouble();
            b.y = scanner.nextDouble();
            c.x = scanner.nextDouble();
            c.y = scanner.nextDouble();

            System.out.printf("Angle ABC in radians = %f\n", angle2D(a, b, c));
        }
    }

}
