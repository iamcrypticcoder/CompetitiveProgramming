/*
        Problem Link : https://lightoj.com/problem/the-crystal-maze
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
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

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 502

int M, N, Q;
char grid[MAX][MAX];
char color[MAX][MAX];
int mark[MAX][MAX];
MII result;
int collected, areaMark;

bool onGrid(PII u)
{
    return (u.first >= 1 && u.first <= M && u.second >= 1 && u.second <= N);
}

void BFS(PII s)
{
    PII u, v;

    queue<PII> Q;

    Q.push(s);
    color[s.first][s.second] = GRAY;

    while( !Q.empty() ) {
        u = Q.front(); Q.pop();
        color[u.first][u.second] = BLACK;

        if(grid[u.first][u.second] == 'C') collected++;
        mark[u.first][u.second] = areaMark;

        FOR(i, 0, 3) {
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];

            if(onGrid(v) && color[v.first][v.second] == WHITE && grid[v.first][v.second] != '#') {
                color[v.first][v.second] = GRAY;
                Q.push(v);
            }
        }
    }
}

/**
** You may surprized why I run BFS for all points ?
** Actually these will decrease overall runtime.
** Using mark[][] array I am marking each BFS space with different integers
** And for each different BFS area result is same. Right ? Think a bit
** map<int,int> result contains result for each BFS area.
**/
void Cal()
{
    areaMark = 0;

    FOR(i, 1, M) FOR(j, 1, N) {
            if(color[i][j] == WHITE && grid[i][j] != '#') {
                collected = 0;
                BFS(PII(i, j));
                result[areaMark++] = collected;
            }
        }
}

int main()
{

    int i, j, k;
    int TC, tc;
    int x, y;
    char str[20];

    TC = src();

    FOR(tc, 1, TC) {
        scanf("%d %d %d", &M, &N, &Q);

        gets(str);            // Ending Line
        FOR(i, 1, M) FOR(j, 1, N) cin >> grid[i][j];

        memset(color, WHITE, sizeof color);
        Cal();

        printf("Case %d:\n", tc);
        FOR(i, 1, Q) {
            scanf("%d %d", &x, &y);

            printf("%d\n", result[mark[x][y]]);
        }
        result.clear();
    }

    return 0;
}