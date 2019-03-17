/*
        Problem Link : https://uva.onlinejudge.org/external/125/12532.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.010
        Rank : 187
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
#include <limits.h>
#include <algorithm>

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
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline int srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline int srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 100000

uint N, K;
int X[MAX + 7], minusBit[MAX + 7], zeroBit[MAX + 7];

void update(int *bit, int idx, int val) {
    while (idx <= N) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int read(int *bit, int idx) {
    int ret = 1;
    while (idx > 0) {
        ret += bit[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    int v;
    char ch, cmd;

    while (scanf("%u %u", &N, &K) == 2) {
        memset(minusBit, 0, sizeof minusBit);
        memset(zeroBit, 0, sizeof zeroBit);

        FOR(i, 1, N) {
            int val = srcInt();
            if (val == 0) update(zeroBit, i, 1);
            else if (val < 1) update(minusBit, i, 1);
            X[i] = val;
        }
        FOR(k, 1, K) {
            scanf("%c", &cmd);
            scanf("%c", &cmd);
            if (cmd == 'C') {
                i = srcInt();
                v = srcInt();
                if (v < 0) {
                    if (X[i] >= 0) update(minusBit, i, 1);
                    if (X[i] == 0) update(zeroBit, i, -1);
                } else if (v > 0) {
                    if (X[i] < 0) update(minusBit, i, -1);
                    if (X[i] == 0) update(zeroBit, i, -1);
                } else if (v == 0) {
                    if (X[i] != 0) update(zeroBit, i, 1);
                    if (X[i] < 0) update(minusBit, i, -1);
                }
                X[i] = v;
            } else {
                i = srcInt();
                j = srcInt();
                int cntZero = read(zeroBit, j) - read(zeroBit, i-1);
                if (cntZero > 0) {
                    ch = '0';
                } else {
                    int cntMinus = read(minusBit, j) - read(minusBit, i-1);
                    ch = cntMinus & 1 ? '-' : '+';
                }
                printf("%c", ch);
            }
        }
        printf("\n");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
