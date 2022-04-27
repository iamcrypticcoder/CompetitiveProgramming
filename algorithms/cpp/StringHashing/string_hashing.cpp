#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

// This function calculate hash with formula :
// Ex: mahbub
// m * p^0 + a * p^1 + h * p^2 + b * p^3 + u * p^4 + b * p^5
int64_t computeHash1(string str) {
    int n = str.length();
    int64_t p = 53, MOD = 1e9 + 9;

    int64_t ret = 0;
    int64_t power = 1;
    for (int i = 0; i < n; i++) {
        ret = (ret + str[i] * power) % MOD;
        power *= p;
    }
    return ret;
}

// This function calculate hash with formula :
// Ex: mahbub
// m * p^5 + a * p^4 + h * p^3 + b * p^2 + u * p^1 + b * p^0
int64_t computeHash2(string str) {
    int n = str.length();
    int64_t p = 53, MOD = 1e9 + 9;
    int64_t ret = 0;
    for (int i = 0; i < n; i++) {
        ret = (p * ret + str[i]) % MOD;
    }
    return ret;
}

/**
 * Blog on string hashing
 * https://codeforces.com/blog/entry/60445
 */
int main() {
    string txt;
    while (cin >> txt) {
        printf("%s -> %lld\n", txt.c_str(), computeHash1(txt));
        printf("%s -> %lld\n", txt.c_str(), computeHash2(txt));
    }
}

