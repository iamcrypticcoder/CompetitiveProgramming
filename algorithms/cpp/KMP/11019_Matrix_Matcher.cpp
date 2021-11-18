/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.150
    Rank :      115
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

typedef long long LL;

inline int src() { int ret; scanf("%d", &ret); return ret; }

const LL p = 263;
const LL MOD = 1e9 + 9;
vector<string> mat, pattern;
int m, n, x, y;

vector<int> prefix_function(vector<LL> s) {
    int n = s.size();
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

int kmpSearch(vector<LL> txt, vector<LL> pat) {
    int n = txt.size();
    int m = pat.size();

    vector<int> pi = prefix_function(pat);
    int ret = 0;
    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++, j++;
        } else {
            if (j != 0) j = pi[j-1];
            else i++;
        }
        if (j == m) {
            ret++;
            j = pi[j-1];
        }
    }
    return ret;
}

int solve(vector<string> mat, vector<string> pattern) {
    n = mat.size();
    m = (n == 0 ? 0 : mat[0].size());
    x = pattern.size();
    y = (x == 0 ? 0 : pattern[0].size());

    if (n == 0 || m == 0 || x == 0 || y == 0) return 0;
    if (x > n || y > m) return 0;

    // Calc power
    LL pw[n];
    memset(pw, 0, sizeof pw);
    pw[0] = 1;
    for (int i = 1; i < n; i++) pw[i] = (pw[i-1] * p) % MOD;

    // Calc hash for each column of pattern
    vector<LL> hashPatCol(y);
    for (int c = 0; c < y; c++) {
        LL h = pattern[0][c];
        for (int r = 1; r < x; r++)
            h = (h + pattern[r][c] * pw[r]) % MOD;
        hashPatCol[c] = h;
    }

    // Calc hash for each column of mat
    LL hashMat[n+1][m];
    memset(hashMat, 0, sizeof hashMat);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            hashMat[i+1][j] = (hashMat[i][j] + mat[i][j] * pw[i]) % MOD;
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << hashMat[i+1][j] << " ";
//        }
//        cout << endl;
//    }

    int ret = 0;
    for (int i = 0, j = x-1; i <= n-x && j < n; i++, j++) {
        vector<LL> matHashRow(m);
        for (int c = 0; c < m; c++) {
            matHashRow[c] = hashMat[j + 1][c] - hashMat[i][c];
            if (matHashRow[c] < 0) matHashRow[c] += MOD;
            //cout << matHashRow[c] << " ";
        }
        //cout << endl;

        vector<LL> patHashRow(y);
        //LL power = pw[n-1-i-x+1];
        for (int c = 0; c < y; c++) {
            patHashRow[c] = (hashPatCol[c] * pw[i]) % MOD;
            //cout << patHashRow[c] << " ";
        }
        //cout << endl;

        ret += kmpSearch(matHashRow, patHashRow);
    }

    return ret;
}

// https://onlinejudge.org/external/110/11019.pdf
int main() {
    READ("../input.txt");
    // WRITE("output.txt");

    int TC, tc;
    int n, m, x, y;

    cin >> TC;
    for (tc = 1; tc <= TC; tc++) {
        cin >> n >> m;
        mat = vector<string>(n);
        for (int i = 0; i < n; i++) cin >> mat[i];

        cin >> x >> y;
        pattern = vector<string>(x);
        for (int i = 0; i < x; i++) cin >> pattern[i];

        cout << solve(mat, pattern) << endl;
    }
}
