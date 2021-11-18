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

const int MAX = 1e6;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
int combine(int a, int b) {
    return a + b;
}

int N;
int A[MAX + 7];
int st[4*MAX + 7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = (A[l] == 0);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l , mid);
    build(right(p), mid+1, r);
    st[p] = combine(st[left(p)], st[right(p)]);
}

int queryCount(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    int mid = (l + r) >> 1;
    if (j <= mid) return queryCount(left(p), l, mid, i, j);
    if (i > mid) return queryCount(right(p), mid+1, r, i, j);

    return combine(queryCount(left(p), l, mid, i, mid),
                   queryCount(right(p), mid+1, r, mid+1, j));
}

int queryKthZero(int p, int l, int r, int k) {
    if (k > st[p]) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (st[left(p)] >= k) return queryKthZero(left(p), l, mid, k);
    else return queryKthZero(right(p), mid+1, r, k - st[left(p)]);
}

int main() {
    READ("../input.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    build(1, 0, N-1);

    int k;
    while (cin >> k) {
        int kthZero = queryKthZero(1, 0, N-1, k);
        if (kthZero == -1) printf("There is no kth zero\n");
        else printf("%d\'th zero = %d\n", k, kthZero);
    }

    return 0;
}

/**
Input:
10
1 0 2 3 0 0 0 4 0 0
1
2
3
4
5
6
7

Output:
1'th zero = 1
2'th zero = 4
3'th zero = 5
4'th zero = 6
5'th zero = 8
6'th zero = 9
There is no kth zero

**/