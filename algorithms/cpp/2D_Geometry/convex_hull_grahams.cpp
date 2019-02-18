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

double dist2D(Point a, Point b)
{
    return sqrt(SQR(a.x - b.x) + SQR(a.y - b.y));
}
bool isCCW(Point p, Point q, Point r)
{
    // Cross Product
    double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    // If cross product positive then r is on the left side of line pq
    return (cross > 0) || (fabs(cross - 0.0) < EPS);        // Greater or equal to zero
}

Point pivot;

bool compAngle(Point a, Point b)
{
    double cross = (b.x - a.x) * (pivot.y - a.y) - (b.y - a.y) * (pivot.x - a.x);
    if(fabs(cross) < EPS) return dist2D(pivot, a) < dist2D(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return atan2(d1y, d1x) - atan2(d2y, d2x) < 0;
}
void showPoints(vector<Point> pnts)
{
    for(int i = 0; i < pnts.size(); i++) {
        printf("%.2lf %.2lf\n", pnts[i].x, pnts[i].y);
    }
    cout << "\n";

}
vector<Point> grahamsScan(vector<Point> pnts)
{
    vector<Point> ret;

    int n = (int) pnts.size();
    // Selecting the pivot point, most lowest and rightmost if tie
    int pIndex = 0;                 // Pivot Index
    for(int i = 1; i < n; i++)
        if(pnts[i].y < pnts[pIndex].y ||
           (pnts[i].y == pnts[pIndex].y && pnts[i].x > pnts[pIndex].x)) pIndex = i;

    // Placing pivot point at the first of the array
    swap(pnts[0], pnts[pIndex]);
    pivot = pnts[0];
    // Sorting w.r.t angle with pivot point
    sort(pnts.begin()+1, pnts.end(), compAngle);
    //showPoints(pnts);

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

    while( !S.empty() ) { ret.push_back(S.top());   S.pop(); }
    ret.pop_back();

    return ret;
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
        hull = grahamsScan(points);

        cout << "Convex Hull consists of following points:\n";
        showPoints(hull);
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
