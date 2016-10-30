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
int NODES, EDGES;
int nodeNum;
MSI nodeMap;
vector<EDGE> edges;
int minSpanCost, numSpanEdge;

int set[401];
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
        if(numSpanEdge == NODES-1) break;
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            Union(edges[i].u, edges[i].v);
            minSpanCost += edges[i].c;
            numSpanEdge++;
        }
    }
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");

    int TC, tc;
    int S, C;
    string home, city1, city2, line;
    int w;

    //scanf("%d", &TC);
    //cin >> TC;

    while(cin >> S >> C) {
        if(S == 0 && C == 0) break;

        NODES = S; EDGES = C;

        FOR(i, 1, S) {
            cin >> line;
            nodeMap[line] = i;
        }

        FOR(i, 1, C) {
            cin >> city1 >> city2 >> w;
            EDGE e;
            e.u = nodeMap[city1];
            e.v = nodeMap[city2];
            e.c = w;
            edges.PB(e);
        }
        cin >> line;

        minSpanCost = numSpanEdge = 0;
        InitSet(NODES);
        Krushal();

        if(numSpanEdge == NODES-1) {
            cout << minSpanCost << "\n";
        }
        else cout << "Impossible\n";

        edges.clear();
        nodeMap.clear();
    }

    return 0;
}

