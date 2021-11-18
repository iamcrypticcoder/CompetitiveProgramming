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
vector<LL> blockSums;

// Complexity: O(n)
void preProcess() {
    blockSize = (int)sqrt(N) + 1;
    blockSums = vector<LL>(blockSize, 0);
    for (int i = 0; i < N; i++) blockSums[i / blockSize] += A[i];
}

LL query(int l, int r) {
    LL ret = 0;
    int blockL = l / blockSize;
    int blockR = r / blockSize;
    if (blockL == blockR) {
        for (int i = l; i <= r; i++) ret += A[i];
    } else {
        for (int i = l; i <= (blockL+1)*blockSize-1; i++) ret += A[i];
        for (int i = blockL+1; i <= blockR-1; i++) ret += blockSums[i];
        for (int i = blockR*blockSize; i <= r; i++) ret += A[i];
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
3
0 4
1 3
2 4


Output:
8
4
6

**/