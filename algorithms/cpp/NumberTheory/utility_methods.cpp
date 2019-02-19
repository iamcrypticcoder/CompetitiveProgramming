/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
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

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

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

#define MOD 100000007

// Compute (a^n) % m
// Acceted UVA No: 10006
ULL bigMod(ULL a, ULL n, ULL m) {
    if (n == 0) return 1;
    if (n == 1) return a % m;
    ULL ret = bigMod(a, n/2, m);
    ret = (ret * ret) % m;
    if (n % 2 == 1) return (ret * a) % m;
    return ret;
}

// Function to find (1/a mod m).
// This function can find mod inverse if m are prime
ULL modInverseFarmetsTheorem(ULL a, ULL m) {
    if (GCD(a, m) != 1) return -1;

    return (ULL)bigMod(a, m-2, m);
}

ULL extendedEuclid(ULL a, ULL b, ULL xy[]) {
    if (a == 0) {
        xy[0] = 0; xy[1] = 1;
        return b;
    }

    ULL xyPrev[2];
    long gcd = extendedEuclid(b % a, a, xyPrev);

    xy[0] = xyPrev[1] - (b/a) * xyPrev[0];
    xy[1] = xyPrev[0];

    return gcd;
}

// Function to find (1/a mod m).
// This function can find mod inverse if a and m are coprime
ULL modInverseExtendedEuclid(ULL a, ULL m) {
    ULL xy[2];
    long gcd = extendedEuclid(a, m, xy);

    if (gcd != 1) return -1;

    // in case xy[0] is negetive, adding m will make it positive
    ULL ret = (xy[0] % m + m) % m;

    return ret;
}

// This function finds ncr using modular multiplicative inverse
ULL ncr(ULL n, ULL r, ULL m) {
    if (n == r) return 1;
    if (r == 1) return n;

    ULL start = n - min(r, n - r) + 1;

    ULL ret = 1;
    for (long i = start; i <= n; i++) ret = (ret * i) % m;

    ULL until = min(r, n - r), denom = 1;
    for (long i = 1; i <= until; i++) denom = (denom * i)  % m;

    ret = (ret * modInverseFarmetsTheorem(denom, m)) % m;

    return ret;
}

// Another implementation of ncr
ULL ncr2(ULL n, ULL r, ULL m) {
    if (n == r) return 1;
    if (r == 1) return n;

    ULL fact[n];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i-1] * i) % m;

    ULL ret = fact[(int)n];
    ret = ret * modInverseFarmetsTheorem(fact[(int)r], m) % m;
    ret = ret * modInverseFarmetsTheorem(fact[(int)(n-r)], m) % m;

    return ret;
}

int main() {
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;



    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}