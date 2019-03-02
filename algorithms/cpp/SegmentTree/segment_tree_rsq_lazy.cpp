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

int N;
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
int query(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st[p];

    int p1 = query(left(p), L, (L + R) / 2, i, j);
    int p2 = query(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;

    return (p1 + p2);
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

// Update value of parent (p) from it's child
void pushUp(int p) {
    st[p] = st[left(p)] + st[right(p)];
}

// Populate lazy value of parent (p) to it's child reset it's own lazy value
void pushDown(int p, int L, int R) {
    if (lazy[p] == 0) return;

    int mid = (L + R) >> 1;
    st[left(p)] = (mid - L + 1) * lazy[p];
    st[right(p)] = (R - mid) * lazy[p];
    lazy[left(p)] = lazy[right(p)] = lazy[p];
    lazy[p] = 0;
}

// Complexity: O(n)
// Update value by val from pos1 to pos2 and modify whole tree
void updateRangeLazy(int p, int L, int R, int pos1, int pos2, int val) {
    if (pos1 > R || pos2 < L) return;		// Current segment is not within range [pos1 .. pos2]

    // If segment is fully within range
    if (L >= pos1 && R <= pos2) {
        st[p] = (R - L + 1) * val;
        if (L != R) lazy[p] = val;
        return;
    }

    pushDown(p, L, R);

    int mid = (L + R) >> 1;
    updateRangeLazy(left(p), L, mid, pos1, pos2, val);
    updateRangeLazy(right(p), mid + 1, R, pos1, pos2, val);
    pushUp(p);
}

// Complexity:
// Query for Lazy Update
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

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    int arr[7] = { 8, 7, 3, 9, 5, 1, 10 };
    N = 7;
    FOR(i, 0, N - 1) A[i] = arr[i];

    build(1, 0, N-1);

    cout << query(1, 0, N-1, 0, 1) << endl;

    updateRangeLazy(1, 0, N-1, 0, 2, 1);

    cout << queryLazy(1, 0, N-1, 0, 2) << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}