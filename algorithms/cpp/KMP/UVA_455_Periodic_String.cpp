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

int solve(string str) {
    int n = str.length();
    int ret = str.length();

    vector<int> lps = prefix_function(str);
    if (lps[n-1] != 0 && n % (n - lps[n-1]) == 0)
        return min(lps[n-1], n - lps[n-1]);

    return str.length();
}

// https://onlinejudge.org/external/4/455.pdf
int main() {
    READ("../input.txt");
    // WRITE("output.txt");

    int TC, tc;
    string str;

    cin >> TC;
    for (tc = 1; tc <= TC; tc++) {
        cin >> str;
        printf("%d\n", solve(str));
        if (tc != TC) printf("\n");
    }
}
