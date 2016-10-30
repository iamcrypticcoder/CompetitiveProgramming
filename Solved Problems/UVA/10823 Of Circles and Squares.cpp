/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.028
    Rank :      34
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
    Point c;
    double r;
} Circle;

typedef struct {
    Point ll;       // Lower Left Point
    Point ur;       // Upper Right Point
} Rectangle;

typedef struct {
    int objectType;     // 1 means circle, 2 means rectangle/square
    Circle circle;
    Rectangle rect;
    int r, g, b;
} Object;

int isPointInside(Rectangle r, Point p)
{
    if(p.x > r.ll.x && p.x < r.ur.x && p.y > r.ll.y && p.y < r.ur.y) return 1;
    else if(p.x >= r.ll.x && p.x <= r.ur.x && p.y >= r.ll.y && p.y <= r.ur.y) return 0;
    return -1;
}

int isPointInside(Circle c, Point p)
{
    double d = SQR(p.x - c.c.x) + SQR(p.y - c.c.y);
    if(d < SQR(c.r)) return 1;
    else if(d > SQR(c.r)) return -1;

    return 0;
}

int R, P;
Object obj[101];
Point p;

void calcColor(Point p, int &r, int &g, int &b)
{
    int sumR = 0, sumG = 0, sumB = 0;

    bool isOnBorder = false;
    int check;
    int objSelected = 0;

    FOR(i, 1, R) {
        if(obj[i].objectType == 1) {                    // if Circle
            check = isPointInside(obj[i].circle, p);
        } else if(obj[i].objectType == 2) {             // if Rectangle
            check = isPointInside(obj[i].rect, p);
        }

        if(check == 0) {
            isOnBorder = true;
            break;
        } else if(check == 1) {
            objSelected++;
            sumR += obj[i].r;
            sumG += obj[i].g;
            sumB += obj[i].b;
        }
    }

    if(isOnBorder) { r = 0; g = 0; b = 0; }
    else if(objSelected == 0) { r = 255; g = 255; b = 255; }
    else {
        r = (int)round((double)sumR / objSelected);
        g = (int)round((double)sumG / objSelected);
        b = (int)round((double)sumB / objSelected);
    }
}
int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string objectType;
    int length, radius;
    int r, g, b;

    TC = src();

    FOR(tc, 1, TC) {
        scanf("%d %d", &R, &P);

        FOR(i, 1, R) {
            cin >> objectType;
            if(objectType == "SQUARE") {
                Rectangle rect;
                scanf("%lf %lf %d", &rect.ll.x, &rect.ll.y, &length);
                rect.ur.x = rect.ll.x + length;
                rect.ur.y = rect.ll.y + length;

                obj[i].objectType = 2;
                obj[i].rect = rect;
            } else {
                Circle c;
                scanf("%lf %lf %lf", &c.c.x, &c.c.y, &c.r);

                obj[i].objectType = 1;
                obj[i].circle = c;
            }
            scanf("%d %d %d", &obj[i].r, &obj[i].g, &obj[i].b);
        }

        printf("Case %d:\n", tc);
        FOR(i, 1, P) {
            scanf("%lf %lf", &p.x, &p.y);

            calcColor(p, r, g, b);

            printf("(%d, %d, %d)\n", r, g, b);
        }

        if(tc < TC) printf("\n");
    }

    return 0;
}

