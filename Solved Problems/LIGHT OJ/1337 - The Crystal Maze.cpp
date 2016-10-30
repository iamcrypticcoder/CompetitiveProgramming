#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

int M, N, Q;
char grid[501][501];
char color[501][501];
int mark[501][501];
int collect, area_mark;
MII result;


/*
bool on_grid(int i, int j)
{
    return (i >= 0 && i <= M-1 && j >= 0 && j <= N-1);
}

void DFS_Visit(int i, int j)
{
    if(grid[i][j] == 'C') collect++;
    color[i][j] = GRAY;

    q.push(PII(i,j));

    if(on_grid(i+1,j) && grid[i+1][j] != '#' && color[i+1][j] == WHITE) DFS_Visit(i+1, j);
    if(on_grid(i-1,j) && grid[i-1][j] != '#' && color[i-1][j] == WHITE) DFS_Visit(i-1, j);
    if(on_grid(i,j+1) && grid[i][j+1] != '#' && color[i][j+1] == WHITE) DFS_Visit(i, j+1);
    if(on_grid(i,j-1) && grid[i][j-1] != '#' && color[i][j-1] == WHITE) DFS_Visit(i, j-1);

    color[i][j] = BLACK;
}

void DFS()
{
    FOR(i, 0, M-1)
        FOR(j, 0, N-1) {
            if(color[i][j] == WHITE && grid[i][j] != '#') {
                collect = 0;
                DFS_Visit(i, j);
            }
            while( !q.empty() ) {
                PII u = q.front(); q.pop();
                result[u.first][u.second] = collect;
            }
        }
}

*/

bool on_grid(PII u)
{
    return (u.first >= 0 && u.first <= M-1 && u.second >= 0 && u.second <= N-1);
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

        if(grid[u.first][u.second] == 'C') {
            collect++;
        }
        mark[u.first][u.second] = area_mark;

        v = u;
        v.first = u.first - 1;
        if(on_grid(v) && color[v.first][v.second]==WHITE && grid[v.first][v.second] != '#') {
            color[v.first][v.second] = GRAY;
            Q.push(v);
        }

        v = u;
        v.first = u.first + 1;
        if(on_grid(v) && color[v.first][v.second]==WHITE && grid[v.first][v.second] != '#') {
            color[v.first][v.second] = GRAY;
            Q.push(v);
        }

        v = u;
        v.second= u.second - 1;
        if(on_grid(v) && color[v.first][v.second]==WHITE && grid[v.first][v.second] != '#') {
            color[v.first][v.second] = GRAY;
            Q.push(v);
        }

        v = u;
        v.second = u.second + 1;
        if(on_grid(v) && color[v.first][v.second]==WHITE && grid[v.first][v.second] != '#') {
            color[v.first][v.second] = GRAY;
            Q.push(v);
        }
    }

}

void Cal()
{
    area_mark = 0;
    FOR(i, 0, M-1)
        FOR(j, 0, N-1) {
            if(color[i][j] == WHITE && grid[i][j] != '#') {
                collect = 0;
                BFS(PII(i,j));
                result[area_mark++] = collect;
            }
        }
}

int main()
{
//    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    //string str;
    char str[501];
    int x, y;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d %d %d", &M, &N, &Q);

        gets(str);
        FOR(i, 0, M-1) {
            gets(grid[i]);
        }

        memset(color, WHITE, sizeof color);
        Cal();
   //     cout << result[0] << " " << result[1] << "\n";

        printf("Case %d:\n", tc);
        FOR(i, 1, Q) {
            scanf("%d %d", &x, &y);

            printf("%d\n", result[mark[x-1][y-1]]);
        }
        result.clear();
    }
    return 0;

}
