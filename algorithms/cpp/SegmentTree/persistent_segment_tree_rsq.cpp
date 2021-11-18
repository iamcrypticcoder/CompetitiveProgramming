/*
        Problem Link :
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status :
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
    if (i > j) return 0;
    if (i == l && j == r)
        return n->sum;

    int mid = (l + r) >> 1;
    int lv = querySum(n->left, l, mid, i, min(j, mid));
    int rv = querySum(n->right, mid+1, r, max(mid+1, i), j);
    return lv + rv;
}

Node* update(Node* n, int l, int r, int i, int v) {
    if (l == r) {
        return new Node(v);
    }
    int mid = (l + r) >> 1;
    if (i <= mid)
        return new Node(update(n->left, l, mid, i, v), n->right);
    else
        return new Node(n->left, update(n->right, mid+1, r, i, v));
}

int main() {
    READ("../input.txt");

    int versionIndex = 0;
    N = srcInt();
    FOR(i, 0, N-1) A[i] = srcInt();
    rootMap[versionIndex++] = build(0, N-1);

    string cmd;
    int version, pos, val, l, r;
    while (cin >> cmd) {
        if (cmd == "update") {
            cin >> pos >> val;
            Node* root = rootMap[versionIndex-1];
            rootMap[versionIndex++] = update(root, 0, N-1, pos, val);
        }
        if (cmd == "query") {
            cin >> version >> l >> r;
            Node* root = rootMap[version];
            int ans = querySum(root, 0, N-1, l, r);
            printf("%d\n", ans);
        }
    }
    return 0;
}

/**
Input:
10
1 2 3 4 5 6 7 8 9 10
update 4 100
update 5 100
query 0 0 4
query 0 5 9
query 1 0 4
query 2 5 9


Output:
15
40
110
134


**/