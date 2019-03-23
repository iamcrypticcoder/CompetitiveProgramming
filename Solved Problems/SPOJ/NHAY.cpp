/*
        Problem Link : https://www.spoj.com/problems/NHAY/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.28
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
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
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
#define BIG_PRIME 1000000009    // 1e9 + 9
#define VALUE_P 257

ULL bigMod(ULL a, ULL n, ULL m) {
    a = a % m;
    ULL ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ret;
}

VI RobinKarp(string txt, string pat) {
    VI ret;
    int i, j;
    int N = txt.length();
    int M = pat.length();
    LL hashPat = 0;
    LL hashTxt = 0;
    LL h = (LL)bigMod(VALUE_P, M-1, BIG_PRIME);

    for (int i = 0; i < M; i++) {
        hashPat = (VALUE_P * hashPat + pat[i]) % BIG_PRIME;
        hashTxt = (VALUE_P * hashTxt + txt[i]) % BIG_PRIME;
    }

    for (i = 0; i <= N-M; ++i) {
        if (hashPat == hashTxt) {
            for (j = 0; j < M; ++j)
                if (txt[i+j] != pat[j]) break;
            if (j == M) {
                ret.PB(i);
            }
        }

        if (i < N-M) {
            hashTxt = (VALUE_P * (hashTxt - txt[i]*h) + txt[i+M]) % BIG_PRIME;
            if (hashTxt < 0) hashTxt += BIG_PRIME;
        }
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

    int needleLen;
    string txt, pat;

    tc = 1;
    while (scanf("%d", &needleLen) == 1) {
        if (tc > 1) printf("\n");
        getchar();
        getline(cin, pat);
        getline(cin, txt);

        VI indexes = RobinKarp(txt, pat);
        FOR(i, 0, indexes.size()-1) printf("%d\n", indexes[i]);
        tc++;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
