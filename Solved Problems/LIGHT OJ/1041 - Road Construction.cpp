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

typedef struct {
    int u, v, c;
}EDGE;

MSI nodeMap;
vector<EDGE> edges;
int set[101];
VVI G;
int minSpanCost, spanEdge;
char color[101];


void Init()
{
    FOR(i, 1, 100)
        set[i] = i;
}

int FindSet(int u)
{
    return set[u] == u ? u : (set[u] = FindSet(set[u]));
}

void Union(int u, int v)
{
    //set[FindSet(u)] = FindSet(v);
    set[FindSet(u)] = v;
}

int comp(EDGE a, EDGE b)
{
    return a.c < b.c;
}

void Krushal()
{
    sort(edges.begin(), edges.end(), comp);

    minSpanCost = 0;
    FOR(i, 0, edges.SZ-1) {
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            spanEdge++;
            Union(edges[i].u, edges[i].v);
            minSpanCost += edges[i].c;
        }
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    string city1, city2;
    int cost, nodeNum;
    int m, u, v;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> m;

        G = VVI(101);
        nodeNum = 1;
        Init();
        spanEdge = 0;
        FOR(i, 1, m) {
            cin >> city1 >> city2 >> cost;
            if(nodeMap.find(city1) == nodeMap.end()) nodeMap[city1] = nodeNum++;
            if(nodeMap.find(city2) == nodeMap.end()) nodeMap[city2] = nodeNum++;

            u = nodeMap[city1];
            v = nodeMap[city2];

            G[u].PB(v);
            G[v].PB(u);

            if(cost == 0) {
                if(FindSet(u) != FindSet(v)) {
                    spanEdge++;
                    Union(u, v);
                }
            }
            else {
                EDGE e;
                e.u = u;
                e.v = v;
                e.c = cost;
                edges.PB(e);
            }
        }

        cout << "Case " << tc << ": ";
        Krushal();

        if(spanEdge == nodeNum-1-1) {
            cout << minSpanCost << "\n";
        }
        else {
            cout << "Impossible\n";
        }

        edges.clear();
        nodeMap.clear();
    }



    return 0;
}

