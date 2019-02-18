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
** Given list of points of a polygon, returns the signed area of the polygon.
**
** COMPLEXITY:  O(N) N being the number of vertices of the polygon
**
** INPUT:
** List of points of a polygon
**
** OUTPUT:
** The result is positive if the orientation is counterclockwise, and negative otherwise.
** http://en.wikipedia.org/wiki/Polygon
**
** CONDITION(S): Points must be given as counterclockwise or clockwise orientation.
**
** RELIABILITY:
**
** NOTE:
**/
/*
double polygonArea(Point pnts[], int n)
{
    double ret = 0.0;
    for(int i = 0; i < n; i++)
        ret += (pnts[i].x * pnts[(i+1)%n].y - pnts[(i+1)%n].x * pnts[i].y);
    return ret / 2.0;
}
*/

double polygonArea(vector<Point> pnts)
{
    double ret = 0.0;
    int n = pnts.size();
    for(int i = 0; i < n; i++)
        ret += (pnts[i].x * pnts[(i+1)%n].y - pnts[(i+1)%n].x * pnts[i].y);
    return ret / 2.0;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    while(scanf("%d", &N) == 1) {
        points = vector<Point>(N);
        for(int i=0; i<N; i++) {
            //scanf("%lf %lf", &pnts[i].x, &pnts[i].y);
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }

        //printf("%.3lf\n", polygonArea(pnts, N));
        printf("%.3lf\n", polygonArea(points));
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
