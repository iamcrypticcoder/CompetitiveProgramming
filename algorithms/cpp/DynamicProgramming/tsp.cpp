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

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )

#define SQR(x) ((x)*(x))

#define INF 99999999
#define EPS 1e-9
#define PI (2*acos(0.0))
#define TO_RAD (PI/180)
#define TO_DEG (180/PI)

#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<pair<int,int> > > VVP;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define BIT(mask,i) (mask & (1 << i))

int countBit(int mask)
{
    int ret = 0;
    FOR(i, 0, 3)                            // Mask contain at most 4 bits
        if( mask & (1 << i) ) ret++;
    return ret;
}

int NODES, EDGES;
VVB G;
VVI cost;
int DP[16][4];      // We work for 4 nodes labeled 0..3
                       // For 4 nodes at most 16 mask possible labeled 0..15
int startNode = 3;

int Calc(int mask, int endNode)
{
    if(DP[mask][endNode] != INF)
        return DP[mask][endNode];

    if(endNode != startNode && BIT(mask, endNode) && BIT(mask, startNode)) {
        int minCost = INF;
        FOR(j, 0, (NODES-1))
            if(BIT(mask, j) && G[j][endNode])
                minCost = min( minCost, Calc(mask ^ (1 << endNode), j) + cost[j][endNode]);
        return minCost;
    }

    return INF;
}

int TSP()
{
    FOR(i, 0, 15)
        FOR(j, 0, 3)
            DP[i][j] = INF;

    DP[8][3] = 0;
/*
    int test = Calc(15, 2);
    test = Calc(15, 1);
    test = Calc(15, 3);
*/
    int minCost = INF;
    FOR(i, 0, 3) {
        if( i != startNode ) {
            int temp = Calc((1 << NODES)-1, i);
            if(G[i][startNode]) minCost = min( minCost, temp + cost[i][startNode] );
        }
    }
    return minCost;
}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v, c;

//    cout << BIT(3, 5) << "\n";
//    cout << countBit(15);

    while(cin >> NODES >> EDGES) {
        G = VVB(NODES, vector<bool>(NODES));
        cost = VVI(NODES, VI(NODES));   // Contains the cost between vertices

        FOR(i, 1, EDGES) {
            cin >> u >> v >> c;
            G[u][v] = true;
            cost[u][v] = c;
        }

        cout << TSP() << "\n";
    }
	return 0;
}


/*
INPUT
4 12
0 1 10
0 2 15
0 3 20
1 0 5
1 2 9
1 3 10
2 0 6
2 1 13
2 3 12
3 0 8
3 1 8
3 2 9

IF startNode = 0 TSP() = 35
IF startNode = 1 TSP() = 35
IF startNode = 2 TSP() = 35
IF startNode = 3 TSP() = 35

3 6
0 1 10
0 2 5
1 0 40
1 2 20
2 0 10
2 1 5
IF startNode = 0 TSP() = 35
IF startNode = 1 TSP() = 35
IF startNode = 2 TSP() = 35

*/
