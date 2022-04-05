1. **Distance 2D:** Given 2 points (A, B) find the Euclidean distance.
2. **Angle 2D:** Given 3 points (A, B, C) find angle ABC.
3. **CCW Test:** Given 2 points (A, B) and another point C check if C is located on the left/right side of AB.
4. **Line:** Given 2 points (A, B) find the line equation.
5. **Line:** Given 2 line equation check are they parallel/same.
6. **Line:** Given 2 line segments check are they intersect.
7. **Line:** Given a line segment and a point find the closest distance.
8. **Triangle:** Given 3 points (A, B, C) find the area.
9. **Triangle:** Given 3 side lengths find the area.
10. **Triangle:** Given 3 medians find the area.
11. **Triangle:** Given 3 points check if they form a triangle.
12. **Rectangle:** Given bottom-left (BL) and upper-right (UR) points find the area.
13. **Rectangle:** Given 4 points (A, B, C, D) find the area of the rectangle.
14. **Rectangle:** Given 4 points (A, B, C, D) check if they form a rectangle.
15. **Overlapping Area:** Given two rectangles find the overlapping area.
16. **Overlapping Area:** Given two circles find the overlapping area.
17. **Overlapping Area:** Given one circle and one rectangle find the overlapping area.
18. **Point Inside Test:** Given a point and a rectangle check if the point is inside.
19. **Point Inside Test:** Given a point and a circle check if the point is inside.
20. **Point Inside Test:** Given a point and a triangle check if the point is inside.
21. **Point Inside Test:** Given a point and a polygon check if the point is inside.
22. **Polygon:** Given points of polygon find area.
23. **Polygon:** Given points of polygon find the perimeter.
24. **Polygon:** Given points of polygon check if the polygon is convex.
25. **Polygon:** Given points of polygon find a convex hull.
26. **Closest Pair:** Given N points find the closest two points.





### 1. **Distance 2D:** Given 2 points (A, B) find the Euclidean distance:

------

**Code:**

```cpp
struct Point{
    double x, y;
    Point() {}
    Point(double a, double b) : x(a), y(b) {}
};

double dist2D(pair<double, double> a, pair<double, double> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

double dist2D(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double sqrDist2D(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
```


&NewLine;


### 2. Angle 2D: Given 3 points (A, B, C) find angle ABC:

------

**Code:**

```cpp
double dist2D(pair<double, double> a, pair<double, double> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

/**
 * Given 3 points(A, B, C), it returns the magnitude of angle ABC in radians.
 * Uses the Cosine Law, c^2 = a^2 + b^2 - 2ab cos C.
 */
double angle2D(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
    double a = dist2D(B, C), b = dist2D(A, C), c = dist2D(A, B);
    double x = ((a*a) + (c*c) - (b*b)) / (2*a*c);
    return acos(x);
}
```





### 3. **CCW Test:** Given 2 points (A, B) and another point C check if C is located on the left/right side of AB:

------

Cross product of two vector provides area of parallelogram as magnitude and also a direction. Magnitude is positive/zero/negative, then we have left turn/collinear/right turn.

**Code:**

```cpp
/**
 * Cross product of two vector provides area of parallelogram as magnitude and also a direction
 * Magnitude is positive/zero/negative, then we have left turn/collinear/right turn
 * Vector (pq) = {(q.x - p.x), (q.y - p.y)}
 * Vector (qr) = {(r.x - q.x), (r.y - q.y)};
 * Vector (pq) x Vector (qr) = (q.x - p.x)*(r.y - q.y) - (q.y - p.y)*(r.x - q.x)
 */
bool isCCW(Point p, Point q, Point r) {
    int cross = (q.x - p.x)*(r.y - q.y) - (q.y - p.y)*(r.x - q.x);
    return cross > 0;
}
```





### 4. **Line:** Given 2 points (A, B) find the line equation:

```cpp
/**
 * Given 2 points(p1, p2), it returns the equation of line that goes on both p1 and p2.
 * Co-effecients (a, b, c) of equation ax + by = c
 * UVA-378
 */
Line pointsToLine(Point p1, Point p2) {
    Line ret;
    if(p1.x == p2.x) {
        ret.a = 1;
        ret.b = 0;
        ret.c = -p1.x;
    } else {
        ret.b = 1;
        ret.a = -(p1.y - p2.y)/(p1.x - p2.x);
        ret.c = -(ret.b * p1.y) - (ret.a * p1.x);
    }
    return ret;
}
```





### 5. **Line:** Given 2 line equation check are they parallel/same:

**Code:**

```cpp
bool areParallelLine(Line l1, Line l2) {
    return ( (fabs(l1.a - l2.a)) <= EPS && (fabs(l1.b - l2.b)) <= EPS);
}
```





### 6. **Line:** Given 2 line segments check are they intersect:

**Code:**

```cpp
struct Point {
    int x, y;
    Point();
    Point(int a, int b) : x(a), y(b) {}
};

// 0 --> p, q and r are colinear
// 1 --> Counterclockwise
// 2 --> Clockwise
int orientation(Point p, Point q, Point r) {
    int cross = (q.x - p.x)*(r.y - q.y) - (q.y - p.y)*(r.x - q.x);
    if (fabs(cross) < EPS) return 0;
    return (cross > 0) ? 1: 2;
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool areIntersect(Point p1, Point q1, Point p2, Point q2) {
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
```





### 7. **Line:** Given a line segment and a point find the closest distance:

------

**Code:**

```cpp
```





### 8. **Triangle:** Given 3 points (A, B, C) find the area:

**Code:**

```cpp
struct Point {
    double x, y;
    Point();
    Point(double a, double b) : x(a), y(b) {}
};

/**
** DESCRIPTION:
** Given three vertices a triangle, returns the area of the triangle.
**
** FORMULA:
** We know cross product value of two vectors provides area of parallalogram. So divide by 2 gives triangle area
** |AB x BC| / 2 = answer
** vec(AB) = (B.x - A.x, B.y - A.y)
** vec(BC) = (C.x - B.x, C.y - B.x)
**/
double triangleArea(Point a, Point b, Point c) {
    return fabs((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y)) / 2.0;
}
double triangleArea(pair<double, double> a, 
                    pair<double, double> b, 
                    pair<double, double> c) {
    return fabs((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first)) / 2.0;
}
```





### 9. **Triangle:** Given 3 side lengths find the area:

**Code:**

```cpp
/**
** DESCRIPTION:
** Given lengths of three sides of a triangle, returns the area of the triangle.
 * 
** OUTPUT:
** Area of the triangle using heron's formula, If triangle possible
** return -1, If the sides doesn't form a triangle
** area = sqrt(s * (s-a) * (s-b) * (s-c)) where s = (a + b + c) / 2.0
**/
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    if(a > s || b > s || c > s) return -1;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}
```





### 10. **Triangle:** Given 3 medians find the area:

**Code:**

```cpp
/**
** Given lengths of three medians of a triangle, returns the area of the triangle.
** Area of the triangle using heron's formula, If triangle possible
** return -1, If the medians are invalid
**/
double triangleArea(double m1, double m2, double m3) {
    double s = 0.5 * (m1 + m2 + m3);
    double area = s * (s - m1) * (s - m2) * (s - m3);
    if(area < 0.0) return -1.0;
    return sqrt( area ) * 4.0 / 3.0;
}
```



### 11. **Triangle:** Given 3 points check if they form a triangle:

**Code:**

```cpp
double isTriangle(Point a, Point b, Point c) {
    double area = fabs((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y)) / 2.0;
    return area > DBL_EPSILON; 
}
```



### 12. **Rectangle:** Given bottom-left (BL) and upper-right (UR) points find the area:

**Code:**

```cpp
double rectArea(Point bl, Point ur) {
    double length = (ur.x - bl.x);
    double height = (ur.y - bl.y);
    return length*height;
}
```



### 13. **Rectangle:** Given 4 points (A, B, C, D) find the area of the rectangle:

**Code:**

```cpp
struct Point {
    double x, y;
    Point();
    Point(double a, double b) : x(a), y(b) {}
};

double sqrDist(Point a, Point b) {
    return fabs(a.x-b.x)*fabs(a.x-b.x) + fabs(a.y-b.y)*fabs(a.y-b.y);
}

double rectArea(vector<Point> pnts) {
    set<pair<double, double>> uniquePnts;
    for (auto p : pnts) uniquePnts.insert({p.x, p.y});
    if (uniquePnts.size() != 4) return 0.0;

    set<double> uniqueDist;
    for (int i = 0; i <= 2; i++)
        for (int j = i+1; j <= 3; j++)
            uniqueDist.insert(sqrDist(pnts[i], pnts[j]));
    if ((int)uniqueDist.size() > 3) return 0.0;

    int dist[3];
    int i = 0;
    for (auto d : uniqueDist) dist[i++] = d;

    // If form a square
    if ((int)uniqueDist.size() == 2 && 2*dist[0] == dist[1])
        return sqrt(dist[0])*sqrt(dist[0]);

    // If form a rectangle
    if (dist[0] + dist[1] == dist[2]) {
        return sqrt(dist[0])* sqrt(dist[1]);
    }
    return 0.0;
}
```



### 14. **Rectangle:** Given 4 points (A, B, C, D) check if they form a rectangle:

**Code:**

```cpp
struct Point {
    double x, y;
    Point();
    Point(double a, double b) : x(a), y(b) {}
};

double sqrDist(Point a, Point b) {
    return fabs(a.x-b.x)*fabs(a.x-b.x) + fabs(a.y-b.y)*fabs(a.y-b.y);
}

bool isRect(vector<Point> pnts) {
    set<pair<double, double>> uniquePnts;
    for (auto p : pnts) uniquePnts.insert({p.x, p.y});
    if (uniquePnts.size() != 4) return false;

    set<double> uniqueDist;
    for (int i = 0; i <= 2; i++)
        for (int j = i+1; j <= 3; j++)
            uniqueDist.insert(sqrDist(pnts[i], pnts[j]));
    if ((int)uniqueDist.size() > 3) return false;

    int dist[3];
    int i = 0;
    for (auto d : uniqueDist) dist[i++] = d;

    // If form a square
    if ((int)uniqueDist.size() == 2 && 2*dist[0] == dist[1])
        return true;

    // If form a rectangle
    if (dist[0] + dist[1] == dist[2]) {
        return true;
    }
    return false;
}
```



### 15. **Overlapping Area:** Given two rectangles find the overlapping area:

**Code:**

```cpp
double intersectArea(Point bl1, Point ur1, Point bl2, Point ur2) {
    double x = max(bl1.x, bl2.x);
    double y = max(bl1.y, bl2.y);
    double xx = min(ur1.x, ur2.x);
    double yy = min(ur1.y, ur2.y);
    if(x < xx && y < yy) return (xx - x) * (yy - y);
    return 0.0;
}
```



### 16: **Overlapping Area:** Given two circles find the overlapping area:

**Code:**

```cpp
struct Point {
    double x, y;
    Point();
    Point(double a, double b) : x(a), y(b) {}
};

struct Circle {
    Point c;
    double r;
};

double intersectArea(Circle a, Circle b) {
    double d, dA, dB, tx, ty;

    d = sqrt(SQR(b.c.x - a.c.x) + SQR(b.c.y - a.c.y));

    if ((d < DBL_EPSILON) || (d + a.r <= b.r) || (d + b.r <= a.r))
        return SQR((b.r < a.r) ? b.r : a.r) * PI;
    if (d >= a.r + b.r)
        return 0;

    dA = tx = (SQR(d) + SQR(a.r) - SQR(b.r))/d/2;
    ty = sqrt(SQR(a.r) - SQR(tx));
    dB = d - dA;

    return SQR(a.r)*acos(dA/a.r) - dA*sqrt(SQR(a.r)-SQR(dA)) +
           SQR(b.r)*acos(dB/b.r) - dB*sqrt(SQR(b.r)-SQR(dB));
}
```



### 17. **Overlapping Area:** Given one circle and one rectangle find the overlapping area:

**Code:**

```cpp
```



### 18. **Point Inside Test:** Given a point and a rectangle check if the point is inside:

**Code:**

```cpp
/**
** Return 1 if the point p is inside of the rectangle.
** Return 0 if the point p is on rectangle sides
** Return -1 if the point p is outside of the rectangle
 */
int isPointInside(Point bl, Point ur, Point p) {
    if(p.x > bl.x && p.x < ur.x && p.y > bl.y && p.y < ur.y) return 1;
    else if(p.x >= bl.x && p.x <= ur.x && p.y >= bl.y && p.y <= ur.y) return 0;
    return -1;
}
```



### 19. **Point Inside Test:** Given a point and a circle check if the point is inside:

**Code:**

```cpp
/**
** Return 1 if the point(p) is inside of the circle otherwise false
** Return 0 if the point(p) is on the circle perimeter
** Return -1 if the point(p) is outside of the circle
 */
int isPointInside(Point c, double r, Point p) {
    double d = SQR(p.x - c.x) + SQR(p.y - c.y);
    if(d < SQR(r)) return 1;
    else if(d > SQR(r)) return  -1;
    return 0;
}
```



### 20. **Point Inside Test:** Given a point and a triangle check if the point is inside:

**Code:**

```cpp
double triangleArea(Point a, Point b, Point c) {
    return fabs((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y)) / 2.0;
}

bool isPointInside(Point p1, Point p2, Point p3, Point p) {
    double a1, a2, a3, total;
    a1 = triangleArea(p1, p2, p);
    a2 = triangleArea(p2, p3, p);
    a3 = triangleArea(p3, p1, p);
    total = triangleArea(p1, p2, p3);
    return (fabs(a1 + a2 + a3 - total) <= EPS) ? true : false;
}
```



### 21. **Point Inside Test:** Given a point and a polygon check if the point is inside:

**Code:**

```cpp
TODO
```



### 22. **Polygon:** Given points of polygon find area:

**Code:**

```cpp
double polygonArea(vector<Point> pnts) {
    double ret = 0.0;
    int n = pnts.size();
    for(int i = 0; i < n; i++)
        ret += (pnts[i].x * pnts[(i+1)%n].y - pnts[(i+1)%n].x * pnts[i].y);
    return ret / 2.0;
}
```



### 23. **Polygon:** Given points of polygon find the perimeter:

**Code:**

```cpp
double polygonPerimeter(Point pnts[], int n) {
    double ret = 0.0;
    for(int i = 0; i < n-1; i++)
        ret += dist2D(pnts[i], pnts[i+1]);
    ret += dist2D(pnts[n-1], pnts[0]);        // dist between last point and first point
    return ret;
}
```



### 24. **Polygon:** Given points of polygon check if the polygon is convex:

**Idea:**

Main idea is any three points should have same CCW test result.

**Code:**

```cpp
bool isConvex(vector<Point> points) {
    int n = (int)points.size();
    if (n < 3) return false;
    bool direction = isCCW(points[0], points[1], points[2]);
    for (int i = 1; i < n; i++) {
        if (isCCW(points[i], points[(i+1)%n], points[(i+2)%n]) != direction) 
            return false;
    }
    return true;
}
```



### 25. **Polygon:** Given points of polygon find a convex hull:

**Code: (Graham's Scan) **

```cpp
#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define EPS 1e-9
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)
#define SQR(x) ((x)*(x))

inline int src() { int ret; scanf("%d", &ret); return ret; }

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b) : x(a), y(b) {}
};
double dist2D(Point a, Point b) {
    return SQR(a.x - b.x) + SQR(a.y - b.y);
}
bool isCCW(Point p, Point q, Point r) {
    // Cross Product
    double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    // If cross product positive then r is on the left side of line pq
    return (cross > 0) || (fabs(cross - 0.0) < DBL_EPSILON);        // Greater or equal to zero
}
void showPoints(vector<Point> pnts) {
    for (auto p : pnts) printf("%.2lf %.2lf\n", p.x, p.y);
    cout << "\n";
}
vector<Point> grahamsScan(vector<Point> pnts) {
    vector<Point> ret;
    int n = (int) pnts.size();
    if (n <= 3) return pnts;     // Special case

    // Selecting the pivot Point, most bottom and rightmost if tie
    int pIndex = 0;                 // Pivot Index
    for(int i = 1; i < n; i++)
        if(pnts[i].y < pnts[pIndex].y ||
           (pnts[i].y == pnts[pIndex].y && pnts[i].x > pnts[pIndex].x)) pIndex = i;

    // Placing pivot Point at the first of the array
    swap(pnts[0], pnts[pIndex]);
    Point pivot = pnts[0];
    // Sorting w.r.t angle with pivot Point
    sort(pnts.begin()+1, pnts.end(), [&](Point a, Point b) {
        double cross = (b.x - a.x) * (pivot.y - a.y) - (b.y - a.y) * (pivot.x - a.x);
        if(fabs(cross) < DBL_EPSILON) return dist2D(pivot, a) < dist2D(pivot, b);
        double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
        double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
        return atan2(d1y, d1x) - atan2(d2y, d2x) < 0;
    });
    cout << "Points after sorted: " << endl;
    showPoints(pnts);

    Point top1, top2;       // top1 is the top element of Stack, top2 is second top element
    stack<Point> S;
    S.push(pnts[n-1]);
    S.push(pnts[0]);

    int i = 1;
    while(i < n) {
        top2 = S.top();  S.pop();               // Getting 2nd top element
        top1 = S.top();  S.push(top2);          // Getting top element
        if(isCCW(top1, top2, pnts[i]))  S.push(pnts[i++]);
        else S.pop();
    }

    while( !S.empty() ) {
        ret.push_back(S.top());
        S.pop();
    }
    ret.pop_back();

    return ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    int N;
    Point p;
    vector<Point> Points;
    vector<Point> hull;

    while(cin >> N) {
        for(int i = 1; i <= N; i++) {
            cin >> p.x >> p.y;
            Points.push_back(p);
        }
        hull = grahamsScan(Points);

        cout << "Convex Hull consists of following Points:\n";
        showPoints(hull);
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
```



**Input:**

```
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
```

**Output:**

```
Points after sorted:
0.00 0.00
3.00 1.00
1.00 1.00
2.00 2.00
3.00 3.00
4.00 4.00
1.00 2.00
0.00 3.00
Convex Hull consists of following Points:
0.00 3.00
4.00 4.00
3.00 1.00
0.00 0.00
```



**Code: (AMC)**

```cpp
#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define EPS 1e-9
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)
#define SQR(x) ((x)*(x))

inline int src() { int ret; scanf("%d", &ret); return ret; }

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b) : x(a), y(b) {}
};
bool isCCW(Point p, Point q, Point r) {
    double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    // If cross product positive then r is on the left side of line pq
    //return (cross > 0) || (fabs(cross - 0.0) < EPS);       // Greater or equal to zero
    return cross > 0;
}
void showPoints(vector<Point> pnts) {
    for (auto p : pnts) printf("%.2lf %.2lf\n", p.x, p.y);
    cout << "\n";
}
// Sorting wrt Y, if tie then X
bool comp(Point a, Point b) {
    if(fabs(a.x - b.x) < EPS) return a.y < b.y;
    return a.x < b.x;

    //if(fabs(a.y - b.y) < EPS) return a.x < b.x;
    //return a.y < b.y;
}

/**
 * Given a list of points, returns the points that of convex hull
 * COMPLEXITY:  N*lg(N) where N being the number of vertices of the polygon
 * http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
 */
vector<Point> convexHullAMC(vector<Point> pnts) {
    vector<Point> hull;
    int n = pnts.size();
    if (n <= 3) return pnts; // Special case

    sort(pnts.begin(), pnts.end(), [](Point a, Point b) {
        if(fabs(a.x - b.x) < EPS) return a.y < b.y;
        return a.x < b.x;
    });
    cout << "Points after sorted: " << endl;
    showPoints(pnts);

    // Construct bottom part of hull
    for(int i = 0; i < n; i++) {
        //int size = hull.size();
        while(hull.size() >= 2 && !isCCW(hull[hull.size()-2], hull[hull.size()-1], pnts[i]))
            hull.pop_back();
        hull.push_back(pnts[i]);
    }

    // Construct top part of hull
    int l = hull.size() + 1;
    for(int i = n-1; i >= 0; i--) {
        //int size = hull.size();
        while(hull.size() >= l && !isCCW(hull[hull.size()-2], hull[hull.size()-1], pnts[i]))
            hull.pop_back();
        hull.push_back(pnts[i]);
    }
    return hull;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    int N;
    Point p;
    vector<Point> points;
    vector<Point> hull;

    while(cin >> N) {
        for(int i = 1; i <= N; i++) {
            cin >> p.x >> p.y;
            points.push_back(p);
        }
        hull = convexHullAMC(points);
        cout << "Convex Hull consists of following points:\n";
        showPoints(hull);
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
```



**Input:**

```
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
```



**Output:**

```
Points after sorted:
0.00 0.00
0.00 3.00
1.00 1.00
1.00 2.00
2.00 2.00
3.00 1.00
3.00 3.00
4.00 4.00

Convex Hull consists of following points:
0.00 0.00
3.00 1.00
4.00 4.00
0.00 3.00
0.00 0.00
```





### 26. **Closest Pair:** Given N points find the closest two points:

**Divide and Conquer Approach:**

<img src="https://i.ibb.co/G3SSNPg/closest-pair-dnc.png" style="zoom:25%;" />



**Code: (Divide and Conquer)**

```cpp
#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

inline int src() { int ret; scanf("%d", &ret); return ret; }

struct Point{
    double x, y;
    Point() {}
    Point(double a, double b) : x(a), y(b) {}
};

double sqrDist2D(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void closestPairDnC(vector<Point> pnts, int l, int r, double& minDist, Point& p1, Point& p2) {
    if(r-l+1 < 2) return;
    if(r-l+1 == 2) {
        double d = sqrDist2D(pnts[0], pnts[1]);
        if (d < minDist) {
            minDist = d;
            p1 = pnts[0], p2 = pnts[1];
        }
        return;
    }

    int mid = l + (r-l)/2;
    closestPairDnC(pnts, l, mid, minDist, p1, p2);
    closestPairDnC(pnts, mid+1, r, minDist, p1, p2);

    /// Build an vector strip that contains points close (closer than min)
    /// to the line passing through the middle point
    vector<Point> strip;
    for (auto p : pnts)
        if(SQR(p.x - pnts[mid].x) < minDist) strip.push_back(p);
    // Sorting by y-coordinate
    sort(strip.begin(), strip.end(), [](Point p1, Point p2) {
        return p1.y < p2.y;
    });

    // Find the closest points in strip.
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i+1; j < (int)strip.size(); j++) {
            if(SQR(strip[i].y - strip[j].y) >= minDist) break;
            Point a = strip[i], b = strip[j];
            double d = SQR(b.x-a.x)+SQR(b.y-a.y);
            if (d < minDist) {
                minDist = d;
                p1 = a, p2 = b;
            }
        }
    }
}

double closestPair(vector<Point> pnts, Point& p1, Point& p2) {
    int n = (int)pnts.size();
    if(n < 2) return DBL_EPSILON;
    if(n == 2) {
        double minDist = sqrt(sqrDist2D(p1, p2));
        p1 = pnts[0], p2 = pnts[1];
        return minDist;
    }

    // Sort w.r.t X
    sort(pnts.begin(), pnts.end(), [](Point p1, Point p2) {
        return p1.x < p2.x;
    });

    int l = 0, r = n-1;
    int mid = l + (r-l)/2;
    double minDist = DBL_MAX;
    closestPairDnC(pnts, l, mid, minDist, p1, p2);
    closestPairDnC(pnts, mid+1, r, minDist, p1, p2);
    minDist = sqrt(minDist);
    return minDist;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;
    int N;
    while(scanf("%d", &N) == 1) {
        vector<Point> pnts(N);
        for (auto& p : pnts) scanf("%lf %lf", &p.x, &p.y);
        Point p1, p2;
        double minDist = closestPair(pnts, p1, p2);

        printf("Closest Points are (%.2lf, %.2lf) and (%.2lf, %.2lf)\n", p1.x, p1.y, p2.x, p2.y);
        printf("Closest Distance is: %.4lf\n", minDist);
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
```



**Input:**

```
8
3 1
0 2
0 9
2 5
4 4
5 7
7 4
7 1

13
1 1
1 5
2 3
3 1
3 4
3 7
4 9
5 7
6 5
9 3
9 8
10 1
12 3
```



**Output:**

```
Closest Points are (4.00, 4.00) and (2.00, 5.00)
Closest Distance is: 2.2361
Closest Points are (2.00, 3.00) and (3.00, 4.00)
Closest Distance is: 1.4142

https://i.ibb.co/G3SSNPg/closest-pair-dnc.png
```



**Code: (Using Sweep Line)**

```cpp
#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

inline int src() { int ret; scanf("%d", &ret); return ret; }

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b) : x(a), y(b) {}
};

bool compX(Point a, Point b)
{
    if(fabs(a.x - b.x) < EPS) return a.y < b.y;
    return a.x < b.x;
}
class SetComparator {
public:
    bool operator() (const Point a, const Point b) {
        if(fabs(a.y - b.y) < DBL_EPSILON) return a.x < b.x;
        return a.y < b.y;
    }
};

void showPnts(vector<Point> pnts) {
    for (Point p : pnts) printf("%lf %lf\n", p.x, p.y);
    cout << endl;
}

// Complexity: N*lg(N)
double closestPairSweepLine(vector<Point> pnts, Point& p1, Point& p2) {
    int n = (int)pnts.size();
    int leftMostIndex = 1;      // Left Most Point Index which is within 'minDist'
    set<Point, SetComparator> candidates;
    double minDist = DBL_MAX;

    // Sort w.r.t X axis
    sort(pnts.begin(), pnts.end(), [](Point p1, Point p2) {
        if(fabs(p1.x - p2.x) < EPS) return p1.y < p2.y;
        return p1.x < p2.x;
    });

    for(int i = 0; i < n; i++) {
        Point current = pnts[i];
        while(current.x - pnts[leftMostIndex].x > minDist) {
            candidates.erase(pnts[leftMostIndex]);
            leftMostIndex++;
        }

        Point lowerLimit;
        lowerLimit.x = current.x;
        lowerLimit.y = current.y - minDist;
        auto lowerBound = candidates.lower_bound(lowerLimit);

        for(auto it = lowerBound; it->y <= pnts[i].y + minDist && it != candidates.end(); it++ ) {
            double dist = SQR(pnts[i].x - it->x) + SQR(pnts[i].y - it->y);
            if(dist < minDist) {
                minDist = dist;
                p1 = pnts[i];
                p2 = *it;
            }
        }
        candidates.insert(pnts[i]);
    }
    return sqrt(minDist);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;
    int n;
    while(scanf("%d", &n) == 1) {
        vector<Point> pnts(n);
        for (Point& p : pnts) scanf("%lf %lf", &p.x, &p.y);
        Point p1, p2;
        double minDist = closestPairSweepLine(pnts, p1, p2);

        printf("Closest Points are (%.2lf, %.2lf) and (%.2lf, %.2lf)\n", p1.x, p1.y, p2.x, p2.y);
        printf("Closest Distance is: %.4lf\n", minDist);
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
```

