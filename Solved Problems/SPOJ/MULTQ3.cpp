/*
	Problem Link : https://www.spoj.com/problems/MULTQ3/
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Status : WA
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

void swap(int &a, int &b, int &c) {
    int tmp = c;
    c = b;
    b = a;
    a = tmp;
}

struct Node {
    int lazy;
    int cnt[3];
    void createLeaf() {
        cnt[0] = 1;
        cnt[1] = cnt[2] = 0;
        lazy = 0;
    }
    void raise(int n) {
        n = n % 3;
        while(n > 0) {
            swap(cnt[0], cnt[1], cnt[2]);
            n--;
        }
    }
    void combine(Node &a, Node &b) {
        for (int i = 0; i < 3; ++i) cnt[i] = a.cnt[i] + b.cnt[i];
    }
};

int N, Q;
Node st[4 * MAX + 7];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

void build(int p, int l, int r) {
    if (l == r) {
        st[p].createLeaf();
        return;
    }

    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p].combine(st[left(p)], st[right(p)]);
    st[p].lazy = 0;
}

void pushUp(int p) {
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushDown(int p, int l, int r) {
    if (st[p].lazy == 0) return;

    st[left(p)].raise(st[p].lazy);
    st[right(p)].raise(st[p].lazy);
    st[left(p)].lazy  = st[right(p)].lazy = st[p].lazy;
    st[p].lazy = 0;
}

void updateRangeAdd(int p, int l, int r, int i, int j, int val) {
    if (i == l && j == r) {
        st[p].raise(1);
        if (l != r) st[p].lazy += val;
        return;
    }

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) updateRangeAdd(left(p), l, mid, i, j, val);
    else if (i > mid) updateRangeAdd(right(p), mid+1, r, i, j, val);
    else {
        updateRangeAdd(left(p), l, mid, i, mid, val);
        updateRangeAdd(right(p), mid+1, r, mid+1, j, val);
    }

    pushUp(p);
}

Node query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid+1, r, i, j);
    Node ret;
    Node lNode = query(left(p), l, mid, i, mid);
    Node rNode = query(right(p), mid+1, r, mid+1, j);
    ret.combine(lNode, rNode);
    return ret;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    double cl = clock();

    N = src();
    Q = src();

    build(1, 0, N-1);

    FOR(q, 1, Q) {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0) updateRangeAdd(1, 0, N-1, a, b, 1);
        else {
            Node node = query(1, 0, N-1, a, b);
            printf("%d\n", node.cnt[0]);
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
