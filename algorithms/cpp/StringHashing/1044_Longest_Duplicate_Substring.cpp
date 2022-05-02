#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;
const int64_t p = 53;

class Solution {
public:
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

    bool manualCheck(string& s, int i, int j, int len) {
        int n = (int)s.length();
        while (len && i < n && j < n) {
            if (s[i] != s[j]) return false;
            i++, j++;
            len--;
        }
        return true;
    }

    // O(n)
    string check(string& s, int len) {
        if (len == 0) return "";

        int n = (int)s.length();
        int64_t pPowLen = bigPow(p, len-1, MOD);

        int64_t hash = 0;
        for (int i = 0; i < len; i++)
            hash = (p * hash + s[i]) % MOD;

        unordered_map<int64_t, int> mp;
        mp[hash] = 0;

        for (int i = 0; i < n-len; i++) {
            hash = (p * (hash - s[i]*pPowLen) + s[i+len]) % MOD;
            if (hash < 0) hash += MOD;

            if (mp.find(hash) == mp.end()) {
                mp[hash] = i+1;
            } else {
                int x = mp[hash];
                int y = i+1;
                if (manualCheck(s, x, y, len)) {
                    return s.substr(y, len);
                } else {
                    mp[hash] = i+1;
                }
            }
        }

        return "";
    }

    // O (n lg n)
    string longestDupSubstring(string s) {
        int n = (int)s.length();
        int l = 0, r = n;
        string ret = "";
        while (l <= r) {
            int mid = l + (r-l)/2;
            string res = check(s, mid);
            if (res.length() > ret.length()) ret = res;
            if (res == "") r = mid-1;
            else l = mid+1;
        }
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.longestDupSubstring("abcd") << endl;
    cout << sol.longestDupSubstring("banana") << endl;
    cout << sol.longestDupSubstring("aaaa") << endl;

    return 0;
}
