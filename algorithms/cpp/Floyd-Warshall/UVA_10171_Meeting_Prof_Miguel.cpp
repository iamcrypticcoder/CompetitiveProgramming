/*
        Problem Link : https://onlinejudge.org/external/101/10171.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
        Rank : 1132
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
const int MAX_N     = int(26);

int yGraph[MAX_N][MAX_N];
int mGraph[MAX_N][MAX_N];
int src, dest;

void resetGraph() {
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++) {
            yGraph[i][j] = (i == j ? 0 : INF);
            mGraph[i][j] = (i == j ? 0 : INF);
        }
}

void floydWarshall() {
    for (int k = 0; k < MAX_N; k++) {
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                yGraph[i][j] = min(yGraph[i][j], yGraph[i][k] + yGraph[k][j]);
                mGraph[i][j] = min(mGraph[i][j], mGraph[i][k] + mGraph[k][j]);
            }
        }
    }
}

vector<char> solve(int& minEnergy) {
    vector<char> ret;
    floydWarshall();
    minEnergy = INT_MAX;
    for (int i = 0; i < MAX_N; i++) {
        if (yGraph[src][i] != INF && mGraph[dest][i] != INF) {
            int d = yGraph[src][i] + mGraph[dest][i];
            if (d < minEnergy) {
                minEnergy = d;
                ret.clear();
                ret.push_back('A'+i);
            } else if (d == minEnergy) {
                ret.push_back('A'+i);
            }
        }
    }
    return ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();
    char age, dir, city1, city2;
    int u, v, c;
    int N;

    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        getchar();
        resetGraph();

        for (int i = 0; i < N; i++) {
            scanf("%c %c %c %c %d", &age, &dir, &city1, &city2, &c);
            getchar();
            u = city1 - 'A';
            v = city2 - 'A';
            if (age == 'Y') {
                yGraph[u][v] = min(yGraph[u][v], c);
                if (dir == 'B') yGraph[v][u] = min(yGraph[v][u], c);
            } else {
                mGraph[u][v] = min(mGraph[u][v], c);
                if (dir == 'B') mGraph[v][u] = min(mGraph[v][u], c);
            }
        }

        scanf("%c %c", &city1, &city2);
        src = city1 - 'A';
        dest = city2 - 'A';

        int minEnergy;
        auto list = solve(minEnergy);
        if (list.size() == 0) printf("You will never meet.\n");
        else {
            printf("%d", minEnergy);
            for (char ch : list) printf(" %c", ch);
            cout << endl;
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
