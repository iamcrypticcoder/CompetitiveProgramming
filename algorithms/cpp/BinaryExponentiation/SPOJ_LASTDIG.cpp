#include <iostream>

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
    int a, b;

    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> a >> b;
        cout << bigMod(a, b, 10) << endl;
    }

    return 0;
}
