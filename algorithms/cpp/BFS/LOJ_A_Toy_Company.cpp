/*
        Problem Link : https://lightoj.com/problem/a-toy-company
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
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
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

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

typedef unsigned int uint;
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
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1000001

string startWord, endWord;
int n;
bool forbid[51][3][26];

void addToForbiddenList(int idx, string s1, string s2, string s3) {
    for (int i = 0; i < s1.size(); i++)
        forbid[idx][0][s1[i] - 'a'] = true;
    for (int i = 0; i < s2.size(); i++)
        forbid[idx][1][s2[i] - 'a'] = true;
    for (int i = 0; i < s3.size(); i++)
        forbid[idx][2][s3[i] - 'a'] = true;
}

bool isForbidden(string s) {
    for (int i = 0; i < n; i++)
        if (forbid[i][0][s[0] - 'a'] &&
            forbid[i][1][s[1] - 'a'] &&
            forbid[i][2][s[2] - 'a']) return true;
    return false;
}

int bfs() {
    if (isForbidden(startWord) || isForbidden(endWord)) return -1;

    unordered_map<string, int> dist;

    queue<string> Q;
    dist[startWord] = 0;
    Q.push(startWord);

    while (!Q.empty()) {
        string u = Q.front(); Q.pop();
        for (int i = 0; i < 3; i++) {
            for (int j = -1; j <= 1; j++) {
                string v = u;
                v[i] = u[i] + j;
                if (v[i] < 'a') v[i] = 'z';
                else if (v[i] > 'z') v[i] = 'a';
                if (isForbidden(v)) continue;
                if (dist.find(v) == dist.end() || dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
    }

    if (dist.find(endWord) == dist.end()) return -1;
    return dist[endWord];
}


int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    string s1, s2, s3;

    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        cin >> startWord >> endWord;
        n = srcInt();
        memset(forbid, false, sizeof forbid);
        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2 >> s3;
            addToForbiddenList(i, s1, s2, s3);
        }

        int ret = bfs();
        printf("Case %d: %d\n", tc, ret);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
