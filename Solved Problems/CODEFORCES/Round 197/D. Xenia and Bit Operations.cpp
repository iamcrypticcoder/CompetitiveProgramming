/*
  Problem Link: https://codeforces.com/contest/339/problem/D
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
  Status : AC
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

#define MAX (1 << 17)

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

struct Node {
    int result, depth;
    void createLeaf(int val) {
        depth = 1;
        result = val;
    }
    void combine(Node &a, Node &b) {
        depth = a.depth + 1;
        if (depth % 2 == 0) {
            result = a.result | b.result;
        } else {
            result = a.result ^ b.result;
        }
    }
};

int N, M;
int A[MAX + 7];
Node st[2 * MAX + 7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p].createLeaf(A[l]);
        return;
    }

    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid + 1, r);
    st[p].combine(st[left(p)], st[right(p)]);
}

void updateSingle(int p, int l, int r, int pos, int val) {
    if (l == r) {
        st[p].createLeaf(val);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) updateSingle(left(p), l, mid, pos, val);
    else updateSingle(right(p), mid + 1, r, pos, val);

    st[p].combine(st[left(p)], st[right(p)]);
}

Node query() {
    return st[1];
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();


    N = src();
    M = src();

    FOR(i, 0, (1 << N) - 1) A[i] = src();
    build(1, 0, (1 << N) - 1);

    FOR(q, 1, M) {
        int p, b;
        scanf("%d %d", &p, &b);
        updateSingle(1, 0, (1 << N) - 1, p-1, b);
        printf("%d\n", query().result);
    }
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
