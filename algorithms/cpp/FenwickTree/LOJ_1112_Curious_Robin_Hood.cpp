/*
        Problem Link : https://lightoj.com/problem/curious-robin-hood
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

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

const int MAX_N = int(1e5);

int N, Q;
vector<int> A;
vector<int> bit;

void add(int idx, int delta) {
    while (idx < N) {
        bit[idx] += delta;
        idx = idx | (idx+1);
    }
}

void build() {
    bit = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
        add(i, A[i]);
}

int sum(int r) {
    int ret = 0;
    while (r >= 0) {
        ret += bit[r];
        r = (r & (r+1)) - 1;
    }
    return ret;
}

int rsq(int l, int r) {
    return sum(r) - sum(l-1);
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    int TC, tc;
    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        printf("Case %d:\n", tc);
        N = srcInt();
        Q = srcInt();
        A = vector<int>(N);
        for (int i = 0; i < N; i++)
            A[i] = srcInt();
        build();

        for (int q = 1; q <= Q; q++) {
            int cmd = srcInt();
            if (cmd == 1) {
                int i = srcInt();
                printf("%d\n", A[i]);
                add(i, -A[i]);
                A[i] = 0;
            }
            if (cmd == 2) {
                int i = srcInt();
                int v = srcInt();
                add(i, v);
                A[i] += v;
            }
            if (cmd == 3) {
                int i = srcInt();
                int j = srcInt();
                printf("%d\n", rsq(i, j));
            }
        }
    }


    return 0;
}

/**

*/