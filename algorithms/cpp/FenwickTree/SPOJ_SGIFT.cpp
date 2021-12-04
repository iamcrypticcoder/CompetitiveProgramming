/*
        Problem Link : https://www.spoj.com/problems/SGIFT/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
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
const int MAX_Q = int(1e5);

int N, Q;
int A[MAX_N + 7];
LL csum[MAX_N + 7];

void calcPrefixSum() {
    csum[0] = A[0];
    for (int i = 1; i < N; i++)
        csum[i] = csum[i-1] + A[i];
}

LL solve(int i, int j) {
    if (i == 0) return csum[j-1];
    return csum[j-1] - csum[i-1];
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    N = srcInt();
    for (int i = 0; i < N; i++)
        A[i] = srcInt();
    Q = srcInt();

    sort(A, A + N);
    calcPrefixSum();

    for (int q = 1; q <= Q; q++) {
        int a = srcInt();
        int b = srcInt();

        int i = lower_bound(A, A + N, a) - A;
        int j = upper_bound(A, A + N, b) - A;
        //printf("i = %d, j = %d\n", i, j);

        printf("%lld\n", solve(i, j));
    }

    return 0;
}
