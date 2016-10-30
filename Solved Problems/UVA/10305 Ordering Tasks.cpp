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
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
VVI G;
VI color;
VI topoOrder;

void DFS_Visit(int u)
{
    color[u] = GRAY;

    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];
        if(color[v] == WHITE)
            DFS_Visit(v);
    }
    topoOrder.PB(u);
    color[u] = BLACK;
}

void TopoSort()
{
    topoOrder.clear();
    color = VI(NODE+1, WHITE);

    FOR(i, 1, NODE)
        if(color[i] == WHITE)
            DFS_Visit(i);
    reverse(topoOrder.begin(), topoOrder.end());

}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v;

    while(cin >> NODE >> EDGE) {
        if(NODE == 0 && EDGE == 0) break;

        G = VVI(NODE+1);

        FOR(i, 1, EDGE) {
            cin >> u >> v;
            G[u].PB(v);
        }

        TopoSort();

        cout << topoOrder[0];
        FOR(i, 1, topoOrder.SZ-1)
            cout << " " << topoOrder[i];
        cout << "\n";
    }

	return 0;
}
