
/*
        Problem Link : https://www.spoj.com/problems/ANDROUND/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : Compilation Error
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

#define MAX 20000

inline uint left(uint p) { return (p << 1); }
inline uint right(uint p) { return (p << 1) + 1; }

struct Node {
    uint andVal;
    void createLeaf(uint val) {
        andVal = val;
    }
    void combine(Node &a, Node &b) {
        andVal = a.andVal & b.andVal;
    }
};

uint N, K;
uint A[MAX + 7];
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
}

uint query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p].andVal;
    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid+1, r, i, j);

    uint tmp1 = query(left(p), l, mid, i, mid);
    uint tmp2 = query(right(p), mid+1, r, mid+1, j);
    return (tmp1 & tmp2);
}

uint calcAnd(int i) {
    uint x = (i-K+N) % N;
    uint y = (i+K) % N;
    if (x == 0 && y == 0) return A[0];

    uint ret = UINT_MAX;
    if (K < N/2)
        ret = query(1, 0, N-1, x, y);
    else if (K > N/2) {
        if (x-1 >= 0) ret = query(1, 0, N-1, 0, x-1);
        if (y+1 <= N-1) ret = ret & query(1, 0, N-1, y+1, N-1);
    } else if (K == N/2) {
        ret = query(1, 0, N-1, 0, N-1);
    }
    return ret;
}

int main()
{
    READ("input.txt");
    //WRITE("input.txt");

    int i, j;
    uint TC, tc;
    double cl = clock();

    TC = srcUInt();
    FOR(tc, 1, TC) {
        N = srcUInt();
        K = srcUInt();
        K = K % N;

        FOR(i, 0, N-1) A[i] = srcUInt();
        build(1, 0, N-1);

        printf("%u", calcAnd(0));
        FOR(i, 1, N-1) {
            printf(" %u", calcAnd(i));
        }
        printf("\n");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
