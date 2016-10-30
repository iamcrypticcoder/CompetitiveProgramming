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

#define MAX_DIM 99
#define WHITE 0
#define GRAY 1
#define BLACK 2

bool G[MAX_DIM+1][MAX_DIM+1];
int color[MAX_DIM+1][MAX_DIM+1];
int ROW, COL;        // NxM Grid
int R, C;
int areaOfLake = 0;

int DFS_VISIT(int i, int j)
{
    areaOfLake++;
    color[i][j] = GRAY;


    if(G[i-1][j-1] == 1 && color[i-1][j-1] == WHITE)    DFS_VISIT(i-1, j-1);
    if(G[i-1][j]   == 1 && color[i-1][j]   == WHITE)    DFS_VISIT(i-1, j);
    if(G[i-1][j+1] == 1 && color[i-1][j+1] == WHITE)    DFS_VISIT(i-1, j+1);
    if(G[i][j-1]   == 1 && color[i][j-1]   == WHITE)    DFS_VISIT(i, j-1);
    if(G[i][j+1]   == 1 && color[i][j+1]   == WHITE)    DFS_VISIT(i, j+1);
    if(G[i+1][j-1] == 1 && color[i+1][j-1] == WHITE)    DFS_VISIT(i+1, j-1);
    if(G[i+1][j]   == 1 && color[i+1][j]   == WHITE)    DFS_VISIT(i+1, j);
    if(G[i+1][j+1] == 1 && color[i+1][j+1] == WHITE)    DFS_VISIT(i+1, j+1);

    color[i][j] = BLACK;

    return areaOfLake;
}

int main()
{
//    freopen("E:\\input.txt", "r", stdin);
//    freopen("E:\\output.txt", "w", stdout);

    int tc, TC, i, j, k;
    int row, col, r, c;
    string line;

    scanf("%d\n", &TC);

    while(TC--) {
        memset(G, 0, sizeof(G));
        row = 0;
        while(1) {
            getline(cin, line);

            if(line[0] != 'W' && line[0] != 'L')    break;

            row++;
            col = line.size();
            FOR(i, 1, line.size()) {
                if(line[i-1] == 'W')    G[row][i] = 1;
                else                    G[row][i] = 0;
                color[row][i] = WHITE;
            }
        }

        sscanf(line.c_str(), "%d %d", &r, &c);
        areaOfLake = 0;
        memset(color, WHITE, sizeof(color));                // Changing state of all node.
        if(G[r][c] == 1) DFS_VISIT(r, c);
        cout << areaOfLake << "\n";

        while(getline(cin, line)) {
            if(line.size() == 0) break;
            sscanf(line.c_str(),"%d %d",&r,&c);
            areaOfLake = 0;
            memset(color, WHITE, sizeof(color));
            if(G[r][c] == 1) DFS_VISIT(r, c);
            cout << areaOfLake << "\n";
        }
        if(TC != 0) cout << "\n";

    }
	return 0;
}
