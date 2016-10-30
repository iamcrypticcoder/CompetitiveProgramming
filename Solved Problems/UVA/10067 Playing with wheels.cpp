// Accepted 0.228
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


VVI G;
VI color;
VI dist;
queue<int> Q;
int source, dest;
VI forbid;


void BFS(int s)
{
    int u, v;
    color = VI(10000, WHITE);
    dist = VI(10000, INF);

    color[s] = GRAY;
    dist[s] = 0;

    while( ! Q.empty()) Q.pop();
    Q.push(s);

    while( ! Q.empty() ) {
        u = Q.front();  Q.pop();

        if(u == dest) {
            break;
        }

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE && forbid[v] != -1) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

void BuildGraph()
{
    int u, v, temp;
    int d1, d2, d3, d4;

    G = VVI(10000);

    FOR(node, 0, 9999) {

        d1 = node / 1000;
        d2 = (node % 1000) / 100;
        d3 = (node % 100) / 10;
        d4 = node % 10;

        if(d1-1 == -1) v = 10 * (10 * (10 * (9) + d2) + d3) + d4;           // Wheel 1 Left.
        else v = 10 * (10 * (10 * (d1-1) + d2) + d3) + d4;
        G[node].push_back(v);

        if(d1+1 == 10) v = 10 * (10 * (10 * (0) + d2) + d3) + d4;           // Wheel 1 Right.
        else v = 10 * (10 * (10 * (d1+1) + d2) + d3) + d4;
        G[node].PB(v);

        if(d2-1 == -1) v = 10 * (10 * (10 * d1 + (9)) + d3) + d4;           // Wheel 2 Left.
        else v = 10 * (10 * (10 * d1 + (d2-1)) + d3) + d4;
        G[node].PB(v);

        if(d2+1 == 10) v = 10 * (10 * (10 * d1 + (0)) + d3) + d4;           // Wheel 2 Right.
        else v = 10 * (10 * (10 * d1 + (d2+1)) + d3) + d4;
        G[node].PB(v);

        if(d3-1 == -1) v = 10 * (10 * (10 * d1 + d2) + (9)) + d4;           // Wheel 3 Left.
        else v = 10 * (10 * (10 * d1 + d2) + (d3-1)) + d4;
        G[node].PB(v);

        if(d3+1 == 10) v = 10 * (10 * (10 * d1 + d2) + (0)) + d4;           // Wheel 3 Right.
        else v = 10 * (10 * (10 * d1 + d2) + (d3+1)) + d4;
        G[node].PB(v);

        if(d4-1 == -1) v = 10 * (10 * (10 * d1 + d2) + d3) + 9;             // Wheel 4 Left.
        else v = 10 * (10 * (10 * d1 + d2) + d3) + d4-1;
            G[node].PB(v);

        if(d4+1 == 10) v = 10 * (10 * (10 * d1 + d2) + d3) + 0;             // Wheel 4 Right.
        else v = 10 * (10 * (10 * d1 + d2) + d3) + d4+1;
        G[node].PB(v);
    }
}

int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    int d1, d2, d3, d4, temp;
    int num_of_forbid;

    BuildGraph();
    cin >> TC;

    while(TC--) {
        cin >> d1 >> d2 >> d3 >> d4;
        source = 10 * (10 * (10 * d1 + d2) + d3) + d4;
        cin >> d1 >> d2 >> d3 >> d4;
        dest = 10 * (10 * (10 * d1 + d2) + d3) + d4;

   //     cout << source << " " << dest;

        cin >> num_of_forbid;

        forbid = VI(10000, 0);
        FOR(i, 1, num_of_forbid) {
            cin >> d1 >> d2 >> d3 >> d4;
            temp = 10 * (10 * (10 * d1 + d2) + d3) + d4;
            forbid[temp] = -1;
        }

        if(forbid[source] != -1) BFS(source);
        else {
            cout << "-1\n";
            continue;
        }

        if(dist[dest] == INF)
            cout << "-1\n";
        else cout << dist[dest] << "\n";
    }
	return 0;
}


/*
2
1 7 4 0
9 4 8 8
2
4 5 5 1
7 1 1 5

3 4 8 4
9 9 2 5
5
3 3 3 7
4 3 8 0
8 8 0 6
8 1 9 8
9 7 2 2

Output should :
11
14
My Output :
23
18
*/
