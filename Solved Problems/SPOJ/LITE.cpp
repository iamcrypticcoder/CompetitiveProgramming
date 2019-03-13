/*
        Problem Link : https://www.spoj.com/problems/LITE/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.29
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
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline int srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline int srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 100000

inline int left(int p) { return (p << 1); }
inline int right(int p) { return (p << 1) + 1; }

struct Node {
    uint onCount, lazyFlipCount = 0;
    void createLeaf(int val) {
        onCount = val;
        lazyFlipCount = 0;
    }
    void combine(Node &a, Node &b) {
        onCount = a.onCount + b.onCount;
    }
};

uint N, M;
Node st[3*MAX+7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p].createLeaf(0);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushUp(int p, int l, int r) {
    st[p].onCount = st[left(p)].onCount + st[right(p)].onCount;
}

void pushDown(int p, int l, int r) {
    if (st[p].lazyFlipCount == 0) return;

    int mid = (l + r) >> 1;
    st[left(p)].onCount = (uint)(mid - l + 1) - st[left(p)].onCount;
    st[right(p)].onCount = (uint)(r - mid) - st[right(p)].onCount;
    st[left(p)].lazyFlipCount = st[left(p)].lazyFlipCount == 0 ? 1 : 0;
    st[right(p)].lazyFlipCount = st[right(p)].lazyFlipCount == 0 ? 1 : 0;
    st[p].lazyFlipCount = 0;
}

void updateRangeFlip(int p, int l, int r, int i, int j) {
    if (i == l && j == r) {
        st[p].onCount = (uint)(r - l + 1) - st[p].onCount;
        if (l != r) st[p].lazyFlipCount = st[p].lazyFlipCount == 0 ? 1 : 0;
        return;
    }

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) updateRangeFlip(left(p), l, mid, i, j);
    else if (i > mid) updateRangeFlip(right(p), mid+1, r, i, j);
    else {
        updateRangeFlip(left(p), l, mid, i, mid);
        updateRangeFlip(right(p), mid+1, r, mid+1, j);
    }
    pushUp(p, l, r);
}

uint query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p].onCount;

    pushDown(p, l, r);

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid+1, r, i, j);

    uint tmp1 = query(left(p), l, mid, i, mid);
    uint tmp2 = query(right(p), mid+1, r, mid+1, j);
    return tmp1 + tmp2;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    N = srcUInt();
    M = srcUInt();
    build(1, 0, N-1);
    FOR(q, 1, M) {
        int cmd = srcInt();
        int x = srcInt();
        int y = srcInt();
        if (cmd == 0) {
            updateRangeFlip(1, 0, N-1, x-1, y-1);
        } else {
            printf("%u\n", query(1, 0, N-1, x-1, y-1));
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
