/*
        Problem Link : https://www.spoj.com/problems/ADASEA/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :  4.53
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
#include <limits.h>
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

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int MAX_N = int(1e5);

int N, M;
vector<string> grid;
vector<vector<bool>> visited;

bool onGrid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

pair<LL, LL> reduceFractions(pair<LL, LL> f) {
    long long g = GCD(f.first, f.second);
    return {f.first / g, f.second / g};
}

void dfs(int x, int y, int &islandSize) {
    visited[x][y] = true;
    islandSize++;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!onGrid(xx, yy)) continue;
        if (visited[xx][yy] || grid[xx][yy] == '~') continue;
        dfs(xx, yy, islandSize);
    }
}

pair<LL, LL> solve() {
    vector<pair<LL, LL>> fractions;
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == false && grid[i][j] == '#') {
                int islandSize = 0;
                dfs(i, j, islandSize);
                long long up = (LL)islandSize * islandSize;
                long long down = N * M;
                fractions.push_back(reduceFractions({up, down}));
            }
        }
    }

    long long lcm = 1;
    for (pair<LL, LL> x : fractions) lcm = LCM(lcm, x.second);
    long long up = 0;
    long long down = lcm;
    for (pair<LL, LL> x : fractions) up += ((lcm / x.second) * x.first);

    pair<LL, LL> ret = reduceFractions({up, down});
    return ret;
}

int main() {
    READ("../input.txt");
    // WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        N = srcInt();
        M = srcInt();
        grid = vector<string>(N);
        for (string& s : grid) cin >> s;

        pair<LL, LL> ans = solve();
        if (ans.first == ans.second) printf("1\n");
        else if (ans.second == 1) printf("%lld\n", ans.first);
        else printf("%lld / %lld\n", ans.first, ans.second);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
