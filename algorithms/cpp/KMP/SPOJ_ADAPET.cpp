// Problem Link : https://www.spoj.com/problems/ADAPET/
// Solved By : iamcrypticcoder
#include <bits/stdc++.h>
using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

// Input Methods
inline int32_t srcInt32() { int ret; scanf("%d", &ret); return ret; }
inline uint32_t srcUInt32() { uint32_t ret; scanf("%u", &ret); return ret; }
inline int64_t srcInt64() { int64_t ret; scanf("%lld", &ret); return ret; }
inline uint64_t srcUInt64() { uint64_t ret; scanf("%llu", &ret); return ret; }

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int64_t solve(string& s, int k) {
    if (k == 1) return (int64_t)s.length();
    int64_t n = (int64_t)s.length();
    vector<int> pi = prefix_function(s);
    int64_t ret = n * k;
    ret -= ((int64_t)(k-1) * pi[n-1]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //READ("../input.txt");
    //WRITE("output.txt");

    int64_t TC, tc;
    double cl = clock();

    cin >> TC;
    for (tc = 1; tc <= TC; tc++) {
        string str;
        int k;
        cin >> str >> k;
        cout << solve(str, k) << "\n";
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
