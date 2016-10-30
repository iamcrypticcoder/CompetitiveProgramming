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

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

VS dictionary;
map<string, int> nodeMap;
VVI G;
queue<int> Q;
VI color;
VI dist;
int nodes;

void BFS(int source)
{
    int u, v;
    color = VI(nodes+1, WHITE);
    dist = VI(nodes+1, INF);

    color[source] = GRAY;
    dist[source] = 0;

    Q.push(source);

    while( ! Q.empty() ) {
        u = Q.front();  Q.pop();

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

bool isEdge(string u, string v)
{
    if(u.SZ != v.SZ) return false;

    int diff = 0;
    FOR(i, 0, u.SZ) {
        if(u[i] != v[i]) diff++;
        if(diff > 1) return false;
    }

    return true;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);


    int i, j, k;
    int TC, tc;
    string word, line;
    string source, dest;

    cin >> TC;
    getline(cin, word);
    getline(cin, word);

    while(TC--) {

        nodes = 0;
        while(getline(cin, word)) {
            if(word == "*") break;
            dictionary.PB(word);
            nodeMap[word] = ++nodes;
        }

        G = VVI(nodes+1);

        FOR(i, 0, dictionary.SZ-1)
            FOR(j, i+1, dictionary.SZ-1)
                if(isEdge(dictionary[i], dictionary[j])) {
                    G[nodeMap[dictionary[i]]].PB(nodeMap[dictionary[j]]);
                    G[nodeMap[dictionary[j]]].PB(nodeMap[dictionary[i]]);
                }

        while(getline(cin, line)) {
            if(line.SZ == 0) break;
            stringstream ss(line);

            ss >> source;
            ss >> dest;

            BFS(nodeMap[source]);

            cout << source << " " << dest << " " << dist[nodeMap[dest]] << "\n";
        }
        if(TC != 0) cout << "\n";

        dictionary.clear();
        nodeMap.clear();
        G.clear();
        color.clear();
        dist.clear();
    }

	return 0;
}
