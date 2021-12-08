/*
        Problem Link : https://www.spoj.com/problems/SHPATH/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : RTE
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

int N;
vector<vector<PII>> G;
vector<int> dist;
map<string, int> cityMap;

int dijkstra(int s, int t) {
    dist = vector<int>(N+1, INT_MAX);
    dist[s] = 0;
    auto comp = [](PII p1, PII p2) {
        return p2.second > p2.second;
    };
    priority_queue<PII, vector<PII>, decltype(comp)> pq(comp);
    pq.push({s, 0});

    while (!pq.empty()) {
        PII p = pq.top(); pq.pop();
        int u = p.first;
        if (u == t) break;

        for (PII v : G[u]) {
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push({v.first, dist[v.first]});
            }
        }
    }
}

int solve(int s, int t) {
    dijkstra(s, t);
    return dist[t];
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    string str;
    int u, v, c;
    int nodeNum;
    string src, dest;

    TC = srcUInt();
    for (tc = 1; tc <= TC; tc++) {
        N = srcInt();
        getline(cin, str);
        G = vector<vector<PII>>(N+1);
        cityMap.clear();
        nodeNum = 0;
        for (int i = 0; i < N; i++) {
            getline(cin, str);
            cityMap[str] = ++nodeNum;
            int u = nodeNum;
            int p = srcInt();
            for (int j = 0; j < p; j++) {
                scanf("%d %d", &v, &c);
                G[u].push_back({v, c});
                G[v].push_back({u, c});
            }
            getline(cin, str);
        }
        int r = srcInt();
        getline(cin, str);
        for (int i = 0; i < r; i++) {
            cin >> src >> dest;
            int s = cityMap[src];
            int t = cityMap[dest];
            //cout << s << t << endl;
            printf("%d\n", solve(s, t));
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}