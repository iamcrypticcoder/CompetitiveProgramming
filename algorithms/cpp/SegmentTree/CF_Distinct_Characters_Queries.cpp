/*
	Problem : https://codeforces.com/contest/1234/problem/D
	Time :    AC
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

typedef unsigned long long ULL;

const int MAX = int(1e5);

int N;
string S;
vector<bool> st[4*MAX+7];

vector<bool> combine(vector<bool> set1, vector<bool> set2) {
    vector<bool> ret = vector<bool>(26);
    for (int i = 0; i < 26; i++) ret[i] = (set1[i] || set2[i]);
    return ret;
}

void build(int p, int l, int r) {
    //printf("p = %d, l = %d, r = %d\n", p, l, r);
    if (l == r) {
        st[p] = vector<bool>(26, false);
        st[p][S[l] - 'a'] = true;
        return;
    }
    int mid = (l + r) >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    st[p] = combine(st[2*p], st[2*p+1]);
}

void updateSingle(int p, int l, int r, int pos, char ch) {
    //printf("p = %d, l = %d, r = %d, pos = %d, ch = %c\n", p, l, r, pos, ch);
    if (l == r) {
        fill(st[p].begin(), st[p].end(), false);
        st[p][ch - 'a'] = true;
        return;
    }

    int mid = (l + r) >> 1;
    if (pos <= mid) updateSingle(2*p, l, mid, pos, ch);
    else updateSingle(2*p+1, mid+1, r, pos, ch);
    st[p] = combine(st[2*p], st[2*p+1]);
}

vector<bool> query(int p, int l, int r, int i, int j) {
    if (i > j) return vector<bool>(26, false);
    if (i == l && j == r) return st[p];
    int mid = (l + r) >> 1;
    vector<bool> lv = query(2*p, l, mid, i, min(j, mid));
    vector<bool> rv = query(2*p+1, mid+1, r, max(i, mid+1), j);
    return combine(lv, rv);
}

int main() {
    READ("../input.txt");
    int Q;
    int cmd, pos, l, r;
    char ch;

    cin >> S;
    N = int(S.size());
    build(1, 0, N-1);

    Q = src();
    for (int q = 1; q <= Q; q++) {
        cmd = src();
        if (cmd == 1) {
            pos = src();
            cin >> ch;
            updateSingle(1, 0, N-1, pos-1, ch);
        }

        if (cmd == 2) {
            cin >> l >> r;
            vector<bool> set = query(1, 0, N-1, l-1, r-1);
            int ans = 0;
            for (auto x : set) ans += (x == true);
            printf("%d\n", ans);
        }
    }

    return 0;
}

