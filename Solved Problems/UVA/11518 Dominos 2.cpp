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


using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define MAX_DIMENSION 25
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

int numOfTiles, m, l;
vector<vector<short> > G;
char color[10001];

int DFS_VISIT(int start)
{
    int countAdj = 1;
    color[start] = GRAY;

    FOR(i, 0, G[start].size()-1) {
        if(color[G[start][i]] == WHITE)
            countAdj += DFS_VISIT(G[start][i]);
    }

    color[start] = BLACK;

    return countAdj;
}

int main()
{
//    freopen("E:\\input.txt", "r", stdin);
//    freopen("E:\\output.txt", "w", stdout);

    int tc, TC, i, j, k;
    int x, y, z;
    int countAdj;

    cin >> TC;

    while(TC--) {
        G = vector<vector<short> >(10001);
        cin >> numOfTiles >> m >> l;

        FOR(i, 1, m) {
            cin >> x >> y;
            G[x].push_back(y);
        }
        memset(color, WHITE, sizeof(color));
        countAdj = 0;
        FOR(i, 1, l) {
            cin >> z;
            if(color[z] == WHITE) countAdj += DFS_VISIT(z);
        }

        cout << countAdj << "\n";

        G.clear();
    }

	return 0;
}
