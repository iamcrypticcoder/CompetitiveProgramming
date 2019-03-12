/*
	Problem Link : https://www.spoj.com/problems/AKVQLD03/
	Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Status : [AC, WA, TLE, RTE] 
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
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

#define MAX       1000000

uint N;                 // Number of elements in A
uint A[MAX + 7];        // Original input array
ULL st[2 * MAX + 7];    // Segment Tree

void build() {
    for (int i = 0; i < N; ++i) st[N + i] = A[i];
    for (int i = 2*N-1; i > 1; i -= 2)
        st[i >> 1] = st[i] + st[i ^ 1];
}

ULL query(int l, int r) {
    ULL sum = 0;
    l += N, r += N;
    while (l <= r) {
        if (l & 1) sum += st[l];
        if (!(r & 1)) sum += st[r];
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return sum;
}

void updateSingle(int i, int val) {
    A[i] = val;
    i = i + N;
    st[i] = val;
    while (i > 1) {
        st[i >> 1] = st[i] + st[i ^ 1];
        i = i >> 1;
    }
}

int main()
{
    int i, j, k;
    int TC, tc;
    double cl = clock();

    int Q;

    memset(A, 0, sizeof(A));
    memset(st, 0, sizeof(st));

    scanf("%d %d", &N, &Q);

    FOR(q, 1, Q) {
        char cmd[10];
        int p, f, a, b;
        scanf("%s", cmd);
        if (strcmp(cmd, "find") == 0) {
            scanf("%d %d", &a, &b);
            printf("%llu\n", query(a-1, b-1));
            continue;
        }
        if (strcmp(cmd, "add") == 0) {
            scanf("%d %d", &p, &f);
            updateSingle(p-1, A[p-1] + f);
            continue;
        }
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
