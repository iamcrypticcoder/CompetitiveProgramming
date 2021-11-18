/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.20
    Rank :      AC
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

vector<int> kmpSearch(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();
    vector<int> pi = prefix_function(pat);

    vector<int> ret;

    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++, j++;
        } else {
            if (j != 0) j = pi[j-1];
            else i++;
        }
        if (j == m) {
            //printf("pattern found at index %d in T\n", i-j);
            ret.push_back(i-j);
            j = pi[j-1];
        }
    }
    return ret;
}

// https://www.spoj.com/problems/NAJPF/
int main() {
    READ("../input.txt");
    // WRITE("output.txt");
    string txt, pat;

    int TC = src();
    for (int tc = 1; tc <= TC; tc++) {
        cin >> txt >> pat;
        vector<int> v = kmpSearch(txt, pat);
        if (v.size() == 0) {
            printf("Not Found\n");
        } else {
            printf("%d\n", v.size());
            for (int& x : v) printf("%d ", x+1);
            printf("\n");
        }
        if (tc < TC) printf("\n");
    }
}
