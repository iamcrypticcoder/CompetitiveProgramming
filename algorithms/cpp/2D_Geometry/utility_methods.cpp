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

/**
** INPUT: Two points (a, b) of a cartesian coordinate
** OUTPUT: Cartesian Distance
** COMPLEXITY: O(1)
**/
double cartesianDist2D(pair<double, double> a, pair<double, double> b)
{
    return sqrt(SQR(a.first - b.first) + SQR(a.second - b.second));
}


/**
** INPUT: Three points (a, b, c) of a triangle.
** OUTPUT: Area of the triangle using following formula.
** COMPLEXITY: O(1)
**/
double triangleArea(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
    return fabs((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first)) / 2.0;
}


/**
** INPUT: Lengths of three sides (a, b, c) of a triangle.
** OUTPUT: Area of the triangle using heron formula
** area = sqrt(s * (s-a) * (s-b) * (s-c)) where s = (a + b + c) / 2.0
** COMPLEXITY: O(1)
**/
double triangleArea(double a, double b, double c)
{
   double s = (a + b + c) / 2.0;
   if(a > s || b > s || c > s) return -1;
   return sqrt(s * (s-a) * (s-b) * (s-c));
}


/**
** INPUT: UpperLeft and LowerRight points of a rectangle.
** OUTPUT: Area of the rectangle.
** COMPLEXITY: O(1)
**/
double rectangleArea(pair<double, double> uL, pair<double, double> lR)
{
    pair<double, double> uR;

    uR.first = lR.first;
    uR.second = uL.second;

    return cartesianDist2D(uL, uR) * cartesianDist2D(uR, lR);
}


/**
** INPUT: List of points of a polygon
** OUTPUT: Area of the polygon.
** http://en.wikipedia.org/wiki/Polygon
** COMPLEXITY: O(N)
**/
double polygonArea(vector<pair<double, double> > pnts)
{
    double ret = 0.0;
    int n = pnts.size();
    for(int i = 0; i < n; i++)
        ret += (pnts[i].first * pnts[(i+1)%n].second - pnts[(i+1)%n].first * pnts[i].second);
    return ret / 2.0;
}


/**
** INPUT: UpperLeft and LowerRight point of a rectangle and a point p.
** Output:
** Return true if the point p is inside of the rectangle.
** Return false if the point p is outside of the rectangle or on rectangle sides
** COMPLEXITY: O(1)
**/
bool isPointInside(pair<double, double> uL, pair<double, double> lR, pair<double, double> p)
{
    return (p.first > uL.first && p.first < lR.first && p.second > lR.second && p.second < uL.second);
}


/**
** INPUT: Center point and radius of a circle and a point p.
** Output:
** Return true if the point p is inside of the circle.
** Return false if the point p is outside of the circle.
** Even if the point is in circle sides.
** COMPLEXITY: O(1)
**/
bool isPointInside(pair<double, double> c, double r, pair<double, double> p)
{
    return ( SQR(p.first - c.first) + SQR(p.second - c.second) < SQR(r) );
}


/**
** INPUT: Three points (p1, p2, p3) of a circle and a point (p).
** OUTPUT:
** Return true if the point p is inside of the circle.
** Return false if the point p is outside of the circle.
** Even if the point is in circle sides.
** COMPLEXITY: O(1)
**/
bool isPointInside(pair<double, double> p1,
                   pair<double, double> p2,
                   pair<double, double> p3,
                   pair<double, double> p)
{
    double a1, a2, a3, total;

    a1 = triangleArea(p1, p2, p);
    a2 = triangleArea(p2, p3, p);
    a3 = triangleArea(p3, p1, p);
    total = triangleArea(p1, p2, p3);

    return (fabs(a1 + a2 + a3 - total) <= EPS) ? true : false;
}


/**
** INPUT: Given two rectangle as their lower left and upper right points
** ll1 = lower left point of 1st rectangle
** ur1 = upper right point of 1st rectangle
** ll2 = lower left point of 2st rectangle
** ur1 = upper right point of 2st rectangle
**
** CONDITION(S):
** Lower Left point must be LOWER and LEFT of Upper Right point
**
** OUTPUT:
** if they overlapped then Area of overlapped regions, otherwise -1
**
** COMPLEXITY: O(1)
**/
double overlapArea(pair<double, double> ll1,
                   pair<double, double> ur1,
                   pair<double, double> ll2,
                   pair<double, double> ur2)
{
    double x = max(ll1.first, ll2.first);
    double y = max(ll1.second, ll2.second);
    double xx = min(ur1.first, ur2.first);
    double yy = min(ur1.second, ur2.second);

    if(x < xx && y < yy) return (xx - x) * (yy - y);

    return -1;
}



int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    vector<pair<double, double> > pnts;
    pnts.push_back(pair<double, double>(-3, -2));
    pnts.push_back(pair<double, double>(-1,  4));
    pnts.push_back(pair<double, double>( 6,  1));
    pnts.push_back(pair<double, double>( 3,  10));
    pnts.push_back(pair<double, double>(-4,  9));

    cout << polygonArea(pnts) << endl;

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
