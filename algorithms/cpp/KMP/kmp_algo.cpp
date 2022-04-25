// Problem Link :
// Solved By : iamcrypticcoder

#include <bits/stdc++.h>

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
            printf("Pattern found at index %d in T\n", i-j);
            j = pi[j-1];
        }
    }
}

int main() {
    kmpSearch("abdabcabc", "abc");
    printf("\n");
    kmpSearch("abababa", "aba");
    printf("\n");
    kmpSearch("ababacababa", "abacababa");
    printf("\n");
    kmpSearch("AAAA", "A");
    printf("\n");
}

/**
Useful video link - https://www.youtube.com/watch?v=GTJr8OvyEVQ

Suppose pattern =

a a b a a b a a a
0 1 0 1 2 3 4 5 2

 */
