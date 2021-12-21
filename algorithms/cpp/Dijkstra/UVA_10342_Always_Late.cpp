/*
        Problem Link : https://onlinejudge.org/external/103/10342.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
        Rank : 283
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
    int node, dist;
    State();
    State(int a, int b) : node(a), dist(b) {}
    bool operator < (const State& o) const {
        return dist > o.dist;
    }
};

int N, R, Q;
vector<vector<PII>> G;

void dijkstra(int src, int dest, vector<pair<int, int>>& dist) {
    dist = vector<pair<int, int>>(N, {INT_MAX, INT_MAX});
    dist[src] = {0, INT_MAX};
    priority_queue<State> pq;
    for (PII v : G[src]) {
        pq.push(State(v.first, v.second));
    }

    while (!pq.empty()) {
        State u = pq.top(); pq.pop();

        // If dist matched with shortest, no nothing
        if (u.dist == dist[u.node].first) continue;

        // If shortest distance isn't found yet.
        if (dist[u.node].first == INT_MAX) {
            dist[u.node].first = u.dist;
        } else {
            // If new shortest dist found
            if (u.dist < dist[u.node].first) {
                dist[u.node].second = dist[u.node].first;
                dist[u.node].first = u.dist;
            } else if (dist[u.node].second == INT_MAX || u.dist < dist[u.node].second) {
                // If new 2nd shortest found
                dist[u.node].second = u.dist;
            } else continue;
        }

        for (PII v : G[u.node]) {
            pq.push(State(v.first, u.dist + v.second));
        }
    }
}

int secondShortest(int src, int dest) {
    vector<pair<int, int>> dist;
    dijkstra(src, dest, dist);
//    for (int i = 0; i < dist.size(); i++) {
//        printf("%d -> %d %d\n", i, dist[i].first, dist[i].second);
//    }
    return dist[dest].second;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int u, v, c;

    tc = 1;
    while (scanf("%d %d", &N, &R) == 2) {
        G = vector<vector<PII>>(N);
        for (int i = 0; i < R; i++) {
            scanf("%d %d %d", &u, &v, &c);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }

        printf("Set #%d\n", tc++);
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            scanf("%d %d", &u, &v);
            int ans = secondShortest(u, v);
            if (ans == INT_MAX) printf("?\n");
            else printf("%d\n", ans);
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
