/*
        Problem Link : https://lightoj.com/problem/points-in-rectangle
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

const int MAX_N = int(1e3+7);

int n, m;
vector<vector<bool>> A;
vector<vector<int>> bit;

int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit[i][j];
    return ret;
}

int rsq(int i, int j, int k, int l) {
    int ret = sum(k, l);
    if (i-1 >= 0) ret -= sum(i-1, l);
    if (j-1 >= 0) ret -= sum(k, j-1);
    if (i-1 >= 0 && j-1 >= 0) ret += sum(i-1,j-1);
    return ret;
}

void add(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < m; j = j | (j + 1))
            bit[i][j] += delta;
}

void build() {
    n = m = MAX_N;
    A = vector<vector<bool>>(n, vector<bool>(m, false));
    bit = vector<vector<int>>(n, vector<int>(m, 0));
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    int tc, TC;
    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        printf("Case %d:\n", tc);

        build();

        int Q = srcInt();
        for (int q = 1; q <= Q; q++) {
            int cmd = srcInt();
            if (cmd == 0) {
                int x = srcInt();
                int y = srcInt();
                if (false == A[x][y]) {
                    A[x][y] = true;
                    add(x, y, 1);
                }
            }
            if (cmd == 1) {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("%d\n", rsq(x1, y1, x2, y2));
            }
        }
    }

    return 0;
}

/**

1
9
0 1 1
0 2 6
1 1 1 6 6
1 2 2 5 5
0 5 5
1 0 0 6 5
0 3 3
0 2 6
1 2 1 10 10

*/