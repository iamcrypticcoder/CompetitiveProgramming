/*
        Problem Link : https://www.spoj.com/problems/PSEGTREE/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.31
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
#include <limits.h>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS             1e-9
#define SQR(x)          ((x)*(x))
#define INF             2000000000
#define TO_DEG          57.29577951
#define PI              2*acos(0.0)

#define ALL_BITS                                ((1 << 31) - 1)
#define NEG_BITS(mask)                          (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)                       (mask & (1 << i))
#define ON_BIT(mask, i)                         (mask |= (1 << i))
#define OFF_BIT(mask, i)                        (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                         (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)                (x & (x-1))

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<uint, uint> PUU;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<uint> VU;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<uint, uint> MUU;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline int srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline int srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_N 100000

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

uint N, Q;
int A[MAX_N];
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

int main()
{
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    int versionIndex = 0;

    N = srcUInt();
    FOR(i, 0, N-1) A[i] = srcInt();
    rootMap[versionIndex++] = build(0, N-1);

    Q = srcUInt();
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


    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
