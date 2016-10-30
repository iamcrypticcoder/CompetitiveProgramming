#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
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

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;

VVI G;

void Floyd()
{
    FOR(i, 1, NODE)
        G[i][i] = 0;

    FOR(i, 1, NODE)
        FOR(j, 1, NODE)
            FOR(k, 1, NODE)
                G[i][j] = G[j][i] = max(G[i][j], min(G[i][k], G[k][j]));
                //G[j][k] = max(G[j][k], min(G[j][i], G[i][k]));
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");

    int TC, tc;
    int u, v, c, s, t;
    int capacity, num_tourist, trip;

    tc = 1;
    while(cin >> NODE >> EDGE) {
        if(NODE == 0 && EDGE == 0) break;
  //      if(tc > 1) cout << "\n";
        G =VVI(NODE+1);
        FOR(i, 1, NODE)
            G[i] = VI(NODE+1);

        FOR(i, 1, NODE) FOR(j, 1, NODE) G[i][j] = -INF;

        FOR(i, 1, EDGE) {
            cin >> u >> v >> c;
            G[u][v] = c;
            G[v][u] = c;
        }
        Floyd();

        cin >> s >> t >> num_tourist;

        capacity = G[s][t];

        trip = (int)ceil(( (double)num_tourist / (capacity-1) ));

        cout << "Scenario #" << tc++ << "\n";
        cout << "Minimum Number of Trips = " << trip << "\n";
        cout << "\n";
    }
    return 0;
}