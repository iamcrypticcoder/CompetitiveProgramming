#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )

#define SQR(x) ((x)*(x))
#define BIT(mask,i) (mask & (1 << i))

#define INF 99999999
#define EPS 1e-9
#define PI (2*acos(0.0))
#define TO_RAD (PI/180)
#define TO_DEG (180/PI)

#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<vector<PII> > VVP;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

VI unit;
VVI G;
int endNode;

int TotalEarning(int u)
{
   int maxUnit = -1;
   int nodeChoose;
   FOR(i, 0, G[u].SZ-1) {
      int v = G[u][i];
      if(unit[v] > maxUnit) {
         maxUnit = unit[v];
         nodeChoose = v;
      }
   }

   if(maxUnit == -1) {
      endNode = u;
      return 0;
   }
   return maxUnit + TotalEarning(nodeChoose);
}


int main()
{
    READ("input.txt");
    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int val;
   int n, m, u, v;

   cin >> TC;

   FOR(tc, 1, TC) {
      cin >> n >> m;

      G = VVI(n);
      unit = VI(n);

      FOR(i, 0, n-1) {
         cin >> val;
         unit[i] = val;
      }

      FOR(i, 1, m) {
         cin >> u >> v;
         G[u].PB(v);
      }

      int ans = TotalEarning(0);

      cout << "Case " << tc << ": ";
      cout << ans << " " << endNode << "\n";

   }

	return 0;
}
