/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.842
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

#define MAX 701

typedef struct {
    int x, y;
} Point;

int N;
Point pnts[MAX];
Point slp[MAX];

void normalize(Point &p)
{
    int x = abs(p.x);
    int y = abs(p.y);

    if(x != 0 && y != 0) {
        int g = GCD(x, y);

        x /= g;
        y /= g;

        p.x = (p.x < 0) ? -x : x;
        p.y = (p.y < 0) ? -y : y;
    }
    else if(x == 0) {
        p.x = -1;
        p.y = -1;
    }
    else if(y == 0) {
        p.x = 0;
        p.y = 0;
    }
}

bool compX(Point a, Point b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string line;
    Point p;

    cin >> TC;
    getchar();
    getchar();

    FOR(tc, 1, TC) {
        N = 0;
        while(getline(cin, line)) {
            if(line.length() == 0) break;
            stringstream ss(line);
            ss >> pnts[N].x >> pnts[N].y;
            N++;
        }

        int ans = 2;

        FOR(i, 0, N-1) {
            k = 0;
            FOR(j, 0, N-1) {
                if(i != j) {
                    slp[k].x = pnts[i].x - pnts[j].x;
                    slp[k].y = pnts[i].y - pnts[j].y;
                    normalize(slp[k]);
                    k++;
                }
            }

            sort(slp, slp+N-1, compX);

            int cnt = 1;
            FOR(l, 1, N-2) {
                if(slp[l].x == slp[l-1].x && slp[l].y == slp[l-1].y) cnt++;
                else cnt = 1;
                ans = max(ans, cnt + 1);
            }
        }

        cout << ans << endl;
        if(tc < TC) cout << endl;
    }
    return 0;
}


