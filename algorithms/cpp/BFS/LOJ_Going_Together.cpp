/*
        Problem Link : https://lightoj.com/problem/going-together
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 62 ms
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

// Notice: 3 (x, y) positions. Total 6 digits. Max node 99,99,99
const int MAX_NODE = int(1e6);

struct Node {
    pair<int, int> a, b, c;
};

int N;
vector<string> grid;
map<pair<int, int>, bool> targetMap;

int dist[10][10][10][10][10][10];

int getDist(Node v) {
    return dist[v.a.first][v.a.second][v.b.first][v.b.second][v.c.first][v.c.second];
}
void setDist(Node v, int d) {
    dist[v.a.first][v.a.second][v.b.first][v.b.second][v.c.first][v.c.second] = d;
}

bool onGrid(pair<int, int> p) {
    return p.first >= 0 && p.first < N && p.second >= 0 && p.second < N;
}
bool isObstacle(pair<int, int> p) {
    return grid[p.first][p.second] == '#';
}

bool isAllInCorrectTarget(Node node) {
    pair<int, int> a, b, c;
    a = node.a;
    b = node.b;
    c = node.c;
    // All should be in diff cells
    if (a == b || b == c || c == a) return false;

    // All should be in target cell
    return targetMap[a] && targetMap[b] && targetMap[c];
}

int bfs(Node s) {
    int ret = INT_MAX;

    queue<Node> Q;
    Q.push(s);
    memset(dist, -1, sizeof dist);
    setDist(s, 0);

    while (!Q.empty()) {
        Node u = Q.front(); Q.pop();
        if (isAllInCorrectTarget(u)) {
            ret = getDist(u);
            break;
        }
        for (int i = 0; i < 4; i++) {
            Node v;
            pair<int, int> aa = {u.a.first + dx[i], u.a.second + dy[i]};
            pair<int, int> bb = {u.b.first + dx[i], u.b.second + dy[i]};
            pair<int, int> cc = {u.c.first + dx[i], u.c.second + dy[i]};
            if (!onGrid(aa) || isObstacle(aa)) aa = u.a;
            if (!onGrid(bb) || isObstacle(bb)) bb = u.b;
            if (!onGrid(cc) || isObstacle(cc)) cc = u.c;

            // If a and b placed at same cell
            if (aa == bb) {
                if (bb == cc) cc = u.c;
                aa = u.a, bb = u.b;
            }
            // If a and c placed at same cell
            if (aa == cc) {
                aa = u.a, cc = u.c;
            }
            // If b and c placed at same cell
            if (bb == cc) {
                bb = u.b, cc = u.c;
                if (bb == aa) aa = u.a;
            }

            v.a = aa; v.b = bb; v.c = cc;

            if (getDist(v) == -1) {
                setDist(v, getDist(u) + 1);
                Q.push(v);
            }
        }
    }

    return ret;
}

int solve() {
    vector<pair<int, int>> robots = vector<pair<int, int>>(3);
    targetMap.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c = grid[i][j];
            if (c == 'A') robots[0] = {i, j};
            if (c == 'B') robots[1] = {i, j};
            if (c == 'C') robots[2] = {i, j};
            if (c == 'X') targetMap[{i, j}] = true;
        }
    }

    Node startNode;
    startNode.a = {robots[0].first, robots[0].second};
    startNode.b = {robots[1].first, robots[1].second};
    startNode.c = {robots[2].first, robots[2].second};

    int ret = bfs(startNode);
    return ret;
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

        int ans = solve();
        printf("Case %d: %s\n", tc, ans == INT_MAX ? "trapped" : to_string(ans).c_str());
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
