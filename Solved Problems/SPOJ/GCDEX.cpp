/*
        Problem Link : https://www.spoj.com/problems/GCDEX/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : GCDEX
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

ULL GCD (ULL a, ULL b) { while (b)b ^= a ^= b ^= a %= b;  return a; }
ULL LCM (ULL a, ULL b) { ULL g = GCD(a, b); return (a/g) * b; }

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

#define MAX 1000000

uint bigPrime[MAX + 7];
ULL gcdSum[MAX + 7];
ULL DP[MAX + 7];

// Main idea for faster pre cal is to use result of previous gcdSum.
// Suppose we need to calc gcdSum(12), then we can use result of gcdSum(4)
// and multiply formula part for prime 3.
void preCal() {
    memset(bigPrime, -1, sizeof bigPrime);

    for (int i = 2; i <= MAX; ++i) {
        if (bigPrime[i] == -1) {
            bigPrime[i] = i;
            // Only for primes up to root of MAX
            if (i <= 2000)
                for (int j = i*i; j <= MAX; j += i) bigPrime[j] = i;
        }
    }

    gcdSum[1] = 1;
    DP[1] = 0;
    for (int i = 2; i <= MAX; ++i) {
        int p = bigPrime[i];
        int a = 0;
        ULL pa = 1;
        int tmp = i;

        while (tmp % p == 0) {
            a++;
            pa *= p;
            tmp /= p;
        }
        gcdSum[i] = ((a+1) * pa - a * (pa / p)) * gcdSum[tmp];
        DP[i] = DP[i-1] + gcdSum[i] - i;
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    preCal();

    int n;

    while (scanf("%d", &n) == 1) {
        if (n == 0) break;

        printf("%llu\n", DP[n]);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
