/*
        Problem Link : https://leetcode.com/problems/min-cost-to-connect-all-points/
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

#define SQR(x)          ((x)*(x))

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

const int INF       = int(1e9);
const double EPS    = double(1e-9);
const double TO_DEG = double(57.29577951);
const double PI     = 2*acos(0.0);
const int MAX_N     = int(1e5);

struct Edge {
    int u, v, w;
    Edge();
    Edge(int a, int b, int c) : u(a), v(b), w(c) {}
    bool operator < (const Edge& o) {
        return w < o.w;
    }
};

vector<int> dset;
void initSet(int N) {
    dset = vector<int>(N);
    for (int i = 0; i < N; i++) dset[i] = i;
}
int findSet(int u) {
    return dset[u] == u ? u : (dset[u] = findSet(dset[u]));
}
void unionSet(int u, int v) {
    dset[findSet(u)] = findSet(v);
}

int N;
vector<Edge> edges;

int kruskal() {
    int ret = 0;
    sort(edges.begin(), edges.end());
    initSet(N);
    int edgeTaken = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (edgeTaken == N-1) break;
        int u = edges[i].u, v = edges[i].v;
        if (findSet(u) != findSet(v)) {
            unionSet(u, v);
            ret += edges[i].w;
            edgeTaken++;
        }
    }
    return ret;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    N = points.size();
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back(Edge(i, j, d));
        }
    }

    int ans = kruskal();

    return ans;
}

int main() {
    //READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();



    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
