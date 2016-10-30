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

int C, S, Q;
int dist[101][101];

void Floyd()
{
    FOR(i, 1, C) dist[i][i] =0;

    FOR(k, 1, C)
        FOR(i, 1, C)
            FOR(j, 1, C)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v, c;

    tc = 1;
    while(cin >> C >> S >> Q) {
        if(C == 0 && S == 0 && Q == 0) break;
        if(tc > 1) cout << "\n";

        FOR(i, 1, C)    FOR(j, i+1, C)  dist[i][j] = dist[j][i] = INF;

        FOR(i, 1, S) {
            cin >> u >> v >> c;
            dist[u][v] = dist[v][u] = c;
        }

        Floyd();

        cout << "Case #" << tc++ << "\n";
        FOR(i, 1, Q) {
            cin >> u >> v;
            if(dist[u][v] == INF)
                cout << "no path\n";
            else cout << dist[u][v] << "\n";
        }

    }

	return 0;
}
