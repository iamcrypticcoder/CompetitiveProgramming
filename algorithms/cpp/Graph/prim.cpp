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

struct Node {
	VI adj;
	VI cost;
};

struct Edge {
	int u, v, cost;
};

int NODE, EDGE;

Node node[MAX];
Edge edge[MAX];
bool status[MAX][MAX];
bool used[MAX];
int U[MAX];


VI STV;
vector<Edge> spanEdges;						    // Spanning Tree Edges
int spanCost;								// Minimum Cost

void Input()
{
	int u, v, c;

	cout << "Total Nodes : ";
	cin >> NODE;
	cout << "Total Edges : ";
	cin >> EDGE;

    FOR(i, 1, EDGE) {
		cin >> u >> v >> c;
		node[u].adj.push_back(v);
		node[u].cost.push_back(c);
		node[v].adj.push_back(u);
		node[v].cost.push_back(c);

		edge[i].u = u;
		edge[i].v = v;
		edge[i].cost = c;
	}
}

void ShowEdge()
{
    FOR(i, 1, EDGE)
		cout << edge[i].u << " " << edge[i].v << " " << edge[i].cost << "\n";
}

void init()
{
	FOR(i, 1, NODE) U[i] = i;
}

int find(int n)
{
	int temp;
	temp = n;

	while(U[temp] != temp)
		temp = U[temp];
	return temp;
}

void Merge(int x, int y)
{
	x < y ? U[y] = x : U[x] = y;
}

void Prim()
{
	int i, j, tu, tv, U, V;
	int min;
//	EDGE tempEdge;

	init();

	spanCost = 0;
	STV.push_back(1);
	used[1] = true;

	while(STV.size() != NODE) {
		min = INF;

		for(i=0; i<STV.size(); i++)
			for(j=0; j<node[STV[i]].adj.size(); j++) {
				tu = STV[i];
				tv = node[STV[i]].adj[j];

				if(status[tu][tv] == 0 && node[tu].cost[j] < min && find(tu) != find(tv)) {
					min = node[STV[i]].cost[j];
					U = tu;
					V = tv;
				}
			}
			STV.push_back(V);
			status[U][V] = status[V][U] = true;
			Merge(U, V);
			spanCost += min;
	}
	cout << spanCost << "\n";
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();

    Input();

    Prim();

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
