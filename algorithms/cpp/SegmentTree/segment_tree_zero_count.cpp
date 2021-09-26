/*
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Time :
	Rank :
	Complexity:
*/

#define _CRT_SECURE_NO_WARNINGS

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

const int MAX = 1e6;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

struct Node {
    unsigned int cnt = 0;
    int lazy = INT_MIN;
    void resetNode() {
        cnt = 0;
        lazy = INT_MIN;
    }
    void combine(Node &a, Node &b) {
        cnt = a.cnt + b.cnt;
    }
};

int A[MAX];
Node st[3 * MAX + 7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p].cnt = (A[l] == 0 ? 1 : 0);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushUp(int p) {
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushDown(int p, int l, int r) {
    if (st[p].lazy == INT_MIN) return;

    int mid = (l + r) >> 1;
    if (st[p].lazy == 0) {
        st[left(p)].cnt = (unsigned int)(mid-l+1);
        st[right(p)].cnt = (unsigned int)(r-mid+1);
    } else {
        st[left(p)].cnt = st[right(p)].cnt = 0;
    }
    st[left(p)].lazy = st[right(p)].lazy = st[p].lazy;
    st[p].lazy = INT_MIN;
}

void updateRangeLazy(int p, int l, int r, int i, int j, int val) {
    if (i == l && j == r) {
        st[p].cnt = (unsigned int)(r - l + 1) * (val == 0 ? 1 : 0);
        if (l != r) st[p].lazy = val;
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (j <= mid) updateRangeLazy(left(p), l, mid, i, j, val);
    else if (i > mid) updateRangeLazy(right(p), mid + 1, r, i, j, val);
    else {
        updateRangeLazy(left(p), l, mid, i, mid, val);
        updateRangeLazy(right(p), mid + 1, r, mid + 1, j, val);
    }
    pushUp(p);
}

unsigned int queryLazy(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p].cnt;

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) return queryLazy(left(p), l, mid, i, j);
    if (i > mid) return queryLazy(right(p), mid + 1, r, i, j);

    unsigned int tmp1 = queryLazy(left(p), l, mid, i, mid);
    unsigned int tmp2 = queryLazy(right(p), mid + 1, r, mid+1, j);
    return tmp1 + tmp2;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    vector<int> arr { 1, 0, 3, 0, 0, 0, 6, 0 };
    int N = arr.size();

    // Build ST
    for (int i = 0; i < N; i++) A[i] = arr[i];
    build(1, 0, N-1);

    int cnt = queryLazy(1, 0, N-1, 0, N-1);
    printf("Zero count from index %d to %d = %d\n\n", 0, N-1, cnt);

    updateRangeLazy(1, 0, N-1, 0, 3, 0);
    updateRangeLazy(1, 0, N-1, 0, 3, 100);

    for (int i = 0; i < N; i++) {
        cnt = queryLazy(1, 0, N-1, 0, i);
        printf("Zero count from index %d to %d = %d\n", 0, i, cnt);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
Zero count from index 0 to 7 = 5

Zero count from index 0 to 0 = 0
Zero count from index 0 to 1 = 0
Zero count from index 0 to 2 = 0
Zero count from index 0 to 3 = 0
Zero count from index 0 to 4 = 1
Zero count from index 0 to 5 = 2
Zero count from index 0 to 6 = 2
Zero count from index 0 to 7 = 3

**/
