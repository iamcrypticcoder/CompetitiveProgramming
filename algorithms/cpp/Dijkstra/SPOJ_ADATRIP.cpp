/*
        Problem Link : https://www.spoj.com/problems/ADATRIP/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
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

int N, M, Q;
map<PII, int> edgeMap;
vector<vector<PII>> G;
vector<int> dist;

PII dijkstra(int src) {
    dist = vector<int>(N, INT_MAX);
    auto comp = [](PII p1, PII p2) {
        return p1.second > p2.second;
    };
    priority_queue<PII, vector<PII>, decltype(comp)> pq(comp);
    pq.push({src, 0});
    dist[src] = 0;

    int maxLen = 0;
    int cnt = 0;
    while (!pq.empty()) {
        PII u = pq.top(); pq.pop();
        if (u.second > maxLen) {
            maxLen = u.second;
            cnt = 1;
        } else if (u.second == maxLen) {
            cnt++;
        }
        for (PII v : G[u.first]) {
            if (dist[u.first] + v.second < dist[v.first]) {
                dist[v.first] = dist[u.first] + v.second;
                pq.push({v.first, dist[v.first]});
            }
        }
    }

    return {maxLen, cnt};
}

PII solve(int src) {
    return dijkstra(src);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int u, v, c;

    scanf("%d %d %d", &N, &M, &Q);
    G = vector<vector<PII>>(N);
    edgeMap.clear();
    for (int i = 0; i < M; i++) {
        u = srcInt();
        v = srcInt();
        c = srcInt();
        if (edgeMap.find({u, v}) != edgeMap.end())
            c = min(c, edgeMap[{u, v}]);
        edgeMap[{u, v}] = c;
        edgeMap[{v, u}] = c;
    }
    for (pair<PII, int> p : edgeMap) {
        u = p.first.first, v = p.first.second;
        c = p.second;
        //printf("edge = %d %d %d\n", u, v, c);
        G[u].push_back({v, c});
    }

    for (int i = 0; i < Q; i++) {
        int q = srcInt();
        PII ans = solve(q);
        printf("%d %d\n", ans.first, ans.second);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}