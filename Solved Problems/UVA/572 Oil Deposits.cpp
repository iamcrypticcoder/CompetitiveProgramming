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

#define MAX_DIMENSION 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

bool G[MAX_DIMENSION+1][MAX_DIMENSION+1];
int color[MAX_DIMENSION+1][MAX_DIMENSION+1];
int ROW, COL;

void Input()
{
    int i, j;
    string temp;

    memset(G, 0, sizeof(G));

    FOR(i, 1, ROW) {
        cin >> temp;
        FOR(j, 1, COL) {
            if(temp[j-1] == '*') G[i][j] = 0;
            else G[i][j] = 1;
            color[i][j] = WHITE;
        }
    }
}

void DFS_VISIT(int i, int j, int color);

int DFS()                   // Returns number of component
{
    int i, j;
    int numComponent = 0;       // Denotes the number of connected component

    FOR(i, 1, ROW)
        FOR(j, 1, COL)
            if(G[i][j] == 1 && color[i][j] == WHITE)
                DFS_VISIT(i, j, ++numComponent);
    return numComponent;
}

void DFS_VISIT(int i, int j, int numComp)
{
    color[i][j] = GRAY;

    if(G[i-1][j-1] == 1 && color[i-1][j-1] == WHITE)    DFS_VISIT(i-1, j-1, numComp);
    if(G[i-1][j]   == 1 && color[i-1][j]   == WHITE)    DFS_VISIT(i-1, j, numComp);
    if(G[i-1][j+1] == 1 && color[i-1][j+1] == WHITE)    DFS_VISIT(i-1, j+1, numComp);
    if(G[i][j-1]   == 1 && color[i][j-1]   == WHITE)    DFS_VISIT(i, j-1, numComp);
    if(G[i][j+1]   == 1 && color[i][j+1]   == WHITE)    DFS_VISIT(i, j+1, numComp);
    if(G[i+1][j-1] == 1 && color[i+1][j-1] == WHITE)    DFS_VISIT(i+1, j-1, numComp);
    if(G[i+1][j]   == 1 && color[i+1][j]   == WHITE)    DFS_VISIT(i+1, j, numComp);
    if(G[i+1][j+1] == 1 && color[i+1][j+1] == WHITE)    DFS_VISIT(i+1, j+1, numComp);

    color[i][j] = BLACK;
}


int main()
{
    while(cin >> ROW >> COL) {
        if(ROW == 0 && COL == 0) break;
        Input();

        int ans = DFS();

        cout << ans << "\n";
    }
    return 0;
}
