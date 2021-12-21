#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

struct State {
    int node, dist, nodeCnt;
    State();
    State(int a, int b, int c) : node(a), dist(b), nodeCnt(c) {}
    bool operator < (const State& o) const {
        return dist > o.dist;
    }
};


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // Make adj list
    vector<vector<pair<int, int>>> G = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < flights.size(); i++) {
        int u = flights[i][0], v = flights[i][1], c = flights[i][2];
        G[u].push_back({v, c});
    }

    // Start dijkstra
    priority_queue<State> pq;
    vector<int> dist = vector<int>(n, INT_MAX);
    pq.push(State(src, 0, 1));
    dist[src] = 1;                      // Dist based on stops nodes

    while (!pq.empty()) {
        State u = pq.top(); pq.pop();

        if (u.node == dst) return u.dist;

        // Can't use more than k+2 nodes as a path
        if (u.nodeCnt == k+2) continue;

        for (auto p : G[u.node]) {
            if (u.nodeCnt+1 < dist[p.first]) {
                dist[p.first] = u.nodeCnt+1;
                pq.push(State(p.first, u.dist + p.second, dist[p.first]));
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main()
{
    READ("../input.txt");
    //WRITE("output.txt");



    return 0;
}