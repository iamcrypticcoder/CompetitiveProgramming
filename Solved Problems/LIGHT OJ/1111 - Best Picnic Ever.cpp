/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203

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
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODES, EDGES, K;
VVI G;
VI peo;
vector<char> color;
VI dist;

void BFS(int s)
{
    int u, v;

    queue<int> Q;

    color = vector<char>(NODES+1);
    Q.push(s);
    color[s] = GRAY;
    dist[s] += 1;

    while( !Q.empty() ) {
        u = Q.front();  Q.pop();

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] += 1;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

int main()
{
    READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    int u, v;
    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d %d %d", &K, &NODES, &EDGES);

        FOR(i, 1, K)  {
            scanf("%d", &u);
            peo.PB(u);
        }

        G = VVI(NODES+1);
        FOR(i, 1, EDGES) {
            scanf("%d %d", &u, &v);
            G[u].PB(v);
        }

        dist = VI(NODES+1);

        FOR(i, 0, peo.SZ-1) {
            BFS(peo[i]);
        }

        int ans = 0;
        FOR(i, 1, NODES) {
            if(dist[i] == K) ans++;
        }

        printf("Case %d: %d\n", tc, ans);

        peo.clear();
    }

    return 0;
}

