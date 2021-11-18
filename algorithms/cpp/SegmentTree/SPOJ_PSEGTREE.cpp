/*
        Problem Link : https://www.spoj.com/problems/PSEGTREE/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.31
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

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

const int MAXN = 1e5;

struct Node {
    Node *left, *right;
    int sum = 0;

    Node(int val) {
        this->left = this->right = nullptr;
        this->sum = val;
    }
    Node(Node *l, Node *r) {
        this->left = l;
        this->right = r;
        if (l) this->sum += l->sum;
        if (r) this->sum += r->sum;
    }
};

int N, Q;
int A[MAXN];
//Node* rootMap[MAX_N];
map<int, Node*> rootMap;

Node* build(int l, int r) {
    if (l == r) {
        return new Node(A[l]);
    }
    int mid = (l + r) >> 1;
    Node* left = build(l, mid);
    Node* right = build(mid+1, r);
    return new Node(left, right);
}

int querySum(Node* n, int l, int r, int i, int j) {
    if (i == l && j == r) {
        return n->sum;
    }

    int mid = (l + r) >> 1;
    if (j <= mid) return querySum(n->left, l, mid, i, j);
    if (i > mid) return querySum(n->right, mid+1, r, i, j);

    int tmp1 = querySum(n->left, l, mid, i, mid);
    int tmp2 = querySum(n->right, mid+1, r, mid+1, j);
    return tmp1 + tmp2;
}

Node* update(Node* n, int l, int r, int i, int v) {
    if (l == r) {
        return new Node(n->sum + v);
    }
    int mid = (l + r) >> 1;
    if (i <= mid)
        return new Node(update(n->left, l, mid, i, v), n->right);
    else
        return new Node(n->left, update(n->right, mid+1, r, i, v));
}

int main() {
    int versionIndex = 0;
    N = srcInt();
    FOR(i, 0, N-1) A[i] = srcInt();
    rootMap[versionIndex++] = build(0, N-1);

    Q = srcInt();
    FOR(i, 0, Q-1) {
        int cmd = srcInt();
        int idx = srcInt();
        if (cmd == 1) {
            int pos = srcInt() - 1;
            int v = srcInt();
            Node* root = rootMap[idx];
            rootMap[versionIndex++] = update(root, 0, N-1, pos, v);
        } else {
            int l = srcInt() - 1;
            int r = srcInt() - 1;
            Node* root = rootMap[idx];
            int ans = querySum(root, 0, N-1, l, r);
            printf("%d\n", ans);
        }
    }

    return 0;
}
