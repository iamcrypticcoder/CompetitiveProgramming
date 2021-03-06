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

int NODE, EDGE;
VVI G;
int DP[1001][2];
bool visited[1001];

int minCover(int u, int isPlaced)
{
   if(G[u].SZ == 0) {
      return 1;
   }
   if(DP[u][isPlaced] != -1) return  DP[u][isPlaced];

   int sum = isPlaced ? 1 : 0;

   FOR(i, 0, G[u].SZ-1) {
      int v = G[u][i];
      if(!visited[v]) {
         visited[u] = true;
         if(!isPlaced) sum += minCover(v, 1);
         else sum += min(minCover(v, 1), minCover(v, 0));
         visited[u] = false;
      }
   }
   return DP[u][isPlaced] = sum;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int temp;
   int u, v;

   while(scanf("%d", &NODE) != EOF) {
      if(NODE == 0) break;

      G = VVI(NODE+1);

      FOR(u, 1, NODE) {
         cin >> temp;
         FOR(i, 1, temp) {
            cin >> v;
            G[u].PB(v);
         }
      }

      memset(visited, 0, sizeof visited);
      memset(DP, -1, sizeof DP);

      int minVertex = min(minCover(1, 1), minCover(1, 0));

      printf("%d\n", minVertex);
   }


   return 0;
}
