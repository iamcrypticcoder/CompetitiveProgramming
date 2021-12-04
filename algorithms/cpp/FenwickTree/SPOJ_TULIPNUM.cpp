/*
        Problem Link : https://www.spoj.com/problems/TULIPNUM/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : TLE
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
#include <iterator>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

const int MAX_N = int(1e5);
const int MAX_Q = int(1e5);
const int MAX_Ai = int(1e6);

int N, Q;
int A[MAX_N + 7];
map<int, int> lastSeen;
// first = query number, second.first = l, second.second = r
pair<int, PII> queries[MAX_Q + 7];
int qAns[MAX_Q + 7];
int bit[MAX_N + 7];

bool comp(pair<int, PII> p1, pair<int, PII> p2) {
    if (p1.ss.ss == p2.ss.ss) return p1.ss.ff < p2.ss.ff;
    return p1.ss.ss < p2.ss.ss;
}

void add(int idx, int val) {
    while (idx <= N) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int sum(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int rsq(int l, int r) {
    return sum(r) - sum(l-1);
}

int main() {
    double cl = clock();

    int TC = srcInt();
    for (int tc = 1; tc <= TC; tc++) {
        N = srcInt();
        Q = srcInt();
        FOR(i, 1, N) A[i] = srcInt();
        FOR(i, 0, Q-1) {
            scanf("%d %d", &queries[i].ss.ff, &queries[i].ss.ss);
            queries[i].ff = i;
        }
        sort(queries, queries + Q, comp);
        lastSeen.clear();
        memset(bit, 0, sizeof bit);

        int q = 0;
        FOR(i, 1, N) {
            if (lastSeen.find(A[i]) != lastSeen.end())
                add(lastSeen[A[i]], -1);
            lastSeen[A[i]] = i;
            add(i, 1);

            while (q < Q && queries[q].ss.ss == i) {
                qAns[queries[q].ff] = rsq(queries[q].ss.ff, queries[q].ss.ss);
                q++;
            }
        }

        printf("Case %d:\n", tc);
        FOR(q, 0, Q-1) printf("%d\n", qAns[q]);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}