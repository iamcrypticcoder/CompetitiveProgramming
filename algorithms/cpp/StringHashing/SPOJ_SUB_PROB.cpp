/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      TLE
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

const long long p = 67;
const long long MOD = 1e9+9;

long long computeHash(string str) {
    long long hash = 0;
    long long power = 1;
    for (int i = 0; i < str.length(); i++) {
        hash = (hash + str[i] * power) % MOD;
        power = (power*p) % MOD;
    }
    return hash;
}

void solve(string text, vector<string> patList) {
    int n = text.length();

    // Calc powers
    vector<long long> power(n);
    power[0] = 1;                   // p^0 = 1
    for (int i = 1; i < n; i++)
        power[i] = (power[i-1] * p) % MOD;  // p^i

    // Calc hash of text
    vector<long long> hash(n+1);
    hash[0] = 0;
    for (int i = 0; i < n; i++)
        hash[i+1] = (hash[i] + text[i] * power[i]) % MOD;

    // Complexity = O(patList.size() * text.size())
    for (string& pat : patList) {
        bool isFound = false;
        int m = pat.length();
        long long patHash = computeHash(pat);
        for (int i = 0; i <= n-m; i++) {
            long long curHash = (hash[i+m] - hash[i] + MOD) % MOD;
            long long x = (patHash * power[i]) % MOD;
            if (curHash == x) {
                isFound = true;
                break;
            }
        }
        printf("%c\n", isFound ? 'Y' : 'N');
    }
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    int n;
    string text;
    vector<string> patList;

    cin >> text;
    n = src();
    patList = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> patList[i];
    }

    solve(text, patList);
}
