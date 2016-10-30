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
#define INF 99999999

#define MAX 101

typedef struct NODE {
    int label, dist;

    bool operator < (const NODE &b) const {
        return dist > b.dist;
    }
};

vector<int> dist;
vector<int> parent;
vector<int> path;
priority_queue<NODE> minQ;
vector<vector<pair<int, int> > > G;
int nodes;


void DIJKSTRA(int source) {
    dist = vector<int>(nodes+1, INF);
    parent = vector<int>(nodes+1, -1);

    dist[source] = 0;
    NODE u, v;
    u.label = source;
    u.dist = 0;
    minQ.push(u);

    while( ! minQ.empty()) {
        NODE u = minQ.top();
        minQ.pop();

        FOR(i, 0, G[u.label].size()-1) {
            pair<int, int> p = G[u.label][i];
            v.label = p.first;

            if(dist[u.label] + p.second < dist[p.first]) {
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
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int temp, label, cost, source, target;
    NODE tempNode;
    int tc = 1;

    while(cin >> nodes) {
        if(nodes == 0) break;

        G = vector<vector<pair<int, int> > >(nodes+1);

        FOR(i, 1, nodes) {
            cin >> temp;

            FOR(j, 1, temp) {
                cin >> label >> cost;
                G[i].push_back(pair<int,int>(label, cost));
            }
        }

        cin >> source >> target;

        DIJKSTRA(source);

        cout << "Case " << tc++ << ": Path = ";
        MakePath(target);
        cout << path[0];
        FOR(i, 1, path.size()-1)
            cout << " " << path[i];
        cout << "; ";

        cout << dist[target] << " second delay\n";

        dist.clear();
        parent.clear();
        path.clear();
        G.clear();
    }

/*
    NODE temp;

    temp.label = 1;
    temp.cost = 10;

    MINQ.push(temp);

    temp.label = 2;
    temp.cost = 5;

    MINQ.push(temp);

    cout << (MINQ.top()).cost;
*/
	return 0;
}
