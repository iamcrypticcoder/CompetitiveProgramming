#include <iostream>

using namespace std;

/* Integer Version of Point */
struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) {x = _x; y= _y;}
};
/* Double Version of Point */
struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) {x = _x; y= _y;}
};
struct Line {
    double a, b, c;         // ax + by = c
    Line() {}
    Line(double _a, double _b, double _c) {
        a = _a; b = _b; c = _c;
    }
};
/* Double Version of Cricle */
struct Circle {
    Point c;            // Center of circle
    double r;           // Radius of circle
    Circle() {}
    Circle(Point _c, double _r) {c = _c; r = _r;}
};
/* Integer/Double Version of Rectangle */
struct Rectangle {
    Point ll;           // Lower-left point
    Point ur;           // Upper-right point
    Rectangle() {}
    Rectangle(Point _ll, Point _ur) { ll = _ll; ur = _ur; }
};
struct LineSegment {
    Point p;        // Start point
    Point q;        // End Point
    LineSegment() {}
    LineSegment(Point _p, Point _q) { p = _p; q = _q; }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
