#include<bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

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

int main() {
    //READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    vector<pair<int, int>> unionInfo { {1, 2}, {2, 3}, {10, 11}, {12, 13}, {10, 12} };
    initSet(20);
    for (auto& p : unionInfo) unionSet(p.first, p.second);

    for (int i = 1; i <= 20; i++)
        if (findSet(i) == i)
            printf("Root = %d, Size = %d, Rank = %d\n", i, dsize[i], drank[i]);

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**

OUTPUT:
Root = 1, Size = 3, Rank = 1
Root = 4, Size = 1, Rank = 0
Root = 5, Size = 1, Rank = 0
Root = 6, Size = 1, Rank = 0
Root = 7, Size = 1, Rank = 0
Root = 8, Size = 1, Rank = 0
Root = 9, Size = 1, Rank = 0
Root = 10, Size = 4, Rank = 2
Root = 14, Size = 1, Rank = 0
Root = 15, Size = 1, Rank = 0
Root = 16, Size = 1, Rank = 0
Root = 17, Size = 1, Rank = 0
Root = 18, Size = 1, Rank = 0
Root = 19, Size = 1, Rank = 0
Root = 20, Size = 1, Rank = 0
 
*/
