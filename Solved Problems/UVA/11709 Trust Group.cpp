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
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int P, T;
MSI nodeMap;
VVI G;
VI color, dfsNum, dfsLow;
int nodeNum = 0;
stack<int> S;
VI inStack;
int numComp = 0;

void strongConnect(int u);
void Tarjan()
{
    color = VI(P+1, WHITE);
    dfsNum = VI(P+1);
    dfsLow = VI(P+1);
    inStack = VI(P+1, false);
    numComp = 0;

    FOR(i, 1, P) {
        if(color[i] == WHITE)
            strongConnect(i);
    }
}

void strongConnect(int u)
{
    dfsNum[u] = dfsLow[u] = nodeNum++;
    color[u] = GRAY;
    S.push(u);  inStack[u] = true;

    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];

        if(color[v] == WHITE) {
            strongConnect(v);
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if(inStack[v] == true)
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }

    if(dfsNum[u] == dfsLow[u]) {
        numComp++;
        int w = -1;
        while(w != u) { w = S.top();    S.pop();    inStack[w] = false; }
    }

}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string str1, str2;
    int nodeNum;

    while(cin >> P >> T) {
        if(P == 0 && T == 0) break;
        getline(cin, str1);

        nodeNum = 0;
        FOR(i, 1, P) {
            getline(cin, str1);
            nodeMap[str1] = ++nodeNum;
        }

        G = VVI(P+1);

        FOR(i, 1, T) {
            getline(cin, str1);
            getline(cin, str2);
            G[nodeMap[str1]].PB(nodeMap[str2]);
        }

        Tarjan();

        cout << numComp << "\n";

        nodeMap.clear();
    }

	return 0;
}
