/*
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
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

typedef unsigned long long ULL;

const int MAX = 1e6;

int N;
vector<int> A;
ULL st[4 * MAX + 7];
int lazy[4 * MAX + 7];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
inline ULL combine(int a, int b) { return a + b; }

void build(int p, int l, int r) {
    lazy[p] = INT_MIN;
    if (l == r) {
        st[p] = A[l];
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
    st[left(p)] = ((ULL)(mid-l+1) * lazy[p]);
    st[right(p)] = ((ULL)(r-mid) * lazy[p]);
    lazy[left(p)] = lazy[right(p)] = lazy[p];
    lazy[p] = INT_MIN;
}

void updateRangeLazy(int p, int l, int r, int i, int j, int val) {
    //printf("p = %d, l = %d, r = %d, i = %d, j = %d\n", p, l, r, i, j);
    if (i > j) return;
    if (i == l && j == r) {
        st[p] = ((ULL)(r - l + 1) * val);
        if (l != r) lazy[p] = val;
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

    cin >> N;
    A = vector<int>(N);
    for (auto& x : A) cin >> x;

    build(1, 0, N-1);

    string cmd;
    int l, r, x;
    while (cin >> cmd) {
        if (cmd == "query") {
            cin >> l >> r;
            int ret = queryLazy(1, 0, N-1, l, r);
            printf("Sum from index %d to %d = %d\n", l, r, ret);
        }
        if (cmd == "update") {
            cin >> l >> r >> x;
            updateRangeLazy(1, 0, N-1, l, r, x);
        }
    }

    return 0;
}


/**
10
1 2 3 4 5 6 7 8 9 10
update 0 4 2
update 0 1 10
update 8 9 20
query 0 0
query 1 1
query 2 2
query 3 3
query 4 4
query 5 5
query 6 6
query 7 7
query 8 8
query 9 9
query 0 9
query 0 4
query 5 9

Final array after update : 10 10 2 2 2 6 7 8 20 20

Output:
Sum from index 0 to 0 = 10
Sum from index 1 to 1 = 10
Sum from index 2 to 2 = 2
Sum from index 3 to 3 = 2
Sum from index 4 to 4 = 2
Sum from index 5 to 5 = 6
Sum from index 6 to 6 = 7
Sum from index 7 to 7 = 8
Sum from index 8 to 8 = 20
Sum from index 9 to 9 = 20
Sum from index 0 to 9 = 87
Sum from index 0 to 4 = 26
Sum from index 5 to 9 = 61

**/