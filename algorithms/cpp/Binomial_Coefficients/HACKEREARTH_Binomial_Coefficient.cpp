/*
    Problem Link : https://www.hackerearth.com/problem/algorithm/binomial-coefficient-1/
    Time :          AC
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

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

typedef long long LL;

const LL MOD = 1e9 + 7;
const LL MAX = 1e6;
vector<LL> fact;
vector<LL> inv, invFact;

// Find a^n % m
// Complexity: O(lg n)
LL bigMod(LL a, LL n, LL m) {
    a = a % m;
    LL ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ret;
}

// Complexity: O(n)
void preCalFactorial(int m) {
    fact = vector<LL>(MAX+7);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= MAX; i++)
        fact[i] = (fact[i-1] * i) % m;
}

// Complexity: O(n) = 1e6
void preCalInserveFactorial(int m) {
    inv = vector<LL>(MAX+7);
    inv[1] = 1;
    invFact = vector<LL>(MAX+7);
    invFact[0] = invFact[1] = 1;
    for(int i = 2; i <= MAX; ++i) {
        inv[i] = m - (m / i) * inv[m % i] % m;
        invFact[i] = (invFact[i-1] * inv[i]) % m;
    }
}

// Complexity: O(1)
LL nCk2(int n, int k, int m) {
    return fact[n] * invFact[k] % m * invFact[n-k] % m;
}

LL solve(int a, int b, int n, int k) {
    LL ret = nCk2(n, n-k, MOD);
    ret = ret * bigMod(a, k, MOD) % MOD;
    ret = ret * bigMod(b, n-k, MOD) % MOD;
    return ret;
}

int main() {
    preCalFactorial(MOD);
    preCalInserveFactorial(MOD);

    int a, b, n, k;
    while (cin >> a >> b >> n >> k) {
        printf("%lld\n", solve(a, b, n, k));
    }

    return 0;
}
