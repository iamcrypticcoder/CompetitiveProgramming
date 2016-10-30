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

//---------------------------- GLOBAL VARIABLES ----------------------------

#define MAX_PRIME 10000100
bool Flag[MAX_PRIME + 10];    // Take 10 more extra elements
vector<int> Primes;
int totalPrimes;

void Sieve()
{
   int i = 2, j;

   int root = (int)sqrt(MAX_PRIME);
   while( i <= root ) {
      for(j = i+i; j <= MAX_PRIME; j += i) Flag[j] = 1;
      for(++i; Flag[i]; i++);
   }
   Primes.push_back(2);
	for(i = 3; i <= MAX_PRIME; i += 2)  // i+=2 ?? there is no consecutive prime except 2,3
		if(Flag[i] == 0)
			Primes.push_back(i);
   totalPrimes = Primes.size();
}
/**
   Description: Given LCM N count number of pairs whose LCM is N.
   Formula:
      If N = p1^a1 * p2 ^ a2 * .... pn^an
      Then { (2*a2+1) * (2*a2+1) * ...... * (2*an+1) + 1 } / 2
   Solved:
**/
long long countPairsGivenLCM(long long N)
{
   if(N == 1) return 1;
   long long ret = 1;

   long long root = (long long)sqrt(N);
   for(int i=0; Primes[i] <= root && i < totalPrimes; i++) {
      if(N % Primes[i] == 0) {
         int power = 0;
         while( N % Primes[i] == 0 ) {
            power++;
            N /= Primes[i];
         }
         ret *= (2*power+1);
      }
      if(N == 1) break;                // This is great optimization
   }
   if(N > 1) ret *= (2*1+1);

   return (ret+1) / 2;
}


int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   long long N;

   Sieve();

   scanf("%d", &TC);

   FOR(tc, 1, TC) {
      scanf("%lld", &N);

      printf("Case %d: %lld\n", tc, countPairsGivenLCM(N));
   }
   return 0;
}
