/*
        Problem Link : https://lightoj.com/problem/gathering-food
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : WA
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

int N;
vector<string> grid;
vector<pair<int, int>> foods;
int foodCount;

bool onGrid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

int bfs(pair<int, int> source, pair<int, int> sink) {
    vector<vector<int>> dist = vector<vector<int>>(11, vector<int>(11, INT_MAX));
    queue<pair<int, int>> Q;
    Q.push(source);
    dist[source.first][source.second] = 0;

    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        if (u == sink) break;

        int x = u.first, y = u.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!onGrid(nx, ny)) continue;
            if (grid[nx][ny] == '#') continue;
            if (grid[nx][ny] == '.' || make_pair(nx, ny) == sink) {
                if (dist[x][y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }

    return dist[sink.first][sink.second];
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    TC = srcInt();
    for (tc = 1; tc <= TC; tc++) {
        N = srcInt();
        grid = vector<string>(N);
        for (auto& s : grid) cin >> s;

        foods = vector<pair<int, int>>(26);
        foodCount = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isalpha(grid[i][j])) {
                    foods[grid[i][j] - 'A'] = {i, j};
                    foodCount++;
                }
            }
        }
//        printf("foodCount = %d\n", foodCount);

        int ret = 0;
        for (int i = 0; i <= foodCount-2; i++) {
            int d = bfs(foods[i], foods[i+1]);
            //printf("d = %d\n", d);
            if (d == INT_MAX) {
                ret = INT_MAX;
                break;
            }
            ret += d;
        }

        if(ret == INT_MAX) printf("Case %d: Impossible\n", tc );
        else printf("Case %d: %d\n", tc, ret);
        //printf("Case %d: %s\n", tc, (ret == INT_MAX ? "Impossible" : to_string(ret).c_str()));
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
