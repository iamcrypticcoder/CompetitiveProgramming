/*
    Problem Link: https://codeforces.com/problemset/problem/52/C
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
    Status :    WA at test case 5
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

typedef long long LL;

const int MAX = 2e5;

int N;
vector<int> A;
LL st[4*MAX+7];
LL lazy[4*MAX+7];

LL combine(LL a, LL b) {
    return min(a, b);
}

void build(int p, int l, int r) {
    lazy[p] = 0;
    if (l == r) {
        st[p] = A[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    st[p] = combine(st[2*p], st[2*p+1]);
}

void pushDown(int p, int l, int r) {
    if (lazy[p] == 0) return;

    int mid = (l + r) >> 1;
    st[2*p] += (LL(mid - l + 1) * lazy[p]);
    st[2*p+1] += (LL(r - mid) * lazy[p]);
    lazy[2*p] += lazy[p];
    lazy[2*p+1] += lazy[p];
    lazy[p] = 0;
}

void pushUp(int p) {
    st[p] = min(st[2*p], st[2*p+1]);
}

void updateRange(int p, int l, int r, int i, int j, int v) {
    if (i > j) return;
    if (i == l && j == r) {
        st[p] += ((LL)(j - i + 1) * v);
        if (l != r) lazy[p] += v;
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    updateRange(2*p, l, mid, i, min(j, mid), v);
    updateRange(2*p+1, mid+1, r, max(i, mid+1), j, v);
    pushUp(p);
}

LL query(int p, int l, int r, int i, int j) {
    if (i > j) return INT_MAX;
    if (i == l && j == r) return st[p];
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    LL lv = query(2*p, l, mid, i, min(j, mid));
    LL rv = query(2*p+1, mid+1, r, max(i, mid+1), j);
    return combine(lv, rv);
}

void updateModified(int l, int r, int v) {
    if (l <= r) {
        updateRange(1, 0, N-1, l, r, v);
        return;
    }
    updateRange(1, 0, N-1, l, N-1, v);
    updateRange(1, 0, N-1, 0, r, v);
}

LL queryModified(int l, int r) {
    if (l <= r) return query(1, 0, N-1, l, r);
    LL x = query(1, 0, N-1, l, N-1);
    LL y = query(1, 0, N-1, 0, r);
    return min(x, y);
}

int main() {
    READ("../input.txt");

    int M;
    string str, token;
    int l, r, v;

    cin >> N;
    A = vector<int>(N);
    for (auto& x : A) cin >> x;

    build(1, 0, N-1);

    cin >> M;
    getline(cin, str);
    for (int i = 0; i < M; i++) {
        getline(cin, str);
        stringstream ss(str);
        int t = 0;
        while (getline(ss, token, ' ')) {
            if (t == 0) l = stoi(token);
            if (t == 1) r = stoi(token);
            if (t == 2) v = stoi(token);
            t++;
        }

        if (t == 2) {
            printf("%lld\n", queryModified(l, r));
        }
        if (t == 3) {
            if (v != 0) updateModified(l, r, v);
        }
    }

    return 0;
}