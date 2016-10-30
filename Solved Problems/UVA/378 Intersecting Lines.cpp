/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.015
    Rank :      2271
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

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) {
        x = _x; y = _y;
    }
};

struct Line {
    double a, b, c;
    Line() {}
    Line(double _a, double _b, double _c) {
        a = _a; b = _b; c = _c;
    }
};

Line pointToLine(Point p1, Point p2)
{
    Line ret;

    if(p1.x == p2.x) {
		ret.a = 1;
		ret.b = 0;
		ret.c = -p1.x;
	}
	else {
		ret.b = 1;
		ret.a = -(p1.y - p2.y)/(p1.x - p2.x);
		ret.c = -(ret.b * p1.y) - (ret.a * p1.x);
	}
	return ret;
}

bool areSameLine(Line l1, Line l2)
{
    return ( (fabs(l1.a - l2.a)) <= EPS && (fabs(l1.b - l2.b)) <= EPS && (fabs(l1.c - l2.c)) <= EPS);
}

bool areParallelLine(Line l1, Line l2)
{
    return ( (fabs(l1.a - l2.a)) <= EPS && (fabs(l1.b - l2.b)) <= EPS);
}

Point intersectionPoint(Line l1, Line l2)
{
    Point ret;
    ret.x = (l1.b*l2.c - l2.b*l1.c) / (l1.a*l2.b - l2.a*l1.b);
	ret.y = (l1.c*l2.a - l2.c*l1.a) / (l1.a*l2.b - l2.a*l1.b);
	return ret;
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    Point P1, P2, P3, P4, P5;
    Line L1, L2;

    cin >> TC;

    cout << "INTERSECTING LINES OUTPUT\n";

    FOR(tc, 1, TC) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &P1.x, &P1.y, &P2.x, &P2.y, &P3.x, &P3.y, &P4.x, &P4.y);

        L1 = pointToLine(P1,P2);
        L2 = pointToLine(P3,P4);

        if(areSameLine(L1, L2) == true)
			cout << "LINE\n";
		else if(areParallelLine(L1, L2) == true)
			cout << "NONE\n";
		else {
			P5 = intersectionPoint(L1, L2);
			printf("POINT %.2lf %.2lf\n", P5.x, P5.y);
		}
    }
    cout << "END OF OUTPUT\n";

    return 0;
}


