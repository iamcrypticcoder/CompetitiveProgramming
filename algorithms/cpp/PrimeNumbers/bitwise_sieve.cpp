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

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

const int MAX_PRIME = 1e7;
ULL bitFlag[MAX_PRIME / 64 + 7];
vector<int> primes;

void sieveBitwise()
{
    for (int i = 3; i*i <= MAX_PRIME; i += 2) {
        if ((bitFlag[i/64] & (1LL << (i%64))) == 0) {
            for (ULL j = i*i; j <= MAX_PRIME; j += 2*i) {
                bitFlag[(j/64)] |= (1L << (j%64));
            }
        }
    }
    primes.push_back(2);
    for (ULL i = 3; i <= MAX_PRIME; i += 2)
        if ((bitFlag[i/64] & (1L << (i%64))) == 0) primes.push_back(i);
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


int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    sieveBitwise();

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
    cout << primeFreq(5, 10) << endl;
    */

    //cout << countDivisors(36) << endl;
    //cout << sumDivisors(60) << endl;
    //cout << eulerPhi(36) << endl;

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
