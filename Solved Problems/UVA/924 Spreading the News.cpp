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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
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
typedef vector<string> VS;

#define WHITE 0
#define GRAY 1
#define BLACK 2


int NODE, EDGE;
VVI G;
VI dist, color;
VVI layer;
queue<int> Q;
int source;

int BFS(int s)
{
    int u,v;

    color = VI(NODE, WHITE);
    dist = VI(NODE, INF);
    layer = VVI(NODE);

    dist[s] = 0;
    color[s] = GRAY;
    Q.push(s);

    while( ! Q.empty() ) {
        u = Q.front();  Q.pop();

        layer[dist[u]].PB(u);

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }

}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    int friends, temp;

    cin >> NODE;
    G = VVI(NODE);

    FOR(i, 0, NODE-1) {
        cin >> friends;

        FOR(j, 1, friends) {
            cin >> temp;
            G[i].PB(temp);
        }
    }

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> source;

        if(G[source].SZ == 0) {         // If no employee (but the source) hears the piece of news, the output line contains the integer 0.
            cout << "0\n";
            continue;
        }

        BFS(source);

        int maxBoom = layer[1].SZ;
        int firstDay = 1;

        FOR(i, 2, layer.SZ-1) {
            if(layer[i].SZ > maxBoom) {
                maxBoom = layer[i].SZ;
                firstDay = i;
            }
        }

        cout << maxBoom << " " << firstDay << "\n";
    }

	return 0;
}
