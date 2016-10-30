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

struct EDGE {
    int u, v, c;
};

int NODES;
int length[51][51];
int set[51];
vector<EDGE> edges;
int totalEdgeCost, minSpanCost;
int numSpanEdges;

void InitSet()
{
    FOR(i, 0, NODES)
        set[i] = i;
}

int FindSet(int u)
{
    return set[u] == u ? u : (set[u] = FindSet(set[u]));
}

void Union(int u, int v)
{
    set[FindSet(u)] = FindSet(v);
}

bool comp(EDGE u, EDGE v)
{
    return u.c < v.c;
}

void Krushal()
{
    sort(edges.begin(), edges.end(), comp);

    numSpanEdges = 0;
    FOR(i, 0, edges.SZ-1) {
        if(numSpanEdges >= NODES-1) break;
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            Union(edges[i].u, edges[i].v);
            minSpanCost += edges[i].c;
            numSpanEdges++;
        }
    }
}

int main()
{
    READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    int n;
    scanf("%d", &TC);
    //cin >> TC;

	FOR(tc, 1, TC) {
        //cin >> n;
        scanf("%d", &n);
        NODES = n;

        totalEdgeCost = 0;
        FOR(u, 1, n)
            FOR(v, 1, n) {
                //cin >> length[u][v];
                scanf("%d", &length[u][v]);
                totalEdgeCost += length[u][v];
                if(u != v && length[u][v] != 0) {
                    EDGE e;
                    e.u = u;
                    e.v = v;
                    e.c = length[u][v];
                    edges.PB(e);
                }
            }

        minSpanCost = 0;
        InitSet();
        Krushal();

        //cout << "Case " << tc << ": ";
        printf("Case %d: ", tc);
        if(numSpanEdges == n-1) {
            //cout << totalEdgeCost - minSpanCost << "\n";
            printf("%d\n", totalEdgeCost - minSpanCost);
        }
        else {
            //cout << "-1\n";
            printf("-1\n");
        }

        edges.clear();

	}
    return 0;
}

