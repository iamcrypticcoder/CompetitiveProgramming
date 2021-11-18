/*
    Problem Link: https://codeforces.com/contest/121/problem/E
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
    Status :
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
#include <climits>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;

const int MAX_N = int(3e5 + 2);
const LL MOD = LL(1e9 + 9);

int fib[MAX_N + 7];
int N;
vector<int> A;
LL st[4*MAX_N + 7];
LL lazy[4*MAX_N + 7];

void preCalFib(int n) {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= n; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
}

LL combine(LL a, LL b) {
    return (a + b) % MOD;
}

void build(int p, int l, int r) {
    lazy[p] = 0;
    if (l == r) {
        st[p] = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    st[p] = combine(st[2*p], st[2*p+1]);
}

void pushDown(int p, int l, int r) {
    if (lazy[p] == 0) return;

    int mid = (l + r) >> 1;
    st[2*p] = (st[2*p] + lazy[p]) % MOD;
    st[2*p+1] = (st[2*p+1] + lazy[p]) % MOD;
    lazy[2*p] += lazy[p];
    lazy[2*p+1] += lazy[p];
    lazy[p] = 0;
}

void updateRange(int p, int l, int r, int i, int j) {
    if (i > j) return;
    if (i == l && j == r) {
        int n = r - l + 1;
        int sumFn = fib[n+2] - 1;                           // Formula sum of fib up to N
        st[p] = (st[p] + sumFn) % MOD;
        if (l != r) lazy[p] = (lazy[p] + sumFn) % MOD;
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    updateRange(2*p, l, mid, i, min(j, mid));
    updateRange(2*p+1, mid+1, j, max(i, mid+1), j);

}

int main() {
    READ("../input.txt");

    int M;
    string str, token;
    int l, r, v;

    cin >> N;
    A = vector<int>(N);
    for (auto& x : A) cin >> x;

    preCalFib(N);

    cin >> M;
    for (int m = 1; m <= M; m++) {

    }


    return 0;
}