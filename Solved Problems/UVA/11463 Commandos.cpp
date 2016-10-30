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
int G[101][101];
int source, sink;

void Reset()
{
   FOR(i, 1, NODES) FOR(j, 1, NODES) {
      if(i == j) { G[i][j] = 0; continue; }
      G[i][j] = G[j][i] = INF;
   }

}
int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int u, v;

   cin >> TC;

   FOR(tc, 1, TC) {
      cin >> NODES >> EDGES;

      Reset();

      FOR(i, 1, EDGES) {
         cin >> u >> v;
         G[u+1][v+1] = G[v+1][u+1] = 1;
      }

      cin >> source >> sink;

      FOR(k, 1, NODES)
         FOR(i, 1, NODES)
            FOR(j, 1, NODES) {
               if(G[i][k] != INF && G[k][j] != INF)
                  G[i][j] = G[j][i] = min(G[i][j], G[i][k] + G[k][j]);
            }


      /*
      FOR(i, 1, NODES) {
         FOR(j, 1, NODES) cout << G[i][j] << "\t";
         cout << endl;
      }
      */

      int ans = -1;
      FOR(k, 1, NODES) {
         ans = max(ans, G[source+1][k] + G[k][sink+1]);
      }

      printf("Case %d: %d\n", tc, ans);
   }

   return 0;
}
