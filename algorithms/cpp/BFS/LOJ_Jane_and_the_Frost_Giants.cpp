/*
        Problem Link : https://lightoj.com/problem/jane-and-the-frost-giants
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : Memory Limit Excceded
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
#include <limits.h>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS             1e-9
#define SQR(x)          ((x)*(x))
#define INF             2000000000
#define TO_DEG          57.29577951
#define PI              2*acos(0.0)

#define ALL_BITS                                ((1 << 31) - 1)
#define NEG_BITS(mask)                          (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)                       (mask & (1 << i))
#define ON_BIT(mask, i)                         (mask |= (1 << i))
#define OFF_BIT(mask, i)                        (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                         (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)                (x & (x-1))

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<uint, uint> PUU;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<uint> VU;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<uint, uint> MUU;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int MAX = int(200);

int R, C;
vector<string> grid;
int fireDist[MAX+3][MAX+3];
int janeDist[MAX+3][MAX+3];

bool checkCell(int x, int y) {
    return (x >= 0 && x < R && y >= 0 && y <= C && grid[x][y] != '#');
}

void bfsFire(pair<int, int> src) {
    queue<pair<int, int>> Q;
    Q.push(src);
    fireDist[src.first][src.second] = 0;

    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        int x = u.first, y = u.second;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (!checkCell(xx, yy)) continue;
            if (fireDist[xx][yy] == INT_MAX) {
                fireDist[xx][yy] = fireDist[x][y] + 1;
                Q.push({xx, yy});
            }
        }
    }
}

void bfsJane(pair<int, int> src) {
    queue<pair<int, int>> Q;
    Q.push(src);
    janeDist[src.first][src.second] = 0;

    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        int x = u.first, y = u.second;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (!checkCell(xx, yy)) continue;
            if (janeDist[x][y] + 1 < fireDist[xx][yy]) {
                janeDist[xx][yy] = janeDist[x][y] + 1;
                Q.push({xx, yy});
            }
        }
    }
}

int solve() {
    int ret = INT_MAX;
    pair<int, int> jCell, fCell;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        if (grid[i][j] == 'F') fCell = {i, j};
        if (grid[i][j] == 'J') jCell = {i, j};
        fireDist[i][j] = janeDist[i][j] = INT_MAX;
    }

    bfsFire(fCell);
//    for (vector<unsigned char> v : fireDist) {
//        for (int x : v) cout << x << " ";
//        cout << endl;
//    }
    bfsJane(jCell);

    for (int j = 0; j < C; j++) {
        ret = min(ret, janeDist[0][j]);
        ret = min(ret, janeDist[R-1][j]);
    }
    for (int i = 0; i < R; i++) {
        ret = min(ret, janeDist[i][0]);
        ret = min(ret, janeDist[i][C-1]);
    }

    return ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        R = srcInt();
        C = srcInt();
        grid = vector<string>(R);
        for (string& s : grid) cin >> s;

        int ans = solve();
        printf("Case %d: %s\n", tc, ans == INT_MAX ? "IMPOSSIBLE" : to_string(ans+1).c_str());
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
