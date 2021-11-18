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

struct Node {
    ULL sum = 0;
    void setSum(ULL val) {
        sum = val;
    }
    void combine(Node &a, Node &b) {
        sum = a.sum + b.sum;
    }
};

int N;
int A[MAX];
Node st[4 * MAX];

inline int left(int p) { return p << 1; }
inline int right(int p) { return (p << 1) + 1; }

// Complexity: O(n)
void build(int p, int l, int r) {
    if (l == r) {
        st[p].setSum(A[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid+1, r);
    st[p].combine(st[left(p)], st[right(p)]);
}

Node query(int p, int l, int r, int i, int j) {
    if (i == l && j == r) return st[p];

    int mid = (l + r) >> 1;
    if (j <= mid) return query(left(p), l, mid, i, j);
    if (i > mid) return query(right(p), mid + 1, r, i, j);

    Node ret;
    Node lNode = query(left(p), l, mid, i, mid);
    Node rNode = query(right(p), mid+1, r, mid+1, j);
    ret.combine(lNode, rNode);
    return ret;
}

void updateSingle(int p, int l, int r, int i, int val) {
    if (l == r) {
        st[p].setSum(val);
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) updateSingle(left(p), l, mid, i, val);
    else updateSingle(right(p), mid+1, r, i, val);
    st[p].combine(st[left(p)], st[right(p)]);
}

void updateRange(int p, int l, int r, int i, int j, int val) {
    // See lazy RSQ
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    int arr[7] = { 8, 7, 3, 9, 5, 1, 10 };
    N = 7;
    FOR(i, 0, N - 1) A[i] = arr[i];

    build(1, 0, N-1);

    Node node = query(1, 0, N-1, 0, N-1);
    cout << node.sum << endl;

    updateSingle(1, 0, N-1, 5, 0);

    node = query(1, 0, N-1, 0, N-1);
    cout << node.sum << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}