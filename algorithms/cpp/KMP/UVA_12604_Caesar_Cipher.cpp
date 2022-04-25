// Problem Link :
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

string A, W, S;
unordered_map<char, int> posMap;

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

// Return true if only one occurance found, otherwise false
bool kmpSearch(string& text, string& pattern, vector<int>& pi) {
    int n = text.length();
    int m = pattern.length();

    int ret = 0;
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
        } else {
            if (j != 0) j = pi[j-1];
            else i++;
        }
        if (j == m) {
            ret++;
            if (ret > 1) return false;
            j = pi[j-1];
        }
    }

    return ret == 1;
}

string shift(int k) {
    int n = (int)S.length();
    string ret(n, ' ');
    for (int i = 0; i < n; i++) {
        int newCharPos = (posMap[S[i]] - k + (int)A.length()) % (int)A.length();
        ret[i] = A[newCharPos];
    }
    return ret;
}

void solve() {
    // Build char position map
    for (int i = 0; i < (int)A.length(); i++) posMap[A[i]] = i;

    vector<int> pi = prefix_function(W);

    // We will try all possible shifts k [0..(Size of A-1)]
    vector<int> shiftList;
    for (int k = 0; k < (int)A.length(); k++) {
        string text = shift(k);
        if (kmpSearch(text, W, pi)) shiftList.push_back(k);
    }

    if ((int)shiftList.size() == 0) {
        cout << "no solution\n";
    } else if ((int)shiftList.size() == 1) {
        cout << "unique: " << shiftList[0] << "\n";
    } else {
        cout << "ambiguous:";
        for (auto& x : shiftList) cout << " " << x;
        cout << "\n";
    }
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
        cin >> A >> W >> S;
        solve();
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**
INPUT:

4
ABC
ABC
ABCBBBABC
ABC
ABC
ABCBCAABC
D7a
D7a
D7aaD77aDD7a
ABC
ABC
ABC

OUTPUT:

no solution
unique: 1
ambiguous: 1 2
unique: 0

**/
