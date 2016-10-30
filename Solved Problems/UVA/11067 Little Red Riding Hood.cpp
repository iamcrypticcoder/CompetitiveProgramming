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
typedef vector<bool> VB;
typedef vector<vector<bool> > VVB;
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

int w, h;
VVI DP;
VVB wolf;

int Cal()
{
   DP[0][0] = 0;

   int i = 1;
   while(wolf[0][i] == false) {
      DP[0][i++] = 1;
      if(i > h) break;
   }
   i = 1;
   while(wolf[i][0] == false) {
      DP[i++][0] = 1;
      if(i > w) break;
   }

   FOR(i, 1, w)
      FOR(j, 1, h)
         if(wolf[i][j] == false)
            DP[i][j] = DP[i-1][j] + DP[i][j-1];

   return DP[w][h];
}

int main()
{
   READ("input.txt");
   WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int numOfWolf;
   int x, y;

   while(cin >> w >> h) {
      if(w == 0 && h == 0) break;
      DP = VVI(w+1, VI(h+1));
      wolf = VVB(w+1, VB(h+1));

      cin >> numOfWolf;

      FOR(i, 1, numOfWolf) {
         cin >> x >> y;
         wolf[x][y] = true;
      }

      Cal();
      int ans = DP[w][h];

      if(ans == 1)
         cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
      else if(ans == 0)
         cout << "There is no path.\n";
      else cout << "There are " << ans << " paths from Little Red Riding Hood's house to her grandmother's house.\n";

   }


	return 0;
}
