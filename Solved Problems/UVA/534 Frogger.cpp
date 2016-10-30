#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
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
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    double x, y;
}POINT;

double POINT_DIST(POINT a, POINT b)
{
    return sqrt(SQR(a.x - b.x) + SQR(a.y - b.y));
}

int N;
vector<POINT> VP;
double dist[201][201];

void Floyd()
{
    FOR(i, 1, N)    FOR(j, i+1, N)    dist[i][j] = dist[j][i] = POINT_DIST(VP[i], VP[j]);
    FOR(i, 1, N)
        dist[i][i] = 0;

    FOR(k, 1, N)
        FOR(i, 1, N)
            FOR(j, 1, N)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));

}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    POINT p;

    tc = 1;
    while(cin >> N) {
        if(N == 0) break;
  //      if(tc > 1) cout << "\n";

        VP = vector<POINT>(N+1);

        FOR(i, 1, N) {
            cin >> p.x >> p.y;

            VP[i] = p;
        }
    //    double d = POINT_DIST(VP[1], VP[2]);

        Floyd();

        cout << "Scenario #" << tc++ << "\n";
        printf("Frog Distance = %.3lf\n\n", dist[1][2]);
    }


	return 0;
}


/** Another solution better than above **/
/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.019
    Rank :      482
    Complexity: O(E lg E) + O(V)
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
    double w;
} Edge;

int NODE, EDGE;
vector<Edge> edges;
vector<Edge> spanEdge;
double mstCost;

vector<vector<pair<int, double> > > G;
VC color;
int source, sink;       // We have to find minimax cost from node "source" to "sink"
bool sinkFound;

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
    int edgeTaken = 0;
    mstCost = 0;

    G = vector<vector<pair<int, double> > >(NODE);
    sort(edges.begin(), edges.end(), Increase);
    InitSet(NODE);
    for(int i=0; i<edges.size(); i++) {
        if(edgeTaken == NODE-1) break;                      // If you don't need edges after getting spanning edges then keep this line.
        if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
            int u = edges[i].u;
            int v = edges[i].v;
            double w = edges[i].w;
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
double dfs(int u, double minimaxCost)
{
    if(u == sink) sinkFound = true;
    color[u] = BLACK;
    double ret = minimaxCost;
    FOR(i, 0, G[u].size()-1) {
        int v = G[u][i].first;
        double w = G[u][i].second;
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
   // WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    vector<PII> pnts;

    tc = 1;
    while(scanf("%d", &NODE) == 1) {
        if(NODE == 0) break;
        //if(tc > 1) printf("\n");

        pnts = vector<PII>(NODE);
        FOR(i, 0, NODE-1) {
            scanf("%d %d", &pnts[i].first, &pnts[i].second);
        }
        FOR(i, 0, NODE-1) FOR(j, i+1, NODE-1) {
            Edge e;
            e.u = i;
            e.v = j;
            e.w = sqrt(SQR(pnts[i].first - pnts[j].first) + SQR(pnts[i].second - pnts[j].second));
            edges.PB(e);
        }

        Kruskal();

        color = VC(NODE, WHITE);
        source = 0;
        sink = 1;
        sinkFound = false;
        printf("Scenario #%d\n", tc++);
        printf("Frog Distance = %.3lf\n\n", dfs(source, 0));

        edges.clear();
        spanEdge.clear();

    }

    return 0;
}
