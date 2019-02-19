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

#define MAX_PRIME 10000000

bool flag[MAX_PRIME+7];
VI primes;

struct powerPrime {
    LL p;
    int a;      // p^a
};

void sieveNormal() {
    int i = 2;
    while (i * i <= MAX_PRIME) {
        for (int j = i*i; j <= MAX_PRIME; j += i)
            flag[j] = true;
        while(flag[++i]);
    }
    primes.PB(2);
    for (i = 3; i <= MAX_PRIME; i += 2)
        if (!flag[i]) primes.PB(i);
}

void sieveOptimized() {
    for (int i = 3; i*i <= MAX_PRIME; i += 2) {
        if (!flag[i]) {
            for (int j = i*i; j <= MAX_PRIME; j += 2*i)
                flag[j] = true;
        }
    }
    primes.PB(2);
    for (int i = 3; i <= MAX_PRIME; i += 2) {
        if (!flag[i]) primes.PB(i);
    }
}

bool isPrime(LL n) {
    if(n < 2) return 0;
    if(n <= MAX_PRIME) return (!flag[n]);
    int root = sqrt(n);
    for(int i = 0; primes[i] <= root; i++)
        if(n % primes[i] == 0) return false;
    return true;
}

vector<LL> factorize(LL n)
{
    vector<LL> ret;
    int root = sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        while(!(n % primes[i])) { n /= primes[i]; ret.PB(primes[i]); }
    }
    if(n > 1) ret.PB(n);
    if(n == 1 && ret.size() == 0) ret.PB(1);
    return ret;
}

vector<powerPrime> factorizeAsPower(long long n)
{
    vector<powerPrime> ret;
    powerPrime pp;
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

// This function tells us how many prime p we will get after factorizing n!.
int primeInFactorial(int p, int n)
{
    int ret = 0;
    while(n > 0) {
        n = n / p;
        ret += n;
    }
    return ret;
}

int countDivisors(ULL n)
{
    if(n == 0) return 0;
    int ret = 1;
    int root = (int)sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        int power = 0;
        while(!(n % primes[i])) { n /= primes[i]; power++; }
        if(power > 0) ret *= (power + 1);
    }
    if(n > 1) ret *= 2;
    return ret;
}

ULL sumDivisors(ULL n)
{
    if(n == 0) return 0;
    ULL ret = 1;
    int root = (int)sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        int pi = primes[i];
        ULL tmp = pi;
        while(!(n % pi)) { n /= pi; tmp *= pi; }
        if(tmp > pi) ret *= (tmp - 1) / (pi - 1);
    }
    if(n > 1) ret *= (n*n - 1) / (n - 1);
    return ret;
}

ULL eulerPhi(ULL n)
{
    ULL ret = n;
    int root = (int)sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        int pi = primes[i];
        if(!(n % pi)) ret -= (ret / pi);
        while(n % pi == 0) n /= pi;
    }
    if(n > 1) ret -= (ret / n);
    return ret;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    //sieveNormal();
    sieveOptimized();

    /*
    cout << primes.size() << endl;
    FOR(i, 0, 20) cout << primes[i] << endl;
    cout << isPrime(100000004987) << endl;
    */

    /*
    vector<LL> f = factorize(100000004987);
    FOR(i, 0, f.size()-1) cout << f[i] << endl;
    */

    /*
    vector<powerPrime> f = factorizeAsPower(100000004987);
    FOR(i, 0, f.size()-1) cout << f[i].p << " " << f[i].a << endl;
    */

    /*
    cout << primeInFactorial(5, 10) << endl;
    */

    //cout << countDivisors(36) << endl;
    // cout << sumDivisors(14) << endl;
    //cout << eulerPhi(36) << endl;

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
