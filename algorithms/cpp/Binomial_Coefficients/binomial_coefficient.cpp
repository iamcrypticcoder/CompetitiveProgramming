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

const int MAX = 1e7;
const int MOD = 1e8 + 7;
vector<LL> fact;
vector<LL> inv, invFact;

int GCD(int a,int b) {   while(b)b^=a^=b^=a%=b;  return a;   }

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

// Complexity: O(n)
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

// Complexity: O(lg a)
LL inverse(LL a) {
    if (GCD(a, MOD) != 1) return -1;
    return (LL)bigMod(a, MOD-2, MOD);
}

// Complexity: O(lg(min(k, n-k)))
LL nCk1(int n, int k, int m) {
    return fact[n] * inverse(fact[k] * fact[n-k] % MOD) % MOD;
}

// Complexity: O(1)
LL nCk2(int n, int k, int m) {
    return fact[n] * invFact[k] % m * invFact[n-k] % m;
}

int main() {
    preCalFactorial(MOD);
    preCalInserveFactorial(MOD);

    cout << "Using nCk method 1:" << endl;
    for (int n = 1; n <= 10; n++) {
        for (int k = 0; k <= n; k++) {
            printf("%lld ", nCk1(n, k, MOD));
        }
        printf("\n");
    }

    cout << "Using nCk method 2:" << endl;
    for (int n = 1; n <= 10; n++) {
        for (int k = 0; k <= n; k++) {
            printf("%lld ", nCk2(n, k, MOD));
        }
        printf("\n");
    }

    return 0;
}
