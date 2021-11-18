/*
    Problem Link : https://www.codechef.com/LTIME24/problems/NWAYS/
    Time :      Partially Accepted
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
const LL MAX = 2e6;
vector<LL> fact;
vector<LL> inv, invFact;

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
    for(int i = 2; i <= MAX; ++i)
        inv[i] = m - (m/i) * inv[m%i] % m;

    invFact = vector<LL>(MAX+7);
    invFact[0] = invFact[1] = 1;
    for (int i = 2; i <= MAX; i++)
        invFact[i] = (invFact[i-1] * inv[i]) % m;
}

// Complexity: O(1)
LL nCk2(int n, int k, int m) {
    return fact[n] * invFact[k] % m * invFact[n-k] % m;
}

LL solve(int n, int k) {
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        int x = k, y = i;
        LL multi = (n-i) * (i == 0 ? 1 : 2);
        LL tmp = nCk2(x+y, y, MOD) * multi % MOD;
        ret = (ret + tmp) % MOD;
    }
    return ret;
}

int main() {

    preCalFactorial(MOD);
    preCalInserveFactorial(MOD);

    int TC = srcInt();
    for (int tc = 1; tc <= TC; tc++) {
        int n = srcInt();
        int k = srcInt();

        printf("%lld\n", solve(n, k));
    }

    return 0;
}


/**

Suppose N = 4, K = 5

A      ----   B
0, 1   ----  5, 1
0, 2   ----  5, 2
0, 3   ----  5, 3
0, 4   ----  5, 4





**/