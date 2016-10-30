/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 0.004
    Rank : 74
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

unsigned int DP[1121][15][1121];
VI primes;

bool isPrime(int n)
{
   int root = (int)sqrt(n);
   FOR(i, 2, root)
      if(n % i == 0) return false;
   return true;
}

void GeneratePrime()
{
   primes.PB(12345);
   FOR(i, 2, 1121)
      if(isPrime(i)) primes.PB(i);
}

int ways(int n, int k, int i)
{
   if(n == 0 && k == 0) return 1;
   else if(n < 0 || i > primes.SZ-1 || k == 0) return 0;
   else if(DP[n][k][i] != -1) return DP[n][k][i];
   else return DP[n][k][i] = ways(n-primes[i], k-1, i+1) + ways(n, k, i+1);
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int n;

   GeneratePrime();
   FOR(n, 0, 1120) FOR(k, 0, 14) FOR(i, 0, 1120) DP[n][k][i] = -1;

   while(scanf("%d %d", &n, &k) != EOF) {
      if(n == 0 && k == 0) break;

      printf("%u\n", ways(n, k, 1));
   }

   return 0;
}


/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 0.004
    Rank : 35
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

unsigned int DP[1121][15];
VI primes;

bool isPrime(int n)
{
   int root = (int)sqrt(n);
   FOR(i, 2, root)
      if(n % i == 0) return false;
   return true;
}

void GeneratePrime()
{
   primes.PB(12345);
   FOR(i, 2, 1121)
      if(isPrime(i)) primes.PB(i);
}

void BottomUp()
{
   DP[0][0] = 1;

   FOR(i, 1, primes.SZ-1) FORD(n, 1120, primes[i]) FOR(k, 1, 14)
      DP[n][k] += DP[n-primes[i]][k-1];
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int n;

   GeneratePrime();
   BottomUp();

   while(scanf("%d %d", &n, &k) != EOF) {
      if(n == 0 && k == 0) break;

      printf("%u\n", DP[n][k]);
   }


   return 0;
}

