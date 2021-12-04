/*
        Problem Link : https://www.spoj.com/problems/SUMSUM/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 3.47
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

using namespace std;

#define ALL_BITS                                ((1 << 31) - 1)
#define NEG_BITS(mask)                          (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)                       (mask & (1 << i))
#define ON_BIT(mask, i)                         (mask |= (1 << i))
#define OFF_BIT(mask, i)                        (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                         (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)                (x & (x-1))

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;

const int MAX_N = int(1e5);

int N, Q;
int A[MAX_N + 7];
int bit[28][MAX_N];

void add(int i, int idx, int delta) {
    while (idx < N) {
        bit[i][idx] += delta;
        idx = idx | (idx+1);
    }
}

void init() {
    memset(bit, 0, sizeof bit);
    for (int i = 0; i < N; i++) {
        for (int b = 0; b < 28; b++) {
            if (TEST_BIT(A[i], b)) add(b, i, 1);
        }
    }
}

int sum(int b, int r) {
    int ret = 0;
    while (r >= 0) {
        ret += bit[b][r];
        r = (r & (r+1)) - 1;
    }
    return ret;
}

int rsq(int b, int l, int r) {
    return sum(b, r) - sum(b, l-1);
}

void command1(int i, int x) {
    for (int b = 0; b < 28; b++)
        if (TEST_BIT(A[i], b)) add(b, i, -1);
    A[i] = x;
    for (int b = 0; b < 28; b++)
        if (TEST_BIT(A[i], b)) add(b, i, 1);
}

LL command2(string op, int i1, int i2) {
    if (i1 == i2) return 0;
    LL ret = 0;
    LL n = (i2 - i1 + 1);
    LL totalPairs = (n * (n-1)) / 2;
    LL activePairs;
    for (int b = 0; b < 28; b++) {
        LL cntOne = rsq(b, i1, i2);
        LL cntZero = n - cntOne;

        if (op == "XOR") {
            activePairs = cntOne * cntZero;
        }
        if (op == "OR") {
            LL zeroPairs = (cntZero * (cntZero-1)) / 2;
            activePairs = totalPairs - zeroPairs;
        }
        if (op == "AND") {
            activePairs = (cntOne * (cntOne-1)) / 2;
        }
        ret += (activePairs * (1 << b));
    }
    return ret;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    string op;

    N = srcInt();
    Q = srcInt();
    for (int i = 0; i < N; i++)
        A[i] = srcInt();

    init();

    for (int q = 1; q <= Q; q++) {
        int cmd = srcInt();
        if (cmd == 1) {
            int x = srcInt();
            int i = srcInt();
            command1(i-1, x);
        }
        if (cmd == 2) {
            cin >> op;
            int i1 = srcInt();
            int i2 = srcInt();
            printf("%lld\n", command2(op, i1-1, i2-1));
        }
    }

    return 0;
}
