/*
    Problem Link: https://www.spoj.com/problems/INVCNT/
    Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
    Time :
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

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)   {   return a/GCD(a,b)*b;                }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 200000

int N;
int arr[MAX + 7];
int tmp[MAX + 7];
int bit[MAX + 7];

void update(int idx, int val) {
    while (idx <= N) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

ULL read(int idx) {
    ULL sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);;
    }
    return sum;
}

uint lowerBound(int x) {
    uint l = 0, r = N-1;
    while (l < r) {
        uint mid = (l + r) >> 1;
        if (x <= tmp[mid]) r = mid;
        else if (x > tmp[mid]) l = mid + 1;
    }
    return l;
}

ULL countInversion() {
    ULL ret = 0;
    FOR(i, 0, N-1) tmp[i] = arr[i];
    sort(tmp, tmp + N);
    memset(bit, 0, sizeof bit);
    FOR(i, 0, N-1) {
        int rank = lowerBound(arr[i]) + 1;
        ret += (read(N) - read(rank));
        update(rank, 1);
    }
    return ret;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    TC = src();
    FOR(tc, 1, TC) {
        N = src();
        FOR(i, 0, N-1) arr[i] = src();

        printf("%llu\n", countInversion());
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
