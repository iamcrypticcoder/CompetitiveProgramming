/*
        Problem Link : https://lightoj.com/problem/rider
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 53 ms
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

const int MAX = int(1e5);

int M, N;
vector<string> grid;
vector<vector<int>> visitCount;
int riderCount;
vector<pair<int, int>> ridersPos;
vector<int> ridersK;
vector<vector<vector<int>>> dist;
vector<pair<int, int>> reachCells;

bool onGrid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

void bfs(int riderIdx, int x, int y, int k) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    dist[riderIdx][x][y] = 0;
    visitCount[x][y]++;

    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        int x = u.first, y = u.second;

        for (int i = 0; i < 8; i++) {
            int xx = x + dxKnightMove[i];
            int yy = y + dyKnightMove[i];
            if (!onGrid(xx, yy)) continue;
            if (dist[riderIdx][x][y] + 1 < dist[riderIdx][xx][yy]) {
                dist[riderIdx][xx][yy] = dist[riderIdx][x][y] + 1;
                visitCount[xx][yy]++;
                Q.push({xx, yy});
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int d = dist[riderIdx][i][j];
            if (d != INT_MAX) {
                // Suppose dist = 9, k = 5, actual dist = 9/5 + (9%5 > 0)
                // Because total jump required = 9/5 + rest distance with one jump
                dist[riderIdx][i][j] = d / k + (d % k > 0);
            }
        }
    }
}

int solve() {
    ridersPos.clear();
    ridersK.clear();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (isdigit(grid[i][j])) {
                ridersPos.push_back({i, j});
                ridersK.push_back(grid[i][j] - '0');
            }
        }
    }
    riderCount = ridersPos.size();
    if (riderCount == 1) return 0;

    visitCount.assign(M, vector<int>(N, 0));
    dist.assign(riderCount, vector<vector<int>>(M, vector<int>(N, INT_MAX)));
    for (int i = 0; i < riderCount; i++) {
        bfs(i, ridersPos[i].first, ridersPos[i].second, ridersK[i]);
    }

//    for (auto v : visitCount) {
//        for (auto x : v) cout << x << " ";
//        cout << endl;
//    }

    int ret = INT_MAX;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visitCount[i][j] != riderCount) continue;
            int sum = 0;
            for (int k = 0; k < riderCount; k++) sum += dist[k][i][j];
            ret = min(ret, sum);
        }
    }

    return ret == INT_MAX ? -1 : ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        M = srcInt();
        N = srcInt();
        grid = vector<string>(M);
        for (auto& s : grid) cin >> s;

        int ans = solve();
        printf("Case %d: %d\n", tc, ans);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
