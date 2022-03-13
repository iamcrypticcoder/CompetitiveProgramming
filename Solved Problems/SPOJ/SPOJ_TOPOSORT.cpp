/*
        Problem Link : https://www.spoj.com/problems/TOPOSORT/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : [AC, WA, TLE, RTE]
        Time : 0.18
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

int allBits()               { return ((1 << 31) - 1);     }
int negBits(int n)          { return n ^ ((1 << 31) - 1); }
bool checkBit(int n, int i) { return (n & (1 << i));      }
int setBit(int n, int i)    { return (n | (1 << i));      }
int clearBit(int n, int i)  { return (n & ~(1 << i));     }
int flipBit(int n, int i)   { return (n ^ (1 << i));      }
bool isPower2(int n)        { return (n && !(n & (n-1))); }

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

int n, m;
vector<vector<int>> adjMat;

vector<int> kahnsAlgo() {
    vector<int> inDeg(n+1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : adjMat[u]) inDeg[v]++;
    }

    // Push all nodes with 0 in degree
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int u = 1; u <= n; u++)
        if (inDeg[u] == 0) Q.push(u);

    vector<int> ret;
    int visited = 0;
    while (!Q.empty()) {
        int u = Q.top();
        Q.pop();
        ret.push_back(u);
        for (int v : adjMat[u]) {
            inDeg[v]--;
            if (inDeg[v] == 0) Q.push(v);
        }
        visited++;
    }

    // If all nodes aren't traversed, it means cycle exists
    if (visited != n) return vector<int>();

    return ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    int u, v;

    scanf("%d %d", &n, &m);
    adjMat = vector<vector<int>>(n+1);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adjMat[u].push_back(v);
    }

    vector<int> ans = kahnsAlgo();
    if (ans.empty()) printf("Sandro fails.\n");
    else {
        printf("%d", ans[0]);
        for (int i = 1; i < (int)ans.size(); i++)
            printf(" %d", ans[i]);
        printf("\n");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
