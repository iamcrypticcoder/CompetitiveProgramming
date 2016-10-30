/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

typedef struct {
    int u, v;
    int w;
} Edge;

int NODE, EDGE;
vector<Edge> edges;
vector<Edge> spanEdge;
int mstCost;
vector<int> heavyCycleEdges;

// -------------------- Disjoint Set Structure --------------------------------------
int dset[10001];
void InitSet(int N)     {   FOR(i, 0, N)    dset[i] = i;     }
int FindSet(int u)      {   return dset[u] == u ? u : (dset[u] = FindSet(dset[u]));    }
void Union(int u, int v){   dset[FindSet(u)] = FindSet(v); }
// ----------------------------------------------------------------------------------

int Increase(Edge a, Edge b)
{
    return a.w < b.w;
}

int Kruskal()
{
    mstCost = 0;

    sort(edges.begin(), edges.end(), Increase);
    InitSet(NODE);
    for(int i=0; i<edges.size(); i++) {
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            spanEdge.push_back(edges[i]);
            Union(edges[i].u, edges[i].v);
            mstCost += edges[i].w;
            //cout << edges[i].u << edges[i].v;
        } else {
            heavyCycleEdges.PB(edges[i].w);
        }
    }
    return mstCost;
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v;
    int w;
    Edge edge;

    while(scanf("%d %d", &NODE, &EDGE) == 2) {
        if(NODE == 0 && EDGE == 0) break;

        for(int i=1; i<=EDGE; i++) {
            cin >> u >> v >> w;
            edge.u = u;
            edge.v = v;
            edge.w = w;
            edges.push_back(edge);
        }

        Kruskal();

        if(heavyCycleEdges.SZ == 0) printf("forest");
        else {
            printf("%d", heavyCycleEdges[0]);
            FOR(i, 1, heavyCycleEdges.SZ-1) printf(" %d", heavyCycleEdges[i]);
        }
        printf("\n");

        edges.clear();
        spanEdge.clear();
        heavyCycleEdges.clear();
    }

    return 0;
}


