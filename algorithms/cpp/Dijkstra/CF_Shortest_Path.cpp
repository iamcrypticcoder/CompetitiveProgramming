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

const int MAX_N = int(1e3);

struct Triplet {
    int x, y, z;
    Triplet(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    bool operator==(const Triplet& o) const {
        return (x == o.x && y == o.y && z == o.z);
    };
};
namespace std {
    template<> struct hash<Triplet> {
        std::size_t operator()(const Triplet& p) const noexcept {
            unsigned long long ret = 0;
            ret = (ret * 31) + p.x;
            ret = (ret * 31) + p.y;
            ret = (ret * 31) + p.z;
            return ret;
        }
    };
}
struct State {
    int node, prevNode, dist;
    State();
    State(int a, int b, int c) : node(a), prevNode(b), dist(c) {}
    bool operator < (const State& o) const {
        return dist > o.dist;
    }
};

int N, M, K;
vector<vector<int>> G;
vector<int> parent, dist;
unordered_set<Triplet> forbids;
vector<vector<bool>> visited;

void bfs() {
    visited.assign(MAX_N+1, vector<bool>(MAX_N+1, false));
    dist.assign(N+1, INT_MAX);
    parent.assign(N+1, -1);
    priority_queue<State> pq;
    pq.push(State(1, -1, 0));
    dist[1] = 0;

    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        if (u.node == N) break;
        int a = u.prevNode, b = u.node;
        for (int v : G[u.node]) {
            int c = v;
            if (forbids.find({a, b, c}) != forbids.end()) continue;

            if (dist[u.node] + 1 < dist[v]) {
                dist[v] = dist[u.node] + 1;
                parent[v] = u.node;
                pq.push(State(v, u.node, dist[v]));
            }
        }
    }
}

void makePath(int u, vector<int>& path) {
    if (parent[u] != -1) makePath(parent[u], path);
    path.push_back(u);
}

vector<int> solve() {
    bfs();
    vector<int> path;
    if (dist[N] == INT_MAX) return path;
    makePath(N, path);
    return path;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int a, b, c, u, v;

    cin >> N >> M >> K;
    G = vector<vector<int>>(N+1);
    for (int i = 0; i < M; i++) {
        u = srcInt();
        v = srcInt();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c;
        forbids.insert({a, b, c});
    }

    vector<int> path = solve();
    if (path.size() == 0) cout << "-1\n";
    else {
        cout << path.size()-1 << endl;
        for (int x : path) cout << x << " ";
        cout << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}