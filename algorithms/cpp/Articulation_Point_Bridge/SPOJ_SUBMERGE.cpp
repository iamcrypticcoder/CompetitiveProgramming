/*
        Problem Link :
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : [AC, WA, TLE, RTE]
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

const int MAX = int(1e5);

int N, M;
vector<vector<int>> G;
vector<int> color;
vector<int> dfsNum, dfsLow, parent;
vector<bool> articulationVertex;
int nodeNum, dfsRoot, rootChildren;

void articulationPoint(int u) {
    dfsNum[u] = dfsLow[u] = nodeNum++;
    color[u] = GRAY;
    for (int v : G[u]) {
        if (color[v] == WHITE) {
            parent[v] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPoint(v);
            if (dfsLow[v] >= dfsNum[u]) articulationVertex[u] = true;
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        } else if (v != parent[u]) {
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
        }
    }
}

int solve() {
    dfsNum = vector<int>(N+1);
    dfsLow = vector<int>(N+1);
    parent = vector<int>(N+1);
    color = vector<int>(N+1, WHITE);
    articulationVertex = vector<bool>(N+1, false);

    nodeNum = 0;
    for (int i = 1; i <= N; i++) {
        if (color[i] == WHITE) {
            dfsRoot = i;
            rootChildren = 0;
            articulationPoint(i);
            articulationVertex[dfsRoot] = (rootChildren > 1);
        }
    }

    int ret = 0;
    for (bool x : articulationVertex) if (x) ret++;
    return ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int u, v;

    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        G = vector<vector<int>>(N+1);
        for (int i = 0; i < M; i++) {
            u = srcInt();
            v = srcInt();
            G[u].push_back(v);
            G[v].push_back(u);
        }

        printf("%d\n", solve());
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}