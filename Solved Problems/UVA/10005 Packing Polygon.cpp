/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.012
    Rank :      652
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
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a, int b) {   while(b) b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 1001

typedef struct {
    double x, y;
} Point;

int N;
vector<Point> pnts;
double radius;

double dist2D(Point a, Point b)
{
    return sqrt(SQR(a.x-b.x)+SQR(a.y-b.y));
}

/**
** OUTPUT:
** Return 1 if the point(p) is inside of the circle otherwise false
** Return 0 if the point(p) is on the circle perimeter
** Return -1 if the point(p) is outside of the circle
**/

int isPointInside(Point c, double r, Point p)
{
    double d = SQR(p.x - c.x) + SQR(p.y - c.y);
    if(d < SQR(r)) return 1;
    else if(d > SQR(r)) return  -1;

    return 0;
}

bool circle2PtsRad(Point p1, Point p2, double r, Point &center)
{
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r*r / d2 - 0.25;
    if(det < 0.0) return false;
    double h = sqrt(det);
    center.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    center.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;

    return true;
}

bool testAllPoints(Point center)
{
    FOR(i, 0, N-1) {
        if( isPointInside(center, radius, pnts[i]) == -1) return false;
    }
    return true;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   while(scanf("%d", &N) == 1) {
        if(N == 0) break;
        pnts = vector<Point>(N);

        FOR(i, 0, N-1) {
            cin >> pnts[i].x >> pnts[i].y;
        }
        cin >> radius;

        if(N == 1) {                    // Special Case
            printf("The polygon can be packed in the circle.\n");
            continue;
        }
        if(radius < 0.0) {
            printf("There is no way of packing that polygon.\n");
            continue;
        }

        bool isPackingPossible = false;

        FOR(i, 0, N-1) {
            if( !isPackingPossible ) {
                FOR(j, i+1, N-1) {
                    Point center;
                    if(circle2PtsRad(pnts[i], pnts[j], radius, center) && testAllPoints(center)) {
                        isPackingPossible = true;
                        break;
                    }
                    if(circle2PtsRad(pnts[j], pnts[i], radius, center) && testAllPoints(center)) {
                        isPackingPossible = true;
                        break;
                    }
                }
            }
        }

        if(isPackingPossible) printf("The polygon can be packed in the circle.\n");
        else printf("There is no way of packing that polygon.\n");
   }


   return 0;
}
