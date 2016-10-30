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
#include <sstream>
#include <map>


using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define MAX_DIMENSION 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;


char G[MAX_DIMENSION+1][MAX_DIMENSION+1];
int color[MAX_DIMENSION+1][MAX_DIMENSION+1];
int dim;
int numComponent;
bool usedComp[MAX_DIMENSION+1];
int compX[MAX_DIMENSION+1];
int compY[MAX_DIMENSION+1];
int totalDiscovered ;

int DFS_VISIT(int i, int j, int compNum)
{
    int discovered = 1;
    color[i][j] = GRAY;

    if(G[i-1][j] == compNum && color[i-1][j] == WHITE)   discovered += DFS_VISIT(i-1, j, compNum);
    if(G[i+1][j] == compNum && color[i+1][j] == WHITE)   discovered += DFS_VISIT(i+1, j, compNum);
    if(G[i][j-1] == compNum && color[i][j-1] == WHITE)   discovered += DFS_VISIT(i, j-1, compNum);
    if(G[i][j+1] == compNum && color[i][j+1] == WHITE)   discovered += DFS_VISIT(i, j+1, compNum);

    color[i][j] = BLACK;

    return discovered;
}

int main()
{
 //   freopen("E:\\input.txt", "r", stdin);
 //   freopen("E:\\output.txt", "w", stdout);


    int TC, i, j, k;
    int a, b;
    string line;
    stringstream ss;

    while(cin >> dim) {
        if(dim == 0) break;
        memset(G, 0, sizeof(G));
        memset(color, WHITE, sizeof(color));
 /*
        FOR(i, 0, dim)
            FOR(j, 0, dim)
                G[i][j] = 0;
*/
        getline(cin, line);

        numComponent = 1;
        FOR(i, 1, dim-1) {
            getline(cin, line);
            stringstream ss(line);

            while(ss >> a && ss >> b)
                G[a][b] = numComponent;

                compX[numComponent] = a;
                compY[numComponent] = b;

            numComponent++;
        }

        FOR(i, 1, dim) {
            FOR(j, 1, dim)
                if(G[i][j] == 0) {
                    G[i][j] = numComponent;
                    compX[numComponent] = i;
                    compY[numComponent] = j;
                }
        }
        totalDiscovered = 0;

        FOR(i, 1, numComponent) {
            totalDiscovered += DFS_VISIT(compX[i], compY[i], i);
        }

        if(totalDiscovered == dim*dim) cout << "good\n";
        else cout << "wrong\n";
    }

	return 0;
}
