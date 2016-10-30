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
#define INF 999999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int M, C, K, price[25][25];
int memo[210][25];

int shop(int ml, int gi)
{
   if(ml < 0) return -INF;
   if(gi == C) return M - ml;
   if(memo[ml][gi] != -1) return memo[ml][gi];

   int max_val = -INF;
   FOR(model, 1, price[gi][0])
      max_val = max(max_val, shop(ml - price[gi][model], gi + 1));
   return memo[ml][gi] = max_val;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   scanf("%d", &TC);
   while(TC--) {
      scanf("%d %d", &M, &C);
      FOR(i, 0, C-1) {
         cin >> K;
         price[i][0] = K;
         FOR(j, 1, K) cin >> price[i][j];
      }

      memset(memo, -1, sizeof(memo));

      int score = shop(M, 0);
      if(score < 0) cout << "no solution\n";
      else cout << score << "\n";

   }

   return 0;
}
