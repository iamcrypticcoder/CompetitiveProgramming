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
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODES, EDGES;
VVI G;
VI color;
VB isNode;
int nVam, nLy;

int BFS(int s)
{
    int u, v;
    queue<int> Q;

    color[s] = GRAY;
    nVam++;
    Q.push(s);

    while( ! Q.empty() ) {
        u = Q.front();  Q.pop();

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE) {
                if(color[u] == GRAY) {
                    color[v] = BLACK;
                    nLy++;
                    Q.push(v);
                }
                else if(color[u] == BLACK) {
                    color[v] = GRAY;
                    nVam++;
                    Q.push(v);
                }
            }
        }
    }
}

int main()
{
    READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    int u, v, n, maxNode;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d", &n);

        G = VVI(20001);
        //color = VI(20001);
        isNode = vector<bool>(20001);       // For Optimization

        maxNode = -1;
        FOR(i, 1, n) {
            scanf("%d %d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
            if(u > maxNode) maxNode = u;
            if(v > maxNode) maxNode = v;
            isNode[u] = isNode[v] = true;       // For Optimization
            //color[u] = color[v] = WHITE;
        }

        color = VI(maxNode+1);

        int ans = 0;
        FOR(i, 1, maxNode) {
            if(isNode[i] && color[i] == WHITE) {
                nVam = nLy = 0;
                BFS(i);
                ans += max(nVam, nLy);
            }
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}

