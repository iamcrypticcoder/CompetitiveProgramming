/*
        Problem Link : https://lightoj.com/problem/wavio-sequence
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status :    AC
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

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

const int MAX_N = int(1e5);

vector<int> lisNlgN(vector<int> v) {
    int n = v.size();
    vector<int> piles = vector<int>(n, INT_MAX);
    int maxLen = 0;
    vector<int> posValues;

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(piles.begin(), piles.end(), v[i]) - piles.begin();
        posValues.push_back(pos);
        piles[pos] = v[i];
        maxLen = max(maxLen, pos+1); // Plus 1 because of 0-based index.
    }
    return posValues;
}

int main() {
    READ("../input.txt");

    int TC = srcInt();
    for (int tc = 1; tc <= TC; tc++) {
        int N = srcInt();
        vector<int> v = vector<int>(N);
        for (auto& x : v) x = srcInt();

        vector<int> lisPos = lisNlgN(v);
        reverse(v.begin(), v.end());
        vector<int> ldsPos = lisNlgN(v);
        reverse(ldsPos.begin(), ldsPos.end());

        int maxLen = -1;
        for (int i = 0; i < N; i++)
            maxLen = max(maxLen, min(lisPos[i], ldsPos[i]));

        printf("Case %d: %d\n", tc, 2*maxLen+1);
    }

    return 0;
}