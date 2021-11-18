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

int gcd(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

inline int src() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 1e6;

int N;
int A[MAX + 7];
int st[4 * MAX + 7];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
int combine(int a, int b) { return gcd(a, b); }

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p] = combine(st[left(p)], st[right(p)]);
}

int query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid + 1, r, i, j);

    return combine(query(left(p), l, mid, i, mid),
                   query(right(p), mid+1, r, mid+1, j));
}

int main() {
    READ("../input.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
        A[i] = src();

    build(1, 0, N-1);

    int l, r;
    while (cin >> l >> r) {
        int x = query(1, 0, N-1, l, r);
        printf("GCD from %d to %d is %d\n", l, r, x);
    }

    return 0;
}

/**
Input:
10
2 4 6 12 16 18 20 22 26 30
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


**/