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

typedef struct {
    Point c;        // Center of circle
    double r;       // Radius of circle
} Circle;

typedef struct {
    Point ll;       // Lower Left Point
    Point ur;       // Upper Right Point
} Rectangle;

double triangleArea(Point a, Point b, Point c)
{
    return fabs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) / 2.0;
}

/**
** DESCRIPTION:
** Given UpperLeft and LowerRight point of a rectangle and a point p this function tells
** whether point p is inside of rectangle or not
**
** COMPLEXITY:  O(1)
**
** INPUT:
** UpperLeft and LowerRight point of a rectangle and a point p
** or, LowerLeft and UpperRight point of a rectangle and a point p
**
** OUTPUT:
** Return 1 if the point p is inside of the rectangle.
** Return 0 if the point p is on rectangle sides
** Return -1 if the point p is outside of the rectangle
**
** CONDITION(S): UpperLeft Point must be positioned in upper and left side of the LowerRight point.
**
** RELIABILITY:
**
** NOTE:
**/
/*
int isPointInside(Point uL, Point lR, Point p)
{
    if(p.x > uL.x && p.x < lR.x && p.y > lR.y && p.y < uL.y) return 1;
    else if(p.x >= uL.x && p.x <= lR.x && p.y >= lR.y && p.y <= uL.y) return 0;
    return -1;
}
*/
int isPointInside(Point ll, Point ur, Point p)
{
    if(p.x > ll.x && p.x < ur.x && p.y > ll.y && p.y < ur.y) return 1;
    else if(p.x >= ll.x && p.x <= ur.x && p.y >= ll.y && p.y <= ur.y) return 0;
    return -1;
}
int isPointInside(Rectangle r, Point p)
{
    if(p.x > r.ll.x && p.x < r.ur.x && p.y > r.ll.y && p.y < r.ur.y) return 1;
    else if(p.x >= r.ll.x && p.x <= r.ur.x && p.y >= r.ll.y && p.y <= r.ur.y) return 0;
    return -1;
}

/**
** DESCRIPTION:
** Given center and radius of a circle and a point p this function checks
** whether point p is inside of circle or not
**
** COMPLEXITY:  O(1)
**
** INPUT:
** Center point(c) and radius(r) of a circle and a point(p).
**
** OUTPUT:
** Return 1 if the point(p) is inside of the circle otherwise false
** Return 0 if the point(p) is on the circle perimeter
** Return -1 if the point(p) is outside of the circle

** CONDITION(S):
**
** RELIABILITY:
**
** NOTE:
** if x^2 + y^2 < r^2 then inside
** if x^2 + y^2 = r^2 then on circle
** if x^2 + y^2 > r^2 then outside
**
**/
int isPointInside(Point c, double r, Point p)
{
    double d = SQR(p.x - c.x) + SQR(p.y - c.y);
    if(d < SQR(r)) return 1;
    else if(d > SQR(r)) return  -1;

    return 0;
}
int isPointInside(Circle c, Point p)
{
    double d = SQR(p.x - c.c.x) + SQR(p.y - c.c.y);
    if(d < SQR(c.r)) return 1;
    else if(d > SQR(c.r)) return -1;

    return 0;
}

/**
** DESCRIPTION:
** Given three points of a circle and a point p this function checks
** whether point p is inside of circle or not
**
** COMPLEXITY:  O(1)
**
** INPUT:
** Three points (p1, p2, p3) of a circle and a point(p).
**
** OUTPUT:
** Return true if the point(p) is inside of the circle otherwise false
**
** CONDITION(S):
**
** RELIABILITY:
**
**/
bool isPointInside(Point p1, Point p2, Point p3, Point p)
{
    double a1, a2, a3, total;

    a1 = triangleArea(p1, p2, p);
    a2 = triangleArea(p2, p3, p);
    a3 = triangleArea(p3, p1, p);
    total = triangleArea(p1, p2, p3);

    return (fabs(a1 + a2 + a3 - total) <= EPS) ? true : false;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    Rectangle rect;
    Point uL, lR;
    Point ll, ur;
    Point p;

    ll.x = 6; ll.y = 1;
    ur.x = 10; ur.y = 4;
    rect.ll.x = 6; rect.ll.y = 1;
    rect.ur.x = 10; rect.ur.y = 4;

    p.x = 5; p.y = 1;
    cout << isPointInside(ll, ur, p) << " " << isPointInside(rect, p) << endl;           // Output should be -1

    p.x = 6; p.y = 1;
    cout << isPointInside(ll, ur, p) << " " << isPointInside(rect, p) << endl;             // Output = 0

    p.x = 6; p.y = 4;
    cout << isPointInside(ll, ur, p) << " " << isPointInside(rect, p) << endl;             // Output = 0

    p.x = 6; p.y = 5;
    cout << isPointInside(ll, ur, p) << " " << isPointInside(rect, p) << endl;             // Output = -1

    p.x = 10; p.y = 5;
    cout << isPointInside(ll, ur, p) << " " << isPointInside(rect, p) << endl;             // Output = -1

    p.x = 11; p.y = 3;
    cout << isPointInside(ll, ur, p) << " " << isPointInside(rect, p) << endl;             // Output = -1

    p.x = 7; p.y = 2;
    cout << isPointInside(ll, ur, p) << " " << isPointInside(rect, p) << endl;             // Output = -1

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
