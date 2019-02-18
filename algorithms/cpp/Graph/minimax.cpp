/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
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

vector<vector<PII> > G;
VC color;
int source, sink;       // We have to find minimax cost from node "source" to "sink"
bool sinkFound;

// -------------------- Disjoint Set Structure --------------------------------------
int dset[10001];
void InitSet(int N)     {   FOR(i, 0, N)    dset[i] = i;     }
int FindSet(int u)      {   return dset[u] == u ? u : (dset[u] = FindSet(dset[u]));    }
void Union(int u, int v){   dset[FindSet(u)] = FindSet(v); }
// ----------------------------------------------------------------------------------


void Input()
{
    int u, v;
    int w;
    Edge edge;

    cin >> NODE >> EDGE;

    for(int i=1; i<=EDGE; i++) {
        cin >> u >> v >> w;
        edge.u = u;
        edge.v = v;
        edge.w = w;
        edges.push_back(edge);
    }
}

int Increase(Edge a, Edge b)
{
    return a.w < b.w;
}

int Kruskal()
{
    int edgeTaken = 0;
    mstCost = 0;

    G = vector<vector<PII> >(NODE);
    sort(edges.begin(), edges.end(), Increase);
    InitSet(NODE);
    for(int i=0; i<edges.size(); i++) {
        if(edgeTaken == NODE-1) break;                      // If you don't need edges after getting spanning edges then keep this line.
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            spanEdge.push_back(edges[i]);
            Union(u, v);
            mstCost += edges[i].w;
            edgeTaken++;
            //cout << edges[i].u << edges[i].v;

            G[u].PB(make_pair(v, w));
            G[v].PB(make_pair(u, w));
        }
    }
    return mstCost;
}

// This will find minimax cost from node "source" to "sink"
int dfs(int u, int minimaxCost)
{
    if(u == sink) sinkFound = true;
    color[u] = BLACK;
    int ret = minimaxCost;
    FOR(i, 0, G[u].size()-1) {
        int v = G[u][i].first;
        int w = G[u][i].second;
        if(color[v] == WHITE) ret = max(ret, dfs(v, w));
        if( !sinkFound ) ret = minimaxCost;
        else break;
    }

    color[u] = WHITE;
    return ret;
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v, w;


    Input();
    cout << Kruskal() << endl;

    for(int i=0; i<spanEdge.size(); i++) {
        cout << spanEdge[i].u << " ";
        cout << spanEdge[i].v << " ";
        cout << spanEdge[i].w << "\n";
    }

    /*
    cin >> NODE >> EDGE;
    G = vector<vector<PII> >(NODE);
    FOR(i, 1, EDGE) {
        cin >> u >> v >> w;
        G[u].PB(make_pair(v, w));
        G[v].PB(make_pair(u, w));
    }
    */
    color = VC(NODE, WHITE);
    source = 0;
    sink = 6;
    sinkFound = false;
    cout << dfs(source, 0) << endl;

    return 0;
}


