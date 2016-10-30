#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2


struct EDGE {
    int u, v, income, expense;
};

int NODES, EDGES;
vector<EDGE> edges;
int source;
VI dist, parent;

void BellmanFord()
{
    // Step 1: initialize graph
    dist = VI(NODES, INF);
    parent = VI(NODES, -1);
    dist[source] = 0;

    // Step 2: relax edges repeatedly
    FOR(i, 0, NODES-1)
        FOR(i, 0, edges.SZ-1) {
            EDGE e = edges[i];
            if(dist[e.u] + e.c < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.c;
                parent[e.v] = e.u;
            }
        }
    // Step 3: check for negative-weight cycles
    FOR(i, 0, edges.SZ-1) {
        EDGE e = edges[i];
        if(dist[e.u] + e.c < dist[e.v]) {
            cout << "Graph contain a negative weight cycle\n";
            break;
        }
    }

}


int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> NODES >> EDGES >> P;

        EDGE e;
        FOR(i, 1, EDGES) {
            cin >> e.u >> e.v >> e.income >> e.expense;
            edges.PB(e);
        }

        BellmanFord();


    }

    return 0;
}

