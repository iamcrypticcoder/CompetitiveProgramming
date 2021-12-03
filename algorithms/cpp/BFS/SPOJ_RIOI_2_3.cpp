/*
        Problem Link : https://www.spoj.com/problems/RIOI_2_3/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.70
        Rank :
        Complexity:
*/

#define _CRT_SECURE_NO_WARNINGS

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
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

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

long long GCD(long long a, long long b) { while (b)b ^= a ^= b ^= a %= b;  return a; }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

// Input Methods
inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

const char WHITE = 0;
const char GRAY = 1;
const char BLACK = 2;

const int MAX = int(50);

int N;
pair<int, int> src, dest;
vector<vector<int>> grid;
int dist[MAX][MAX][1 << 10];

bool onGrid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int calcMask(int n) {
    int ret = 0;
    while (n) {
        ret += (n & 1);
        n /= 2;
    }
    return ret;
}

int bfs(int x, int y) {
    int ret = INT_MAX;
    int mask = 0;

    memset(dist, -1, sizeof dist);
    queue<vector<int>> Q;
    ON_BIT(mask, grid[x][y]);
    Q.push({x, y, mask});
    dist[x][y][mask] = calcMask(mask);

    while (!Q.empty()) {
        vector<int> u = Q.front(); Q.pop();
        int x = u[0], y = u[1], mask = u[2];

        if (make_pair(x, y) == dest) {
            ret = min(ret, dist[x][y][mask]);
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (!onGrid(xx, yy)) continue;
            int newMask = mask | (1 << grid[xx][yy]);
            if (dist[xx][yy][newMask] == -1) {
                dist[xx][yy][newMask] = calcMask(newMask);
                Q.push({xx, yy, newMask});
            }
        }
    }
    return ret;
}

int solve() {
    int ans = bfs(src.first, src.second);

//    for (vector<int> v : dist) {
//        for (int x : v) cout << x << " ";
//        cout << endl;
//    }

    return ans;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    TC = srcUInt();
    for (tc = 1; tc <= TC; tc++) {
        N = srcInt();
        grid = vector<vector<int>>(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int& x : grid[i]) cin >> x;
        }
        scanf("%d %d", &src.first, &src.second);
        scanf("%d %d", &dest.first, &dest.second);

        int ans = solve();
        printf("%d\n", ans);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
