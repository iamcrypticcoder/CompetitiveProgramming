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
VI color, dfsNum, dfsLow, parent;
int nodeNum;
vector<bool> articulationVertex;
vector<II> articulationBridge;
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
            }
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if(v != parent[u])
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }

    color[u] = BLACK;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int u, v, temp;
    string line;

    while(cin >> NODE) {
        getchar();
        if(NODE == 0) {
            cout << "0 critical links\n\n";
            continue;
        }

        G = VVI(NODE);
        color = VI(NODE+1, WHITE);
        dfsNum = VI(NODE+1);
        dfsLow = VI(NODE+1);
        parent = VI(NODE+1, -1);
        articulationVertex = vector<bool>(NODE, false);


        while(getline(cin, line)) {
            if(line.SZ == 0) break;
            FOR(i, 0, line.SZ-1)
                if(line[i] == '(' || line[i] == ')')
                    line[i] = ' ';

            stringstream ss(line);

            ss >> u;
            ss >> temp;
            while(ss >> v) {
                G[u].PB(v);
             //   G[v].PB(u);
            }
        }
/*
        FOR(i, 0, NODE-1) {
            cout << i << "-- ";
            FOR(j, 0, G[i].SZ-1)
                cout << G[i][j] << " ";
            cout << "\n";
        }
*/
        // For Articulation Point and Bridge
        nodeNum = 0;
        FOR(i, 0, NODE-1) {
            if(color[i] == WHITE) {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
                articulationVertex[dfsRoot] = (rootChildren > 1);
            }
        }

        sort(articulationBridge.begin(), articulationBridge.end());

        cout << articulationBridge.SZ << " critical links\n";
        FOR(i, 0, articulationBridge.SZ-1)
            cout << articulationBridge[i].first << " - " << articulationBridge[i].second << "\n";
        cout << "\n";

        articulationBridge.clear();
    }

    return 0;
}

/*
7
0 (4) 1 2 3 4
1 (3) 0 2 3
2 (3) 1 0 3
3 (4) 0 1 2 4
4 (4) 0 3 6 5
5 (1) 4
6 (1) 4

3
0 (1) 1
1 (1) 0
2 (0)

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)
*/

