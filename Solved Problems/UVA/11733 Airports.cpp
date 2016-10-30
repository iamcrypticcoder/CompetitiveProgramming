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
vector<EDGE> edges;
int N, M, A;
int minSpanCost, numSpanEdge, numAirport;

int set[10001];
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
        if(numSpanEdge < NODES-1 && edges[i].c < A) {
            if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
                Union(edges[i].u, edges[i].v);
                minSpanCost += edges[i].c;
                numSpanEdge++;
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
        scanf("%d %d %d", &N, &M, &A);
        NODES = N;

        EDGE e;
        FOR(i, 1, M) {
            scanf("%d %d %d", &e.u, &e.v, &e.c);
            edges.PB(e);
        }

        InitSet(NODES);
        minSpanCost = numSpanEdge = numAirport = 0;
        Krushal();

        FOR(i, 1, N) {
            if(set[i] == i) {
                minSpanCost += A;
                numAirport++;
            }
        }

        cout << "Case " << tc << ": " << minSpanCost << " " << numAirport <<"\n";

        edges.clear();
    }

    return 0;
}

