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

#define MAX 100007

// a denotes number of integers mod 3 = 0
typedef struct {
	int a, b, c;
} Node;

int N, q;
Node st[3 * MAX];
int lazy[3 * MAX];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

// [a,b,c] will be [c,a,b]
void swapNode(Node &n) {
	n.a = n.a + n.b + n.c;
	n.b = n.a - (n.b + n.c);
	n.c = n.a - (n.b + n.c);
	n.a = n.a - (n.b + n.c);
}

void pushUp(int p) {
	int l = left(p), r = right(p);
	st[p].a = st[l].a + st[r].a;
	st[p].b = st[l].b + st[r].b;
	st[p].c = st[l].c + st[r].c;
}

void pushDown(int p, int L, int R) {
	if (lazy[p] == 0) return;

	int mid = (L + R) >> 1;
	lazy[p] = lazy[p] % 3;
	FOR(i, 1, lazy[p]) {
		swapNode(st[left(p)]);
		swapNode(st[right(p)]);
	}
	lazy[left(p)] += lazy[p];
	lazy[right(p)] += lazy[p];
	lazy[p] = 0;
}

void build(int p, int L, int R) {
	if (L == R) {
		st[p].a = 1, st[p].b = 0, st[p].c = 0;
		return;
	}

	int mid = (L + R) >> 1;
	build(left(p), L, mid);
	build(right(p), mid + 1, R);
	pushUp(p);
}

void updateRangeLazy(int p, int L, int R, int pos1, int pos2, int val) {
	if (pos1 > R || pos2 < L) return;		// Current segment is not within range [pos1 .. pos2]

	// If segment is fully within range
	if (L >= pos1 && R <= pos2) {
		swapNode(st[p]);
		if (L != R) lazy[p] += val;
		return;
	}

	pushDown(p, L, R);

	int mid = (L + R) >> 1;
	updateRangeLazy(left(p), L, mid, pos1, pos2, val);
	updateRangeLazy(right(p), mid + 1, R, pos1, pos2, val);
	pushUp(p);
}

int queryLazy(int p, int L, int R, int pos1, int pos2) {
	if (pos1 > R || pos2 < L) return 0;		// Current segment is not within range [pos1 .. pos2]

	// If segment is fully within range
	if (L >= pos1 && R <= pos2) return st[p].a;

	pushDown(p, L, R);

	int mid = (L + R) >> 1;
	int p1 = queryLazy(left(p), L, mid, pos1, pos2);
	int p2 = queryLazy(right(p), mid + 1, R, pos1, pos2);
	return (p1 + p2);
}


int main()
{
	READ("input.txt");
	//WRITE("output.txt");
	int i, j, k;
	int TC, tc;
	double cl = clock();

	int op, x, y;

	TC = src();

	FOR(tc, 1, TC) {
		printf("Case %d:\n", tc);
		scanf("%d %d", &N, &q);

		memset(lazy, 0, sizeof lazy);
		build(1, 0, N - 1);

		FOR(i, 1, q) {
			scanf("%d %d %d", &op, &x, &y);

			if(op == 0) updateRangeLazy(1, 0, N-1, x, y, 1);
			else printf("%d\n", queryLazy(1, 0, N-1, x, y));
		}
	}
	
	cl = clock() - cl;
	fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

	return 0;
}
