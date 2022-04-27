#include <bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

// Finds a^n % m
int64_t bigPow(int64_t a, int64_t n, int64_t m) {
    a %= m;
    int64_t ret = 1;
    while (n) {
        if (n & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ret;
}

// https://cp-algorithms.com/string/rabin-karp.html
// https://cp-algorithms.com/string/string-hashing.html
vector<int> robinKarp(string txt, string pat) {
    int N = txt.size(), M = pat.size();
    long long hashPat = 0, hashTxt = 0;
    long long p = 67, MOD = 1e9 + 7;
    long long pPowM = bigPow(p, M-1, MOD);
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
    READ("../input.txt");
    string txt, pat;

    while (cin >> txt >> pat) {
        vector<int> occurance = robinKarp(txt, pat);
        for (auto& x : occurance)
            cout << x << " ";
        cout << endl;
    }
}
