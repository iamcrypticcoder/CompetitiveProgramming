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

int N, q;
int A[MAX];
int st[3 * MAX];
int lazy[3 * MAX];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

// Complexity: O(2n-1) = O(n)
void build(int p, int L, int R) {
	if (L == R) {
		st[p] = A[L];
		return;
	}

	build(left(p), L, (L + R) / 2);
	build(right(p), (L + R) / 2 + 1, R);

	st[p] = st[left(p)] + st[right(p)];
}

// Complexity: O(lg n)
int rsq(int p, int L, int R, int i, int j) {
	if (i > R || j < L) return -1;
	if (L >= i && R <= j) return st[p];

	int p1 = rsq(left(p), L, (L + R) / 2, i, j);
	int p2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);

	if (p1 == -1) return p2;
	if (p2 == -1) return p1;

	return p1 + p2;
}

// Complexity: O(lg n)
void updateSingle(int p, int L, int R, int pos, int val) {
	if (L == R) {
		A[pos] = st[p] = val;
		return;
	}
	int mid = (L + R) / 2;
	if (pos <= mid) updateSingle(left(p), L, mid, pos, val);
	else updateSingle(right(p), mid + 1, R, pos, val);

	st[p] = st[left(p)] + st[right(p)];
}

// Complexity: O(n)
// Update value by val from pos1 to pos2 and modify whole tree
/*
void updateRange(int p, int L, int R, int pos1, int pos2, int val) {
	if (pos1 > R || pos2 < L) return;
	if (L == R) {
		A[L] = st[p] = val;
		return;
	}
	int mid = (L + R) / 2;
	updateRange(left(p), L, mid, pos1, pos2, val);
	updateRange(right(p), mid + 1, R, pos1, pos2, val);

	st[p] = st[left(p)] + st[right(p)];
}
*/

void updateRange(int p, int L, int R, int pos1, int pos2, int val) {
	if (pos1 > R || pos2 < L) return;		// Current segment is not within range [pos1 .. pos2]

	// This node needs to be updated
	if (lazy[p] != -1) {
		st[p] = (R - L + 1) * lazy[p];
		if (L != R) {
			int mid = (L + R) / 2;
			st[left(p)] = (mid - L + 1) * lazy[p];
			st[right(p)] = (R - mid) * lazy[p];
			lazy[left(p)] = lazy[right(p)] = lazy[p];
		}
		lazy[p] = -1;
	}

	// If segment is fully within range
	if (L >= pos1 && R <= pos2) {
		st[p] = (R - L + 1) * val;
		if (L != R) {						// If not leaf node
			int mid = (L + R) / 2;
			st[left(p)] = (mid - L + 1) * val;
			st[right(p)] = (R - mid) * val;
			lazy[left(p)] = val;
			lazy[right(p)] = val;
		}
		return;
	}

	int mid = (L + R) / 2;
	updateRange(left(p), L, mid, pos1, pos2, val);
	updateRange(right(p), mid + 1, R, pos1, pos2, val);
	st[p] = st[left(p)] + st[right(p)];
}

int queryRange(int p, int L, int R, int pos1, int pos2) {
	if (pos1 > R || pos2 < L) return 0;		// Current segment is not within range [pos1 .. pos2]

	// This node needs to be updated
	if (lazy[p] != -1) {
		st[p] = (R - L + 1) * lazy[p];
		if (L != R) {
			int mid = (L + R) / 2;
			st[left(p)] = (mid - L + 1) * lazy[p];
			st[right(p)] = (R - mid) * lazy[p];
			lazy[left(p)] = lazy[right(p)] = lazy[p];
		}
		lazy[p] = -1;
	}

	// If segment is fully within range
	if (L >= pos1 && R <= pos2) return st[p];

	int mid = (L + R) / 2;
	int p1 = queryRange(left(p), L, mid, pos1, pos2);
	int p2 = queryRange(right(p), mid+1, R, pos1, pos2);
	return (p1 + p2);
}

int main()
{
	READ("input.txt");
	//WRITE("output.txt");
	int i, j, k;
	int TC, tc;
	double cl = clock();

	int op;
	int x, y, v;

	TC = src();

	FOR(tc, 1, TC) {
		printf("Case %d:\n", tc);
		scanf("%d %d", &N, &q);

		memset(st, 0, sizeof st);
		memset(lazy, -1, sizeof lazy);

		FOR(i, 1, q) {
			op = src();
			if (op == 1) {
				scanf("%d %d %d", &x, &y, &v);
				updateRange(1, 0, N - 1, x, y, v);
			}
			else if (op == 2) {
				scanf("%d %d", &x, &y);
				int sum = queryRange(1, 0, N - 1, x, y);
				//cout << sum << endl;
				if (sum % (y - x + 1) == 0) printf("%d\n", sum / (y-x+1));
				else {
					int g = GCD(sum, y - x + 1);
					printf("%d/%d\n", sum/g, (y - x + 1)/g);
				}
			}
		}
	}

	cl = clock() - cl;
	fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

	return 0;
}
