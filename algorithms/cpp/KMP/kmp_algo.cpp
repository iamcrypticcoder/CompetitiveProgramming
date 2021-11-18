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

void kmpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = prefix_function(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
        } else {
            if (j != 0) j = pi[j-1];
            else i++;
        }
        if (j == m) {
            printf("pattern found at index %d in T\n", i-j);
            j = pi[j-1];
        }
    }
}

int main() {
    kmpSearch("abdabcabc", "abc");
    kmpSearch("abababa", "aba");
    kmpSearch("ababacababa", "abacababa");
}

/**
Useful video link - https://www.youtube.com/watch?v=GTJr8OvyEVQ

Suppose pattern =

a a b a a b a a a
0 1 0 1 2 3 4 5 2

 */