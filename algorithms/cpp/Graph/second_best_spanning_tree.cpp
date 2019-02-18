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
typedef unsigned long long ULL;
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

int GCD(int a,int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)   {   return a/GCD(a,b)*b;                }

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

#define MAX 10000

typedef struct {
    int u, v;
    int w;
} Edge;

int NODE, EDGE;                 // Number of nodes and number of edges in graph
vector<Edge> edges;             // Contains edges of the graph
vector<Edge> mstEdges;          // Contains only edges of MST
vector<Edge> secondMstEdges;    // Contains only edges of second best MST
int mstCost, secondMstCost;

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

    for(int i=1; i <= EDGE; i++) {
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

void secondBestMST()
{
    int i, j, u, v;
    mstCost = 0;
    secondMstCost = INF;
    vector<Edge> tempEdges;

    InitSet(NODE);
    sort(edges.begin(), edges.end(), Increase);

    for(i=0; i<edges.size(); i++) {
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            mstEdges.push_back(edges[i]);
            Union(edges[i].u, edges[i].v);
            mstCost += edges[i].w;
            //cout << edges[i].u << edges[i].v;
        }
    }

    for(i = 0; i < mstEdges.size(); i++) {
        InitSet(NODE);
        int weight = 0;
        tempEdges = vector<Edge>();
        for(j=0; j<edges.size(); j++) {
            u = edges[j].u;
            v = edges[j].v;
            if(min(u, v) == min(mstEdges[i].u, mstEdges[i].v) &&
               max(u, v) == max(mstEdges[i].u, mstEdges[i].v)) continue;
            if(FindSet(u) != FindSet(v)) {
                tempEdges.push_back(edges[j]);
                Union(u,v);
                weight += edges[j].w;
                //cout << edges[j].u << edges[j].v;
            }
        }
        if(weight < secondMstCost) {
            secondMstCost = weight;
            secondMstEdges = vector<Edge>(tempEdges.begin(), tempEdges.end());
        }
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();

    Input();
    secondBestMST();

    cout << mstCost << " " << secondMstCost << endl;

    FOR(i, 0, secondMstEdges.size()-1)
        cout << secondMstEdges[i].u << " " << secondMstEdges[i].v << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
