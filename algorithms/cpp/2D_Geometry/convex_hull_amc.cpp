/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <float.h>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)   {   return a/GCD(a,b)*b;                }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 10000

typedef struct {
    double x, y;
} Point;

bool isCCW(Point p, Point q, Point r)
{
    // Cross Product
    double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    // If cross product positive then r is on the left side of line pq
    //return (cross > 0) || (fabs(cross - 0.0) < EPS);       // Greater or equal to zero
    return cross > 0;
}

void showPoints(vector<Point> pnts)
{
    for(int i = 0; i < pnts.size(); i++) {
        printf("%.2lf %.2lf\n", pnts[i].x, pnts[i].y);
    }
    cout << "\n";
}

// Sorting wrt Y, if tie then X
bool comp(Point a, Point b)
{
    if(fabs(a.x - b.x) < EPS) return a.y < b.y;
    return a.x < b.x;

    //if(fabs(a.y - b.y) < EPS) return a.x < b.x;
    //return a.y < b.y;
}

/**
** DESCRIPTION:
** Given a list of points, returns the points that of convex hull
**
** COMPLEXITY:  N*lg(N) where N being the number of vertices of the polygon
**
** INPUT:
** A list of points in 2D coordinates
**
** OUTPUT:
** Points of convex hull
** http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
**
** CONDITION(S):
**
** RELIABILITY: 5
**
** NOTE:
**/
vector<Point> convexHullAMC(vector<Point> pnts)
{
    vector<Point> hull;
    int n = pnts.size();

    sort(pnts.begin(), pnts.end(), comp);
    showPoints(pnts);

    for(int i=0; i < n; i++) {
        //int size = hull.size();
        while(hull.size() >= 2 && !isCCW(hull[hull.size()-2], hull[hull.size()-1], pnts[i]))
            hull.pop_back();
        hull.push_back(pnts[i]);
    }

    int l = hull.size() + 1;
    for(int i = n-1; i >= 0; i--) {
        //int size = hull.size();
        while(hull.size() >= l && !isCCW(hull[hull.size()-2], hull[hull.size()-1], pnts[i]))
            hull.pop_back();
        hull.push_back(pnts[i]);
    }
    return hull;
}

int main()
{
    //READ("input.txt");
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
