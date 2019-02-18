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

#define MAX_NODE 10000

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

void dijkstra(int source, int target)
{
    dist = VI(NODES+1, INF);
    parent = VI(NODES+1, -1);

    NODE u, v;

    dist[source] = 0;
    u.label = source;
    u.dist = 0;

    minQ.push(u);

    while( !minQ.empty() ) {
        u = minQ.top(); minQ.pop();
/**
        // You can do this optimization for some problems
        if( u.label == target) {
            while( !minQ.empty() ) minQ.pop();
            return;
        }
**/
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
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();

    int s, t, c;
    int source, target;

    while( cin >> NODES >> EDGES ) {
        if(!NODES && !EDGES) break;

        G = VVP( NODES +1 );

        FOR(i, 1, EDGES) {
            cin >> s >> t >> c;

            G[s].PB(pair<int,int>(t,c));
            G[t].PB(pair<int,int>(s,c));
        }

        cin >> source >> target;

        dijkstra(source, target);
        MakePath(target);

        cout << "Distance of target : " << dist[target] << "\n";
        cout << "PATH : ";
        cout << path[0];
        FOR(i, 1, path.size()-1)
            cout << " " << path[i];

        dist.clear();
        parent.clear();
        path.clear();
        G.clear();
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
