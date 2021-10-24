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

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

long long bigMod(long long a,
                 long long n,
                 long long m) {
    a = a % m;
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ret;
}

int solve(string str, int K) {
    int n = str.length();
    long long p1 = 31, p2 = 37;
    long long MOD = 1e9 + 9;
    long long p1PowK = (long long)bigMod(p1, K-1, MOD);
    long long p2PowK = (long long)bigMod(p2, K-1, MOD);

    long long hash1 = 0, hash2 = 0;         // Double hashing
    for (int i = 0; i < K; i++) {
        hash1 = (p1 * hash1 + str[i]) % MOD;
        hash2 = (p2 * hash2 + str[i]) % MOD;
    }
    set<pair<long long, long long>> set;
    for (int i = 0; i <= n-K; i++) {
        pair<long long, long long> p = {hash1, hash2};
        set.insert(p);
        if (i < n-K) {
            hash1 = ((p1 * (hash1 - str[i] * p1PowK)) + str[i + K]) % MOD;
            hash2 = ((p2 * (hash2 - str[i] * p2PowK)) + str[i + K]) % MOD;
            if (hash1 < 0) hash1 += MOD;
            if (hash2 < 0) hash2 += MOD;
        }
    }
    return set.size();
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    int TC = src();
    for (int tc = 1; tc <= TC; tc++) {
        int N = src();
        int K = src();
        getchar();
        string str;
        getline(cin, str);
        printf("%d\n", solve(str, K));
    }
}
