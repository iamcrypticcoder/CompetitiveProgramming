/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.022
    Rank :      1645
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
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

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

#define MAX 30

typedef struct Node {
    int a, b, c;
};

int L, R, C;
char grid[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int dir[6][3] = { {0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0} };

bool onGrid(Node node)
{
    if(node.a < 0 || node.b < 0 || node.c < 0)  return false;
    if(node.a > L-1 || node.b > R-1 || node.c > C-1)  return false;

    return true;
}
int BFS(Node src, Node dest)
{
    Node u, v;
    queue<Node> Q;

    dist[src.a][src.b][src.c] = 0;
    Q.push(src);

    while( !Q.empty() ) {
        u = Q.front(); Q.pop();

        if(grid[u.a][u.b][u.c] == 'E') {
            while( ! Q.empty()) Q.pop();
            break;
        }

        int curDist = dist[u.a][u.b][u.c] + 1;

        FOR(i, 0, 5) {
            v.a = u.a + dir[i][0];
            v.b = u.b + dir[i][1];
            v.c = u.c + dir[i][2];

            if(onGrid(v)) {
                if(grid[v.a][v.b][v.c] == '.' || grid[v.a][v.b][v.c] == 'E') {
                    if(curDist < dist[v.a][v.b][v.c]) {
                        dist[v.a][v.b][v.c] = curDist;
                        Q.push(v);
                    }
                }
            }
        }

    }

    return dist[dest.a][dest.b][dest.c];
}
int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    Node src, dest;

    while(scanf("%d %d %d", &L, &R, &C) == 3) {
        if(L == 0 && R == 0 && C == 0) break;
        FOR(i, 0, L-1) FOR(j, 0, R-1) FOR(k, 0, C-1) {
            //scanf("%c", &grid[i][j][k]);                  // Remember scanf also takes
            cin >> grid[i][j][k];                           // newline as char
            if(grid[i][j][k] == 'S') {
                src.a = i;
                src.b = j;
                src.c = k;
            } else if(grid[i][j][k] == 'E') {
                dest.a = i;
                dest.b = j;
                dest.c = k;
            }
            dist[i][j][k] = INF;
        }

        int t = BFS(src, dest);

        if(t == INF) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", t);
    }
    return 0;
}


