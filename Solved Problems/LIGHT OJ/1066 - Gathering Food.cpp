/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 0.004
    Rank : 20
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

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

struct NODE {
    int x, y;
    char ch;

    bool operator < (const NODE &b) const {
        return ch < b.ch;
    }
};

int N;
VS grid;
char color[10][10];
VVI dist;
vector<NODE> letters;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool on_grid(NODE p)
{
    return (p.x >= 0 && p.x < N && p.y >= 0 && p.y < N);
}

int BFS(NODE s)
{
    NODE u, v;

    queue<NODE> Q;
    dist = VVI(N, VI(N, INF));
    FOR(i, 0, N-1) memset(color[i], WHITE, sizeof(color[i]));

    color[s.x][s.y] = GRAY;
    Q.push(s);
    dist[s.x][s.y] = 0;

    while( !Q.empty() ) {
        u = Q.front();  Q.pop();

        if(u.ch == s.ch + 1)  {
            return dist[u.x][u.y];
        }

        FOR(i, 0, 3) {
            v = u;
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];

            if(on_grid(v) && color[v.x][v.y] == WHITE) {
                v.ch = grid[v.x][v.y];
                if(grid[v.x][v.y] == '.') {
                    dist[v.x][v.y] = dist[u.x][u.y] + 1;
                    color[v.x][v.y] = GRAY;
                    Q.push(v);
                }
                else if(isalpha(grid[v.x][v.y])) {
                    if(grid[v.x][v.y] < s.ch || grid[v.x][v.y] == s.ch + 1) {
                        dist[v.x][v.y] = dist[u.x][u.y] + 1;
                        color[v.x][v.y] = GRAY;
                        Q.push(v);
                    }
                }
            }
        }
        color[u.x][u.y] = BLACK;
    }

    return INF;
}
int main()
{
    READ("input.txt");
//    WRITE("output.txt");

    int TC, tc;
    int k;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d", &N);

        grid = VS(N);
        NODE n;
        FOR(i, 0, N-1) {
            cin >> grid[i];
            FOR(j, 0, N-1) {
                if(isalpha(grid[i][j])) {
                    n.x = i;
                    n.y = j;
                    n.ch = grid[i][j];
                    letters.PB(n);
                }
            }
        }

        sort(letters.begin(), letters.end());

        int ans = 0;
        bool impos = false;
        FOR(i, 0, letters.SZ-2) {
            n = letters[i];
            int temp = BFS(n);
            if(temp == INF) { impos = true; break; }
            ans += temp;
        }

        if(impos == true) printf("Case %d: Impossible\n", tc );
        else printf("Case %d: %d\n", tc, ans);

        letters.clear();
    }

    return 0;
}

