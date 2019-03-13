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

#define MAX 1000

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }


uint N, M;
int A[MAX+7][MAX+7];
ULL st[3*MAX+7][3*MAX+7];

void buildY(int px, int lx, int rx, int py, int ly, int ry) {
    if (ly == ry) {
        st[px][py] = lx == rx ? A[lx][ly] : st[left(px)][py] + st[right(px)][py];
        return;
    }
    int mid = (ly + ry) >> 1;
    buildY(px, lx, rx, left(py), ly, mid);
    buildY(px, lx, rx, right(py), mid+1, ry);
    st[px][py] = st[px][left(py)] + st[px][right(py)];
}

void buildX(int px, int lx, int rx) {
    if (lx != rx) {
        int mid = (lx + rx) >> 1;
        buildX(left(px), lx, mid);
        buildX(right(px), mid+1, rx);
    }
    buildY(px, lx, rx, 1, 0, M-1);
}

int querySumY(int px, int py, int ly, int ry, int k, int l) {
    if (k == ly && l == ry) return st[px][py];

    int mid = (ly + ry) >> 1;
    if (l <= mid) return querySumY(px, left(py), ly, mid, k, l);
    else if (k > mid) return querySumY(px, right(py), mid+1, ry, k, l);

    return querySumY(px, left(py), ly, mid, k, mid) + querySumY(px, right(py), mid+1, ry, mid+1, l);
}

int querySumX(int px, int lx, int rx, int i, int j, int k, int l) {
    if (i == lx && j == rx) return querySumY(px, 1, 0, M-1, k, l);
    int mid = (lx + rx) >> 1;
    if (j >= mid) querySumX(left(px), lx, mid, i, j, k, l);
    else if (i > mid) querySumX(right(px), mid+1, rx, i, j, k, l);

    return querySumX(left(px), lx, mid, i, mid, k, l) + querySumX(right(px), mid+1, rx, mid+1, j, k, l);
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    cin >> N >> M;
    FOR(i, 0, N-1) FOR(j, 0, M-1) cin >> A[i][j];

    buildX(1, 0, N-1);

    cout << querySumX(1, 0, N-1, 1, 2, 1, 2) << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**

Input:
10  5  7 15
9   6 17  3
0  13  1 19
11  8  2 14


 **/