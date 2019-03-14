/*
	Problem Link : https://www.spoj.com/problems/DQUERY/
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Status : AC
	Time : 0.27
	Rank :
	Complexity:
*/

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
typedef pair<uint, uint> PUU;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<uint> VU;
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

ULL GCD(ULL a, ULL b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

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

#define MAX_N 30000
#define MAX_Q 200000
#define MAX_AN 1000007

struct Query {
    uint index;
    uint l, r;

    Query() { }
    Query(uint index, uint l, uint r) {
        this->index = index;
        this->l = l;
        this->r = r;
    }
};

uint N, Q;
uint A[MAX_N + 7];
Query queries[MAX_Q + 7];
uint queryResult[MAX_Q + 7];
int blockSize;

bool comp(Query a, Query b) {
    if (a.l/blockSize == b.l/blockSize) return a.r < b.r;
    return a.l/blockSize < b.l/blockSize;
}

void processQuery() {
    blockSize = (uint)sqrt(N);

    sort(queries, queries + Q, comp);

    int moLeft = 0, moRight = 0;
    uint counter = 0;
    int freq[MAX_AN] = { 0 };

    for (int i = 0; i < Q; ++i) {
        int l = queries[i].l, r = queries[i].r;

        while (moLeft < l) {
            freq[A[moLeft]]--;
            if (freq[A[moLeft]] == 0) counter--;
            moLeft++;
        }

        while (moLeft > l) {
            freq[A[moLeft-1]]++;
            if (freq[A[moLeft-1]] == 1) counter++;
            moLeft--;
        }

        while (moRight <= r) {
            freq[A[moRight]]++;
            if (freq[A[moRight]] == 1) counter++;
            moRight++;
        }

        while (moRight > r+1) {
            freq[A[moRight-1]]--;
            if (freq[A[moRight-1]] == 0) counter--;
            moRight--;
        }

        queryResult[queries[i].index] = counter;
    }
}

int main()
{
    READ("input.txt");
    //WRITE("input.txt");

    int i, j;
    int TC, tc;
    double cl = clock();

    N = srcUInt();
    FOR(i, 0, N-1) A[i] = srcUInt();
    Q = srcUInt();
    FOR(i, 0, Q-1) {
        queries[i].index = i;
        queries[i].l = srcUInt() - 1;
        queries[i].r = srcUInt() - 1;
    }

    processQuery();

    FOR(i, 0, Q-1) printf("%u\n", queryResult[i]);

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
