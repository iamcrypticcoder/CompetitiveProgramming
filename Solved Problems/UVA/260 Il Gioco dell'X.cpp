#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<vector<bool> > VVB;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int N;
VS grid;
VVB color;
bool isWin;

bool on_grid(int i, int j)
{
    return (i >= 0 && i < N && j >= 0 && j < N);
}

void DFS_Visit(int i, int j, char ch)
{
    if(ch == 'w' && j == N-1) isWin = true;
    else if(ch == 'b' && i == N-1) isWin = true;

    color[i][j] = GRAY;

    if(on_grid(i-1, j-1) && color[i-1][j-1] == WHITE && grid[i-1][j-1] == ch)
        DFS_Visit(i-1, j-1, ch);

    if(on_grid(i-1, j) && color[i-1][j] == WHITE && grid[i-1][j] == ch)
        DFS_Visit(i-1, j, ch);

    if(on_grid(i, j-1) && color[i][j-1] == WHITE && grid[i][j-1] == ch)
        DFS_Visit(i, j-1, ch);

    if(on_grid(i, j+1) && color[i][j+1] == WHITE && grid[i][j+1] == ch)
        DFS_Visit(i, j+1, ch);

    if(on_grid(i+1, j) && color[i+1][j] == WHITE && grid[i+1][j] == ch)
        DFS_Visit(i+1, j, ch);

    if(on_grid(i+1, j+1) && color[i+1][j+1] == WHITE && grid[i+1][j+1] == ch)
        DFS_Visit(i+1, j+1, ch);

    color[i][j] = BLACK;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;

    tc = 1;
    while(cin >> N) {
        if(N == 0) break;
        getchar();

        color  = VVB(N);
        FOR(i, 0, N-1)
            color[i] = vector<bool>(N, false);

        grid = VS(N);

        FOR(i, 0, grid.SZ-1)
            getline(cin, grid[i]);


        isWin = false;
        FOR(i, 0, N-1) {
            if(color[i][0] == WHITE && grid[i][0] == 'w')
                DFS_Visit(i, 0, 'w');
        }

        if(isWin) {
            cout << tc++ << ' ' << "W" << "\n";
            continue;
        }

        isWin = false;
        FOR(i, 0, N-1) {
            if(color[0][i] == WHITE && grid[0][i] == 'b')
                DFS_Visit(0, i, 'b');
        }

        if(isWin) {
            cout << tc++ << ' ' << "B" << "\n";
            continue;
        }

    }

    return 0;
}

