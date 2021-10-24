/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
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
#include <unordered_set>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

typedef long long LL;

const LL p = 257;
const LL MOD = 1e9 + 9;

long long bigMod(long long a,
                 long long n,
                 long long m) {
    a = a % m;
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ret;
}

// Complexity:
int countPalindromeSubstring(string s) {
    int n = s.length();
    string ss = s;
    reverse(ss.begin(), ss.end());

    LL hash1[n+1], hash2[n+1];
    memset(hash1, 0, sizeof hash1);
    memset(hash2, 0, sizeof hash2);
    for (int i = 0; i < n; i++) {
        hash1[i+1] = (hash1[i] * p + s[i]) % MOD;
        hash2[i+1] = (hash2[i] * p + ss[i]) % MOD;
    }

    for (int i = 0; i < n; i++) {
        // For odd palins
        int l = 0, r = min(i, n-1-i);
        while (l <= r) {
            int mid = (l + r) / 2;

        }
    }

}

int main() {
    READ("../input.txt");

    string s;
    while (cin >> s) {
        cout << countPalindromeSubstring(s) << endl;
    }
}


/**



**/