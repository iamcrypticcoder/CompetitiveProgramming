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
VI dist, color, parent, path;
queue<int> Q;
MSI nodeMap;
map<int, char> charMap;

int BFS(int s, int t)
{
    int u, v;

    dist = VI(NODE+1, INF);
    color = VI(NODE+1, WHITE);
    parent = VI(NODE+1);

    dist[s] = 0;
    color[s] = WHITE;
    parent[s] = -1;

    while( ! Q.empty() ) Q.pop();
    Q.push(s);

    while( !Q.empty() ) {
        u = Q.front();  Q.pop();

        if(u == t) return dist[t];

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
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

void MakePath(int n)
{
    if(n == -1) return;
    MakePath(parent[n]);
    path.PB(n);
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    int QUERY, nodeNum;
    string str1, str2;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> EDGE >> QUERY;

        G = VVI(10001);
        nodeNum = 0;
        FOR(i, 1, EDGE) {
            cin >> str1 >> str2;
            if(nodeMap.find(str1) == nodeMap.end()) {
                nodeMap[str1] = ++nodeNum;
                charMap[nodeNum] = str1[0];
            }
            if(nodeMap.find(str2) == nodeMap.end()) {
                nodeMap[str2] = ++nodeNum;
                charMap[nodeNum] = str2[0];
            }
            G[nodeMap[str1]].PB(nodeMap[str2]);
            G[nodeMap[str2]].PB(nodeMap[str1]);
        }
        NODE = nodeNum;

        FOR(i, 1, QUERY) {
            cin >>str1 >> str2;
  //          cout << nodeMap[str1] << " " << nodeMap[str2];
            BFS(nodeMap[str1], nodeMap[str2]);
            MakePath(nodeMap[str2]);
            FOR(i, 0, path.SZ-1)
                cout << charMap[path[i]];
            cout << "\n";
            path.clear();
        }

        if(tc != TC) cout << "\n";

        nodeMap.clear();
        charMap.clear();
    }

	return 0;
}
