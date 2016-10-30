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
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

struct NODE {
    int label, cost;

    bool operator<(const NODE &b) const
    {
        return cost > b.cost;
    }
};

struct POINT {
    int x, y;

    double dist()
    {
        return sqrt(SQR(x) + SQR(y));
    }

    bool operator<(const NODE &b) const
    {
        return this.dist() > b.dist();
    }
};


int edges[500][500];
int source;
priority_queue<NODE> prioQ;
VI dist;
int n, m;

void DIJLSTRA(NODE s)
{
    NODE u, v;

    dist = VI(500, INF);

    dist[s.label] = 0;
    prioQ.push(s);

    while(!prioQ.empty()) {
        u = prioQ.top(); prioQ.pop();

        FOR(i, 0, n-1) {
            if(edges[u.label][i] != -1) {
                if(dist[i] == -1) {
                    v.label = i;
                    v.cost = dist[i] = edges[u.label][i];
                    prioQ.push(v);
                }
                else if(max(dist[u.label], edges[u.label][i])  < dist[i]) {
                    v.label = i;
                    v.cost = dist[i] = max(dist[u.label], edges[u.label][i]);
                    prioQ.push(v);
                }

            }
        }
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int u, v, w;

    cin >> TC;

    FOR(tc, 1, TC) {
        //cin >> n >> m;
        scanf("%d %d", &n, &m);

        FOR(i, 0, n-1)
            memset(edges[i], -1, sizeof(edges[i]));

        FOR(i, 1, m) {
        //    cin >> u >> v >> w;
            scanf("%d %d %d", &u, &v, &w);
            if(edges[u][v] == -1) edges[u][v] = edges[v][u] = w;
            else edges[u][v] = edges[v][u]= min(edges[u][v], w);
        }
        scanf("%d", &source);
        NODE s;
        s.label = source;
        s.cost = 0;

        DIJLSTRA(s);

        //cout << "Case " << tc << ":\n";
        printf("Case %d:\n", tc);
        FOR(i, 0, n-1) {
            if(dist[i] == INF)  printf("Impossible\n");
            else printf("%d\n", dist[i]);
        }

    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

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
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODES, EDGES;
int cost[501][501];
int dist[501];
int cutU, cutV;
vector<PI> cutted;

int BFS(int src)
{
   int u, v;
   queue<int> Q;

   FOR(i, 0, NODES) dist[i] = INF;
   dist[src] = 0;
   Q.push(src);

   while( ! Q.empty() ) {
      u = Q.front();    Q.pop();

      FOR(v, 0, NODES-1) {
         if(cost[u][v] != INF) {
            if(max(dist[u], cost[u][v]) < dist[v]) {
               dist[v] = max(dist[u], cost[u][v]);
               Q.push(v);
               //cutU = u;   cutV = v;
            }
         }
      }
   }
}

/*
void MaxFlow(int src, int dest)
{
   int cutCost = 0;

   while(true) {
      BFS(src, dest);
      if(dist[dest] == INF) break;
      cutted.PB(make_pair(cutU, cutV));
   }
}
*/

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int u, v, c, src;

   scanf("%d", &TC);

   FOR(tc, 1, TC) {
      scanf("%d %d", &NODES, &EDGES);

      FOR(i, 0, NODES-1) FOR(j, 0, NODES-1) cost[i][j] = INF;

      FOR(i, 1, EDGES) {
         scanf("%d %d %d", &u, &v, &c);
         cost[u][v] = cost[v][u] = min(cost[u][v], c);
      }
      scanf("%d", &src);

      BFS(src);

      printf("Case %d:\n", tc);
      FOR(i, 0, NODES-1) {
         if(dist[i] == INF) printf("Impossible\n");
         else printf("%d\n", dist[i]);
      }


      /*
      MaxFlow();

      FOR(i, 0, cutted.SZ-1)
         printf("%d %d\n", cutted[i].first, cutted[i].second);

      printf("\n");
      */
   }

   return 0;
}
