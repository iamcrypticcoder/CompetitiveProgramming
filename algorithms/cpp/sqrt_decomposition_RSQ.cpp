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

#define MAX 100000

struct Query {
    int idx;
    int l, r;

    Query() { }
    Query(int idx, int l, int r) {
        this->idx = idx;
        this->l = l;
        this->r = r;
    }
};

int N, Q;
int A[MAX + 7];
Query queries[MAX + 7];
uint blockSize;
vector<LL> blockSums;

void preProcess() {
    blockSize = (uint)sqrt(N) + 1;
    blockSums = vector<LL>(blockSize, 0);
    FOR(i, 0, N) blockSums[i / blockSize] += A[i];
}

LL query(int l, int r) {
    LL ret = 0;
    int blockL = l / blockSize;
    int blockR = r / blockSize;
    if (blockL == blockR) {
        FOR(i, l, r) ret += A[i];
    } else {
        FOR(i, l, (blockL+1)*blockSize-1) ret += A[i];
        FOR(i, blockL+1, blockR-1) ret += blockSums[i];
        FOR(i, blockR*blockSize, r) ret += A[i];
    }
    return ret;
}

int main()
{
    //READ("input.txt");
    //WRITE("input.txt");

    int i, j;
    int TC, tc;
    double cl = clock();

    N = 9;
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    FOR(i, 0, N-1) A[i] = a[i];
    preProcess();

    Q = 3;
    queries[0] = Query(0, 0, 4);
    queries[1] = Query(1, 1, 3);
    queries[2] = Query(2, 2, 4);

    FOR(i, 0, Q-1) printf("%lld\n", query(queries[i].l, queries[i].r));

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
