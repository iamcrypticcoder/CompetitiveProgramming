/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      AC
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
#include <unordered_map>
#include <limits.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string solve(string pat) {
    string txt = pat;
    reverse(txt.begin(), txt.end());
    int n = txt.length();
    int m = pat.length();

    vector<int> pi = prefix_function(pat);
    int ret = INT_MIN;
    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++, j++;
            ret = max(ret, j);
        } else {
            if (j != 0) j = pi[j-1];
            else i++;
        }
        if (j == m) {
            j = pi[j-1];
        }
    }

    string tmp = pat.substr(0, ret);
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int main() {
    //READ("../input.txt");

    int TC = src();
    string s;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> s;
        cout << solve(s) << endl;
    }
}

