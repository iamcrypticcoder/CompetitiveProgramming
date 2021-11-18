/*
    Problem Link: https://onlinejudge.org/external/114/11402.pdf
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
    Status : Wrong Answer
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
#include <climits>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

const int MAX = int(1e6 + 24000);

int N;
vector<char> A;
int st[4 * MAX + 7];
int lazy[4 * MAX + 7];

int combine(int a, int b) { return a + b; }

void build(int p, int l, int r) {
    lazy[p] = INT_MIN;
    if (l == r) {
        st[p] = (A[l] == 1 ? 1 : 0);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p] = combine(st[left(p)], st[right(p)]);
}

void pushUp(int p) {
    st[p] = combine(st[left(p)], st[right(p)]);
}

void pushDown(int p, int l, int r) {
    if (lazy[p] == INT_MIN) return;

    int mid = (l + r) >> 1;
    if (lazy[p] == 1) {
        st[left(p)] = mid - l + 1;
        st[right(p)] = r - mid;
        lazy[left(p)] = lazy[right(p)] = lazy[p];
    }
    if (lazy[p] == 0) {
        st[left(p)] = st[right(p)] = 0;
        lazy[left(p)] = lazy[right(p)] = lazy[p];
    }
    if (lazy[p] == -1) {
        st[left(p)] = (mid - l + 1) - st[left(p)];
        st[right(p)] = (r - mid) - st[right(p)];

        if (lazy[left(p)] == -1) lazy[left(p)] = INT_MIN;
        else if (lazy[left(p)] == 1) lazy[left(p)] = 0;
        else if (lazy[left(p)] == 0) lazy[left(p)] = 1;

        if (lazy[right(p)] == -1) lazy[right(p)] = INT_MIN;
        else if (lazy[right(p)] == 1) lazy[right(p)] = 0;
        else if (lazy[right(p)] == 0) lazy[right(p)] = 1;
    }
    lazy[p] = INT_MIN;
}

void updateRangeLazy(int p, int l, int r, int i, int j, int val) {
    //printf("p = %d, l = %d, r = %d, i = %d, j = %d\n", p, l, r, i, j);
    if (i > j) return;
    if (i == l && j == r) {
        if (val == 1) st[p] = (r - l + 1);
        if (val == 0) st[p] = 0;
        if (val == -1) st[p] = (r - l + 1) - st[p];
        if (l != r) {
            if (val == -1) {
                if (lazy[p] == -1) lazy[p] = INT_MIN;
                else if (lazy[p] == 1) lazy[p] = 0;
                else if (lazy[p] == 0) lazy[p] = 1;
            } else {
                lazy[p] = val;
            }
        }
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    updateRangeLazy(left(p), l, mid, i, min(mid, j), val);
    updateRangeLazy(right(p), mid + 1, r, max(i, mid+1), j, val);
    pushUp(p);
}

int queryLazy(int p, int l, int r, int i, int j) {
    //printf("p = %d, l = %d, r = %d, i = %d, j = %d\n", p, l, r, i, j);
    if (i > j) return 0;
    if (i == l && j == r) return st[p];

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    int lv = queryLazy(left(p), l, mid, i, min(mid, j));
    int rv = queryLazy(right(p), mid + 1, r, max(i, mid+1), j);
    return combine(lv, rv);
}

int main() {
    READ("../input.txt");

    int M, T, Q;
    string str;
    char ch;
    int l, r;
    int TC = src();

    for (int tc = 1; tc <= TC; tc++) {
        printf("Case %d:\n", tc);
        cin >> M;
        string land;
        for (int i = 1; i <= M; i++) {
            cin >> T >> str;
            for (int j = 1; j <= T; j++) land += str;
        }

        N = (int)land.size();
        A = vector<char>(N);
        for (int i = 0; i < N; i++)
            A[i] = land[i] - '0';

        build(1, 0, N-1);

        Q = src();
        int q = 1;
        for (int i = 0; i < Q; i++) {
            cin >> ch >> l >> r;
            if (ch == 'F') {
                updateRangeLazy(1, 0, N-1, l, r, 1);
            }
            if (ch == 'E') {
                updateRangeLazy(1, 0, N-1, l, r, 0);
            }
            if (ch == 'I') {
                updateRangeLazy(1, 0, N-1, l, r, -1);
            }
            if (ch == 'S') {
                int ans = queryLazy(1, 0, N-1, l, r);
                printf("Q%d: %d\n", q++, ans);
            }
        }
    }

    return 0;
}