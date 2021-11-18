/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
	Time :
	Rank :
	Complexity:
*/

#define _CRT_SECURE_NO_WARNINGS

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

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
typedef unsigned long long ULL;

inline int src() { int ret; scanf("%d", &ret); return ret; }

const int MAX = 1e6;

int N;
int A[MAX];
int st[4 * MAX];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }
inline int combine(int a, int b) { return a + b; }

// Complexity: O(n)
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p] = combine(st[left(p)], st[right(p)]);
}

int query(int p, int l, int r, int i, int j) {
    // TODO: Impl
}

void updateSingle(int p, int l, int r, int i, int val) {
    if (l == r) {
        st[p] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) updateSingle(left(p), l, mid, i, val);
    else updateSingle(right(p), mid+1, r, i, val);
    st[p] = combine(st[left(p)], st[right(p)]);
}

// he task is as follows: for a given value x we have to quickly find smallest index i such that
// the sum of the first i elements of the array a[] is greater or equal to x (assuming that the
// array a[] only contains non-negative values).
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();


    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}