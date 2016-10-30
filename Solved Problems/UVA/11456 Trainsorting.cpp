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

int N;
VI A, LI, LD;

int LIS()
{
   int i, j;

   LI = VI(N+1, 1);

   int lisLength = 1;

   FOR(i, 1, N) FOR(j, i+1, N)
      if(A[j] > A[i]) {
         if(LI[i] + 1 > LI[j] ) {
            LI[j] = LI[i] + 1;
            if(LI[j] > lisLength) {
               lisLength = LI[j];
            }
         }
      }
   return lisLength;
}

int LDS()
{
   int i, j;

   LD = VI(N+1, 1);

   int ldsLength = 1;

   FOR(i, 1, N) FOR(j, i+1, N)
      if(A[j] < A[i]) {
         if(LD[i] + 1 > LD[j] ) {
            LD[j] = LD[i] + 1;
            if(LD[j] > ldsLength) {
               ldsLength = LD[j];
            }
         }
      }
   return ldsLength;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   TC = src();

   FOR(tc, 1, TC) {
      N = src();

      A = VI(N+1);

      FOR(i, 1, N) scanf("%d", &A[i]);
      reverse(A.begin()+1, A.end());

      int lis = LIS();
      int lds = LDS();

//      FOR(i, 1, N) cout << LI[i] << " ";
//      cout << "\n";
//      FOR(i, 1, N) cout << LD[i] << " ";

      int ans = 0;
      FOR(i, 1, N) if(LI[i] + LD[i] - 1 > ans) ans = LI[i] + LD[i] - 1;

      printf("%d\n", ans);
   }

   return 0;
}
