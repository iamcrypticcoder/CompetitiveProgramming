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

int N;                      // Number of Points given
Point pnts[10001];
Point minA, minB;           // two points of closest pair
double minDist;             // Distance of closest pair

bool compX(Point a, Point b)
{
    return (a.x < b.x);
}
bool compY(Point a, Point b)
{
    return (a.y < b.y);
}

void checkPair(Point a, Point b)
{
    double d = SQR(b.x-a.x)+SQR(b.y-a.y);
    if(d < minDist) {
        minDist = d;
        minA = a; minB = b;
    }
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
void divideAndConquer(Point p[], int n)
{
    int i, j, cnt;
    vector<Point> strip;

    if(n == 2) checkPair(p[1], p[2]);         /* base cases */
    if(n <= 2) return;

    int mid = n / 2;
    divideAndConquer(p, mid);
    divideAndConquer(p + mid, n - mid);

    /// Build an vector strip that contains points close (closer than min)
    /// to the line passing through the middle point
    for(i = 1; i <= n; i++)
        if(SQR(p[i].x - p[mid].x) < minDist) strip.push_back(p[i]);
    sort(strip.begin(), strip.end(), compY);                    // Sorting by y-coordinate

    // Find the closest points in strip.
    for(i = 0; i < strip.size(); i++) {
        if(SQR(strip[i].x - p[mid].x) >= minDist) break;
        for(j = i+1; j < strip.size(); j++) {
            if(SQR(strip[i].y - strip[j].y) >= minDist) break;
            checkPair(strip[i], strip[j]);
        }
    }
}

// Make sure points are stored in array from index 1
double closestPair(Point p[], int n)
{
    minDist = DBL_MAX;
    sort(p + 1, p + 1 + n, compX);
    divideAndConquer(p, n);
}

void showPnts()
{
    for(int i = 1; i <= N; i++) {
        printf("%lf %lf\n", pnts[i].x, pnts[i].y);
    }
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
        for(i = 1; i <= N; i++)
            scanf("%lf %lf", &pnts[i].x, &pnts[i].y);

        closestPair(pnts, N);

        printf("Closest Points are (%.4lf, %.4lf) and (%.4lf, %.4lf)\n", minA.x, minA.y, minB.x, minB.y);
        printf("Closest Distance is: %.4lf\n", sqrt(minDist));
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
