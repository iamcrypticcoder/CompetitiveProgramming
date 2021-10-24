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

const long long MOD = 1e9 + 9;
const long long p = 61;
string pat, txt;

long long bigMod (long long a, long long n, long long b)
{
    if (n == 0) return 1;
    if (n == 1) return a % b;
    long long ans = bigMod(a,n / 2 ,b);
    ans = (ans * ans) % b;
    if (n % 2 == 1 ) return ans * a % b;
    return ans;
}

int solve() {
    int n = (int)txt.length();
    int m = (int)pat.length();

    long long pPowM = bigMod(p, m-1, MOD);

    long long patHash = 0;
    for (int i = 0; i < m; i++) {
        patHash = ((patHash * p) + pat[i]) % MOD;
    }

    int ret = 0;
    int i = 0;
    string belt;
    long long txtHash = 0;
    while (i < n) {
        belt += txt[i];
        int len = (int)belt.length();
        if (len <= m) {
            txtHash = ((txtHash * p) + belt[len-1]) % MOD;
        } else {
            txtHash = ((p * (txtHash - belt[len-1-m]*pPowM)) + belt[len-1]) % MOD;
            if (txtHash < 0) txtHash += MOD;
        }

        if (txtHash == patHash && belt.substr(len-m) == pat) {
            belt.erase(len-m, m);
            len = (int)belt.length();
            ret++;

            // Calc txtHash of last m chars in belt
            txtHash = 0;
            for (int j = max(0, len-m); j < len; j++) {
                txtHash = ((txtHash * p) + belt[j]) % MOD;
            }
        };

        i++;
    }

    return ret;
}

// https://www.hackerrank.com/contests/womens-codesprint-5/challenges/gift-boxes
int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    int TC = src();
    for (int tc = 1; tc <= TC; tc++) {
        cin >> pat >> txt;
        cout << solve() << endl;
    }
}
