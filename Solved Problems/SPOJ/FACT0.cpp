/*
        Problem Link : https://www.spoj.com/problems/FACT0/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : [AC, WA, TLE, RTE] 
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

ULL GCD(ULL a, ULL b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline uint src() { uint ret; scanf("%u", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_PRIME 31622776 + 1000

ULL bitFlag[MAX_PRIME / 64 + 7];
VI primes;

struct PowerPrime {
    ULL p;
    int a;      // p^a
};

void sieveBitwise() {
    for (int i = 3; i*i <= MAX_PRIME; i += 2) {
        if ((bitFlag[i/64] & (1LL << (i%64))) == 0) {
            for (ULL j = i*i; j <= MAX_PRIME; j += 2*i) {
                bitFlag[(j/64)] |= (1L << (j%64));
            }
        }
    }
    primes.PB(2);
    for (ULL i = 3; i <= MAX_PRIME; i += 2)
        if ((bitFlag[i/64] & (1L << (i%64))) == 0) primes.PB(i);
}

bool isPrime(ULL n) {
    if (n < 2) return false;
    if (n != 2 && (n & 1) == 0) return false;
    if(n <= MAX_PRIME) return !(bitFlag[n/64] & (1L << (n%64)));
    int root = sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++)
        if(n % primes[i] == 0) return false;
    return true;
}

vector<PowerPrime> factorizeAsPower(ULL n)
{
    vector<PowerPrime> ret;
    PowerPrime pp;
    int root = sqrt((double)n), power;
    for(int i=0; primes[i] <= root; i++) {
        int power = 0;
        while(!(n % primes[i])) { n /= primes[i]; power++; }
        if(power > 0) {
            pp.p = primes[i], pp.a = power;
            ret.PB(pp);
        }
    }
    if(n > 1) {
        pp.p = n, pp.a = 1;
        ret.PB(pp);
    }
    if(n == 1 && ret.size() == 0) {
        pp.p = 1, pp.a = 1;
        ret.PB(pp);
    }
    return ret;
}

int main()
{

    int i, j, k;
    int TC, tc;
    double cl = clock();

    sieveBitwise();

    ULL n;

    while (scanf("%llu", &n) == 1) {
        if (n == 0) break;

        vector<PowerPrime> list = factorizeAsPower(n);
        printf("%llu^%d ", list[0].p, list[0].a);
        for (i = 1; i < list.SZ; ++i) {
            PowerPrime pp = list[i];
            printf(" %llu^%d", pp.p, pp.a);
        }
        printf("\n");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
