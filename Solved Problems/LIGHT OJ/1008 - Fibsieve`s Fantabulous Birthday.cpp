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

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline ULL src() { ULL ret; scanf("%ull", &ret); return ret; }

ULL uRoot, lRoot;
ULL uSqr, lSqr;
ULL S;
ULL x, y;

int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");
   int i, j, k;
   ULL TC, tc;

   //TC = src();
   cin >> TC;

   FOR(tc, 1, TC) {
      cin >> S;

      lRoot = (ULL)sqrt(S);
      uRoot = (ULL)sqrt(S) + 1;

      lSqr = SQR(lRoot);
      uSqr = SQR(uRoot);

      if(lSqr == S && lSqr % 2 == 0) {
         x = lRoot; y = 1;
      }
      else if(lSqr == S && lSqr % 2 != 0) {
         x = 1; y = lRoot;
      }
      else if(uSqr % 2 == 0) {
         x = S - (lSqr+1) + 1;
         if(x > uRoot) x = uRoot;

         y = uSqr - S + 1;
         if(y > uRoot) y = uRoot;
      }
      else {
         x = uSqr - S + 1;
         if(x > uRoot) x = uRoot;

         y = S - (lSqr+1) + 1;
         if(y > uRoot) y = uRoot;
      }

      cout << "Case " << tc << ": " << x << " " << y << "\n";
      //printf("Case %d: %d %d\n", tc, x, y);
   }

   return 0;
}
