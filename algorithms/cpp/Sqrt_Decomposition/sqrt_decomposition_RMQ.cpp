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
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 1e5;

int N, Q;
int A[MAX + 7];
int blockSize;
vector<int> blocks;

// Complexity: O(n)
void preProcess() {
    blockSize = (int)sqrt(N) + 1;
    blocks = vector<int>(blockSize, INT_MAX);
    for (int i = 0; i < N; i++)
        blocks[i / blockSize] = min(blocks[i / blockSize], A[i]);
}

int query(int l, int r) {
    int ret = INT_MAX;
    int blockL = l / blockSize;
    int blockR = r / blockSize;
    if (blockL == blockR) {
        for (int i = l; i <= r; i++) ret = min(ret, A[i]);
    } else {
        for (int i = l; i <= (blockL+1)*blockSize-1; i++) ret = min(ret, A[i]);
        for (int i = blockL+1; i <= blockR-1; i++) ret = min(ret, blocks[i]);
        for (int i = blockR*blockSize; i <= r; i++) ret = min(ret, A[i]);
    }
    return ret;
}

int main()
{
    READ("../input.txt");
    //WRITE("input.txt");

    int i, j;
    int TC, tc;
    double cl = clock();

    int l, r;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    preProcess();

    cin >> Q;
    for (int i = 0 ; i < Q; i++) {
        cin >> l >> r;
        printf("%lld\n", query(l, r));
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
Input:
9
1 1 2 1 3 4 5 2 8
12
0 0
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
0 4
4 5
6 8


Output:
1
1
2
1
3
4
5
2
8
1
3
2

**/