/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/
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

typedef struct {
    int u, v;
    int w;
} EDGE;

vector<EDGE> edges;
vector<EDGE> spanEdge;

// -------------------- Disjoint Set Structure --------------------------------------
int set[1000];
void InitSet(int N)     {   FOR(i, 1, N)    set[i] = i;     }
int FindSet(int u)      {   return set[u] == u ? u : (set[u] = FindSet(set[u]));    }
void Union(int u, int v){   set[FindSet(u)] = FindSet(v); }
// ----------------------------------------------------------------------------------

int NODE;
int K, M;
int prevCost, newCost;

int Increase(EDGE a, EDGE b)
{
    return a.w < b.w;
}

void Kruskal()
{
   InitSet(NODE+1);
   sort(edges.begin(), edges.end(), Increase);

   newCost = 0;
   FOR(i, 0, edges.size()-1)
      if(FindSet(edges[i].u) != FindSet(edges[i].v)) {
         //spanEdge.push_back(edges[i]);
         Union(FindSet(edges[i].u), FindSet(edges[i].v));
         newCost += edges[i].w;
      }
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int u, v, w;
   EDGE e;

   tc = 1;
   while(scanf("%d", &NODE) != EOF) {
      if(tc > 1) cout << "\n";

      prevCost = 0;
      FOR(i, 1, NODE-1) {
         scanf("%d %d %d", &u, &v, &w);
         prevCost += w;
      }
      K = src();
      FOR(i, 1, K) {
         scanf("%d %d %d", &u, &v, &w);
         e.u = u;
         e.v = v;
         e.w = w;
         edges.PB(e);
      }
      M = src();
      FOR(i, 1, M) {
         scanf("%d %d %d", &u, &v, &w);
         e.u = u;
         e.v = v;
         e.w = w;
         edges.PB(e);
      }
      Kruskal();

      printf("%d\n%d\n", prevCost, newCost);

      edges.clear();
      tc++;
   }

   return 0;
}
