#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>        // For memset function
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
#define EPS 1e-9
#define PI (2*acos(0.0))
#define TO_RAD (PI/180)
#define TO_DEG (180/PI)

#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

struct NODE {
    int label, dist;

    bool operator < ( const NODE &b ) const {
        return dist > b.dist;
    }
};
typedef vector<vector<pair<int, int> > > VVP;
// The first element of pair contains label and second element contain cost of that label

int NODES, EDGES;
VI dist;
VI parent;
VI path;
priority_queue<NODE> minQ;
VVP G;

void DIJKSTRA(int source)
{
    dist = VI(NODES, INF);
    parent = VI(NODES, -1);

    NODE u, v;

    dist[source] = 0;
    u.label = source;
    u.dist = 0;

    minQ.push(u);

    while( !minQ.empty() ) {
        u = minQ.top(); minQ.pop();

        FOR(i, 0, G[u.label].size()-1) {
            pair<int, int> p = G[u.label][i];
            v.label = p.first;

            if( dist[u.label] + p.second < dist[p.first] ) {
                dist[p.first] = dist[u.label] + p.second;
                v.dist = dist[p.first];
                parent[p.first] = u.label;
                minQ.push(v);
            }
        }
    }
}

void MakePath(int target)
{
    if(parent[target] != -1)
        MakePath(parent[target]);
    path.push_back(target);
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    int s, t, c;
    int source, target;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> NODES >> EDGES >> source >> target;

        G = VVP(NODES);

        FOR(i, 1, EDGES) {
            cin >> s >> t >> c;

            G[s].PB(PII(t, c));
            G[t].PB(PII(s, c));
        }

        DIJKSTRA(source);

        cout << "Case #" << tc << ": ";

        if(dist[target] == INF)
            cout << "unreachable\n";
        else cout << dist[target] << "\n";

        dist.clear();
        parent.clear();
        path.clear();
        G.clear();
    }

    return 0;
}
