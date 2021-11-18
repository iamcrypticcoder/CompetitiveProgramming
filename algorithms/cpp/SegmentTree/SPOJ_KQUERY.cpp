/*
	Problem : https://www.spoj.com/problems/KQUERY/
	Time :   Wrong Answer
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

inline int src() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 3e4;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

int N, Q;
vector<int> A;
vector<int> st[4*MAX+7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = vector<int>(1, A[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    vector<int> v1 = st[left(p)], v2 = st[right(p)];
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(st[p]));
}

int query(int p, int l, int r, int i, int j, int x) {
    if (i > j) return 0;
    if (i == l && j == r) {
        auto it = lower_bound(st[p].begin(), st[p].end(), x);
        if (it == st[p].end()) return 0;
        return *it == x ? st[p].end() - it - 1 : st[p].end() - it;
    }
    int mid = (l + r) >> 1;
    int lv = query(left(p), l, mid, i, min(j, mid), x);
    int rv = query(right(p), mid+1, r, max(i, mid+1), j, x);
    return lv + rv;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    N = src();
    A = vector<int>(N);
    for (auto& x : A) x = src();

    build(1, 0, N-1);

    Q = src();
    int l, r, k;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &l, &r, &k);
        int ans = query(1, 0, N-1, l-1, r-1, k);
        printf("%d\n", ans);
    }

    return 0;
}
