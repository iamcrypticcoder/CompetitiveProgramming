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
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

const int MAX_PRIME = 1e7;
vector<bool> flag;
vector<int> primes;

void sieveBasic() {
    flag = vector<bool>(MAX_PRIME+7, false);
    flag[0] = flag[1] = true;       // Not prime
    int i = 2;
    while (i * i <= MAX_PRIME) {
        for (int j = i*i; j <= MAX_PRIME; j += i)
            flag[j] = true;
        while(flag[++i]);
    }
    primes.push_back(2);
    for (i = 3; i <= MAX_PRIME; i += 2)
        if (!flag[i]) primes.push_back(i);
}

void sieveOptimized() {
    flag = vector<bool>(MAX_PRIME+7, false);
    flag[0] = flag[1] = true;       // Not prime
    for (int i = 3; i*i <= MAX_PRIME; i += 2) {
        if (!flag[i]) {
            for (int j = i*i; j <= MAX_PRIME; j += 2*i)
                flag[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAX_PRIME; i += 2) {
        if (!flag[i]) primes.push_back(i);
    }
}

bool isPrime(LL n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if(n <= MAX_PRIME) return (!flag[n]);
    int root = sqrt(n);
    for(int i = 0; primes[i] <= root; i++)
        if(n % primes[i] == 0) return false;
    return true;
}

vector<LL> factorize(LL n) {
    if (n < 2) return {n};
    vector<LL> ret;
    int root = sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        while(n % primes[i] == 0) {
            n /= primes[i];
            ret.push_back(primes[i]);
        }
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret.push_back(n);
    return ret;
}

// Return prime factorization as p1^a1 * p2*a2 * p3^a3 ... pn*an
vector<pair<int, int>> factorizeAsPower(long long n) {
    if (n < 2) return {{n, 1}};
    vector<pair<int, int>> ret;
    int root = sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int power = 0;
        while(!(n % primes[i])) { n /= primes[i]; power++; }
        ret.push_back({primes[i], power});
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret.push_back({n, 1});
    return ret;
}

int countDivisors(long long n) {
    if(n == 0) return 0;
    int ret = 1;
    int root = sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int power = 0;
        while(!(n % primes[i])) { n /= primes[i]; power++; }
        ret *= (power + 1);
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret *= 2;
    return ret;
}

long long sumDivisors(long long n) {
    if(n == 0) return 0;
    long long ret = 1;
    int root = (int)sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int pi = primes[i];
        LL tmp = pi;
        while(n % pi == 0) { n /= pi; tmp *= pi; }
        ret *= (tmp - 1) / (pi - 1);
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret *= (n*n - 1) / (n - 1);
    return ret;
}

long long eulerPhi(long long n) {
    long long ret = n;
    int root = (int)sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        if (n % primes[i] != 0) continue;
        int pi = primes[i];
        while(n % pi == 0) n /= pi;
        ret -= (ret / pi);
        if (n == 1 || isPrime(n)) break;
    }
    if(n > 1) ret -= (ret / n);
    return ret;
}


// This function tells us how many prime p we will get after factorizing n!.
int primeInFactorial(int p, int n) {
    int ret = 0;
    while(n > 0) {
        n = n / p;
        ret += n;
    }
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
