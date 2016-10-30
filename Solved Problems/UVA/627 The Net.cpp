
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

VVI G;              // Adjacency List
queue<int> Q;
VI dist;
VI color;
VI parent;
VI path;

int N, M;

int BFS(int s, int t)
{
    int u, v;

    dist = VI(N+1, INF);
    color =  VI(N+1, WHITE);
    parent = VI(N+1);

    dist[s] = 0;
    color[s] = GRAY;
    parent[s] = -1;

    while( ! Q.empty() ) Q.pop();               // At first blank Queue.
    Q.push(s);

    while( ! Q.empty()) {
        u = Q.front();  Q.pop();

        if(u == t)
            return dist[t];

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                parent[v] = u;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

void MakePath(int target)
{
    if(target == -1) return;
    MakePath(parent[target]);
    path.PB(target);
}

int main()
{
  //  READ("input.txt");
  //  WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    int temp, a;
    int start, target;
    string line;

    while(cin >> N) {
        getline(cin, line);
        G = VVI(N+1);

        FOR(i, 1, N) {
            getline(cin, line);
            FOR(i, 0, line.SZ-1) if(line[i] == '-' || line[i] == ',') line[i] = ' ';
            stringstream ss(line);

            ss >> a;

            while(ss >> temp) {
                G[a].PB(temp);
            }
        }

        cin >> M;
        cout << "-----\n";
        FOR(i, 1, M) {
            cin >> start >> target;
            BFS(start, target);

            if(dist[target] == INF)
                cout << "connection impossible\n";
            else {
                if( !path.empty()) path.clear();
                MakePath(target);
                cout << path[0];
                FOR(i, 1, path.SZ-1)
                    cout << " " << path[i];
                cout << "\n";
            }
        }
    }
	return 0;
}
