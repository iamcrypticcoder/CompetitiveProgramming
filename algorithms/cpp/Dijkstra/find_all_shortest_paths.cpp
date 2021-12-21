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

struct State {
    int node, dist;
    State();
    State(int a, int b) : node(a), dist(b) {}
    bool operator < (const State& o) const {
        return dist > o.dist;
    }
};

int N, M;
vector<vector<PII>> G;
vector<vector<int>> parents;

void dijkstra(int src) {
    vector<int> dist = vector<int>(N, INT_MAX);
    parents = vector<vector<int>>(N);
    priority_queue<State> pq;
    dist[src] = 0;
    pq.push(State(src, 0));
    parents[src] = {-1};

    while (!pq.empty()) {
        State u = pq.top(); pq.pop();

        for (PII v : G[u.node]) {
            int d = u.dist + v.second;
            if (d < dist[v.first]) {
                dist[v.first] = d;
                pq.push(State(v.first, d));
                parents[v.first].clear();
                parents[v.first].push_back(u.node);
            } else if (d == dist[v.first]) {
                parents[v.first].push_back(u.node);
            }
        }
    }
}

void makeAllPaths(int u, vector<int>& path, vector<vector<int>>& paths) {
    if (u == -1) {
        vector<int> v = vector<int>(path.rbegin(), path.rend());
        paths.push_back(v);
        return;
    }
    path.push_back(u);
    for (int x : parents[u]) {
        makeAllPaths(x, path, paths);
    }
    path.pop_back();
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int u, v, c;
    int src, dest;

    while (cin >> N >> M) {
        G = vector<vector<PII>>(N);
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &c);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }

        scanf("%d %d", &src, &dest);
        dijkstra(src);
        vector<vector<int>> paths;
        vector<int> path;
        makeAllPaths(dest, path, paths);
        printf("Number of paths = %d\n", paths.size());
        for (vector<int> v : paths) {
            for (int x : v) printf("%d ", x);
            cout << endl;
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**

Input:
8 10
0 1 4
0 2 5
0 3 10
0 7 20
1 4 4
2 5 5
3 6 1
4 7 4
5 7 2
6 7 1
0 7

Output:
Number of paths = 3
0 1 4 7
0 2 5 7
0 3 6 7

*/