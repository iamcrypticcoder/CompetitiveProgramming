/*
        Problem Link : https://www.spoj.com/problems/AKBAR/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :  0.35
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
#include <limits.h>
#include <algorithm>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

const int MAX_NODE = int(1e5);

int N, R, M;

vector<vector<int>> G;
vector<bool> visited;
vector<int> protectionCount;

// Do bfs until dist == maxDist
// Not optimal when already a visited node found while doing bfs
bool bfs(int source, int maxDist) {
    protectionCount[source]++;
    if (protectionCount[source] > 1) return false;

    queue<pair<int, int>> Q;
    Q.push({source, maxDist});
    visited[source] = true;

    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        if (u.second == 0) continue;
        for (auto v : G[u.first]) {
            if (visited[v] == false) {
                protectionCount[v]++;
                Q.push({v, u.second - 1});
                visited[v] = true;
            }
        }
    }
    return true;
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    TC = srcInt();
    for (int tc = 1; tc <= TC; tc++) {
        N = srcInt();
        R = srcInt();
        M = srcInt();

        G = vector<vector<int>>(N+1);
        for (int i = 0; i < R; i++) {
            int u = srcInt();
            int v = srcInt();
            G[u].push_back(v);
            G[v].push_back(u);
        }

        visited = vector<bool>(N+1, false);
        protectionCount = vector<int>(N+1, 0);
        bool result = true;
        for (int i = 0; i < M; i++) {
            int K = srcInt();
            int S = srcInt();
            if (result == false) continue;
            result = bfs(K, S);
        }

        // Check all nodes are visited means all cities are protected
        for (int i = 1; i <= N; i++)
            if (visited[i] == false) {
                result = false;
                break;
            }

        printf("%s\n", result ? "Yes" : "No");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
