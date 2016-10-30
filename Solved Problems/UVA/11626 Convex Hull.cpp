/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.392
    Rank :      303
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

int N, M;
Point pivot;
vector<Point> pnts;

double dist2D(Point a, Point b)
{
    return sqrt(SQR(a.x - b.x) + SQR(a.y - b.y));
}

bool isCCW(Point p, Point q, Point r)
{
    // Cross Product
    double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    // If cross product positive then r is on the left side of line pq
    return (cross > 0);       // Greater or equal to zero
}

bool colinear(Point p, Point q, Point r)
{
    double cross = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
    return (fabs(cross) < EPS);
}

bool compAngle(Point a, Point b)
{
    double cross = (b.x - a.x) * (pivot.y - a.y) - (b.y - a.y) * (pivot.x - a.x);
    if(fabs(cross) < EPS) return dist2D(pivot, a) < dist2D(pivot, b);
    return isCCW(pivot, a, b);

    /*
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return atan2(d1y, d1x) - atan2(d2y, d2x) < 0;
    */
}

bool compDist(Point a, Point b)
{
    return dist2D(pivot, a) > dist2D(pivot, b);
}

void grahamsScanSort()
{
    int pIndex = 0;
    for(int i=0; i < M; i++) {
        if(pnts[i].x < pnts[pIndex].x ||
           (pnts[i].x == pnts[pIndex].x && pnts[i].y < pnts[pIndex].y)) pIndex = i;
    }
    swap(pnts[0], pnts[pIndex]);
    pivot = pnts[0];

    sort(pnts.begin()+1, pnts.end(), compAngle);
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    char ch;
    Point pnt;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> N;

        FOR(i, 1, N) {
            cin >> pnt.x >> pnt.y >> ch;
            if(ch == 'Y') pnts.PB(pnt);
        }

        M = pnts.size();

        grahamsScanSort();      // We need to do only grahams scan sorting

        i = M-1;
        while(i-2 >= 0 && colinear(pivot, pnts[i], pnts[i-1])) i--;
        sort(pnts.begin()+i, pnts.end(), compDist);

        cout << M << endl;
        FOR(i, 0, M-1) printf("%d %d\n", (int)pnts[i].x, (int)pnts[i].y);

        pnts.clear();
    }

    return 0;
}


