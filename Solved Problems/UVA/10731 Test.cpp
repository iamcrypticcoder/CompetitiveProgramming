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
typedef vector<char> VC;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

MCI nodeMap;
VC letter;
VVI G;
VI color, dfsNum, dfsLow;
stack<int> S;
vector<bool> inStack;
int nodeNum;
VS comp;

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
        string temp = "";
        int w = -1;
        while(w != u) {
            w = S.top();    S.pop();    inStack[w] = false;
            temp += letter[w-1];
        }
        sort(temp.begin(), temp.end());
        comp.PB(temp);
    }

/*
    if(dfsNum[u] == dfsLow[u]) {
        int w = -1;
        while(w != u) {
            w = S.top();    S.pop();    inStack[w] = false;
            cout << w << " ";
        }
        cout << "\n";
    }
*/
}

void Tarjan()
{
    color = VI(G.SZ, WHITE);
    dfsNum = VI(G.SZ);
    dfsLow = VI(G.SZ);
    inStack = vector<bool>(G.SZ, false);
    nodeNum = 0;

    FOR(u, 1, G.SZ-1) {
        if(color[u] == WHITE)
            strongConnect(u);
    }
}


int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N;
    char activity[6], ch;

    tc = 1;
    while(cin >> N ) {
        if(N == 0) break;
        if(tc > 1) cout << "\n";

        int nodeNum = 0;
        FOR(i, 1, N) {

            FOR(j, 1, 5) {
                cin >> activity[j];
                if(nodeMap.find(activity[j]) == nodeMap.end())  {
                    nodeMap[activity[j]] = (++nodeNum);
                    letter.PB(activity[j]);
                }
            }
            cin >> ch;
            G.resize(nodeMap.SZ+1);
            FOR(j, 1, 5) {
                if(ch != activity[j]) G[nodeMap[ch]].PB(nodeMap[activity[j]]);
            }
        }
        /*
        int edge = 0;
        FOR(i, 1, G.SZ-1)
            edge += G[i].SZ;
        cout << edge;
        */
        Tarjan();

        sort(comp.begin(), comp.end());

        FOR(i, 0, comp.SZ-1) {
            cout << comp[i][0];
            FOR(j, 1, comp[i].SZ-1)
                cout << " " << comp[i][j];
            cout << "\n";
        }

        nodeMap.clear();
        letter.clear();
        G.clear();
        comp.clear();

        tc++;
    }

	return 0;
}
