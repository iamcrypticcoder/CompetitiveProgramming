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

#define PQ priority_queue
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

struct NODE {
    int x, y;
};
struct EDGE {
    int u, v;
    double c;
};
int NODES, EDGES;
vector<NODE> nodes;
vector<EDGE> edges;
double threshold, lRoads, lRailroads;
int nRoads, nRailroads;

int set[1001];
void InitSet(int N)     {   FOR(i, 1, N)    set[i] = i;     }
int FindSet(int u)      {   return set[u] == u ? u : (set[u] = FindSet(set[u]));    }
void Union(int u, int v){   set[FindSet(u)] = FindSet(v); }

bool comp(EDGE A, EDGE B)
{
    return A.c < B.c;
}

void Krushal()
{
    sort(edges.begin(), edges.end(), comp);

    FOR(i, 0, edges.SZ-1) {
        if(nRailroads + nRoads == NODES-1) break;
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            Union(edges[i].u, edges[i].v);
            if(edges[i].c > threshold) {
                lRailroads += edges[i].c;
                nRailroads++;
            }
            else {
                lRoads += edges[i].c;
                nRoads++;
            }
        }
    }
}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;

    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> NODES >> threshold;

        NODE n;
        FOR(i, 1, NODES) {
            cin >> n.x >> n.y;
            nodes.PB(n);
        }

        EDGE e;
        FOR(i, 0, nodes.SZ-1)
            FOR(j, i+1, nodes.SZ-1) {
                NODE u = nodes[i];
                NODE v = nodes[j];
                e.u = i+1;
                e.v = j+1;
                e.c = sqrt(SQR(u.x - v.x) + SQR(u.y - v.y));
                edges.PB(e);
            }

        lRailroads = lRoads = 0.0;
        nRailroads = nRoads = 0;
        InitSet(NODES);
        Krushal();

        cout << "Case #" << tc << ": ";
        printf("%d %.lf %.lf\n", nRailroads+1, lRoads, lRailroads);

        nodes.clear();
        edges.clear();
    }
    return 0;
}

