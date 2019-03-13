/*
    Problem Link: https://uva.onlinejudge.org/external/125/12532.pdf
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Time : 0.150
	Rank : 891
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

#define MAX 100000

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

// Node for Segment Tree RSQ
struct Node {
    int val;
    int ln, rn;
    Node() {
        ln = rn = -1;
    }
    void combine(Node &a, Node &b) {
        val = a.val + b.val;
    }
};

int N, Q;
int A[MAX + 7];
Node st[8 * MAX + 7];       // Segment Tree node pool
int nodeNum = -1;

int newLeaf(int val) {
    Node node = st[++nodeNum];
    node.val = val;
    return nodeNum;
}

int newParent(int ln, int rn) {
    Node node = st[++nodeNum];
    node.ln = ln;
    node.rn = rn;
    node.combine(st[ln], st[rn]);
    return nodeNum;
}

int build(int l, int r) {
    if (l == r) return newLeaf(A[l]);
    int mid = (l + r) >> 1;
    return newParent(build(l, mid), build(mid+1, r));
}

int updateSingle(int p, int l, int r, int i, int val) {
    if (l == r) return newLeaf(st[p].val + val);
    int mid = (l + r) >> 1;
    if (i <= mid) {
        int ln = updateSingle(st[p].ln, l, mid, i, val);
        return newParent(ln, st[p].rn);
    } else {
        int rn = updateSingle(st[p].rn, mid+1, rn, i, val);
        return newParent(st[p].ln, rn);
    }
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

    

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}