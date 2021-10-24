/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      WA after TC 32
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

// Complexity: lg(m) * n
int longestCommonSubstring(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    LL power[n];
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i-1] * p % MOD);

    // Binary search over length of smaller string
    int l = 1, r = min(m, n);
    while (l <= r) {
        int len = (l + r) / 2;
        if (len > m) {
            r = len-1;
            continue;
        }

        // hash of first len chars in both s1 and s2
        LL s1Hash = 0, s2Hash = 0;
        for (int i = 0; i < len; i++) {
            s1Hash = ((s1Hash * p) + s1[i]) % MOD;
            s2Hash = ((s2Hash * p) + s2[i]) % MOD;
        }
        // Find all hashes of substring of length = len from s1
        set<LL> hashes;
        for (int i = 0; i <= n-len; i++) {
            hashes.insert(s1Hash);
            if (i < n-len) {
                s1Hash = ((s1Hash - s1[i]*power[len-1]) * p + s1[i+len]) % MOD;
                if (s1Hash < 0) s1Hash += MOD;
            }
        }

        // Find all hashes of substring of length = len from s2
        // Also search in hashes
        bool found = false;
        for (int i = 0; i <= m-len; i++) {
            if (hashes.find(s2Hash) != hashes.end()) {
                found = true;
                break;
            }
            if (i < m-len) {
                s2Hash = ((s2Hash - s2[i]*power[len-1]) * p + s2[i+len]) % MOD;
                if (s2Hash < 0) s2Hash += MOD;
            }
        }

        if (found) l = len+1;
        else r = len-1;
    }

    return l-1;
}

int main() {
    READ("../input.txt");

    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << longestCommonSubstring(s1, s2) << endl;
    }
}

/**
Input:

-~^v-
^--v
-~
-~v^^^^^v-
~-~-v--~^
~^--^~-v
^^^v-v^^v-v-v~v-
vv^v-^~~^v^~^vv~^^-
~~~vv~-~~vv~v-v--~-^-~^~-^^
~^~--v~-

Output:

1
2
3
3
4


*/