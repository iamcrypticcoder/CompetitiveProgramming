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
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAXN 100

/*
Ref: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
*/

int N;
int tree[MAXN + 1];

/*
Complexity: O(lg N)
*/
void update(int idx, int val) {
	while (idx <= N) {
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

/*
Find index with given cumulative frequency. Dont know which index will be returned
Complexity: O(lg N)
*/
int find(int cumFre) {
	int idx = 0;
	int bitMask = N & -N;
	while (bitMask && idx <= N) {
		int tIdex = idx + bitMask;
		if (cumFre == tree[tIdex]) return tIdex;
		if (cumFre > tree[tIdex]) {
			idx = tIdex;
			cumFre -= tree[tIdex];
		}
		bitMask >>= 1;
	}
	if (cumFre) return -1;
	else return idx;
}

/*
Find greatest index with given cumulative frequency.
Complexity: O(lg N)
*/
int findG(int cumFre) {
	int idx = 0;
	int bitMask = N & -N;
	while ((bitMask != 0) && (idx < N)) {
		int tIdx = idx + bitMask;
		if (cumFre >= tree[tIdx]) {
			// if current cumulative frequency is equal to cumFre,
			// we are still looking for higher index (if exists)
			idx = tIdx;
			cumFre -= tree[tIdx];
		}
		bitMask >>= 1;
	}
	if (cumFre != 0)
		return -1;
	else
		return idx;
}


int main()
{
	READ("input.txt");
	//    WRITE("output.txt");
	int i, j, k;
	int TC, tc;
	int idx, val;

	while (scanf("%d", &N) == 1) {
		FOR(i, 1, N) {
			scanf("%d", &val);
			update(i, val);
		}

		i = 1;
		while (scanf("%d", &idx) == 1) {
			printf("%d %d %d\n", i++, readSingle(idx), read(idx));
		}

		cout << find(9) << endl;
		cout << findG(9) << endl;
	}

	return 0;
}

/*
Input:
16
1 0 1 1 1 0 1 0 1 1 1 1 0 1 1 0

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16

*/
