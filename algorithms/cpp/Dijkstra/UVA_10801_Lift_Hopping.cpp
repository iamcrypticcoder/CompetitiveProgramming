/*
        Problem Link : https://onlinejudge.org/external/108/10801.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
        Rank : 1269
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

struct State {
    int node, elev;
    LL dist;
    State();
    State(int n, int e, LL d) : node(n), elev(e), dist(d) {}
    bool operator < (const State& o) const {
        return dist > o.dist;
    }
};

struct Edge {
    int node, elev, cost;
    Edge();
    Edge(int a, int b, int c) : node(a), elev(b), cost(c) {}
};

int N = 100;
int K;
vector<vector<Edge>> G;

LL dijkstra(int src) {
    vector<LL> dist = vector<LL>(N, LLONG_MAX);
    dist[src] = 0;
    priority_queue<State> pq;
    bool used[5] = { false };
    for (Edge e : G[0]) {
        if (false == used[e.elev]) {
            pq.push(State(src, e.elev, 0));
            used[e.elev] = true;
        }
    }

    while (!pq.empty()) {
        State u = pq.top(); pq.pop();

        if (u.node == K) {
//            for (int i = 0; i < N; i++) printf("%d -> %lld\n", i, dist[i]);
//            cout << endl;
            return u.dist;
        }

        for (Edge e : G[u.node]) {
            // Go through same elevator
            if (u.elev == e.elev) {
                if (u.dist + e.cost < dist[e.node]) {
                    dist[e.node] = u.dist + e.cost;
                    pq.push(State(e.node, e.elev, dist[e.node]));
                }
            } else {
                if (u.dist + e.cost + 60 < dist[e.node]) {
                    dist[e.node] = u.dist + e.cost + 60;
                    pq.push(State(e.node, e.elev, dist[e.node]));
                }
            }
        }
    }

    return dist[K];
}

LL solve() {
    return dijkstra(0);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    uint TC, tc;
    double cl = clock();
    string line;
    int u, v;
    int n;

    while (scanf("%d %d", &n, &K) == 2) {
        vector<int> ti = vector<int>(n);
        for (int &x: ti) x = srcInt();
        getchar();

        G = vector<vector<Edge>>(100);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            stringstream ss(line);
            vector<int> floors;
            while (ss >> u) floors.emplace_back(u);
            for (int j = 0; j < floors.size(); j++) {
                int u = floors[j];
                for (int k = j+1; k < floors.size(); k++) {
                    int v = floors[k];
                    G[u].push_back(Edge(v, i, (v - u) * ti[i]));
                    G[v].push_back(Edge(u, i, (v - u) * ti[i]));
                }
            }
        }

        LL ans = solve();
        printf("%s\n", ans == LLONG_MAX ? "IMPOSSIBLE" : to_string(ans).c_str());
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
