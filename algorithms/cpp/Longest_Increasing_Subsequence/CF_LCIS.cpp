/*
        Problem Link : http://codeforces.com/contest/10/problem/D
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : WA in test case 6
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
#include <limits.h>
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

const int MAX_N = int(500);

int N, M;
vector<int> arr1, arr2;
int c[MAX_N + 7][MAX_N + 7];    // c[] is used to calculate the length.
int t[MAX_N + 7][MAX_N + 7];    // '3' denotes left, '2' denotes up, '1' denotes upper-left

int lcsTopDown(int m, int n) {
    if (c[m][n] != -1) return c[m][n];
    if (m == 0 || n == 0) return (c[m][n] = 0);

    if (arr1[m-1] == arr2[n-1]) {
        t[m][n] = 1;
        return c[m][n] = 1 + lcsTopDown(m-1, n-1);
    }

    int maxVal = max(lcsTopDown(m-1, n), lcsTopDown(m, n-1));
    if (maxVal == c[m-1][n]) t[m][n] = 2;
    else t[m][n] = 3;

    return c[m][n] = maxVal;
}

void genLCS(int i, int j, vector<int>& lcs) {
    if (i == 0 || j == 0) return;
    if (t[i][j] == 1) {
        genLCS(i-1, j-1, lcs);
        lcs.push_back(arr1[i-1]);
    } else if (t[i][j] == 2) {
        genLCS(i-1, j, lcs);
    } else {
        genLCS(i, j-1, lcs);
    }
}

vector<int> lisNlgN(vector<int> v) {
    int n = v.size();
    vector<int> piles = vector<int>(n, INT_MAX);
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(piles.begin(), piles.end(), v[i]) - piles.begin();
        piles[pos] = v[i];
        maxLen = max(maxLen, pos+1); // Plus 1 because of 0-based index.
    }

    vector<int> ret = vector<int>(piles.begin(), piles.begin() + maxLen);
    return ret;
}

int main() {
    READ("../input.txt");

    cin >> N;
    arr1 = vector<int>(N);
    for (auto& x : arr1) cin >> x;
    cin >> M;
    arr2 = vector<int>(M);
    for (auto& x : arr2) cin >> x;

    vector<int> lcs;
    memset(c, -1, sizeof c);
    lcsTopDown(N, M);
    genLCS(N, M, lcs);
    for (auto x : lcs) cout << x << " ";
    cout << endl;

    vector<int> lis = lisNlgN(lcs);
    cout << lis.size() << endl;
    for (auto x : lis) cout << x << " ";
    cout << endl;

    return 0;
}