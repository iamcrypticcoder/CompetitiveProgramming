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
#define INF 9999999

#define MAX_DIMENSION 25+1
#define WHITE 0
#define GRAY 1
#define BLACK 2

char color[MAX_DIMENSION];
int dist[MAX_DIMENSION];
int parent[MAX_DIMENSION];
queue<int> Q;
map<string, int> node_map;
vector<vector<int> > G;
int M, N, P;

void BFS(int source)
{
    FOR(i, 1, M) {
        color[i] = WHITE;
        dist[i] = INF;
        parent[i] = -1;
    }

    color[source] = GRAY;
    dist[source] = 0;
    parent[source] = -1;

    Q.push(source);

    while(!Q.empty()) {
        int u = Q.front();  Q.pop();

        FOR(i, 0, G[u].size()-1) {
            int v = G[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int i, j, k;
    int TC, tc;
    string tempStr1, tempStr2;
    int source, target, ship_size;

    cin >> TC;

    cout << "SHIPPING ROUTES OUTPUT\n\n";

    for(tc=1; tc <= TC; tc++) {
        cin >> M >> N >> P;

        G = vector<vector<int> >(M+1);              //Because all indices start from 1

        FOR(i, 1, M) {
            cin >> tempStr1;
            node_map[tempStr1] = i;
        }

        FOR(i, 1, N) {
            cin >> tempStr1 >> tempStr2;

            int u = node_map[tempStr1];
            int v = node_map[tempStr2];

            G[u].push_back(v);
            G[v].push_back(u);
        }

        cout << "DATA SET  " << tc << "\n\n";

        FOR(i, 1, P) {
            cin >> ship_size >> tempStr1 >> tempStr2;

            source = node_map[tempStr1];
            target = node_map[tempStr2];

            BFS(source);

            if(color[target] == WHITE)
                cout << "NO SHIPMENT POSSIBLE\n";
            else cout << "$" << ship_size * dist[target] * 100 << "\n";
        }
        cout << "\n";
        G.clear();
        node_map.clear();
    }

    cout << "END OF OUTPUT\n";

	return 0;
}
