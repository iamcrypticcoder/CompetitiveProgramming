#include <iostream>

using namespace std;

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
    int TC;
    int x, y, n;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> x >> y >> n;
        cout << bigMod(x, y, n) << endl;
    }
    cin >> x;
    return 0;
}
