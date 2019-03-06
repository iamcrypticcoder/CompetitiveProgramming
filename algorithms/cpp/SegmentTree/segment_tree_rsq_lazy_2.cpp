/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
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

#define MAX 1000000

struct Node {
    LL sum;
    void createLeaf(int val) {
        sum = val;
    }
    void combine(Node &a, Node &b) {
        sum = a.sum + b.sum;
    }
};

int N;
int A[MAX];
Node st[3 * MAX];
int lazy[3 * MAX];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

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

Node query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid + 1, r, i, j);

    Node ret;
    Node lNode = query(left(p), l, mid, i, mid);
    Node rNode = query(right(p), mid+1, r, mid+1, j);
    ret.combine(lNode, rNode);
    return ret;
}

void updateSingle(int p, int l, int r, int pos, int val) {
    if (l == r) {
        st[p].createLeaf(val);
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) updateSingle(left(p), l, mid, pos, val);
    else updateSingle(right(p), mid+1, r, pos, val);

    st[p].combine(st[left(p)], st[right(p)]);
}

void updateRange(int p, int l, int r, int i, int j, int val) {
    if (i > l || j < r) return;
    if (l == r) {
        A[l] = val;
        st[p].createLeaf(val);
        return;
    }
    int mid = (l + r) >> 1;
    updateRange(left(p), l, mid, i, j, val);
    updateRange(right(p), mid + 1, r, i, j, val);

    st[p].combine(st[left(p)], st[right(p)]);
}

// Update value of parent (p) from it's child
void pushUp(int p) {
    st[p].combine(st[left(p)], st[right(p)]);
}

// Populate lazy value of parent (p) to it's child reset it's own lazy value
void pushDown(int p, int l, int r) {
    if (lazy[p] == 0) return;

    int mid = (l + r) >> 1;
    st[left(p)].createLeaf((LL)(mid - l + 1) * lazy[p]);
    st[right(p)].createLeaf((LL)(r - mid) * lazy[p]);
    lazy[left(p)] = lazy[right(p)] = lazy[p];
    lazy[p] = 0;
}

void updateRangeLazy(int p, int l, int r, int i, int j, int val) {
    if (i == l && j == r) {
        st[p].createLeaf((LL)(r - l + 1) * val);
        if (l != r) lazy[p] = val;
        return;
    }

    int mid = (l + r) >> 1;
    if (j <= mid) updateRangeLazy(left(p), l, mid, i, j, val);
    if (i > mid) updateRangeLazy(right(p), mid + 1, r, i, j, val);

    pushDown(p, l, r);

    updateRangeLazy(left(p), l, mid, i, mid, val);
    updateRangeLazy(right(p), mid+1, r, mid+1, j, val);
    pushUp(p);
}

Node queryLazy(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid + 1, r, i, j);

    pushDown(p, l, r);

    Node ret;
    Node lNode = query(left(p), l, mid, i, mid);
    Node rNode = query(right(p), mid+1, r, mid+1, j);
    ret.combine(lNode, rNode);
    return ret;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    int arr[10] = { 8, 7, 3, 9, 5, 1, 10, 4, 1, 6 };
    N = 10;
    FOR(i, 0, N - 1) A[i] = arr[i];

    memset(st, 0, sizeof(st));
    memset(st, 0, sizeof(lazy));

    build(1, 0, N-1);

    Node node = query(1, 0, N-1, 0, N-1)l
    cout << node.sum << endl;

    updateRangeLazy(1, 0, N-1, 0, 2, 1);

    node = queryLazy(1, 0, N-1, 0, 2);
    cout << node.sum << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}