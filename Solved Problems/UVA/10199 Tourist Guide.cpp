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

int N, R;
VVI G;
MSI nodeMap;
int nodeNum;
VS cityNames;
VI color, dfsNum, dfsLow, parent;
vector<bool> articulationVertex;
vector<PII> articulationBridge;
int dfsRoot, rootChildren;

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
            /*
            if(dfsLow[v] > dfsNum[u]) {
                articulationBridge.PB(PII(u, v));
            }
            */
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if(v != parent[u])
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }

    color[u] = BLACK;
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   string str1, str2;

   tc = 1;
   while(cin >> N && N) {
      if(tc > 1) cout << "\n";
      G = VVI(N+1);
      color = VI(N+1, WHITE);
      dfsNum = VI(N+1);
      dfsLow = VI(N+1);
      parent = VI(N+1, -1);
      articulationVertex = vector<bool>(N+1, false);
      cityNames = VS(N+1);

      nodeNum = 0;
      FOR(i, 1, N) {
         cin >> cityNames[i];
         nodeMap[cityNames[i]] = (++nodeNum);
      }

      cin >> R;
      FOR(i, 1, R) {
         cin >> str1 >> str2;
         int a = nodeMap[str1];
         int b = nodeMap[str2];

         G[a].PB(b);
         G[b].PB(a);
      }

      nodeNum = 1;
      FOR(i, 1, N) {
         if(color[i] == WHITE) {
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulationVertex[dfsRoot] = (rootChildren > 1);
         }
      }

      VS artiPoints;
      FOR(i, 1, N)
         if(articulationVertex[i] == true) artiPoints.PB(cityNames[i]);

      sort( artiPoints.begin(), artiPoints.end() );

      printf("City map #%d: %d camera(s) found\n", tc++, artiPoints.SZ);
      FOR(i, 0, artiPoints.SZ-1)
         cout << artiPoints[i] << "\n";

      artiPoints.clear();
      nodeMap.clear();
   }

   return 0;
}
