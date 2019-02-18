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


/**
** DESCRIPTION:
** Rotation of a point around a point
**
** COMPLEXITY:  O(1)
**
** INPUT:
** Reference point(o), the point to be rotated(p) and angle(theta)
**
** OUTPUT:
** Rotates a point P around an origin point O, and returns the new point.
** The parameter theta is the amount to rotate P counter-clockwise measured in radians.
**
** CONDITION(S): theta must in radian
**
** RELIABILITY: 5
**
**/
Point rotate2D(Point o, Point p, double theta)
{
    double mat[2][2];           // This is rotation matrix. http://en.wikipedia.org/wiki/Rotation_matrix
    Point ret;

    mat[0][0] = mat[1][1] = cos(theta);
    mat[1][0] = sin(theta);
    mat[0][1] = -mat[1][0];
    p.x -= o.x;                 // Translating to origin
    p.y -= o.y;
    ret.x = mat[0][0] * p.x + mat[0][1] * p.y + o.x;        // Translating to point o
    ret.y = mat[1][0] * p.x + mat[1][1] * p.y + o.y;

    if(fabs(ret.x) < EPS) ret.x = 0;
    if(fabs(ret.y) < EPS) ret.y = 0;
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

    while(scanf("%lf %lf %lf %lf %lf", &p.x, &p.y, &o.x, &o.y, &deg) == 5) {
        deg *= PI/180.0;
        r = rotate2D(o,p,deg);
        printf("[%.3f,%.3f] rotated %.3f radians around [%.3f,%.3f] = [%.3f,%.3f]\n",
        p.x, p.y, deg, o.x, o.y, r.x, r.y);
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
