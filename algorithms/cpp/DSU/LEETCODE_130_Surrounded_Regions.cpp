/*
        Problem Link : https://leetcode.com/problems/surrounded-regions/
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time :
        Rank :
        Complexity:
*/

class Solution {
public:
    int m, n;

    // ------------------ DSU -----------------
    vector<int> dset, drank;
    void initSet(int n) {
        dset = vector<int>(n+1);
        drank = vector<int>(n+1, 0);
        for (int i = 0; i <= n; i++) dset[i] = i;
    }
    int findSet(int u) {
        return (dset[u] == u ? u : dset[u] = findSet(dset[u]));
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
    // ------------------ DSU -----------------

    bool isBorderCell(int i, int j) {
        return i == 0 || i == m-1 || j == 0 || j == n-1;
    }

    int cellNumber(int i, int j) {
        return i * n + j;
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        initSet(m*n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') continue;
                int u = cellNumber(i, j);
                //printf("%d %d %d\n", i, j, u);
                if (isBorderCell(i, j)) unionSet(u, m*n);
                else {
                    if (board[i-1][j] == 'O') unionSet(u, cellNumber(i-1, j));
                    if (board[i+1][j] == 'O') unionSet(u, cellNumber(i+1, j));
                    if (board[i][j-1] == 'O') unionSet(u, cellNumber(i, j-1));
                    if (board[i][j+1] == 'O') unionSet(u, cellNumber(i, j+1));
                }
            }
        }

        int borderCellRoot = findSet(m*n);
        printf("borderCellRoot = %d\n", borderCellRoot);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') continue;
                int u = cellNumber(i, j);
                if (findSet(u) != borderCellRoot) board[i][j] = 'X';
            }
        }
    }
};

