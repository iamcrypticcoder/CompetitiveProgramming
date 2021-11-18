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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> matchPattern(string text, string pattern) {
    string str = pattern + "$" + text;
    vector<int> z = z_function(str);

    vector<int> ret;
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == pattern.length())
            ret.push_back(i - pattern.length() - 1);
    }
    return ret;
}

int main() {
    vector<int> v = matchPattern("abababa", "aba");
    for (int x : v)
        cout << "Occurance at " <<  x << endl;
}
