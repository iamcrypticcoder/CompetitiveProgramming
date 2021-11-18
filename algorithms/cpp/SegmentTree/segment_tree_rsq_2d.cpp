/*
    Problem Link:
    Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
    Status :
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
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 1000;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
inline int combine(int a, int b) { return a + b; }

int N, M, Q;
vector<vector<int>> A;
ULL st[4*MAX+7][4*MAX+7];

void buildY(int px, int lx, int rx, int py, int ly, int ry) {
    if (ly == ry) {
        st[px][py] = (lx == rx) ? A[lx][ly] : st[left(px)][py] + st[right(px)][py];
        return;
    }
    int mid = (ly + ry) >> 1;
    buildY(px, lx, rx, left(py), ly, mid);
    buildY(px, lx, rx, right(py), mid+1, ry);
    st[px][py] = combine(st[px][left(py)], st[px][right(py)]);
}

void buildX(int px, int lx, int rx) {
    if (lx == rx) {
        buildY(px, lx, rx, 1, 0, M-1);
        return;
    }
    int mid = (lx + rx) >> 1;
    buildX(left(px), lx, mid);
    buildX(right(px), mid+1, rx);
    buildY(px, lx, rx, 1, 0, M-1);
}

void updateY(int px, int lx, int rx, int py, int ly, int ry, int i, int j, int v) {
    if (ly == ry) {
        st[px][py] = (lx == rx) ? v : st[left(px)][py] + st[right(px)][py];
        return;
    }
    int mid = (ly + ry) >> 1;
    if (j <= mid) updateY(px, lx, rx, left(py), ly, mid, i, j, v);
    else updateY(px, lx, rx, right(py), mid+1, ry, i, j, v);
    st[px][py] = combine(st[px][left(py)], st[px][right(py)]);
}

void updateX(int px, int lx, int rx, int i, int j, int v) {
    if (lx == rx) {
        updateY(px, lx, rx, 1, 0, M-1, i, j, v);
        return;
    }
    int mid = (lx + rx) >> 1;
    if (i <= mid) updateX(left(px), lx, mid, i, j, v);
    else updateX(right(px), mid+1, rx, i, j, v);
    updateY(px, lx, rx, 1, 0, M-1, i, j, v);
}

ULL querySumY(int px, int py, int ly, int ry, int k, int l) {
    if (k == ly && l == ry) return st[px][py];

    int mid = (ly + ry) >> 1;
    if (l <= mid) return querySumY(px, left(py), ly, mid, k, l);
    if (k > mid) return querySumY(px, right(py), mid+1, ry, k, l);

    return querySumY(px, left(py), ly, mid, k, mid) + querySumY(px, right(py), mid+1, ry, mid+1, l);
}

ULL querySumX(int px, int lx, int rx, int i, int j, int k, int l) {
    if (i == lx && j == rx) return querySumY(px, 1, 0, M-1, k, l);
    int mid = (lx + rx) >> 1;
    if (j <= mid) return querySumX(left(px), lx, mid, i, j, k, l);
    if (i > mid) return querySumX(right(px), mid+1, rx, i, j, k, l);

    return querySumX(left(px), lx, mid, i, mid, k, l) + querySumX(right(px), mid+1, rx, mid+1, j, k, l);
}

int main() {
    READ("../input.txt");

    cin >> N >> M;
    A = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    buildX(1, 0, N-1);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cout << querySumX(1, 0, N-1, x1, x2, y1, y2) << endl;
    }

    updateX(1, 0, N-1, 2, 2, 10);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cout << querySumX(1, 0, N-1, x1, x2, y1, y2) << endl;
    }

    return 0;
}

/**
Input:
4 4
1 2 3 4
5 6 7 8
9 0 1 2
3 4 5 6
3
0 0 0 0
0 0 1 1
0 0 2 2
3
0 0 0 0
0 0 1 1
0 0 2 2

Output:
1
14
34
1
14
43

 **/
