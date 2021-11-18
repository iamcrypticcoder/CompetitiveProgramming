/*
	Problem : https://www.spoj.com/problems/GSS3/
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

inline int src() { int ret; scanf("%d", &ret); return ret; }

typedef unsigned long long ULL;

const int MAX = 5e4;

struct Node {
    int sum, maxPref, maxSuff, ans;
    Node() {}
    Node(int val) {
        sum = maxPref = maxSuff = ans = val;
    }
};

int N;
int A[MAX];
Node st[4 * MAX+7];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
inline Node combine(Node l, Node r) {
    Node ret;
    ret.sum = l.sum + r.sum;
    ret.maxPref = max(l.maxPref, l.sum + r.maxPref);
    ret.maxSuff = max(r.maxSuff, r.sum + l.maxSuff);
    ret.ans = max(max(l.ans, r.ans), l.maxSuff + r.maxPref);
    return ret;
}

// Complexity: O(n)
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = Node(A[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p] = combine(st[left(p)], st[right(p)]);
}

Node query(int p, int l, int r, int i, int j) {
    //printf("p = %d, l = %d, r = %d, i = %d, j = %d\n", p, l, r, i, j);
    if (i == l && j == r) return st[p];

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid + 1, r, i, j);

    Node lNode = query(left(p), l, mid, i, mid);
    Node rNode = query(right(p), mid+1, r, mid+1, j);
    return combine(lNode, rNode);
}

void updateSingle(int p, int l, int r, int i, int val) {
    if (l == r) {
        st[p] = Node(val);
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) updateSingle(left(p), l, mid, i, val);
    else updateSingle(right(p), mid+1, r, i, val);
    st[p] = combine(st[left(p)], st[right(p)]);
}

int main() {
    READ("../input.txt");

    N = src();
    for (int i = 0; i < N; i++) A[i] = src();
    build(1, 0, N-1);

    int M = src();
    for (int i = 1; i <= M; i++) {
        int cmd = src();
        int x = src();
        int y = src();
        if (cmd == 0) {
            updateSingle(1, 0, N-1, x-1, y);
        } else {
            Node result = query(1, 0, N - 1, x - 1, y - 1);
            printf("%d\n", result.ans);
        }
    }

    return 0;
}

