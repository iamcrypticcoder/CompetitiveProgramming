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

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

int maxZ(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    int ret = INT_MIN;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        ret = max(ret, z[i]);
    }
    return ret;
}

// Complexity: O(n^2)
int countDistinctSubstring(string text) {
    int n = text.length();
    if (n == 0) return 0;
    int ret = 1;
    for (int len = 2; len <= n; len++) {
        string t = text.substr(0, len);
        reverse(t.begin(), t.end());
        int zMax = maxZ(t);
        ret += ((int)t.length() - zMax);
    }
    return ret;
}

// https://cp-algorithms.com/string/z-function.html
int main() {
    string str;
    while (cin >> str) {
        cout << countDistinctSubstring(str) << endl;
    }
}
