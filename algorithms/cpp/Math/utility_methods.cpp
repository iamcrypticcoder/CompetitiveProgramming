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

int GCD(int a, int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)    {   return (a/GCD(a,b)*b);              }

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

#define MAX 10000

// int to string
string toString(int n) {
    string ret;
    while(n) {
        ret += ((n%10) + '0');
        n /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// Palindrome check
bool isPalin(string str) {
    int l = 0, r = str.length() - 1;
    while(l < r) {
        if(str[l++] != str[r--]) return false;
    }
    return true;
}

// 0->"0", 10->"A", 11->"B"
char valueToChar(int val) {
    if(val < 10) return '0' + val;
    return 'A' + val - 10;
}

// '0'->0, 'A'->10, 'B'->11
int charToValue(char ch) {
    if(ch >= '0' && ch <= '9') return ch - '0';
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
    if(ch >= 'a' && ch <= 'z') return ch - 'a' + 36;
}

// 10-BASE to ANY BASE
// This function converts a 10 base number to any base and return the number as string
// 10 = A, 11 = B, 12 = C ...... 25 = Z
string toBase(int n, int b) {
    if(n == 0) return "0";
    string ret;
    while(n) {
        ret += valueToChar(n % b);
        n /= b;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// ANY BASE to 10-base
LL toDecimal(string val, int b) {
    if(val.length() == 0) return 0;
    LL ret = charToValue(val[0]);
    FOR(i, 1, val.length()-1) ret = (ret * b) + charToValue(val[i]);
    return ret;
}

double nthRoot(double x, int nth) {
    return exp(log(x) / nth);
}

// Compute (a^n) % m
// Acceted UVA No: 10006
LL bigMod(LL a, LL n, LL m) {
    if(n == 0) return 1;
    if(n == 1) return a % m;
    LL ans = bigMod(a, n/2, m);
    ans = (ans * ans) % m;
    if(n % 2 == 1) return ans * a % m;
    return ans;
}

// Calc eular totient function. Count number of relative primes to n which is smaller than n
// Acceted UVA No : 10179, 10299, 10820
double phiFunc(int n)
{
    if(n == 1) return 0;
    double ret = n;

    int root = (double)sqrt(n);
    for(int i=2; i <= root; i++) {
        if(n % i == 0) ret *= (1 - 1.0/(double)i);
        while(n % i == 0) n /= i;
    }

    if(n > 1) ret *= (1 - 1.0/(double)n);
    return ret;
}

// Count number of divisors of n
// Accepted UVA No: 11064
int countDivisors(long long n)
{
    if(n == 1) return 1;
    int ret = 1;

    int root = (int)sqrt(n);
    for(int i=2; i <= root; i++) {
        if(n % i == 0) {
            int power = 0;
            while(n % i == 0) { power++; n /= i; }
            ret *= (power+1);
        }
        if(n == 1) break;
    }
    if(n > 1) ret *= 2;
    return ret;
}

// Calculate sum of divisors of n
LL sumDivisors(long long n)
{
    if(n == 0) return 0;
    LL ret = 1;
    int root = (int)sqrt(n);
    for(int i=2; i <= root; i++) {
        if(n % i == 0) {
            int power = 0;
            while(n % i == 0) { power++; n /= i; }
            ret *= ((LL)(pow(i, power + 1) + 0.5) - 1) / (i - 1);
        }
    }
    if(n > 1) ret *= ((LL)(pow(n, 2.0) + 0.5) - 1) / (n - 1);
    return ret;
}

// This function tells us how many prime P we will get after factorizing n!.
// count = floor(N/p) + floor(N/p^2) + floor(N/p^3) + floor(N/p^4)....
int primeFreq(int p, int n)
{
    int c = 0, i = 0;
    while(++i) {
        int t = n / (int)pow((double)p, (double)i);
        if(t == 0) break;
        c += t;
    }
    return c;
}

// http://en.wikipedia.org/wiki/Derangement
// fact[i] represents n!
/*
int dearrangement(int N)
{
    int ret = 0;
    FOR(i, 0, N) {
        if(i % 2 == 0) ret += fact[N] / fact[i];
        else ret -= fact[N] / fact[i];
    }
    return ret;
}
*/

// Returns number of valid factorization of Any number N.
// For N = 12 Ans is 3. (2 x 2 x 3), (2 x 6), (3 x 4).
int countFactorization(int n, int m)
{
    int ret = 0;
    for(int i = m; i*i <= n; i++)
        if(n % i == 0) ret += countFactorization(n/i, i) + 1;
    if(ret == 0) return 1;
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

    cout << toString(1234567890) << endl;
    cout << isPalin("aa") << endl;
    cout << valueToChar(35) << endl;
    cout << toBase(0, 16) << endl;
    cout << toDecimal("11120", 3) << endl;

    cout << bigMod(3, 4, 13) << endl;

    cout << primeFreq(2, 8) << endl;

    cout << countDivisors(60) << endl;
    cout << sumDivisors(60) << endl;

    cout << countFactorization(5, 2) << endl;

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
