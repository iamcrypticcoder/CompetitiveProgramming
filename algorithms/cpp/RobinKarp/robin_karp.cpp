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

long long bigMod (long long a, long long n, long long b)
{
    if (n == 0) return 1;
    if (n == 1) return a % b;
    long long ans = bigMod(a,n / 2 ,b);
    ans = (ans * ans) % b;
    if (n % 2 == 1 ) return ans * a % b;
    return ans;
}

// https://cp-algorithms.com/string/rabin-karp.html
// https://cp-algorithms.com/string/string-hashing.html
vector<int> robinKarp(string txt, string pat) {
    int N = txt.size(), M = pat.size();
    long long hashPat = 0, hashTxt = 0;
    long long p = 53, MOD = 1e9 + 9;
    long long pPowM = bigMod(p, M-1, MOD);
    vector<int> ret;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < M; i++) {
        hashPat = (p * hashPat + pat[i]) % MOD;
        hashTxt = (p * hashTxt + txt[i]) % MOD;
    }
    //printf("Hash of pat = %d\n", hashPat);

    // Checking hash of all substring of length M
    for (int i = 0; i <= N-M; i++) {
        //printf("i = %d, Hash of txt window = %d\n", i, hashTxt);
        // Checking hash value of current window
        if (hashTxt == hashPat) {
            // Check for characters one by one
            int j = 0;
            while (j < M) {
                if (txt[i+j] != pat[j]) break;
                j++;
            }
            if (j == M) ret.push_back(i);
        }

        if (i < N-M) {
            hashTxt = ((p * (hashTxt - txt[i]*pPowM)) + txt[i+M]) % MOD;
            if (hashTxt < 0) hashTxt += MOD;
        }
    }
    return ret;
}

int main() {
    string txt, pat;

    while (cin >> txt >> pat) {
        vector<int> occurance = robinKarp(txt, pat);
        for (auto& x : occurance)
            cout << x << " ";
        cout << endl;
    }
}
