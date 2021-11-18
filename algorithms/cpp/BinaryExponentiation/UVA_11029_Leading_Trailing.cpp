#include <iostream>
#include <math.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;

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
    int TC;
    int n, k;

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> n >> k;
        int ttt = bigMod(n, k, 1000);
        double power = (double)k * log10(n);
        int firstDigits = pow(10, power - floor(power)) * 100.0;
        printf("%03d...%03d\n", firstDigits, ttt);
    }

    return 0;
}
