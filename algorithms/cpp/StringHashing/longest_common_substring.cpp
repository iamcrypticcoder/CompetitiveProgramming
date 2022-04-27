#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

const int64_t p = 257;
const int64_t MOD = 1e9 + 7;

// Finds a^n % m
int64_t bigPow(int64_t a, int64_t n, int64_t m) {
    a %= m;
    int64_t ret = 1;
    while (n) {
        if (n & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ret;
}

// Complexity: lg(m) * n
int longestCommonSubstring(string& s1, string& s2) {
    int n = s1.length();
    int m = s2.length();
    const int maxLen = max(m, n);
    const int minLen = min(m, n);

    int64_t power[maxLen];
    power[0] = 1;
    for (int i = 1; i < maxLen; i++)
        power[i] = (power[i-1] * p % MOD);

    // Binary search over length of smaller string
    int l = 1, r = minLen;
    while (l <= r) {
        int len = l + (r - l) / 2;

        // hash of first len chars in both s1 and s2
        int64_t s1Hash = 0, s2Hash = 0;
        for (int i = 0; i < len; i++) {
            s1Hash = ((s1Hash * p) + s1[i]) % MOD;
            s2Hash = ((s2Hash * p) + s2[i]) % MOD;
        }
        // Find all hashes of substring of length = len from s1
        unordered_set<int64_t> seen;
        for (int i = 0; i <= n-len; i++) {
            seen.insert(s1Hash);
            if (i < n-len) {
                s1Hash = ((s1Hash - s1[i]*power[len-1]) * p + s1[i+len]) % MOD;
                if (s1Hash < 0) s1Hash += MOD;
            }
        }

        // Find all hashes of substring of length = len from s2
        // Also search in hashes
        bool found = false;
        for (int i = 0; i <= m-len; i++) {
            if (seen.find(s2Hash) != seen.end()) {
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
a a
abc abc
mahbub mahbubmahbub
mahbubRmahbub mahabc
mnoabcxy xyabc
abcde c
abcde x

Output:
1
3
6
3
3
1
0

**/
