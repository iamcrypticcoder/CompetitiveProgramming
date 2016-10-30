/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.015
    Rank :      2550
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

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
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

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

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

#define MAX_NODE 10001


typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p;        // Start Point
    Point q;        // End Point
} LineSegment;

Point leftTop, rightBottom;
LineSegment lineSeg;

// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int cross = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (fabs(cross) < EPS) return 0;  // colinear

    return (cross > 0)? 1: 2; // clock or counterclock wise
}
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

/**
** DESCRIPTION:
** Given two line segments check whether they intersect or not
**
** COMPLEXITY:  O(1)
**
** INPUT:
** p1 and q1 are two points of first line segment
** p2 and q2 are two points of second line segment
**
** OUTPUT:
** true - if they intersect
** false - it they don't intersect
**
** CONDITION(S):
**
** RELIABILITY: 10
** UVA 11343
**/
bool areIntersect(Point p1, Point q1, Point p2, Point q2)
{
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

void showLineSegment(LineSegment ls)
{
    cout << ls.p.x << " " << ls.p.y << " " << ls.q.x << " " << ls.q.y << endl;
}

bool intersectionTest()
{
    bool ret = false;

    LineSegment seg1;
    seg1.p = leftTop;
    seg1.q.x = rightBottom.x;
    seg1.q.y = leftTop.y;
    //showLineSegment(seg1);
    ret = ret || areIntersect(seg1.p, seg1.q, lineSeg.p, lineSeg.q);

    seg1.p = leftTop;
    seg1.q.x = leftTop.x;
    seg1.q.y = rightBottom.y;
    //showLineSegment(seg1);
    ret = ret || areIntersect(seg1.p, seg1.q, lineSeg.p, lineSeg.q);

    seg1.p = rightBottom;
    seg1.q.x = leftTop.x;
    seg1.q.y = rightBottom.y;
    //showLineSegment(seg1);
    ret = ret || areIntersect(seg1.p, seg1.q, lineSeg.p, lineSeg.q);


    seg1.p = rightBottom;
    seg1.q.x = rightBottom.x;
    seg1.q.y = leftTop.y;
    //showLineSegment(seg1);
    ret = ret || areIntersect(seg1.p, seg1.q, lineSeg.p, lineSeg.q);

    // Check whether line segment is inside of rectangle
    double xLeft = min(lineSeg.p.x, lineSeg.q.x);
    double xRight = max(lineSeg.p.x, lineSeg.q.x);
    double yTop = max(lineSeg.p.y, lineSeg.q.y);
    double yBottom = min(lineSeg.p.y, lineSeg.q.y);
    ret = ret || (xLeft > min(leftTop.x, rightBottom.x) &&
                  xRight < max(leftTop.x, rightBottom.x) &&
                  yBottom > min(leftTop.y, rightBottom.y) &&
                  yTop < max(leftTop.y, rightBottom.y));

    return ret;
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> lineSeg.p.x >> lineSeg.p.y >> lineSeg.q.x >> lineSeg.q.y;
        cin >> leftTop.x >> leftTop.y >> rightBottom.x >> rightBottom.y;

        if(intersectionTest()) printf("T\n");
        else printf("F\n");
    }
    return 0;
}


