/*
    Problem Link: https://codeforces.com/contest/52/problem/C
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Time :
	Rank : Wrong Answer
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

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 		1e-9
#define SQR(x) 		((x)*(x))
#define INF 		2000000000
#define TO_DEG 		57.29577951
#define PI 			2*acos(0.0)

#define ALL_BITS					((1 << 31) - 1)
#define NEG_BITS(mask)				(mask ^= ALL_BITS)
#define TEST_BIT(mask, i)			(mask & (1 << i))
#define ON_BIT(mask, i)				(mask |= (1 << i))
#define OFF_BIT(mask, i)			(mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)				(x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)	(x & (x-1))

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
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
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2 };

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1<<18

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

struct Node {
    LL val;
    void createLeaf(LL v) {
        val = v;
    }
    void raise(LL v) {
        val += v;
    }
    void combine(Node &a, Node &b) {
        val = min(a.val, b.val);
    }
};

int N, M;
int A[MAX + 7];
Node st[3 * MAX + 7];
LL lazy[3 * MAX + 7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p].createLeaf(A[l]);
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
    if (lazy[p] == 0) return;

    st[left(p)].raise(lazy[p]);
    st[right(p)].raise(lazy[p]);
    lazy[left(p)] = lazy[right(p)] = lazy[p];
    lazy[p] = 0;
}

void updateRangeLazy(int p, int l, int r, int i, int j, int val) {
    if (i == l && j == r) {
        st[p].raise(val);
        if (l != r) lazy[p] += val;
        return;
    }

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) updateRangeLazy(left(p), l, mid, i, j, val);
    else if (i > mid) updateRangeLazy(right(p), mid+1, r, i, j, val);
    else {
        updateRangeLazy(left(p), l, mid, i, mid, val);
        updateRangeLazy(right(p), mid+1, r, mid+1, j, val);
    }

    pushUp(p);
}

Node queryLazy(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) return queryLazy(left(p), l, mid, i, j);
    else if (i > mid) return queryLazy(right(p), mid+1, r, i, j);
    else {
        Node ret;
        Node lNode = queryLazy(left(p), l, mid, i, mid);
        Node rNode = queryLazy(right(p), mid + 1, r, mid + 1, j);
        ret.combine(lNode, rNode);
        return ret;
    }
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    string line;
    int l, r, v;

    N = src();
    FOR(i, 0, N-1) A[i] = src();
    memset
    build(1, 0, N-1);

    M = src();
    getline(cin, line);
    FOR(q, 1, M) {
        getline(cin, line);
        stringstream ss(line);
        ss >> i >> j;
        if (ss >> v) {
            if (i <= j) updateRangeLazy(1, 0, N-1, i, j, v);
            else {
                updateRangeLazy(1, 0, N-1, i, N-1, v);
                updateRangeLazy(1, 0, N-1, 0, j, v);
            }
        } else {
            if (i <= j) {
                Node node = queryLazy(1, 0, N-1, i, j);
                printf("%lld\n", node.val);
            } else {
                Node n1 = queryLazy(1, 0, N - 1, i, N-1);
                Node n2 = queryLazy(1, 0, N - 1, 0, j);
                printf("%lld\n", min(n1.val, n2.val));
            }
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}