/*
	Problem Link: https://www.spoj.com/problems/DIV/
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

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

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

#define MAX_PRIME 1000000
#define MAX       1000000

ULL bitFlag[MAX_PRIME / 64 + 7];
VI primes;
int divs[MAX + 7];

void sieveBitwise()
{
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

void preCal() {
    for (int i = 1; i <= MAX; ++i) {
        for (int j = i; j <= MAX ; j += i) {
            divs[j] += 1;
        }
    }
}

bool isPrime(ULL n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return false;
    if(n <= MAX_PRIME) return !(bitFlag[n/64] & (1L << (n%64)));
    int root = sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++)
        if(n % primes[i] == 0) return false;
    return true;
}

bool check(int n) {
    int root = (int)sqrt(n);
    for (int i = 0; primes[i] <= root; ++i) {
        int p1 = primes[i];
        if (n % p1 == 0) {
            int p2 = n / primes[i];
            if (p1 != p2 && isPrime(n / primes[i])) return true;
            else return false;
        }
    }
    return false;
}

int main()
{
    int i, j, k;
    int TC, tc;
    double cl = clock();

    sieveBitwise();
    preCal();

    int counter = 0;
    for (i = 1; i <= MAX; ++i) {
        if (check(divs[i])) {
            counter = (counter + 1) % 9;
            if (counter == 0) printf("%d\n", i);
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
