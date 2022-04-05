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

/**
INPUT
=====
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

OUTPUT
======
Closest Points are (4.00, 4.00) and (2.00, 5.00)
Closest Distance is: 2.2361
Closest Points are (2.00, 3.00) and (3.00, 4.00)
Closest Distance is: 1.4142

https://i.ibb.co/G3SSNPg/closest-pair-dnc.png

**/
