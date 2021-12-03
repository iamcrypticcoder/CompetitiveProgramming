/*
    Problem Link: https://www.spoj.com/problems/NAKANJ/
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Time :  AC 0.00
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
#include <limits.h>
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

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
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

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1000000

PII source, sink;
int dist[8][8];
char color[8][8];

bool inline onGrid(int i, int j) {
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

void bfs() {
    PII u, v;

    FOR(i, 0, 7) FOR(j, 0, 7) dist[i][j] = INT_MAX;
    memset(color, WHITE, sizeof color);

    queue<PII> Q;

    Q.push(source);
    color[source.ff][source.ss] = GRAY;
    dist[source.ff][source.ss] = 0;

    while (!Q.empty()) {
        u = Q.front(); Q.pop();

        FOR(i, 0, 7) {
            v.ff = u.ff + dxKnightMove[i];
            v.ss = u.ss + dyKnightMove[i];
            if (!onGrid(v.ff, v.ss)) continue;

            if (color[v.ff][v.ss] == WHITE) {
                color[v.ff][v.ss] = GRAY;
                dist[v.ff][v.ss] = dist[u.ff][u.ss] + 1;
                Q.push(v);
            }
        }
    }
}

int main() {
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    string str[2];

    TC = srcInt();
    FOR(tc, 1, TC) {
        cin >> str[0] >> str[1];
        source = {str[0][0] - 'a', str[0][1] - '1'};
        sink = {str[1][0] - 'a', str[1][1] - '1'};

        bfs();

        cout << dist[sink.ff][sink.ss] << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
