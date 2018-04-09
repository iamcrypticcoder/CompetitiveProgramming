package com.mahbub.algorithm;

import javax.sound.sampled.Line;

public class Are_Intersect_Demo {

    static double EPS = 1e-9;

    static class Point {
        double x, y;
        Point() {}
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static class LineSegment {
        Point p, q;
        LineSegment() {}
        LineSegment(Point p, Point q) {
            this.p = p;
            this.q = q;
        }
    }

    static double sqr(double x) {
        return x*x;
    }

    static int orientation(Point p, Point q, Point r) {
        double cross = (q.y - p.y) * (r.x - q.x) -
                (q.x - p.x) * (r.y - q.y);

        if (Math.abs(cross) < EPS) return 0;

        return cross > 0 ? 1 : 2;
    }

    static boolean onSegment(Point p, Point q, Point r) {
        if (q.x <= Math.max(p.x, r.x) && q.x >= Math.min(p.x, r.x) &&
                q.y <= Math.max(p.y, r.y) && q.y >= Math.min(p.y, r.y))
            return true;

        return false;
    }

    static boolean areIntersect(Point p1, Point q1, Point p2, Point q2) {
        // Four possible orientations
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        if (o1 != o2 && o3 != o4) return true;

        // p1, q1 and p2 are colinear and p2 lies on segment p1q1
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;
        // p1, q1 and p2 are colinear and q2 lies on segment p1q1
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;
        // p2, q2 and p1 are colinear and p1 lies on segment p2q2
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;
        // p2, q2 and q1 are colinear and q1 lies on segment p2q2
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;

        return false;
    }

    public static void main(String... args) {

        Point p1 = new Point(1, 1), q1 = new Point(10, 1);
        Point p2 = new Point(1, 2), q2 = new Point(10, 2);

        boolean b = areIntersect(p1, q1, p2, q2);
        System.out.println(b ? "No" : "Yes");

        p1 = new Point(10, 0);
        q1 = new Point(0, 10);
        p2 = new Point(0, 0);
        q2 = new Point(10, 10);

        b = areIntersect(p1, q1, p2, q2);
        System.out.println(b ? "No" : "Yes");


        p1 = new Point(-5, -5);
        q1 = new Point(0, 0);
        p2 = new Point(1, 1);
        q2 = new Point(10, 10);

        b = areIntersect(p1, q1, p2, q2);
        System.out.println(b ? "No" : "Yes");
    }
}
