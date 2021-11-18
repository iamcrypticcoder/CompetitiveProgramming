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

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int src() { int ret; scanf("%d", &ret); return ret; }

int N, W;
vector<int> bWall, eWall;

vector<int> prefix_function(vector<int> s) {
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

int solve() {
    if (eWall.size() > bWall.size()) return 0;
    if (eWall.size() == 1) return bWall.size();

    vector<int> txt(bWall.size()-1);
    vector<int> pat(eWall.size()-1);
    for (int i = 0; i < txt.size(); i++)
        txt[i] = abs(bWall[i+1] - bWall[i]);
    for (int i = 0; i < pat.size(); i++)
        pat[i] = abs(eWall[i+1] - eWall[i]);

    vector<int> pi = prefix_function(pat);
    int ret = 0;
    int i = 0, j = 0;
    while (i < txt.size()) {
        bool isMatch = (txt[i] == pat[j]);
        bool bothGreater = (bWall[i] > eWall[j] && bWall[i+1] > eWall[j+1]);
        bool bothSmaller = (bWall[i] < eWall[j] && bWall[i+1] < eWall[j+1]);
        bool bothEqual = (bWall[i] == eWall[j] && bWall[i+1] == eWall[j+1]);
        bool bothEqualDiff = (abs(bWall[i] - eWall[j]) == abs(bWall[i+1] - eWall[j+1]));
        isMatch = isMatch && (bothGreater || bothSmaller || bothEqual) && bothEqualDiff;
        if (isMatch) {
            i++, j++;
        } else {
            if (j != 0) j = pi[j-1];
            else i++;
        }
        if (j == pat.size()) {
            ret++;
            j = pi[j-1];
        }
    }
    return ret;
}

// https://codeforces.com/contest/471/problem/D
int main() {
    READ("../input.txt");
    // WRITE("output.txt");

    N = src();
    W = src();

    bWall = vector<int>(N);
    eWall = vector<int>(W);

    for (int i = 0; i < N; i++) cin >> bWall[i];
    for (int i = 0; i < W; i++) cin >> eWall[i];

    cout << solve() << endl;
}
