/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
	Time :		0.716 
	Rank :
	Complexity: Segment Tree
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
int dx[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dyKnightMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define GRAY 1
#define BLACK 2

#define MAX 50007

int N, q;
PII segments[MAX];
int queries[MAX];

// Segment Tree
int st[4 * 3 * MAX];
int lazy[4 * 3 * MAX];

// Array Compression
set<int> s;
int sorted[3 * MAX];
int sortedCount;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

void arrayCompress() {
	FOR(i, 0, N - 1) {
		s.insert(segments[i].ff);
		s.insert(segments[i].ss);
	}
	FOR(i, 0, q - 1) s.insert(queries[i]);

	set<int>::iterator it = s.begin();
	sortedCount = 0;
	while (it != s.end()) {
		sorted[sortedCount++] = *it++;
	}
}

inline int getCompressedValue(int val) {
	return lower_bound(sorted, sorted + sortedCount, val) - sorted;
}

void build() {
	memset(st, 0, sizeof st);
	memset(lazy, 0, sizeof lazy);
}

void pushUp(int p) {
	st[p] = st[left(p)] + st[right(p)];
}

void pushDown(int p, int L, int R) {
	if (lazy[p] == 0) return;

	int mid = (L + R) >> 1;
	st[left(p)] += (mid - L + 1) * lazy[p];
	st[right(p)] += (R - mid) * lazy[p];
	lazy[left(p)] += lazy[p];
	lazy[right(p)] += lazy[p];

	lazy[p] = 0;
}

void updateRangeLazy(int p, int L, int R, int pos1, int pos2, int val) {
	if (pos1 > R || pos2 < L) return;		// Current segment is not within range [pos1 .. pos2]

											// If segment is fully within range
	if (L >= pos1 && R <= pos2) {
		st[p] += (R - L + 1) * val;
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
	if (L >= pos1 && R <= pos2) return st[p];

	pushDown(p, L, R);

	int mid = (L + R) >> 1;
	int p1 = queryLazy(left(p), L, mid, pos1, pos2);
	int p2 = queryLazy(right(p), mid + 1, R, pos1, pos2);
	return (p1 + p2);
}

void processSegments() {
	build();
	FOR(i, 0, N - 1) {
		PII seg = segments[i];
		int x = getCompressedValue(seg.ff);
		int y = getCompressedValue(seg.ss);

		updateRangeLazy(1, 0, sortedCount - 1, x, y, 1);
	}
}


int main()
{
	int i, j, k;
	int TC, tc;

	int x, y;

	TC = src();

	FOR(tc, 1, TC) {
		printf("Case %d:\n", tc);
		scanf("%d %d", &N, &q);
		FOR(i, 0, N - 1) scanf("%d %d", &segments[i].ff, &segments[i].ss);
		FOR(i, 0, q - 1) scanf("%d", &queries[i]);

		arrayCompress();
		processSegments();

		FOR(i, 0, q - 1) {
			int x = getCompressedValue(queries[i]);
			printf("%d\n", queryLazy(1, 0, sortedCount - 1, x, x));
		}

		s.clear();
	}

	return 0;
}

/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
	Time :		0.512 
	Rank :
	Complexity:	BIT
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
int dx[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dyKnightMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define GRAY 1
#define BLACK 2

#define MAX 50007

int N, q;
PII segments[MAX];
int queries[MAX];

// BIT
int tree[3 * MAX + 1];

// Array Compression
set<int> s;
int sorted[3 * MAX];
int sortedCount;


void arrayCompress() {
	FOR(i, 0, N - 1) {
		s.insert(segments[i].ff);
		s.insert(segments[i].ss);
	}
	FOR(i, 0, q - 1) s.insert(queries[i]);

	set<int>::iterator it = s.begin();
	sortedCount = 0;
	while (it != s.end()) {
		sorted[sortedCount++] = *it++;
	}
}

inline int getCompressedValue(int val) {
	return lower_bound(sorted, sorted + sortedCount, val) - sorted;
}

void build() {
	memset(tree, 0, sizeof tree);
}

/*
Complexity: O(lg N)
*/
void update(int idx, int val) {
	while (idx <= sortedCount + 1) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

/*
Complexity: O(lg N)
*/
int read(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

/*
Complexity: c * O(lg N)
*/
int readSingle(int idx) {
	int sum = tree[idx];					// sum will be decreased
	if (idx > 0) {							// special case
		int z = idx - (idx & -idx);			// make z first
		idx--;								// idx is no important any more, so instead y, you can use idx
		while (idx != z) {					// at some iteration idx (y) will become z
			sum -= tree[idx];
			idx -= (idx & -idx);			// substruct tree frequency which is between y and "the same path"
		}
	}
	return sum;
}

void processSegments() {
	build();
	FOR(i, 0, N - 1) {
		PII seg = segments[i];
		int x = getCompressedValue(seg.ff);
		int y = getCompressedValue(seg.ss);

		update(x + 1, 1);
		update(y + 2, -1);
	}
}


int main()
{
	int i, j, k;
	int TC, tc;


	int x, y;

	TC = src();

	FOR(tc, 1, TC) {
		printf("Case %d:\n", tc);
		scanf("%d %d", &N, &q);
		FOR(i, 0, N - 1) scanf("%d %d", &segments[i].ff, &segments[i].ss);
		FOR(i, 0, q - 1) scanf("%d", &queries[i]);

		arrayCompress();
		processSegments();

		FOR(i, 0, q - 1) {
			int x = getCompressedValue(queries[i]);
			printf("%d\n", read(x + 1));
		}

		s.clear();
	}

	return 0;
}

/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
	Time :		0.508
	Rank :
	Complexity:	Partial Sum
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
int dx[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dyKnightMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 50007

int N, q;
PII segments[MAX];
int queries[MAX];
int sorted[3 * MAX];
int sum[3 * MAX];
int sortedCount;
set<int> s;

void arrayCompress() {
	FOR(i, 0, N - 1) {
		s.insert(segments[i].ff);
		s.insert(segments[i].ss);
	}
	FOR(i, 0, q - 1) s.insert(queries[i]);

	set<int>::iterator it = s.begin();
	sortedCount = 0;
	while (it != s.end()) {
		sorted[sortedCount++] = *it++;
	}
}

inline int getCompressedValue(int val) {
	return lower_bound(sorted, sorted + sortedCount, val) - sorted;
}

void partialSum() {
	memset(sum, 0, sizeof sum);
	FOR(i, 0, N - 1) {
		PII seg = segments[i];
		int x = getCompressedValue(seg.ff);
		int y = getCompressedValue(seg.ss);
		sum[x] += 1;
		sum[y + 1] -= 1;
	}
	int s = 0;
	FOR(i, 0, sortedCount) sum[i] = (s += sum[i]);
}


int main()
{

	int i, j, k;
	int TC, tc;

	int x, y;

	TC = src();

	FOR(tc, 1, TC) {
		printf("Case %d:\n", tc);
		scanf("%d %d", &N, &q);
		FOR(i, 0, N - 1) scanf("%d %d", &segments[i].ff, &segments[i].ss);
		FOR(i, 0, q - 1) scanf("%d", &queries[i]);

		arrayCompress();
		partialSum();

		FOR(i, 0, q - 1) {
			printf("%d\n", sum[getCompressedValue(queries[i])]);
		}

		s.clear();
	}

	return 0;
}
