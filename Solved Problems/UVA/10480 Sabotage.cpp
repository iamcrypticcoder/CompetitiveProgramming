
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

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )
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
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;
typedef map<string, string> MSS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
VVI G;

// For BFS Algorithm
VI parent, color, dist;                   //
queue<int> Q;

int s, t;

// For EdmondsKarp Algorithm
int f, maxFlow;
VVI cap;        // Capacity Matrix
VVI flow;       // Flow Matrix

void BFS(int s, int t)
{
    int u, v;

    color = VI(NODE+1, WHITE);
    dist = VI(NODE+1, INF);
    parent = VI(NODE+1, -1);

    while( ! Q.empty()) Q.pop();

    Q.push(s);
    dist[s] = 0;
    color[s] = GRAY;

    while(! Q.empty()) {
        u = Q.front();  Q.pop();

        if(u == t) break;

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE && cap[u][v] - flow[u][v] > 0) {
                dist[v] = dist[u] + 1;
                Q.push(v);
                color[v] = GRAY;
                parent[v] = u;
            }
        }
        color[u] = BLACK;
    }
}

void augmentPath(int v, int minEdge)
{
    if(v == s) {
        f = minEdge;
        return;
    }

    while(parent[v] != -1) {
        augmentPath(parent[v], min(minEdge, cap[parent[v]][v] - flow[parent[v]][v]));
        flow[parent[v]][v] += f;
        flow[v][parent[v]] -= f;
        parent[v] = -1;
    }
}

void EdmondsKarp()
{
    while(1) {
        BFS(s, t);
        f = 0;
        augmentPath(t, INF);
        if(f == 0) break;
        maxFlow += f;
    }
}

void ShowResult()
{
    int u, v;

    FOR(u, 1, NODE) {
        if(color[u] == BLACK) {
            FOR(i, 0, G[u].SZ-1) {
                v = G[u][i];
                if(color[v] == WHITE)
                    cout << u << " " <<  v << "\n";
            }
        }
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v, c;

    while(cin >> NODE >> EDGE) {
        if(NODE == 0 && EDGE == 0) break;
        G = VVI(NODE+1);
        cap = VVI(NODE+1);
        flow = VVI(NODE+1);

        FOR(i, 1, NODE) {
            cap[i] = VI(NODE+1);
            flow[i] = VI(NODE+1);
        }

        FOR(i, 1, EDGE) {
            cin >> u >> v >> c;
            G[u].PB(v);
            G[v].PB(u);
            cap[u][v] = c;
            cap[v][u] = c;
        }

        s = 1;  t = 2;

        EdmondsKarp();

        ShowResult();
        cout << "\n";

/*
        FOR(i, 0, edges.SZ-1) {
            cout << edges[i].first << " " << edges[i].second << " ";
            cout << abs(flow[edges[i].first][edges[i].second]) << " ";
            cout << cap[edges[i].first][edges[i].second] << "\n";
        }

        FOR(i, 0, edges.SZ-1) {
            II e = edges[i];
            if(cap[e.first][e.second] == abs(flow[e.first][e.second]))
                cout << e.first << " " << e.second << "\n";
        }

        cout << "\n";
*/

    }
	return 0;
}



/*

#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stdio.h>

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

#define maxn 52

using namespace std;

#define MIN(a, b) (a>b?b:a)

list<int>Edge[maxn];

struct ss {
        int u;
        int cost;
};

class comp {
public:
        bool operator() ( const ss &a, const ss &b) {
                return a.cost < b.cost;
        }
};

priority_queue<ss, vector<ss>, comp >Q;


char Color[maxn];
int MaxF[maxn][maxn];
int Org[maxn][maxn];
int P[maxn];
int N, M;

void Updates(int v, int c) {
        int u;
        if(v == 1) return;
        u = P[v];
        MaxF[u][v] -= c;
        MaxF[v][u] += c;
        Updates(P[v],c);
}


int BFS() {
        ss t, d;
        list<int>::iterator p;
        int c, v;
        t.u = 1;
        t.cost = 1000000000;
        Q.push(t);
        Color[1] = 1;
        while(!Q.empty()) {
                t = Q.top();
                Q.pop();
                for(p = Edge[t.u].begin(); p != Edge[t.u].end(); p++) {
                        v = *p;
                        if(Color[v] || !MaxF[t.u][v]) continue;
                        Color[v] = 1;
                        P[v] = t.u;
                        c = MIN(t.cost,MaxF[t.u][v]);
                        if(v == 2) {
                                Updates(v,c);
                                return 1;
                        }
                        d.cost = c;
                        d.u = v;
                        Q.push(d);
                }
        }
        return 0;
}

void Reset() {
        int i;
        for(i = 1; i<= N; i++)
                Color[i] = 0;
        while(!Q.empty()) { Q.pop(); }
}

void Cal() {
        int i, v;
        list<int>::iterator p;

        while(BFS()) {
                Reset();
        }
        for(i = 1; i<= N; i++) {
                if(Color[i]) {
                        for(p = Edge[i].begin(); p != Edge[i].end(); p++) {
                                v = *p;
                                if(Color[v]) continue;
                                cout<<i<<" "<<v<<endl;
                        }
                }
        }
        cout<<endl;
}


void Free() {
        int i;
        for(i = 1; i<= N; i++){
                Edge[i].clear();
                Color[i] = 0;
        }
}

int main() {
        READ("input.txt");
        WRITE("output.txt");

        int i, u, v, c;
        while(cin>>N>>M) {
                if(!N &&!M) break;
                for(i = 0; i<M; i++) {
                        cin>>u>>v>>c;
                        Org[u][v] = Org[v][u] = c;
                        MaxF[u][v] = MaxF[v][u] = c;
                        Edge[u].push_back(v);
                        Edge[v].push_back(u);
                }
                Cal();
                Free();
        }
}

*/
