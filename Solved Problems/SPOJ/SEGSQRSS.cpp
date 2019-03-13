/*
	Problem Link : https://www.spoj.com/problems/SEGSQRSS/
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Status : AC
	Time : 0.04
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
#include <limits.h>

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

ULL GCD(ULL a, ULL b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 100000

inline uint left(uint p) { return (p << 1); }
inline uint right(uint p) { return (p << 1) + 1; }

struct Node {
    ULL sum, sqSum;
    int addLazy, setLazy;
    void createLeaf(ULL val) {
        sum = val;
        sqSum = SQR(val);
        addLazy = 0;
        setLazy = INT_MIN;
    }
    void combine(Node &a, Node &b) {
        sum = a.sum + b.sum;
        sqSum = a.sqSum + b.sqSum;
    }
};

uint N, Q;
int A[MAX + 7];
Node st[3*MAX + 7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p].createLeaf(A[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p].combine(st[left(p)], st[right(p)]);
    st[p].addLazy = 0;
    st[p].setLazy = INT_MIN;
}

void pushUp(int p) {
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushDown(int p, int l, int r) {
    int mid = (l + r) >> 1;

    // If set lazy exists
    if (st[p].setLazy != INT_MIN) {
        st[left(p)].sum = (ULL)(mid - l + 1) * st[p].setLazy;
        st[left(p)].sqSum = (ULL)(mid - l + 1) * SQR(st[left(p)].setLazy);
        st[right(p)].sum = (ULL)(r - mid) * SQR(st[right(p)].setLazy);
        st[right(p)].sqSum = (ULL)(r - mid) * SQR(st[right(p)].setLazy);
        st[left(p)].setLazy = st[right(p)].setLazy = st[p].setLazy;
        st[p].setLazy = INT_MIN;
    }

    // If add lazy exists
    if (st[p].addLazy != 0) {
        st[left(p)].sqSum += 2*st[left(p)].sum + (r-l+1)*SQR(st[p].addLazy);
        st[right(p)].sqSum += 2*st[right(p)].sum + (r-mid)*SQR(st[p].addLazy);
        st[left(p)].sum += st[p].addLazy;
        st[right(p)].sum += st[p].addLazy;
        st[left(p)].addLazy = st[right(p)].addLazy = st[p].addLazy;
        st[p].addLazy = 0;
    }
}

void updateRangeSet(int p, int l, int r, int i, int j, int x) {
    if (i == l && j == r) {
        st[p].sum = (ULL)(r - l + 1) * x;
        st[p].sqSum = (ULL)(r - l + 1) * SQR(x);
        if (l != r) {
            st[p].addLazy = 0;
            st[p].setLazy = x;
        }
        return;
    }

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) updateRangeSet(left(p), l, mid, i, j, x);
    else if (i > mid) updateRangeSet(right(p), mid + 1, r, i, j, x);
    else {
        updateRangeSet(left(p), l, mid, i, mid, x);
        updateRangeSet(right(p), mid + 1, r, mid + 1, j, x);
    }
    pushUp(p);
}

void updateRangeAdd(int p, int l, int r, int i, int j, int x) {
    if (i == l && j == r) {
        st[p].sqSum += 2*st[p].sum + (ULL)(r-l+1)*SQR(x);
        st[p].sum += (ULL)(r-l+1) * x;
        if (l != r) {
            st[p].addLazy = x;
        }
        return;
    }

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) updateRangeAdd(left(p), l, mid, i, j, x);
    else if (i > mid) updateRangeAdd(right(p), mid + 1, r, i, j, x);
    else {
        updateRangeAdd(left(p), l, mid, i, mid, x);
        updateRangeAdd(right(p), mid + 1, r, mid + 1, j, x);
    }
    pushUp(p);

}

ULL query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p].sqSum;

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid + 1, r, i, j);

    pushDown(p, l, r);

    return query(left(p), l, mid, i, mid) + query(right(p), mid+1, r, mid+1, j);
}

int main()
{
    //READ("input.txt");
    //WRITE("input.txt");

    int i, j;
    uint TC, tc;
    double cl = clock();

    int st, nd, x;

    TC = srcUInt();
    FOR(tc, 1, TC) {
        scanf("%u %u", &N, &Q);
        FOR(i, 0, N-1) A[i] = srcInt();
        build(1, 0, N-1);

        printf("Case %u:\n", tc);
        FOR(q, 1, Q) {
            uint cmd = srcUInt();
            if (cmd == 0) {
                scanf("%d %d %d", &st, &nd, &x);
                updateRangeSet(1, 0, N-1, st-1, nd-1, x);
            } else if (cmd == 1) {
                scanf("%d %d %d", &st, &nd, &x);
                updateRangeAdd(1, 0, N-1, st-1, nd-1, x);
            } else if (cmd == 2) {
                scanf("%d %d", &st, &nd);
                printf("%llu\n", query(1, 0, N-1, st-1, nd-1));
            }
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
