/*
        Problem Link : https://onlinejudge.org/external/113/11367.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.040
        Rank : 1299
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

const int MAX_N = int(1000);    // Max number of node
const int MAX_C = int(100);     // Max fuel capacity

struct State {
    int node, fuel, dist;
    State();
    State(int a, int b, int c) : node(a), fuel(b), dist(c) {}
    bool operator < (const State& o) const {
        return dist > o.dist;
    }
};

int N, M, Q;
vector<int> fuelPrice;
vector<vector<PII>> G;

int dijkstra(int src, int dest, int capacity) {
    vector<vector<int>> dist;       // {node, fuel} -> dist
    dist.assign(N, vector<int>(capacity+1, INT_MAX));
    priority_queue<State> pq;
    dist[src][0] = 0;
    pq.push({src, 0, 0});

    while (!pq.empty()) {
        State u = pq.top(); pq.pop();

        if (u.node == dest) {
            return u.dist;
        }

        // For remaining space of tank, pour 1 liter each time and try to go next node
        for (int curFuel = u.fuel; curFuel <= capacity; curFuel++) {
            for (PII p : G[u.node]) {
                if (p.second > curFuel) continue;
                int addFuelCost = (curFuel - u.fuel) * fuelPrice[u.node];
                int vNode = p.first, vFuel = curFuel - p.second;

                if (u.dist + addFuelCost < dist[vNode][vFuel]) {
                    State v = State(p.first, curFuel - p.second, u.dist + addFuelCost);
                    dist[vNode][vFuel] = u.dist + addFuelCost;
                    pq.push(v);
                }
            }
        }
    }
    return INT_MAX;
}

int solve(int src, int dest, int capacity) {
    return dijkstra(src, dest, capacity);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int u, v, c;

    scanf("%d %d", &N, &M);
    fuelPrice = vector<int>(N);
    G = vector<vector<PII>>(N);
    for (int& x : fuelPrice) x = srcInt();
    for (int i = 0; i < M; i++) {
        u = srcInt();
        v = srcInt();
        c = srcInt();
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    Q = srcInt();
    for (int i = 0; i < Q; i++) {
        int src, dest, capacity;
        scanf("%d %d %d", &capacity, &src, &dest);
        int ans = solve(src, dest, capacity);
        printf("%s\n", ans == INT_MAX ? "impossible" : to_string(ans).c_str());
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
