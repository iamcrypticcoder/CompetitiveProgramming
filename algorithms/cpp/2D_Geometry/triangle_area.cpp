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

typedef pair<double, double> PDD;
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


/**
** DESCRIPTION:
** Given three vertices a triangle, returns the area of the triangle.
**
** FORMULA:
** We know cross product value of two vectors provides area of parallalogram. So divide by 2 gives triangle area
** |AB x BC| / 2 = answer
** vec(AB) = (B.x - A.x, B.y - A.y)
** vec(BC) = (C.x - B.x, C.y - B.x)
**
** COMPLEXITY:  O(1)
**
** INPUT:
** Three points (a, b, c) of a triangle.
**
** OUTPUT:
** Area of the triangle
**
** CONDITION(S):
**
** RELIABILITY: 10
**
** NOTE:
**/
double triangleArea(Point a, Point b, Point c) {
    return fabs((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y)) / 2.0;
}
double triangleArea(PDD a, PDD b, PDD c) {
    return fabs((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first)) / 2.0;
}

/**
** DESCRIPTION:
** Given lengths of three sides of a triangle, returns the area of the triangle.
**
** COMPLEXITY:  O(1)
**
** INPUT:
** Lengths of three sides (a, b, c) of a triangle.
**
** OUTPUT:
** Area of the triangle using heron's formula, If triangle possible
** return -1, If the sides doesn't form a triangle
** area = sqrt(s * (s-a) * (s-b) * (s-c)) where s = (a + b + c) / 2.0
**
** CONDITION(S):
**
** RELIABILITY: 10
**
**/
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    if(a > s || b > s || c > s) return -1;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

/**
** DESCRIPTION:
** Given lengths of three medians of a triangle, returns the area of the triangle.
**
** COMPLEXITY:  O(1)
**
** INPUT:
** Lengths of three medians (a, b, c) of a triangle.
**
** OUTPUT:
** Area of the triangle using heron's formula, If triangle possible
** return -1, If the medians are invalid
**
** CONDITION(S):
**
** RELIABILITY: 10
**
**/
double triangleArea(double m1, double m2, double m3) {
    double s = 0.5 * (m1 + m2 + m3);
    double area = s * (s - m1) * (s - m2) * (s - m3);
    if(area < 0.0) return -1.0;
    return sqrt( area ) * 4.0 / 3.0;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    Point a, b, c;

    while(scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6){
        printf("Area of triangle = %f\n", triangleArea(a,b,c));
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
