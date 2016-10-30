#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;
typedef map<string, string> MSS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
VVI G;

// For BFS Algorithm
VI parent, color, dist;                   //
queue<int> Q;

// For EdmondsKarp Algorithm
int f, maxFlow;
VVI cap;        // Capacity Matrix
VVI flow;       // Flow Matrix
int s, t;


void BFS(int s, int t)
{
    int u, v;

    color = VI(NODE+1, WHITE);
    dist = VI(NODE+1, INF);
    parent = VI(NODE+1, -1);

    while( ! Q.empty()) Q.pop();
    Q.push(s);
    dist[s] = 0;
    color[s] = GRAY;

    while(! Q.empty()) {
        u = Q.front();  Q.pop();

        if(u == t) break;

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(parent[u] != v && color[v] == WHITE && cap[u][v] - flow[u][v] > 0) {
                dist[v] = dist[u] + 1;
                Q.push(v);
                color[v] = GRAY;
                parent[v] = u;
            }
        }
        color[u] = BLACK;
    }
}

void augmentPath(int v, int minEdge)
{
    if(v == s) {
        f = minEdge;
        return;
    }

    while(parent[v] != -1) {
        augmentPath(parent[v], min(minEdge, cap[parent[v]][v] - flow[parent[v]][v]));
        flow[parent[v]][v] += f;
        flow[v][parent[v]] -= f;
        parent[v] = -1;
    }
}

void EdmondsKarp()
{
    maxFlow = 0;
    while(1) {
        BFS(s, t);
        f = 0;
        augmentPath(t, INF);
        if(f == 0) break;
        maxFlow += f;
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v, c;

    tc = 1;
    while(cin >> NODE) {
        if(NODE == 0) break;

        G = VVI(NODE+1);
        cap = VVI(NODE+1);
        flow = VVI(NODE+1);

        FOR(i, 1, NODE) {
            cap[i] = VI(NODE + 1);
            flow[i] = VI(NODE + 1);
        }

        cin >> s >> t >> EDGE;

        FOR(i, 1, EDGE) {
            cin >> u >> v >> c;
            G[u].PB(v);
            G[v].PB(u);
            cap[u][v] += c;
            cap[v][u] += c;
        }


        EdmondsKarp();

        cout << "Network " << tc++ << "\n";
        cout << "The bandwidth is " << maxFlow << ".\n\n";

    }

	return 0;
}
