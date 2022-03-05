/*
        Problem Link : https://leetcode.com/problems/number-of-closed-islands/
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

    vector<vector<int>> grid;
    int m, n;

    bool isBorderCell(int i, int j) {
        return i == 0 || i == m-1 || j == 0 || j == n-1;
    }

    int cellCode(int i, int j) {
        return i * n + j;
    }

    int closedIsland(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();

        initSet(m*n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                int u = cellCode(i, j);
                if (isBorderCell(i, j)) {
                    unionSet(u, m*n);
                    continue;
                }
                if (grid[i-1][j] == 0) unionSet(u, cellCode(i-1, j));
                if (grid[i+1][j] == 0) unionSet(u, cellCode(i+1, j));
                if (grid[i][j-1] == 0) unionSet(u, cellCode(i, j-1));
                if (grid[i][j+1] == 0) unionSet(u, cellCode(i, j+1));
            }
        }

        int borderRoot = findSet(m*n);
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                int u = cellCode(i, j);
                int uRoot = findSet(u);
                if (uRoot != borderRoot && uRoot == u) ret++;
            }
        }

        return ret;
    }
};
