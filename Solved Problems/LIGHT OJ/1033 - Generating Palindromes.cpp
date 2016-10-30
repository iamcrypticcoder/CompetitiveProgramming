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

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define MAXN 101

string X;
int dp[MAXN][MAXN];

int generatePalin(int l, int r)
{
   if(dp[l][r] != -1) return dp[l][r];

   if(l == r) return dp[l][r] = 0;
   if(r - l == 1) return dp[l][r] = (X[l] == X[r] ? 0 : 1);

   if(X[l] == X[r]) return dp[l][r] = generatePalin(l+1, r-1);
   else return dp[l][r] = 1 + min(generatePalin(l+1, r), generatePalin(l, r-1));

   return -1;
}


int main()
{
//    READ("input.txt");
 //   WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   TC = src();

   FOR(tc, 1, TC) {
      cin >> X;

      memset(dp, -1, sizeof dp);

      printf("Case %d: %d\n", tc,generatePalin(0, X.SZ-1));
   }

   return 0;
}
