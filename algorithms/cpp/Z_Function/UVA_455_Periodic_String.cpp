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

int solve(string str) {
    int n = str.length();
    int ret = str.length();
    vector<int> z = z_function(str);

    for (int i = 1; i < n; i++) {
        if (n % i == 0 && z[i] + i == n) {
            ret = i;
            break;
        }
    }
    return ret;
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
