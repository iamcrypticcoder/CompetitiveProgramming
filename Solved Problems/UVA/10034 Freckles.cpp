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

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;

#define MAX 101

typedef struct NODE {
    int label;
    double x, y;
};

typedef struct EDGE {
    double dist;
    NODE u, v;

    bool operator < (const EDGE &b) const {
        return dist < b.dist;
    }
};

double POINT_DISTANCE(NODE p1, NODE p2)
{
    return sqrt(fabs(SQR(p1.x - p2.x) + SQR(p1.y - p2.y)));
}

NODE node[MAX];
vector<EDGE> Edges;
vector<EDGE> spanEdges;

// Disjoint Set Data Structure
VI set;     // This vector also act as parent.

void InitSet()
{
    set = VI(MAX);
    FOR(i, 0, MAX-1) set[i] = i;
}

int FindSet(int n)
{
    if(set[n] == n) return n;
    FindSet(set[n]);
}

void Union(int u, int v)
{
    set[FindSet(u)] = v;
}


double Kruskal()
{
    InitSet();

    double ret = 0;
    sort(Edges.begin(), Edges.end());

    FOR(i, 0, Edges.SZ-1)
        if(FindSet(Edges[i].u.label) != FindSet(Edges[i].v.label)) {
            spanEdges.push_back(Edges[i]);
            Union(FindSet(Edges[i].u.label), FindSet(Edges[i].v.label));
            ret += Edges[i].dist;
        }
    return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int i, j, k;
    int TC, tc;
    int N;
    double x, y;

    NODE u;
    EDGE e;

    cin >> TC;

    while(TC--) {
        cin >> N;

        FOR(i, 1, N) {
            cin >> x >> y;
            u.label = i;
            u.x = x;
            u.y = y;
            node[i] = u;
        }

        FOR(i, 1, N)
            FOR(j, i+1, N) {
                e.dist = POINT_DISTANCE(node[i], node[j]);
                e.u = node[i];
                e.v = node[j];
                Edges.PB(e);
            }

        printf("%.2f\n", Kruskal());

        if(TC != 0) cout << "\n";

        Edges.clear();
    }


	return 0;
}
