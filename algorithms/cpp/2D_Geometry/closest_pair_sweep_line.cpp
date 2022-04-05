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
Closest Points are (3.00, 4.00) and (2.00, 3.00)
Closest Distance is: 1.4142

https://i.ibb.co/G3SSNPg/closest-pair-dnc.png

**/
