/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
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
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODE, EDGE;
VVI G;
//VI color, dfsNum, dfsLow, parent;
int color[10001], dfsNum[10001], dfsLow[10001], parent[10001];
int nodeNum;
//vector<bool> articulationVertex;
bool articulationVertex[10001];
int dfsRoot, rootChildren;
int numArtiPoints;

void articulationPointAndBridge(int u)
{
    dfsNum[u] = dfsLow[u] = nodeNum++;
    color[u] = GRAY;

    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];
        if(color[v] == WHITE) {
            parent[v] = u;

            if(u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v);

            if(dfsLow[v] >= dfsNum[u])  articulationVertex[u] = true;

            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if(v != parent[u])
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }

    color[u] = BLACK;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int a, b;

   scanf("%d", &TC);

   FOR(tc, 1, TC) {

      scanf("%d %d", &NODE, &EDGE);

      G = VVI(NODE+1);
      /*
      color = VI(NODE+1, WHITE);
      dfsNum = VI(NODE+1);
      dfsLow = VI(NODE+1);
      parent = VI(NODE+1, -1);
      articulationVertex = vector<bool>(NODE+1, false);
      */

      memset(color, WHITE, sizeof color);
      //memset(dfsNum, 0, sizeof dfsNum);
      //memset(dfsLow, 0, sizeof dfsLow);
      memset(parent, -1, sizeof parent);
      memset(articulationVertex, false, sizeof articulationVertex);

      FOR(i, 1, EDGE) {
         scanf("%d %d", &a, &b);
         G[a].PB(b);
         G[b].PB(a);
      }

      nodeNum = 1;
      numArtiPoints = 0;
      FOR(i, 1, NODE) {
         if(color[i] == WHITE) {
             dfsRoot = i;
             rootChildren = 0;
             articulationPointAndBridge(i);
             articulationVertex[dfsRoot] = (rootChildren > 1);
         }
      }


      int numArtiPoints = 0;
      FOR(i, 1, NODE)
         if(articulationVertex[i] == true) numArtiPoints++;


      printf("Case %d: %d\n", tc, numArtiPoints);

   }

   return 0;
}
