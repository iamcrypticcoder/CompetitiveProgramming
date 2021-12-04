/*
        Problem Link : https://onlinejudge.org/external/120/12086.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.550
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

const int MAX_N = int(2e5);

int N;
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

    char cmd;
    int a, b;

    int tc = 1;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        if (tc > 1) printf("\n");
        printf("Case %d:\n", tc++);

        A = vector<int>(N);
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        getchar();

        build();

        string line;
        while(getline(cin, line)) {
            if (line == "END") break;
            stringstream ss(line);
            ss >> cmd;
            ss >> a;
            ss >> b;

            if (cmd == 'S') {
                add(a-1, b - A[a-1]);
                A[a-1] = b;
            }
            if (cmd == 'M') {
                printf("%d\n", rsq(a-1, b-1));
            }
        }
    }

    return 0;
}

/**
Input:
3
100
100
100
M 1 1
M 1 3
S 2 200
M 1 2
S 3 0
M 2 3
END
10
1
2
3
4
5
6
7
8
9
10
M 1 10
END
0

*/