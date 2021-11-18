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

typedef long long LL;
typedef unsigned long long ULL;

inline int src() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 1e6;

struct Node {
    int sum, maxPref, maxSuff, ans;
    Node() {}
    Node(int val) {
        sum = val;
        maxPref = maxSuff = ans = max(0, val);
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

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    build(1, 0, N-1);

    int l, r;
    while(cin >> l >> r) {
        Node n = query(1, 0, N-1, l, r);
        printf("Maximal subarray sum of given range [%d, %d] : %d\n", l, r, n.ans);
    }

    return 0;
}


/*
Input:
10
1 -1 -1 2 3 -1 5 2 8 1
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
Maximal subarray sum of given range [0, 0] : 1
Maximal subarray sum of given range [1, 1] : 0
Maximal subarray sum of given range [2, 2] : 0
Maximal subarray sum of given range [3, 3] : 2
Maximal subarray sum of given range [4, 4] : 3
Maximal subarray sum of given range [5, 5] : 0
Maximal subarray sum of given range [6, 6] : 5
Maximal subarray sum of given range [7, 7] : 2
Maximal subarray sum of given range [8, 8] : 8
Maximal subarray sum of given range [9, 9] : 1
Maximal subarray sum of given range [0, 9] : 20
Maximal subarray sum of given range [0, 4] : 5
Maximal subarray sum of given range [5, 9] : 16

*/
