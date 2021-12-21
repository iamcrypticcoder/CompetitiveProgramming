/*
        Problem Link : https://www.spoj.com/problems/MARYBMW/
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
const int MAX_N     = int(5e4);

struct Edge {
    int u, v;
    LL w;
    Edge();
    Edge(int a, int b, LL c) : u(a), v(b), w(c) {}
    bool operator < (const Edge& o) const {
        return w > o.w;
    }
};

int N, M;
vector<Edge> edges, spanEdge;
vector<vector<pair<int, long long>>> G;

// -------------------- Disjoint Set Structure --------------------------------------
int dset[MAX_N+1];
void initSet(int N)     {   FOR(i, 0, N)    dset[i] = i;     }
int findSet(int u)      {   return dset[u] == u ? u : (dset[u] = findSet(dset[u]));    }
void unionSet(int u, int v){   dset[findSet(u)] = findSet(v); }
// ----------------------------------------------------------------------------------

void kruskal() {
    spanEdge.clear();
    sort(edges.begin(), edges.end());
    initSet(N);
    for(int i=0; i<edges.size(); i++) {
        if(findSet(edges[i].u) != findSet(edges[i].v)) {
            spanEdge.push_back(edges[i]);
            unionSet(edges[i].u, edges[i].v);
            //cout << edges[i].u << edges[i].v;
        }
    }
}

LL solve() {
    kruskal();
    // Make graph
    G = vector<vector<pair<int, long long>>>(N+1);
    for (int i = 0; i < spanEdge.size(); i++) {
        int u = spanEdge[i].u, v = spanEdge[i].v, c = spanEdge[i].w;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    vector<char> color = vector<char>(N+1, WHITE);
    vector<LL> dist = vector<LL>(N+1, LLONG_MAX);
    queue<int> q;
    q.push(1);
    color[1] = GRAY;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == N) break;
        for (auto v : G[u]) {
            if (color[v.first] == WHITE) {
                dist[v.first] = min(dist[u], v.second);
                q.push(v.first);
                color[v.first] = GRAY;
            }
        }
        color[u] = BLACK;
    }
    return dist[N] == LLONG_MAX ? -1 : dist[N];
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int u, v;
    LL c;

    TC = srcUInt();
    for (tc = 1; tc <= TC; tc++) {
        scanf("%d %d", &N, &M);
        edges.clear();
        for (int i = 0; i < M; i++) {
            scanf("%d %d %lld", &u, &v, &c);
            edges.push_back(Edge(u, v, c));
        }

        LL ans = solve();
        printf("%lld\n", ans);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
