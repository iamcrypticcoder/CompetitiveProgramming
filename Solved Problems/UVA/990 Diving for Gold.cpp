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

#define MAXN 1001

struct KNAPSACK {
   int d, v, w;
};

int MW, W, N;
KNAPSACK knap[31];
int C[MAXN][31];
bool T[MAXN][31];
VI sol;

int ZeroOneKnapsack()
{
   FOR(w, 0, MW) C[w][0] = 0;
   FOR(i, 0, N) C[0][i] = 0;

   memset(T, 0, sizeof T);

   FOR(w, 0, MW)
      FOR(i, 1, N) {
         if(knap[i].w > w) C[w][i] = C[w][i-1];
         else {
            if( C[w-knap[i].w][i-1] + knap[i].v > C[w][i-1] ) {
               C[w][i] = C[w-knap[i].w][i-1] + knap[i].v;
               T[w][i] = true;
            }
            else C[w][i] = C[w][i-1];
         }
   }
   return C[MW][N];
}

void GenerateSolution(int w, int i)
{
   if(w == 0 || i == 0) return;
   if(T[w][i] == 0) GenerateSolution(w, i-1);
   else {
      GenerateSolution(w-knap[i].w, i-1);
      sol.PB(i);
   }
}

void PrintC()
{
   FOR(i, 0, MW) {
      FOR(j, 0, N) cout << C[i][j] << " ";
      cout << "\n";
   }
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   tc = 1;
   while(scanf("%d %d", &MW, &W) != EOF) {
      if(tc > 1) printf("\n");
      N = src();

      FOR(i, 1, N) {
         scanf("%d %d", &knap[i].d, &knap[i].v);
         knap[i].w = 3 * W * knap[i].d;
      }

      int maxGold = ZeroOneKnapsack();
      //PrintC();
      GenerateSolution(MW, N);

      printf("%d\n%d\n", maxGold, sol.SZ);
      FOR(i, 0, sol.SZ-1) {
         printf("%d %d\n", knap[sol[i]].d, knap[sol[i]].v);
      }
      tc++;
      sol.clear();
   }
   return 0;
}

// TOP DOWN APPROACH

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

#define MAXN 1001

struct KNAPSACK {
   int d, v, w;
};

int MW, W, N;
KNAPSACK knap[31];
int C[MAXN][31];
bool T[MAXN][31];
VI sol;

int ZeroOneKnapsack(int w, int k)
{
   if(C[w][k] != -1) return C[w][k];
   if(w == 0 || k == 0) return C[w][k] = 0;

   int ret = -1;
   int t1, t2;
   if(knap[k].w > w) ret = ZeroOneKnapsack(w, k-1);
   else if((t1 = ZeroOneKnapsack(w - knap[k].w, k-1) + knap[k].v) > (t2 = ZeroOneKnapsack(w, k-1))) {
      T[w][k] = 1;
      ret = t1;
   }
   else ret = t2;

   return ret;
}

void GenerateSolution(int w, int i)
{
   if(w == 0 || i == 0) return;
   if(T[w][i] == 0) GenerateSolution(w, i-1);
   else {
      GenerateSolution(w-knap[i].w, i-1);
      sol.PB(i);
   }
}

void PrintC()
{
   FOR(i, 0, MW) {
      FOR(j, 0, N) cout << C[i][j] << " ";
      cout << "\n";
   }
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   tc = 1;
   while(scanf("%d %d", &MW, &W) != EOF) {
      if(tc > 1) printf("\n");
      N = src();

      FOR(i, 1, N) {
         scanf("%d %d", &knap[i].d, &knap[i].v);
         knap[i].w = 3 * W * knap[i].d;
      }

      memset(C, -1, sizeof C);
      memset(T, 0, sizeof T);
      int maxGold = ZeroOneKnapsack(MW, N);
      GenerateSolution(MW, N);

      printf("%d\n%d\n", maxGold, sol.SZ);
      FOR(i, 0, sol.SZ-1) {
         printf("%d %d\n", knap[sol[i]].d, knap[sol[i]].v);
      }
      tc++;
      sol.clear();
   }
   return 0;
}
