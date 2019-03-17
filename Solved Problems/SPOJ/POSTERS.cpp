/*
        Problem Link : https://www.spoj.com/problems/POSTERS/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.04
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
typedef pair<uint, uint> PUU;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<uint> VU;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<uint, uint> MUU;
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

#define MAX 40000

int N;
PII posters[MAX+7];
set<int> s, wall;
set<int>::iterator it, it1, it2;
MII m;

void compress() {
    int cnt = 0;
    for (it = s.begin(); it != s.end(); it++) {
        m[*it] = ++cnt;
        wall.insert(cnt);
    }
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    TC = srcInt();
    FOR(tc, 1, TC) {
        N = srcInt();
        FOR(i, 0, N-1) {
            int l = srcInt();
            int r = srcInt();
            posters[i] = make_pair(l, r);
            s.insert(l);
            s.insert(r);
        }

        compress();
        //cout << wall.size() << endl;

        int ans = 0;
        FORD(i, N-1, 0) {
            PII p = posters[i];
            p = make_pair(m[p.first], m[p.second]);
            it1 = wall.lower_bound(p.first);
            it2 = wall.upper_bound(p.second);
            //cout << *it1 << " " << *it2 << endl;
            if (it1 != it2) {
                wall.erase(it1, it2);
                ans++;
            }
            //cout << wall.size() << endl;
        }
        printf("%d\n", ans);

        s.clear();
        wall.clear();
        m.clear();
    }

    clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
