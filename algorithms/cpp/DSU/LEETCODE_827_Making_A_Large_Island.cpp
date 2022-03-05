/*
        Problem Link : https://leetcode.com/problems/making-a-large-island/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
        Rank :
        Complexity:
*/

class Solution {
public:
    // -------------------- DSU ----------------------------
    vector<int> dset, drank, dsize;
    void initSet(int n) {
        dset = vector<int>(n+1);
        drank = vector<int>(n+1, 0);
        dsize = vector<int>(n+1, 1);
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
            dsize[a] += dsize[b];
            dsize[b] = 0;
        }
    }
    // ------------------------------------------------------

    const int dx[4] = { 0,  0, 1, -1 };
    const int dy[4] = { 1, -1, 0,  0 };

    vector<vector<int>> grid;
    int n;

    int cellCode(int i, int j) {
        return i * n + j;
    }

    bool onGrid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int largestIsland(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();

        initSet(n*n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int u = cellCode(i, j);
                for (int k = 0; k < 4; k++) {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if (onGrid(ii, jj) && grid[ii][jj] == 1)
                        unionSet(u, cellCode(ii, jj));
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                unordered_set<int> groups;
                int cnt = 1;
                for (int k = 0; k < 4; k++) {
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if (onGrid(ii, jj) && grid[ii][jj] == 1) {
                        int root = findSet(cellCode(ii, jj));
                        if (groups.find(root) == groups.end()) {
                            cnt += dsize[root];
                            groups.insert(root);
                        }
                    }
                }
                ret = max(ret, cnt);
            }
        }
        return ret == 0 ? n*n : ret;
    }
};