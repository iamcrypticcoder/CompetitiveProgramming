#include <iostream>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;

const LL MOD = 10000007;

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

int main() {
    READ("../input.txt");
    int n, k;

    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        LL ans = (2 * bigMod(n-1, k, MOD)) % MOD;
        ans = (ans + bigMod(n, k, MOD)) % MOD;
        ans = (ans + 2*bigMod(n-1, n-1, MOD)) % MOD;
        ans = (ans + bigMod(n, n, MOD)) % MOD;

        printf("%lld\n", ans);
    }

    return 0;
}

/*
 * Simplying the given expression
 *  = Zn + Zn-1 - 2Zn-2
 *  = 2 * (n-1)^k + n^k + 2 * (n-1)^(n-1) + n^n
 *
 */