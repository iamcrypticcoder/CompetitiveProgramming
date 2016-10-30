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

LL GCD(LL a, LL b) {   while(b)b^=a^=b^=a%=b;  return a;   }
LL LCM(LL a, LL b) {
   LL ret = (a / GCD(a, b));
   return ret * b;

   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

#define MAX_PRIME 1000000
bool Flag[MAX_PRIME + 10];    // Take 10 more extra elements
vector<int> Primes;
int totalPrimes;
struct powerPrime {
	long long p, a;					// Every powerPrime is in the form p^a
};								// That is A number is represented in this form --  p1^a1 * p2^a2 * p3^a3

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
bool IsPrime(long long N)
{
   if(N < 2) return 0;
   if(N <= MAX_PRIME) return (!Flag[N]);
   int root = sqrt((double)N);

   for(int i=0; Primes[i] <= root && i < totalPrimes; i++)
      if(N % Primes[i] == 0) return 0;
   return 1;
}
/**
   Dont input 1 in this function. It will crash.
**/
vector<powerPrime> FactorizeAsPower(long long N)
{
   vector<powerPrime> ret;
   powerPrime powP;
   long long power;

	if(IsPrime(N)) {
		powP.p = N;
		powP.a = 1;
		ret.push_back(powP);
		return ret;
	}

	int i = 0;
	while(i < totalPrimes) {
      if(N % Primes[i] == 0) {
         power = 0;
         while(N % Primes[i] == 0) {
				N /= Primes[i];
				power++;
         }
			powP.p = Primes[i];
			powP.a = power;
			ret.push_back(powP);
      }
      i++;
   }
   if( N != 1 ) {
      powP.p = N;
      powP.a = 1;
      ret.push_back(powP);
   }
   return ret;
}

vector<powerPrime> factl;
vector<powerPrime> factL;

bool isPossible(LL l, LL L)
{
   if( l > L ) return false;

   factl = FactorizeAsPower(l);

   FOR(i, 0, factl.SZ-1) {
      if(L % factl[i].p != 0) return false;
   }
   return true;
}

LL intPow(LL a, LL b)
{
   LL ret = 1;
   while(b--) {
      ret *= a;
   }
   return ret;
}
int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   LL a, b, c;
   LL L;

   Sieve();

   TC = src();

   FOR(tc, 1, TC) {
      scanf("%lld %lld %lld", &a, &b, &L);

      long long l = LCM(a, b);

      printf("Case %d: ", tc);
      //if(isPossible(l, L)) {
     if ( L % a != 0 || L % b != 0 ) {
         printf("impossible\n");
     }
     else {
         factl = FactorizeAsPower(l);
         factL = FactorizeAsPower(L);
         LL ans = 1;
         FOR(i, 0, factL.SZ-1) {
            bool isFound = false;
            FOR(j, 0, factl.SZ-1) {
               if(factl[j].p == factL[i].p && factl[j].a == factL[i].a) {
                  isFound = true;
                  break;
               }
            }
            if( !isFound ) ans *= intPow(factL[i].p, factL[i].a);
         }
         printf("%lld\n", ans);
      }
   }

   return 0;
}
