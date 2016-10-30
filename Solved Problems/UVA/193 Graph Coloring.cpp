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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
VVI G;
VI color;
VI temp, solution;
int maxBlack;

bool isPosBlack(int k)
{
    FOR(i, 0, G[k].SZ-1) {
        int v = G[k][i];
        if(color[v] == BLACK) return false;
    }
    return true;
}

void BackTrack(int k)      // Color k'th node
{
    if(k == NODE+1) {
        int numBlack = 0;
        temp.clear();
        FOR(i, 1, NODE) {
            if(color[i] == BLACK) {
                numBlack++;
                temp.PB(i);
            }
        }
        if(numBlack > maxBlack) {
            maxBlack = numBlack;
            solution = temp;
        }
        return;
    }

    if(isPosBlack(k)) {       // If we can make kth node black.
        color[k] = BLACK;
        BackTrack(k+1);
        color[k] = GRAY;
    }

    color[k] = WHITE;
    BackTrack(k+1);
    color[k] = GRAY;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> NODE >> EDGE;
        G = VVI(NODE+1);
        color = VI(NODE+1, GRAY);

        FOR(i, 1, EDGE) {
            cin >> u >> v;
            G[u].PB(v);
            G[v].PB(u);
        }

        maxBlack = -1;
        BackTrack(1);

        cout << maxBlack << "\n";
        cout << solution[0];
        FOR(i, 1, solution.SZ-1) cout << " " << solution[i];
        cout << "\n";

    }
	return 0;
}
