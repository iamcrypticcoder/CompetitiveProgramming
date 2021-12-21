/*
        Problem Link : https://onlinejudge.org/external/107/10724.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
        Rank : 320
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
const int MAX_N     = int(50);

int N, M;
pair<int, int> points[MAX_N+1];
double adjMat[MAX_N+1][MAX_N+1];
double resultMat1[MAX_N+1][MAX_N+1];
double resultMat2[MAX_N+1][MAX_N+1];

double dist2d(pair<int, int> p1, pair<int, int> p2) {
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

bool isEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

void resetGraph() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            adjMat[i][j] = (i == j ? 0.0 : INF);
}

void floydWarshall(double resultMat[][MAX_N+1]) {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                resultMat[i][j] = min(resultMat[i][j], resultMat[i][k] + resultMat[k][j]);
}

double calcCost() {
    double ret = 0.0;
    for (int i = 1; i <= N; i++)
        for (int j = i+1; j <= N; j++)
            ret += (resultMat1[i][j] - resultMat2[i][j]);
    return ret;
}

bool solve(int& u, int& v) {
    memcpy(resultMat1, adjMat, sizeof adjMat);
    floydWarshall(resultMat1);

    double maxCost = 0.0;
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            if (false == isEqual(adjMat[i][j], INF)) continue;

            memcpy(resultMat2, adjMat, sizeof adjMat);
            resultMat2[i][j] = resultMat2[j][i] = dist2d(points[i], points[j]);
            floydWarshall(resultMat2);

            double c = calcCost();
            if (c > maxCost) {
                u = i;
                v = j;
                maxCost = c;
            }
        }
    }
    return isEqual(maxCost, 0.0) ? false : true;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    int x, y, u, v;

    while(scanf("%d %d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        for (int i = 1; i <= N; i++) {
            scanf("%d %d", &x, &y);
            points[i] = {x, y};
        }
        resetGraph();
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &u, &v);
            int d = dist2d(points[u], points[v]);
            adjMat[u][v] = adjMat[v][u] = d;
        }

        bool ans = solve(u, v);
        if (ans) printf("%d %d\n", u, v);
        else printf("No road required\n");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
