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
typedef unsigned long long ULL;
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

ULL GCD(ULL a,ULL b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }


/*
// This is bottom up approach. Time : 0.006
ULL dp[25][150];

void Pre()
{
   dp[1][0] = 6;
   dp[1][1] = 6;
   dp[1][2] = 5;
   dp[1][3] = 4;
   dp[1][4] = 3;
   dp[1][5] = 2;
   dp[1][6] = 1;

   FOR(n, 2, 24) {
      FOR(x, 0, 149) {
         dp[n][x] = 0;
         FOR(k, 1, 6) {
            if(x - k < 0) dp[n][x] += dp[n-1][0];
            else dp[n][x] += dp[n-1][x-k];
         }
      }
   }
}
*/

// This is top down approach. Easy to write and think. Time : 0.009
ULL dp[25][150];
ULL count(int n, int x)
{
   if(dp[n][x] != -1) return dp[n][x];
   if(n == 1 && x == 0) return dp[1][x] = 6;
   if(n == 1 && x == 1) return dp[1][x] = 6;
   if(n == 1 && x == 2) return dp[1][x] = 5;
   if(n == 1 && x == 3) return dp[1][x] = 4;
   if(n == 1 && x == 4) return dp[1][x] = 3;
   if(n == 1 && x == 5) return dp[1][x] = 2;
   if(n == 1 && x == 6) return dp[1][x] = 1;
   if(n == 1 && x > 6) return dp[1][x] = 0;

   ULL ret = 0;
   FOR(k, 1, 6) {
      if(x - k < 0) ret += count(n-1, 0);
      else ret += count(n-1, x - k);
   }
   return dp[n][x] = ret;
}


int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int n, x;

   //Pre();

   TC = src();

   FOR(tc, 1, TC) {
      scanf("%d %d", &n, &x);

      //ULL a = dp[n][x];
      memset(dp, -1, sizeof dp);
      ULL a = count(n, x);
      ULL b = 6;

      FOR(i, 2, n) b *= 6;

      ULL g = GCD(a, b);
      a /= g;
      b /= g;

      printf("Case %d: ", tc);
      if(a == 0) {
         printf("0\n");
      }
      else if(a == b) {
         printf("1\n");
      }
      else cout << a << "/" << b << endl;

   }

   return 0;
}
