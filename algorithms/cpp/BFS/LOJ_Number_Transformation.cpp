/*
        Problem Link : https://lightoj.com/problem/number-transformation
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 62 ms
        Rank :
        Complexity:
*/


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
#include <limits.h>
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

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int MAX_NODE = int(1e3 + 7);

vector<int> findPrimeFactors(int num) {
    vector<int> ret;
    int n = num;
    int root = (int)sqrt(n);
    for (int i = 2; i <= root; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ret.push_back(i);
        }
    }
    if (n > 1 && n != num) ret.push_back(n);
    return ret;
}

int bfs(int s, int t) {
    vector<char> color = vector<char>(MAX_NODE, WHITE);
    vector<int> dist = vector<int>(MAX_NODE, INT_MAX);
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;
    color[s] = GRAY;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;
        vector<int> pfs = findPrimeFactors(u);
        for (int i = 0; i < pfs.size(); i++) {
            int v = u + pfs[i];
            if (v > 1000) continue;
            if (color[v] == WHITE) {
                dist[v] = dist[u] + 1;
                Q.push(v);
                color[v] = GRAY;
            }
        }
        color[u] = BLACK;
    }

    return dist[t];
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        int s = srcInt();
        int t = srcInt();

        int ans = bfs(s, t);
        printf("Case %d: %d\n", tc, ans == INT_MAX ? -1 : ans);
    }


    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
