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

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int MAX_NODE = int(1e5);

int NODES;      // Denotes number of NODES
int EDGES;      // Denotes number of EDGES

vector<vector<int>> G;          // Adjacency List of Graph
vector<int> dist;               // Distance from source node
vector<char> color;             // State of a node
vector<int> parent;             // Parent of a node
vector<int> path;               // Desired Path

/**
Use these prototypes for based on your problem:
When multi-dimension comes in your problem don't use vector, it will increase your coding time.
int dist[MAX][MAX][MAX];    // Multi-dimensional dist array
char color[MAX][MAX][MAX];  // Multi-dimensional color array
char grid[MAX][MAX][MAX];   // Multi-dimensional grid array
**/

void BFS(int source) {
    int u, v;
    queue<int> Q;

    dist = vector<int>(MAX_NODE);
    color = vector<char>(MAX_NODE);
    parent = vector<int>(MAX_NODE);

    Q.push(source);
    dist[source] = 0;
    parent[source] = -1;
    color[source] = GRAY;

    while(!Q.empty()) {
        u = Q.front(); Q.pop();

        for (auto v : G[u]) {
            v = G[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

void makePath(int sink) {
    if(parent[sink] == -1) {
        path.PB(sink);
        return;
    }

    MakePath(parent[sink]);
    path.PB(sink);
}

void showPath() {
    FOR(i, 0, path.SZ-1)
        cout << path[i] << " ";
    cout << endl;
}

int main() {
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();

    int u, v;

    cin >> NODES >> EDGES;
    G = vector<vector<int>>(NODES + 1);

    FOR(i, 1, EDGES) {
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }

    BFS(6);

    MakePath(8);

    ShowPath();

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
