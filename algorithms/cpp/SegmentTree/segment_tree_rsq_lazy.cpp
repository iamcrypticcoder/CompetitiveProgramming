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

struct Node {
    unsigned long long sum = 0;
    int lazy = INT_MIN;
    void combine(Node &a, Node &b) {
        sum = a.sum + b.sum;
    }
};

int N;
int A[MAX];
Node st[3 * MAX + 7];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

void build(int p, int l, int r) {
    if (l == r) {
        st[p].sum = A[l];
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
    st[left(p)].sum = ((unsigned long long)(mid-l+1) * st[p].lazy);
    st[right(p)].sum = ((unsigned long long)(r-mid+1) * st[p].lazy);
    st[p].lazy = st[p].lazy = st[p].lazy;
    st[p].lazy = INT_MIN;
}

void updateRangeLazy(int p, int l, int r, int i, int j, int val) {
    if (i == l && j == r) {
        st[p].sum = ((unsigned long long)(r - l + 1) * val);
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

Node queryLazy(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) return queryLazy(left(p), l, mid, i, j);
    if (i > mid) return queryLazy(right(p), mid + 1, r, i, j);

    Node ret;
    Node ln = queryLazy(left(p), l, mid, i, mid);
    Node rn = queryLazy(right(p), mid + 1, r, mid+1, j);
    ret.combine(ln, rn);
    return ret;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    vector<int> arr { 1, 2, 3, 4, 5, 6, 7 };
    N = arr.size();

    for (int i = 0; i < N; i++) A[i] = arr[i];
    build(1, 0, N-1);

    Node node = queryLazy(1, 0, N-1, 0, N-1);
    printf("Sum from index %d to %d = %d\n", 0, N-1, node.sum);

    updateRangeLazy(1, 0, N-1, 2, 3, -100);

    node = queryLazy(1, 0, N-1, 0, N-1);
    printf("Sum from index %d to %d = %d\n", 0, N-1, node.sum);

    node = queryLazy(1, 0, N-1, 0, 1);
    printf("Sum from index %d to %d = %d\n", 0, 1, node.sum);

    node = queryLazy(1, 0, N-1, 4, 6);
    printf("Sum from index %d to %d = %d\n", 4, 6, node.sum);

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**
Minimum from index 0 to 6 = 28
Minimum from index 0 to 6 = -179
Minimum from index 0 to 1 = 3
Minimum from index 4 to 6 = 18
 **/
