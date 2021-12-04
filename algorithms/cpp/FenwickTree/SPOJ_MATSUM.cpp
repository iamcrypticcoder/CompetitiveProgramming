/*
        Problem Link : https://www.spoj.com/problems/MATSUM/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.58
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

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;

const int MAX_N = 1024;

int N;
vector<vector<int>> A;
vector<vector<LL>> bit;

LL sum(int x, int y) {
    LL ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit[i][j];
    return ret;
}

LL rsq(int i, int j, int k, int l) {
    LL ret = sum(k, l);
    if (i-1 >= 0) ret -= sum(i-1, l);
    if (j-1 >= 0) ret -= sum(k, j-1);
    if (i-1 >= 0 && j-1 >= 0) ret += sum(i-1,j-1);
    return ret;
}

void add(int x, int y, int delta) {
    for (int i = x; i < N; i = i | (i + 1))
        for (int j = y; j < N; j = j | (j + 1))
            bit[i][j] += delta;
}

void init() {
    A = vector<vector<int>>(N, vector<int>(N, 0));
    bit = vector<vector<LL>>(N, vector<LL>(N, 0));
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    char cmd[4];
    int x, y, num;
    int x1, y1, x2, y2;

    int TC = srcInt();
    for (int tc = 1; tc <= TC; tc++) {
        N = srcInt();
        init();
        char cmd[4];
        while (scanf("%s", cmd) == 1) {
            if (strcmp(cmd, "END") == 0) break;
            if (strcmp(cmd, "SET") == 0) {
                scanf("%d %d %d", &x, &y, &num);
                add(x, y, num - A[x][y]);
                A[x][y] = num;
            } else if (strcmp(cmd, "SUM") == 0) {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                printf("%lld\n", rsq(x1, y1, x2, y2));
            }
        }
        if (tc < TC) printf("\n");
    }
    return 0;
}

/*
Input:

1
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END



 */
