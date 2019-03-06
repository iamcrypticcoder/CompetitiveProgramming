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

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

// Complexity: O(2n-1) = O(n)
void build(int p, int L, int R) {
    if (L == R) {
        st[p] = L;
        return;
    }

    build(left(p), L, (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R);

    int p1 = st[left(p)], p2 = st[right(p)];
    st[p] = (A[p1] <= A[p2] ? p1 : p2);
}

// Complexity: O(lg n)
int query(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st[p];

    int p1 = query(left(p), L, (L + R) / 2, i, j);
    int p2 = query(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;

    return (A[p1] >= A[p2] ? p1 : p2);
}

// Complexity: O(lg n)
void updateSingle(int p, int L, int R, int pos, int val) {
    if (L == R) {
        A[pos] = val;
        st[p] = pos;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) updateSingle(left(p), L, mid, pos, val);
    else updateSingle(right(p), mid + 1, R, pos, val);

    int p1 = st[left(p)], p2 = st[right(p)];
    st[p] = (A[p1] <= A[p2] ? p1 : p2);
}

// Complexity: O(n)
// Update value by val from pos1 to pos2 and modify whole tree
void updateRange(int p, int L, int R, int pos1, int pos2, int val) {
    if (pos1 > R || pos2 < L) return;
    if (L == R) {
        A[L] = val;
        st[p] = L;
        return;
    }
    int mid = (L + R) / 2;
    updateRange(left(p), L, mid, pos1, pos2, val);
    updateRange(right(p), mid + 1, R, pos1, pos2, val);

    int p1 = st[left(p)], p2 = st[right(p)];
    st[p] = (A[p1] <= A[p2] ? p1 : p2);
}

// Update value of parent (p) from it's child
void pushUp(int p) {
    // Need to implement
}

// Populate lazy value of parent (p) to it's child reset it's own lazy value
void pushDown(int p, int L, int R) {
    // Need to implement
}

// Complexity: O(n)
// Update value by val from pos1 to pos2 and modify whole tree
void updateRangeLazy(int p, int L, int R, int pos1, int pos2, int val) {
    // Need to implement
}

// Complexity:
// Query for Lazy Update
int queryLazy(int p, int L, int R, int pos1, int pos2) {
    // Need to implement
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

    // At first reset st and lazy according to your desired value
    memset(st, 0, sizeof st);

    build(1, 0, N-1);

    cout << query(1, 0, N-1, 0, 6) << endl;



    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}