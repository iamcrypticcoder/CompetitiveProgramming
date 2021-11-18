#include <iostream>

typedef long long LL;

// Find a^n % m
// Complexity: O(lg n)
LL bigModRecur(LL a, LL n, LL m) {
    if (n == 0) return 1;
    LL ret = bigModRecur(a, n/2, m);
    ret = (ret * ret) % m;
    if (n & 1) ret = (ret * a) % m;
    return ret;
}

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

// Find (a*b) % m
// Complexity: O(lg a)
LL multiplyMod(LL a, LL b, LL m) {
    if (a == 0 || b == 0) return 0;
    int ret = (2 * multiplyMod(a/2, b, m)) % m;
    if (a & 1) ret = (ret * b) % m;
    return ret;
}

// https://cp-algorithms.com/algebra/binary-exp.html
int main() {

    return 0;
}
