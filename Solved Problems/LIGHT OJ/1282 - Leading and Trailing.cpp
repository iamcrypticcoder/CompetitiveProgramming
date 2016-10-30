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

int findMSB(int n, int k, int howMuch)
{
   int ret;

   long double temp = k * log10(n);
   temp = temp - floor(temp);

   ret = (int) pow((long double)10.0, (howMuch-1) + temp);

   return ret;
}

// This function returns (a^b) mod m.
// Dont change LL to int. Otherwise it will return wrong ans
// It fastest enough.
// Used in 10006
LL BigMod (LL a, LL n, LL b)
{
	if (n == 1 ) return a % b;
	LL ans = BigMod(a,n / 2 ,b);
	ans = (ans * ans) % b;
	if (n % 2 == 1 ) return ans * a % b;
	return ans; return ans;
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int n;

   scanf("%d", &TC);

   FOR(tc, 1, TC) {
      scanf("%d %d", &n, &k);

      printf("Case %d: %d %03lld\n", tc, findMSB(n, k, 3), BigMod(n, k, 1000));
   }
   return 0;
}



/*
#include <cstdio>
#include <cmath>

int main() {
int test, cs, n, k, head, tail;
long double c, dn;
scanf("%d", &test);
for(cs = 1; cs <= test; cs++) {
scanf("%d %d",&n, &k);
dn = n; n = n % 1000; tail = 1;
c = k * log10(dn);
c = c - floor(c);
head = (int)pow((long double)10.0, 2 + c);
while(k) {
if(k & 1) tail =(tail * n) % 1000;
k >>= 1, n =(n * n) % 1000;
}
printf("Case %d: %d %03d\n", cs, head, tail);
}
return 0;
}
*/
