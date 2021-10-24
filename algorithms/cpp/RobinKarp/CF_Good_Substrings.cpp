/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      Accepted
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

const long long p = 31;
const long long MOD = 1e9 + 9;
vector<bool> isGood;
vector<vector<int>> charCnt;

bool isGoodSubStr(int l, int r, int k) {
    vector<int> v(26, 0);
    int badCnt = 0;
    for (int i = 0; i < 26; i++) {
        if (l > 0) v[i] = charCnt[r][i] - charCnt[l - 1][i];
        else v[i] = charCnt[r][i];
        if (false == isGood[i]) badCnt += v[i];
        if (badCnt > k) return false;
    }
    return true;
}

int solve(string str, int k) {
    int n = (int)str.length();

    // Build char cumulative frequency table
    charCnt = vector<vector<int>>(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (i > 0) charCnt[i][c-'a'] = charCnt[i-1][c-'a'];
            if (str[i] == c) charCnt[i][c-'a']++;
        }
    }

    // Build power table
    vector<long long> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i-1] * p) % MOD;

    // Calc hash of string
    vector<long long> h(n+1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + str[i] * power[i]) % MOD;

    int ret = 0;
    for (int len = 1; len <= n; len++) {
        set<long long> seen;
        for (int i = 0; i <= n-len; i++) {
            long long hash = (h[i + len] - h[i] + MOD) % MOD;
            hash = (hash * power[n-1-i]) % MOD;
            if (seen.find(hash) == seen.end()) {
                if (isGoodSubStr(i, i+len-1, k))
                    ret++;
                seen.insert(hash);
            }
        }
    }
    return ret;
}

// Problem Link - http://codeforces.com/contest/271/problem/D
int main() {
    //READ("../input.txt");
    //WRITE("output.txt");

    string str, goodStr;
    int k;

    cin >> str;
    cin >> goodStr;
    isGood = vector<bool>(26);
    for (int i = 0; i < 26; i++)
        isGood[i] = (goodStr[i] == '0' ? false : true);
    cin >> k;

    cout << solve(str, k) << endl;
}