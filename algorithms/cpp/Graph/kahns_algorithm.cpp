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

int NODE, EDGE;
vector<vector<int>> G;

vector<int> kahnsAlgo() {
    vector<int> ret;

    vector<int> inDeg(NODE+1, 0);
    for (int u = 1; u <= NODE; u++) {
        for (int v : G[u]) inDeg[v]++;
    }

    // Push all nodes with 0 in degree
    queue<int> Q;
    for (int u = 1; u <= NODE; u++)
        if (inDeg[u] == 0) Q.push(u);

    int visited = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ret.push_back(u);
        for (int v : G[u]) {
            inDeg[v]--;
            if (inDeg[v] == 0) Q.push(v);
        }
        visited++;
    }

    // If all nodes aren't traversed, it means cycle exists
    if (visited != NODE) {
        cout << "There exists a cycle in the graph\n";
        return vector<int>();
    }
    return ret;
}

int main() {
    int u, v;

    while (cin >> NODE >> EDGE) {
        G = vector<vector<int>>(NODE+1);
        for (int i = 1; i <= EDGE; i++) {
            cin >> u >> v;
            G[u].push_back(v);
        }

        vector<int> topoOrder = kahnsAlgo();
        for (int x : topoOrder)
            cout << x << " ";
        cout << endl;
    }
}

/**

Input:
4 5
1 2
1 3
3 2
2 4
3 4

9 9
1 2
2 3
1 4
4 3
5 4
6 5
5 7
6 7
8 7

Output:
1 3 2 4
1 6 8 9 2 5 4 7 3

**/
