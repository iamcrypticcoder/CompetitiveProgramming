#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

//-----------------------------------START OF MDiGraph-------------------------------

#define WHITE 1
#define GRAY 2
#define BLACK 3

#define MAX_NODE 201

class MGraph {
public:	
	int Nodes, Edges;
	bool Link[MAX_NODE][MAX_NODE];					// This means Edges
	int STATUS[MAX_NODE];
	int COLOR[MAX_NODE];
	queue<int> Q;

	void InitStatus();
	void InitLink();
	
	MGraph();
	void InitGraph();

	void InputGraph(int node, int edge);
	
	void Create(int NumOfVertex);

	bool IsBipartite();

	void ShowGraph();
};

void MGraph::InitStatus()
{
	for(int i =1; i<=MAX_NODE-1; i++)
		STATUS[i] = WHITE;
}

void MGraph::InitLink()
{
	int i, j;
	for(i=1; i <= MAX_NODE-1; i++)
		for(j= i; j <= MAX_NODE-1; j++)
			Link[i][j]  = Link[j][i] = false;	
}


MGraph::MGraph()
{
	InitLink();

	Nodes = Edges = 0;
}

void MGraph::InitGraph()
{
	InitLink();

	Nodes = Edges = 0;	
}

void MGraph::InputGraph(int node, int edge)
{
	int i, u, v;

	InitGraph();

	Nodes = node; 
	Edges = edge;

	for(i=1; i <= Edges; i++) {
		cin >> u >> v;
		Link[u+1][v+1] = Link[v+1][u+1] = 1;
	}
}


bool MGraph::IsBipartite()
{
	int i, j, u;
	queue<int> Q;

	InitStatus();
	Q.push(1);		STATUS[1] = GRAY;	
	COLOR[1] = WHITE;

	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		STATUS[u] = BLACK;

		for(i = 1; i<=Nodes; i++)
			if(Link[u][i] == 1 && STATUS[i] == WHITE) {
				STATUS[i] = GRAY;
				Q.push(i);

				COLOR[i] = COLOR[u] == WHITE ? BLACK : WHITE;
			}
	}
	for(i=1; i<=Nodes; i++)
		for(j=i; j<=Nodes; j++)
			if(Link[i][j] == 1 && COLOR[i] == COLOR[j])
					return false;
	return true;
}

void MGraph::ShowGraph()
{
	int i, j;
	for(i=1; i<=Nodes; i++)
		for(j=i; j<=Nodes; j++)
			if(Link[i][j] == 1 || Link[j][i] == 1)
				cout << i << " " << j << "\n";
}	



int main()
{
	MGraph G;
	list<int> T;

	int node, edge;

	while(cin >> node && node != 0) {

		cin >> edge;

		G.InputGraph(node, edge);

		if(G.IsBipartite())
			cout << "BICOLORABLE.\n";
		else 
			cout << "NOT BICOLORABLE.\n";

	}

	return 0;
}

// Another Solution. 0.008


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

int NODE, EDGE;
VVI G;
VI color;

// Colors the vertices with 1 and 2.
int isBipartite(int u, int c)
{
    color[u] = c;
    c = (c == 1 ? 2 : 1);

    int ret = 1;
    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];
        if(color[v] == 0)
            ret = isBipartite(v, c);
        else if(color[v] == color[u])
            return 0;
    }

    return ret;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v;

    while(cin >> NODE) {
        if(NODE == 0) break;

        G = VVI(NODE);                      // Strats from 0 index
        color = VI(NODE);

        cin >> EDGE;

        FOR(i, 1, EDGE) {
            cin >> u >> v;
            G[u].PB(v);
            G[v].PB(u);
        }
        if(isBipartite(0, 1))
            cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }


	return 0;
}