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

https://i.ibb.co/Kw6yKcy/grahams-scan.png

*/
