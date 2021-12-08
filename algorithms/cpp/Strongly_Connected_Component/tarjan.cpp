/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)   {   return a/GCD(a,b)*b;                }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 10000

int NODE, EDGE;
VVI G;
VI color, dfsNum, dfsLow;
int nodeNum = 0;
stack<int> S;
VI inStack;

void strongConnect(int u);
void Tarjan()
{
    FOR(u, 1, NODE) {
        if(color[u] == WHITE)
            strongConnect(u);
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
        int w = -1;
        while(w != u) {
            w = S.top();    S.pop();    inStack[w] = false;
            cout << w << " ";
        }
        cout << "\n";
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();

    int u, v;

    while(cin >> NODE >> EDGE) {

        G = VVI(NODE+1);
        color = VI(NODE+1, WHITE);
        dfsNum = VI(NODE+1);
        dfsLow = VI(NODE+1);
        inStack = VI(NODE+1,  false);

        FOR(i, 1, EDGE) {
            cin >> u >> v;
            G[u].PB(v);
        }

        Tarjan();
        cout << "\n";

    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**

Input:
10 16
3 1
3 2
3 5
3 4
9 6
9 3
9 7
9 8
8 10
8 7
8 6
8 2
10 3
10 9
10 2
10 5

Output:
1
2
5
4
3
6
7
9 10 8

**/