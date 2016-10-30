#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define MAX_DIMENSION 25
#define WHITE 0
#define GRAY 1
#define BLACK 2

bool G[MAX_DIMENSION+1][MAX_DIMENSION+1];
int color[MAX_DIMENSION+1][MAX_DIMENSION+1];
int dim;        // Denoted the dimension

void Input()
{
    int i, j;
    string temp;

    memset(G, 0, sizeof(G));

    FOR(i, 1, dim) {
        cin >> temp;
        FOR(j, 1, dim) {
            if(temp[j-1] == '0') G[i][j] = 0;
            else G[i][j] = 1;
            color[i][j] = WHITE;
        }

 //       cout << "\n";
    }

}

void DFS_VISIT(int i, int j, int color);

int DFS()                   // Returns number of component
{
    int i, j;
    int numComponent = 0;       // Denotes the number of connected component

    FOR(i, 1, dim)
        FOR(j, 1, dim)
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
    int imageNumber = 0;
    while(cin >> dim) {

        Input();

        int numComponent = DFS();

        cout << "Image number " << ++imageNumber << " contains " << numComponent << " war eagles.\n";
    }

    return 0;
}
