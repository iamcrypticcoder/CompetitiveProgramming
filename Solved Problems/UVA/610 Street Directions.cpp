#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> II;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
VVI G;
VVI DG;
VI color, dfsNum, dfsLow, parent;
int nodeNum;
vector<bool> articulationVertex;
vector<II> articulationBridge;
map<II, bool> bridgeMap;
int dfsRoot, rootChildren;

void articulationPointAndBridge(int u)
{
    dfsNum[u] = dfsLow[u] = nodeNum++;
    color[u] = GRAY;

    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];
        if(color[v] == WHITE) {
            parent[v] = u;

            if(u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v);

            if(dfsLow[v] >= dfsNum[u])  articulationVertex[u] = true;
            if(dfsLow[v] > dfsNum[u]) {
                articulationBridge.PB(II(u, v));
                bridgeMap[II(u, v)] = true;
                bridgeMap[II(v, u)] = true;
            }
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if(v != parent[u])
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }

    color[u] = BLACK;
}

void DFS(int u)
{
    color[u] = GRAY;

    FOR(i, 0, G[u].SZ-1)  {
        int v = G[u][i];
        if(color[v] == WHITE) {
            parent[v] = u;
            DG[u].PB(v);
            DFS(v);
        }
        else if(color[v] == GRAY) {
            if(parent[u] != v)
                DG[u].PB(v);
        }
    }

    color[u] = BLACK;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int u, v;

    tc = 1;
    while(cin >> NODE >> EDGE) {
        if(NODE == 0 && EDGE == 0) break;

        G = VVI(NODE + 1);
        color = VI(NODE+1, WHITE);
        dfsNum = VI(NODE+1);
        dfsLow = VI(NODE+1);
        parent = VI(NODE+1, -1);
        articulationVertex = vector<bool>(NODE+1, false);

        FOR(i, 1, EDGE) {
            cin >> u >> v;
            G[u].PB(v);
            G[v].PB(u);
        }

        // For Articulation Point and Bridge.
       nodeNum = 0;

        FOR(i, 1, NODE) {
            if(color[i] == WHITE) {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
                articulationVertex[dfsRoot] = (rootChildren > 1);
            }
        }

        DG = VVI(NODE+1);
        color = VI(NODE+1, WHITE);
        parent = VI(NODE+1, -1);

        DFS(1);

        // Showing Output
        cout << tc << "\n\n";

        FOR(i, 1, NODE) {
            FOR(j, 0, DG[i].SZ-1) {
                cout << i << " " << DG[i][j] << "\n";
                if(bridgeMap[II(i, DG[i][j])] == true)
                    cout << DG[i][j] << " " << i << "\n";
            }
        }

        cout << "#\n";

        bridgeMap.clear();

        tc++;
    }
    return 0;
}

