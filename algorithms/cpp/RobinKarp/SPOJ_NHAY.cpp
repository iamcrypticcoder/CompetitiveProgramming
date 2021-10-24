/*
        Problem Link : https://www.spoj.com/problems/LITE/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.29
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

#define MAX 100000
#define BIG_PRIME 1000000009    // 1e9 + 9
#define VALUE_P 257

unsigned long long bigMod(unsigned long long a,
                          unsigned long long n,
                          unsigned long long m) {
    a = a % m;
    unsigned long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ret;
}

vector<int> RobinKarp(string txt, string pat) {
    vector<int> ret;
    int i, j;
    int N = txt.length();
    int M = pat.length();
    long long hashPat = 0;
    long long hashTxt = 0;
    long long h = (long long)bigMod(VALUE_P, M-1, BIG_PRIME);

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
    int i, j, k;
    int TC, tc;
    double cl = clock();

    int needleLen;
    string txt, pat;

    tc = 1;
    while (scanf("%d", &needleLen) == 1) {
        if (tc > 1) printf("\n");
        getchar();
        getline(cin, pat);
        getline(cin, txt);

        vector<int> indexes = RobinKarp(txt, pat);
        FOR(i, 0, indexes.size()-1) printf("%d\n", indexes[i]);
        tc++;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}