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

//---------------------------- GLOBAL VARIABLES ----------------------------

//---------------------------- KRUSKAL ALGO START --------------------------
typedef struct {
    int u, v;
    int w;
} EDGE;

int NODES, EDGES;
vector<EDGE> edges;
vector<EDGE> spanEdge;
vector<int> spanEdgeIndexes;
int minSpanCost, secondBestCost;
int numWays;

// -------------------- Disjoint Set Structure --------------------------------------
int set[10001];
void InitSet(int N)     {   FOR(i, 1, N)    set[i] = i;     }
int FindSet(int u)      {   return set[u] == u ? u : (set[u] = FindSet(set[u]));    }
void Union(int u, int v){   set[FindSet(u)] = FindSet(v); }
// ----------------------------------------------------------------------------------

int compEdge(EDGE a, EDGE b)
{
    return a.w < b.w;
}

int Kruscal()
{
	int p, q;

	minSpanCost = 0;

	for(int i=0; i < EDGES; i++) {
      p = FindSet(edges[i].u);
      q = FindSet(edges[i].v);
      if(p != q) {
         spanEdge.push_back(edges[i]);
         spanEdgeIndexes.push_back(i);
         Union(p, q);
         minSpanCost += edges[i].w;
         if(spanEdge.size() == NODES - 1) {
            numWays++;
            break;
         }
      }
	}
}

int secondBestMST(int excludedIndex)
{
   int p, q, ret = 0, edgeSeleted = 0;

	for(int i=0; i < EDGES; i++) {
	   if( i == excludedIndex ) continue;
      p = FindSet(edges[i].u);
      q = FindSet(edges[i].v);
      if(p != q) {
         edgeSeleted++;
         Union(p, q);
         ret += edges[i].w;
         if(edgeSeleted == NODES - 1) {
            numWays++;
            return ret;
         }
      }
	}
	return INF;
}
//---------------------------- KRUSKAL ALGO END --------------------------

int main()
{
    READ("input.txt");
    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   EDGE e;

   cin >> TC;

   FOR(tc, 1, TC) {
      cin >> NODES >> EDGES;

      if(NODES == 1 && EDGES == 0) {
         printf("Case #%d : ", tc);
         cout << "No second way\n";
         continue;
      }

      FOR(i, 1, EDGES) {
         cin >> e.u >> e.v >> e.w;
         edges.PB(e);
      }

      InitSet(NODES + 1);
      sort(edges.begin(), edges.end(), compEdge);
      numWays = 0;
      Kruscal();

      // Finding Second Best MST
      secondBestCost = INF;
      FOR(i, 0, spanEdgeIndexes.SZ-1) {
         InitSet(NODES + 1);
         secondBestCost = min(secondBestCost, secondBestMST(spanEdgeIndexes[i]));
      }

      printf("Case #%d : ", tc);
      if(numWays == 0) cout << "No way\n";
      else if(numWays == 1) cout << "No second way\n";
      else if(numWays > 1) cout << secondBestCost << endl;

      edges.clear();
      spanEdge.clear();
      spanEdgeIndexes.clear();

   }

   return 0;
}
