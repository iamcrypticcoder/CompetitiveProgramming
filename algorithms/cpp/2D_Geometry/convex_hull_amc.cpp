/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

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

/*
Input
======
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3

Output
======
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

https://i.ibb.co/Kw6yKcy/grahams-scan.png

*/
