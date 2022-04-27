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

bool isMatch(string& txt, string& pat, int i) {
    int M = (int)pat.length();
    int j = 0;
    while (j < M) {
        if (txt[i+j] != pat[j]) break;
        j++;
    }
    return (j == M);
}

// Find all non-overlapping occurance
vector<int> nonoverlappingOccurance(string& txt, string& pat) {
    int N = txt.size(), M = pat.size();
    long long hashPat = 0, hashTxt = 0;
    long long p = 67, MOD = 1e9 + 7;
    long long pPowM = bigPow(p, M-1, MOD);
    vector<int> ret;

    for (int i = 0; i < M; i++) {
        hashPat = (p * hashPat + pat[i]) % MOD;
        hashTxt = (p * hashTxt + txt[i]) % MOD;
    }
    //printf("Hash of pat = %d\n", hashPat);

    int i = 0;
    while (i <= N-M) {
        if (hashTxt == hashPat && isMatch(txt, pat, i)) {
            ret.push_back(i);
            i += M;                                         // Increase i to i+M
            hashTxt = 0;
            for (int j = 0; j < M && i+j < N; j++)          // Calculate hashTxt again
                hashTxt = (p * hashTxt + txt[i+j]) % MOD;
        } else {
            if (i < N-M) {
                hashTxt = ((p * (hashTxt - txt[i]*pPowM)) + txt[i+M]) % MOD;
                if (hashTxt < 0) hashTxt += MOD;
            }
            i++;
        }
    }
    return ret;
}

int main() {
    READ("../input.txt");

    string txt, pat;

    while (cin >> txt >> pat) {
        vector<int> occurance = nonoverlappingOccurance(txt, pat);
        for (auto& x : occurance)
            cout << x << " ";
        cout << endl;
    }
}

/**

INPUT:
abbabbabba abba
aaaa aa
axaxaxaxa axa

OUTPUT:
0 6
0 2
0 4

*/
