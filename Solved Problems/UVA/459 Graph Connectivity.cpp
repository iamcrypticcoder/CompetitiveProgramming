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

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
int comp;
VVI G;
VI color;


void DFS_Visit(int u)
{
    color[u] = GRAY;

    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];
        if(color[v] == WHITE)
            DFS_Visit(v);
    }
    color[u] = BLACK;
}

void DFS()
{
    comp = 0;
    FOR(u, 1, NODE) {
        if(color[u] == WHITE) {
            comp++;
            DFS_Visit(u);
        }
    }
}

int main()
{
  //  READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    char ch;
    string line;
    cin >> TC;


    FOR(tc, 1, TC) {
        if(tc > 1) cout << "\n";
        cin >> ch;
        getline(cin, line);

        NODE = ch - 'A' + 1;
        G = VVI(NODE+1);
        color = VI(NODE+1, WHITE);

        while(getline(cin, line)) {
            if(line.SZ == 0) break;
            int u = line[0] - 'A' + 1;
            int v = line[1] - 'A' + 1;
            G[u].PB(v);
            G[v].PB(u);
        }

        DFS();

        cout << comp << "\n";

    }

    return 0;
}


