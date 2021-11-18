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
#include <limits.h>
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

inline int src() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 1e6;

int N;
int A[MAX + 7];
pair<int, int> st[4 * MAX + 7];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return {a.first, a.second + b.second};
}

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = {A[l], 1};
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p] = combine(st[left(p)], st[right(p)]);
}

pair<int, int> query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid + 1, r, i, j);

    return combine(query(left(p), l, mid, i, mid),
                   query(right(p), mid+1, r, mid+1, j));
}

void updateSingle(int p, int l, int r, int i, int val) {
    if (l == r) {
        st[p] = {val, 1};
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) updateSingle(left(p), l, mid, i, val);
    else updateSingle(right(p), mid+1, r, i, val);

    st[p] = combine(st[left(p)], st[right(p)]);
}

int main() {
    READ("../input.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
        A[i] = src();

    build(1, 0, N-1);

    int l, r;
    while (cin >> l >> r) {
        auto p = query(1, 0, N-1, l, r);
        printf("Maximum from %d to %d is %d, occurance = %d\n", l, r, p.first, p.second);
    }

    return 0;
}

/**
Input:
10
2 1 3 3 0 5 5 5 4 4
0 0
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
0 9
0 4
5 9

Output:
Maximum from 0 to 0 is 2, occurance = 1
Maximum from 1 to 1 is 1, occurance = 1
Maximum from 2 to 2 is 3, occurance = 1
Maximum from 3 to 3 is 3, occurance = 1
Maximum from 4 to 4 is 0, occurance = 1
Maximum from 5 to 5 is 5, occurance = 1
Maximum from 6 to 6 is 5, occurance = 1
Maximum from 7 to 7 is 5, occurance = 1
Maximum from 8 to 8 is 4, occurance = 1
Maximum from 9 to 9 is 4, occurance = 1
Maximum from 0 to 9 is 5, occurance = 3
Maximum from 0 to 4 is 3, occurance = 2
Maximum from 5 to 9 is 5, occurance = 3

**/