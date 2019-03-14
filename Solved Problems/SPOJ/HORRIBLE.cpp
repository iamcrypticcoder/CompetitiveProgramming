/*
        Problem Link : https://www.spoj.com/problems/HORRIBLE/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.14
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

#define MAX 100000

inline uint left(uint p) { return (p << 1); }
inline uint right(uint p) { return (p << 1) + 1; }

struct Node {
    ULL sum = 0, lazy = 0;
    void createLeaf(ULL val) {
        sum = val;
    }
    void combine(Node &a, Node &b) {
        sum = a.sum + b.sum;
    }
};

uint N, C;
Node st[3*MAX + 7];

void build(uint p, uint l, uint r) {
    if (l == r) {
        st[p].createLeaf(0);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p].combine(st[left(p)], st[right(p)]);
    st[p].lazy = 0;
}


void pushUp(uint p, uint l, uint r) {
    st[p].combine(st[left(p)], st[right(p)]);
}

void pushDown(uint p, uint l, uint r) {
    if (st[p].lazy == 0) return;

    uint mid = (l + r) >> 1;
    st[left(p)].sum += (mid - l + 1) * st[p].lazy;
    st[right(p)].sum += (r - mid) * st[p].lazy;
    st[left(p)].lazy += st[p].lazy;
    st[right(p)].lazy += st[p].lazy;
    st[p].lazy = 0;
}

void update(uint p, uint l, uint r, uint i, uint j, uint v) {
    if (i == l && j == r) {
        st[p].sum += (ULL)(r - l + 1) * v;
        if (l != r) st[p].lazy += v;
        return;
    }
    pushDown(p, l, r);
    uint mid = (l + r) >> 1;
    if (j <= mid) update(left(p), l, mid, i, j, v);
    else if (i > mid) update(right(p), mid+1, r, i, j, v);
    else {
        update(left(p), l, mid, i, mid, v);
        update(right(p), mid+1, r, mid+1, j, v);
    }
    pushUp(p, l, r);
}

ULL query(uint p, uint l, uint r, uint i, uint j) {
    if (i == l && j == r) return st[p].sum;

    pushDown(p, l, r);
    uint mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid+1, r, i, j);
    return query(left(p), l, mid, i, mid) + query(right(p), mid+1, r, mid+1, j);
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    TC = srcUInt();
    FOR(tc, 1, TC) {
        N = srcUInt();
        C = srcUInt();
        build(1, 0, N-1);
        FOR(c, 1, C) {
            uint cmd = srcUInt();
            uint p = srcUInt();
            uint q = srcUInt();
            if (cmd == 0) {
                uint v = srcUInt();
                update(1, 0, N-1, p-1, q-1, v);
            } else {
                printf("%llu\n", query(1, 0, N-1, p-1, q-1));
            }
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
