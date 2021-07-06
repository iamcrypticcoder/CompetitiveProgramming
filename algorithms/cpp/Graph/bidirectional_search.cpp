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

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define PQ priority_queue
#define PB push_back
#define SZ size()

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

int NODES;      // Denotes number of NODES
int EDGES;      // Denotes number of EDGES

VVI G;          // Adjacency List of Graph

int searchLevel(queue<int> &q, bool sVisited[], bool dVisited[], int parent[]) {
    int u = q.front(); q.pop();
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!sVisited[v]) {
            sVisited[v] = true;
            parent[v] = u;
            q.push(v);

            if (dVisited[v]) return v;
        }
    }
    return INT_MIN;
}

vector<int> makePath(int collision, int sParent[], int dParent[]) {
    vector<int> ret;

    // Add source to before collision
    stack<int> s;
    int u = collision;
    while (sParent[u] != -1) {
        u = sParent[u];
        s.push(u);
    }
    while (!s.empty()) {
        ret.PB(s.top()); s.pop();
    }

    // Add collision node
    ret.PB(collision);

    // Add after collision to destination
    u = collision;
    while (dParent[u] != -1) {
        u = dParent[u];
        ret.PB(u);
    }

    return ret;
}

vector<int> bidirectionalSearch(int s, int d) {
    bool sVisited[NODES+1], dVisited[NODES+1];
    int sParent[NODES+1], dParent[NODES+1];
    queue<int> sQ, dQ;

    memset(sVisited, false, sizeof sVisited);
    memset(dVisited, false, sizeof dVisited);

    sQ.push(s);
    sVisited[s] = true;
    sParent[s] = -1;

    dQ.push(d);
    dVisited[d] = true;
    dParent[d] = -1;

    while (!sQ.empty() && !dQ.empty()) {
        int collision = searchLevel(sQ, sVisited, dVisited, sParent);
        if (collision != INT_MIN) {
            cout << "Collision at " << collision << endl;
            return makePath(collision, sParent, dParent);
        }

        collision = searchLevel(dQ, dVisited, sVisited, dParent);
        if (collision != INT_MIN) {
            cout << "Collision at " << collision << endl;
            return makePath(collision, sParent, dParent);
        }
    }
    return vector<int>();
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int u, v;

    cin >> NODES >> EDGES;
    G = VVI(NODES + 1);
    FOR(i, 1, EDGES) {
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }

    vector<int> path = bidirectionalSearch(0, 14);
    if (path.size() == 0) cout << "Unable to reach";
    else {
        for (vector<int>::iterator i = path.begin(); i < path.end(); i++)
            cout << *i << " ";
        cout << endl;
    }
}

/**
 *
Input:

15 14
0 4
1 4
2 5
3 5
4 6
5 6
6 7
7 8
8 9
8 10
9 11
9 12
10 13
10 14

*/