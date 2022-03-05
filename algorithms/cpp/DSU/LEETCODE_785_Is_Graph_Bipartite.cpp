/*
        Problem Link : https://leetcode.com/problems/is-graph-bipartite/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
        Rank :
        Complexity:
*/

class Solution {
public:
    // -------------------- DSU ----------------------------
    vector<int> dset, drank;
    void initSet(int n) {
        dset = vector<int>(n+1);
        drank = vector<int>(n+1, 0);
        for (int i = 0; i <= n; i++) dset[i] = i;
    }
    int findSet(int u) {
        return dset[u] == u ? u : (dset[u] = findSet(dset[u]));
    }
    void unionSet(int u, int v) {
        int a = findSet(u);
        int b = findSet(v);
        if (a != b) {
            if (drank[a] < drank[b]) swap(a, b);
            dset[b] = a;
            if (drank[a] == drank[b]) drank[a]++;
        }
    }
    // ------------------------------------------------------

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        initSet(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int u = i, v = graph[i][j];
                if (findSet(u) == findSet(v)) return false;
                unionSet(graph[i][0], v);
            }
        }
        return true;
    }
};