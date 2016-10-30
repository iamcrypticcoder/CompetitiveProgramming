/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
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
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

int NODES, EDGES;
VVI G;
VI color, dfsNum, dfsLow;
int nodeNum = 0;
stack<int> S;
bool inStack[25+5];
VI compNodes;

VS names;
MSI nodeMap;

void strongConnect(int u)
{
   dfsNum[u] = dfsLow[u] = nodeNum++;
   color[u] = GRAY;
   S.push(u);
   inStack[u] = true;

   FOR(i, 0, G[u].SZ-1) {
      int v = G[u][i];
      if(color[v] == WHITE) {
         strongConnect(v);
         dfsLow[u] = min(dfsLow[u], dfsLow[v]);
      }
      else if(inStack[v] == true) {
         dfsLow[u] = min(dfsLow[u], dfsNum[v]);
      }
   }

   if(dfsNum[u] == dfsLow[u]) {
      int w = -1;
      while(w != u) {
         w = S.top();
         S.pop();
         inStack[w] = false;
         compNodes.PB(w);
      }
      cout << names[compNodes[0]];
      FOR(i, 1, compNodes.SZ-1) {
         cout << ", " << names[compNodes[i]];
      }
      cout << endl;
      compNodes.clear();
   }

}

void Tarjan()
{
   color = VI(NODES + 1, WHITE);
   dfsNum = VI(NODES + 1);
   dfsLow = VI(NODES + 1);
   memset(inStack, false, sizeof inStack);
   nodeNum = 1;

   FOR(u, 1, NODES) {
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
   string str1, str2;
   int u, v;

   tc = 1;
   while(cin >> NODES >> EDGES) {
      if( !NODES && !EDGES ) break;
      if(tc > 1) cout << endl;

      names = VS(NODES + 1);
      G = VVI(NODES + 1);

      nodeNum = 0;
      FOR(i, 1, EDGES) {
         cin >> str1 >> str2;
         if(nodeMap.find(str1) == nodeMap.end())  nodeMap[str1] = (++nodeNum);
         if(nodeMap.find(str2) == nodeMap.end())  nodeMap[str2] = (++nodeNum);
         u = nodeMap[str1];
         v = nodeMap[str2];
         names[u] = str1;
         names[v] = str2;
         G[u].PB(v);
      }

      printf("Calling circles for data set %d:\n", tc++);
      Tarjan();

      nodeMap.clear();
   }

   return 0;
}
