/*
        Problem Link : https://www.spoj.com/problems/DQUERY/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status :
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

#define EPS             1e-9
#define SQR(x)          ((x)*(x))
#define INF             2000000000
#define TO_DEG          57.29577951
#define PI              2*acos(0.0)

#define ALL_BITS                                ((1 << 31) - 1)
#define NEG_BITS(mask)                          (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)                       (mask & (1 << i))
#define ON_BIT(mask, i)                         (mask |= (1 << i))
#define OFF_BIT(mask, i)                        (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                         (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)                (x & (x-1))

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

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline int srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline int srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_N 30000
#define MAX_Q 200000
#define MAX_Ai 1000000

struct Query {
    int idx;
    int l, r;
    Query() {}
    Query (uint idx, uint l, uint r) {
        this->idx = idx;
        this->l = l;
        this->r = r;
    }
};

uint N, Q;
uint A[MAX_N + 7];
int lastSeen[MAX_Ai + 7];
//Query queries[MAX_Q +7];   // Using Qeury structure it was getting TLE. Maybe time limit is very strict.
pair <int, pair<int, int> > queries[MAX_Q + 7];
uint qAns[MAX_Q + 7];
uint bit[MAX_N + 7];

bool comp(Query &a, Query &b) {
    if (a.r == b.r) return a.l <= b.l;
    return a.r <= b.r;
}

void update(int idx, int val) {
    while (idx <= N) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

uint read(int idx) {
    uint sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    N = srcUInt();
    FOR(i, 1, N) A[i] = srcUInt();
    Q = srcUInt();
    FOR(i, 0, Q-1) {
        scanf("%d %d", &queries[i].second.first, &queries[i].first);
        queries[i].second.second = i;
        //scanf("%d %d", &queries[i].l, &queries[i].r);
        //queries[i].idx = i;
    }
    sort(queries, queries + Q);
    memset(lastSeen, -1, sizeof lastSeen);
    memset(bit, 0, sizeof(bit));

    uint q = 0;
    FOR(i, 1, N) {
        if (lastSeen[A[i]] != -1) update(lastSeen[A[i]], -1);
        lastSeen[A[i]] = i;
        update(i, 1);

        while (q < Q && queries[q].first == i) {
            qAns[queries[q].second.second] = read(queries[q].first) - read(queries[q].second.first-1);
            //qAns[queries[q].idx] = read(queries[q].r) - read(queries[q].l - 1);
            q++;
        }
    }

    FOR(q, 0, Q-1) printf("%u\n", qAns[q]);

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
