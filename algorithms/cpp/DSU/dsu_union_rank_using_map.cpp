#include<bits/stdc++.h>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

// -------------------- DSU ----------------------------
unordered_map<int, pair<int, int>> dset;        // x -> parent, rank
unordered_map<int, int> dsize;                  // x -> size

void initSet(vector<int>& arr) {
    for (int& x : arr) {
        dset[x] = {x, 0};
        dsize[x] = 1;
    };
}
int findSet(int u) {
    return (dset[u].first == u ? u : dset[u].first = findSet(dset[u].first));
}
void unionSet(int u, int v) {
    int a = findSet(u);
    int b = findSet(v);
    if (a != b) {
        if (dset[a].second < dset[b].second) swap(a, b);
        dset[b].first = a;
        if (dset[a].second == dset[b].second) dset[a].second++;
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

    vector<int> arr = {100, 200, 1, 2, 3, 5, int(1e9 + 1), int(1e9 + 2), int(1e9 + 3)};
    vector<pair<int, int>> unionInfo { {1, 2}, {2, 5}, {int(1e9 + 1), int(1e9 + 2)}, {int(1e9 + 2), int(1e9 + 3)} };

    initSet(arr);
    for (auto& p : unionInfo) unionSet(p.first, p.second);

    for (auto& x : arr)
        if (findSet(x) == x)
            printf("Root = %d, Size = %d, Rank = %d\n", x, dsize[x], dset[x].second);

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**

OUTPUT:
 
Root = 100, Size = 1, Rank = 0
Root = 200, Size = 1, Rank = 0
Root = 1, Size = 3, Rank = 1
Root = 3, Size = 1, Rank = 0
Root = 1000000001, Size = 3, Rank = 1
 
*/
