/*
        Problem Link : https://www.spoj.com/problems/EAGLE1/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : WA
        Time :
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

const int MAX_N = int(1e5);

int N;
vector<vector<PII>> G;
vector<int> nodeSeq;
vector<int> edgeSeq;
vector<bool> visited;

void dfs(int u, vector<int>& nodes, vector<LL>& edges) {
    visited[u] = true;
    nodes.push_back(u);
    for (int i = 0; i < G[u].size(); i++) {
        PII v = G[u][i];
        if (visited[v.first] == false) {
            edges.push_back(v.second);
            dfs(v.first, nodes, edges);
        }
    }
}

vector<LL> solve() {
    int oneEnd, otherEnd;
    for (int u = 1; u <= N; u++) {
        if (G[u].size() == 1) {
            oneEnd = u;
            break;
        }
    }
    vector<int> nodes;
    vector<LL> edges;
    visited = vector<bool>(N+1, false);
    edges.push_back(0);
    dfs(oneEnd, nodes, edges);

    for (int i = 1; i < edges.size(); i++)
        edges[i] += edges[i-1];
    int sum = edges[edges.size()-1];

    vector<LL> ret = vector<LL>(N);
    for (int i = 0; i < N; i++) {
        int u = nodes[i];
        ret[u-1] = max(edges[i], sum - edges[i]);
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
        N = srcInt();
        G = vector<vector<PII>>(N+1);
        for (int i = 1; i <= N-1; i++) {
            int u = srcInt();
            int v = srcInt();
            int d = srcInt();
            G[u].push_back({v, d});
            G[v].push_back({u, d});
        }

        vector<LL> ret = solve();
        for (auto x : ret) printf("%d ", x);
        cout << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
