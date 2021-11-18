/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
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

const int MAX = 1e5;

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

int N;
vector<int> A;
vector<int> st[4*MAX+7];

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = vector<int>(1, A[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    merge(st[left(p)].begin(), st[left(p)].end(),
          st[right(p)].begin(), st[right(p)].end(),
          back_inserter(st[p]));
}

int query(int p, int l, int r, int i, int j, int x) {
    if (i > j) return INT_MAX;
    if (i == l && j == r) {
        auto pos = lower_bound(st[p].begin(), st[p].end(), x);
        if (pos != st[p].end())
            return *pos;
        return INT_MAX;
    }
    int mid = (l + r) >> 1;
    return min(query(left(p), l, mid, i, min(j, mid), x),
               query(right(p), mid+1, r, max(i, mid+1), j, x));
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");

    cin >> N;
    A = vector<int>(N);
    for (auto& x : A) cin >> x;

    build(1, 0, N-1);

    int l, r, x;
    while (cin >> l >> r >> x) {
        int res = query(1, 0, N-1, l, r, x);
        printf("Smallest number between %d and %d greater/euqal to %d is = %d\n", l, r, x, res);
    }

    return 0;
}

/**
Input:
10
5 6 1 4 3 0 2 5 9 6
0 0 1
1 1 2
2 2 3
3 3 4
4 4 5
5 5 6
6 6 7
7 7 8
8 8 9
9 9 10
0 9 7
0 4 1
5 9 1

Output:
Smallest number between 0 and 0 greater/euqal to 1 is = 5
Smallest number between 1 and 1 greater/euqal to 2 is = 6
Smallest number between 2 and 2 greater/euqal to 3 is = 2147483647
Smallest number between 3 and 3 greater/euqal to 4 is = 4
Smallest number between 4 and 4 greater/euqal to 5 is = 2147483647
Smallest number between 5 and 5 greater/euqal to 6 is = 2147483647
Smallest number between 6 and 6 greater/euqal to 7 is = 2147483647
Smallest number between 7 and 7 greater/euqal to 8 is = 2147483647
Smallest number between 8 and 8 greater/euqal to 9 is = 9
Smallest number between 9 and 9 greater/euqal to 10 is = 2147483647
Smallest number between 0 and 9 greater/euqal to 7 is = 9
Smallest number between 0 and 4 greater/euqal to 1 is = 1
Smallest number between 5 and 9 greater/euqal to 1 is = 2

**/