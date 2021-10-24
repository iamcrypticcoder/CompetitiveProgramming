/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      AC
    Rank :      78 ms
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
#include <unordered_set>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

typedef long long LL;

const long long MOD = 1e9 + 9;
const long long p = 61;
string txt, pattern;
int minBound;


LL bigMod(LL a, LL n, LL m) {
    if (n == 0) return 1;
    LL ret = bigMod(a, n/2, m);
    ret = (ret*ret) % m;
    if (n & 1) ret = (ret * a) % m;
    return ret;
}

int match(string pat) {
    int n = (int)txt.length();
    int m = (int)pat.length();

    long long pPowM = bigMod(p, m-1, MOD);

    long long txtHash = 0;
    long long patHash = 0;
    for (int i = 0; i < m; i++) {
        txtHash = (txtHash * p + txt[i]) % MOD;
        patHash = (patHash * p + pat[i]) % MOD;
    }

    int ret = 0;
    for (int i = 0; i <= n-m; i++) {
        if (txtHash == patHash) {
            ret++;
        }
        if (i < n-m) {
            txtHash = (((txtHash - txt[i]*pPowM) * p) + txt[i+m]) % MOD;
            if (txtHash < 0) txtHash += MOD;
        }
    }
    return ret;
}

string solve() {
    int n = (int)txt.length();
    int m = (int)pattern.length();

    int ret = 0;
    // Binary search over pattern length
    int l = 1, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        string pat = pattern.substr(0, mid);
        int c = match(pat);
        if (c >= minBound) {
            ret = max(ret, mid);
            l = mid+1;
        }
        else r = mid-1;
    }

    return ret == 0 ? "IMPOSSIBLE" : pattern.substr(0, ret);
}

// http://codeforces.com/gym/101466/problem/E
int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    getline(cin, txt);
    getline(cin, pattern);
    cin >> minBound;
    cout << solve() << endl;
}
