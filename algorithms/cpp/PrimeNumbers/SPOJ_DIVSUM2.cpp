/*
    Problem Link: https://www.spoj.com/problems/DIVSUM2/
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Time :      4.31
	Rank :      AC
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

//typedef long long LL;
typedef long long ULL;

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

const ULL MAX = 1e8;            // Root of 1e16

vector<bool> flag;
vector<int> primes;

void sieveOptimized() {
    flag = vector<bool>(MAX + 7, false);
    flag[0] = flag[1] = true;   // Not prime
    for (int i = 3; i*i <= MAX; i += 2) {
        if (!flag[i]) {
            for (int j = i*i; j <= MAX; j += 2*i)
                flag[j] = true;
        }
    }
    primes.emplace_back(2);
    for (int i = 3; i <= MAX; i += 2) {
        if (!flag[i]) primes.emplace_back(i);
    }
}

bool isPrime(ULL n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if (n <= MAX) return !flag[n];
    ULL root = (ULL)sqrt(n);
    for(int i = 0; primes[i] <= root; i++)
        if(n % primes[i] == 0) return false;
    return true;
}

ULL sumDivisors(ULL n) {
    if(n == 0) return 0;
    ULL ret = 1;
    ULL root = (ULL) sqrt((double)n);
    for(int i=0; primes[i] <= root; i++) {
        int pi = primes[i];
        if (n % pi == 0) {
            ULL power = pi;
            while(n % pi == 0) { n /= pi; power *= pi; }
            ret *= (power - 1) / (pi - 1);
            if (n == 1 || isPrime(n)) break;
        }
    }
    if(n > 1) ret *= (n+1);
    return ret;
}

ULL solve(ULL n) {
    return sumDivisors(n) - n;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    ULL n;

    double cl = clock();

    sieveOptimized();

    TC = src();
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%llu", &n);
        printf("%llu\n", solve(n));
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
