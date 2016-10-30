#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()


typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

int m, n;
VS grid;
string IEHOVA = "IEHOVA#";
bool isPos;
VS cmds;

bool on_grid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

void DFS(int i, int j, int index)
{
    if(isPos == true) return;
    if(index > IEHOVA.SZ-1) { isPos = true; return; }

    if(on_grid(i-1, j) && grid[i-1][j] == IEHOVA[index]) {
        cmds.PB("forth");
        DFS(i-1, j, index+1);
    }
    if(on_grid(i, j-1) && grid[i][j-1] == IEHOVA[index]) {
        cmds.PB("left");
        DFS(i, j-1, index+1);
    }
    if(on_grid(i, j+1) && grid[i][j+1] == IEHOVA[index]) {
        cmds.PB("right");
        DFS(i, j+1, index+1);
    }
}

int main()
{
  READ("input.txt");
//    WRITE("output.txt");

    int TC, tc;

    //scanf("%d", &TC);
    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> m >> n;
        grid = VS(m);
        FOR(i, 0, m-1)
            cin >> grid[i];

        isPos = false;
        FOR(i, 0, n-1)
            if(grid[m-1][i] == '@')
                DFS(m-1, i, 0);

        FOR(i, 0, cmds.SZ-2)
            cout << cmds[i] << " ";
        cout << cmds[cmds.SZ-1] << "\n";

        cmds.clear();
    }


    return 0;
}

