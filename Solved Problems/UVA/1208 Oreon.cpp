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

int V, E;
vector<EDGE> edges;
vector<EDGE> spanEdge;
int Cost;

// -------------------- Disjoint Set Structure --------------------------------------
int set[10001];
void InitSet(int N)     {   FOR(i, 1, N)    set[i] = i;     }
int FindSet(int u)      {   return set[u] == u ? u : (set[u] = FindSet(set[u]));    }
void Union(int u, int v){   set[FindSet(u)] = FindSet(v); }
// ----------------------------------------------------------------------------------

void Kruscal()
{
	int p, q;

	Cost = 0;

	for(int i=0; i < E; i++) {
		p = FindSet(edges[i].u);
		q = FindSet(edges[i].v);
		if(p != q) {
			spanEdge.push_back(edges[i]);
			Union(p, q);
			Cost += edges[i].w;
			if(spanEdge.size() == V - 1) break;
		}
	}
}

int comp(EDGE a, EDGE b)
{

   if(a.w == b.w) {
      return min(a.u, a.v) < min(b.u, b.v);
   }
   return a.w < b.w;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   EDGE e;

   cin >> TC;

   FOR(tc, 1, TC) {
      //if(tc > 1) cout << "\n";
      cin >> V;

      FOR(i, 1, V)
         FOR(j, 1, V) {
            scanf("%d,", &e.w);
            if(e.w && j > i) {
               e.u = i;
               e.v = j;
               edges.PB(e);
            }
         }
      E = edges.SZ;

      sort(edges.begin(), edges.end(), comp);
      InitSet(V+1);
      Kruscal();

      cout << "Case " << tc << ":\n";
      FOR(i, 0, spanEdge.SZ-1) {
         //char ch1 = min(spanEdge[i].u, spanEdge[i].v) + 'A' - 1;
         //char ch2 = max(spanEdge[i].u, spanEdge[i].v) + 'A' - 1;

         char ch1 = spanEdge[i].u + 'A' - 1;
         char ch2 = spanEdge[i].v + 'A' - 1;
         cout << ch1 << "-" << ch2 << " " << spanEdge[i].w << "\n";
      }

      edges.clear();
      spanEdge.clear();
   }


   return 0;
}
