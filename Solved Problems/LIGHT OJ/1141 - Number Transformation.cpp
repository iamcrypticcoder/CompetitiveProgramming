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

int S, T;
VI dp, primes;

bool isPrime(LL num)
{
   if(num == 1) return false;
   int root = (int)sqrt(num);

   FOR(i, 2, root) if(num % i == 0) return false;

   return true;
}

int main()
{
 //   READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   cin >> TC;

   FOR(tc, 1, TC) {
	  cin >> S >> T; 
      dp = VI(100000, INF);
      dp[S] = 0;

      FOR(i, S, T) {
         if(dp[i] != INF && !isPrime(i)) {

            int num = i;

            while(num != 1 && !isPrime(num)) {
               int root = (int)sqrt(num);
               FOR(j, 2, root)
                  if(num % j == 0) {
                     while(num % j == 0) num /= j;
                     primes.PB(j);
                  }
            }
            if(isPrime(num)) primes.PB(num);

            FOR(j, 0, primes.SZ-1) {
               dp[i + primes[j]] = min(dp[i + primes[j]], dp[i] + 1);
            }
            primes.clear();
         }
      }

      if(dp[T] == INF) cout << "Case " << tc << ": -1\n";
      else cout << "Case " << tc << ": " << dp[T] << "\n";

   }


   return 0;
}
