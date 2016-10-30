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

int GCD(int a,int b) {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a,int b) {   return a / GCD(a, b) * b;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

#define MAX_N 105
struct Matrix {
   int rows, cols;
   LL mat[MAX_N][MAX_N];
};

int D, N, MOD;
Matrix matA, matB, matC;

Matrix matMul(Matrix a, Matrix b)
{
   Matrix ans;
   int i, j, k;

   ans.rows = a.rows; ans.cols = b.cols;
   FOR(i, 0, ans.rows-1)
      FOR(j, 0, ans.cols-1) {
         ans.mat[i][j] = 0;
         FOR(k, 0, a.cols-1)
         ans.mat[i][j] = (ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD) % MOD;
      }
   return ans;
}

Matrix matPow(Matrix base, int p)
{
   Matrix ret;
   int i, j;
   ret.rows = base.rows;
   ret.cols = base.cols;
   FOR(i, 0, ret.rows-1) FOR(j, 0, ret.cols-1) ret.mat[i][j] = (i == j);

   int count = 1;
   while(p) {
      if(p & 1) ret = matMul(ret, base);
      base = matMul(base, base);
      p >>= 1;
   }
   return ret;
}

void showMat(Matrix m)
{
   FOR(i, 0, m.rows-1) {
      FOR(j, 0, m.cols-1) cout << m.mat[i][j] << " ";
      cout << endl;
   }
}


int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int numDigits;
   int mod[5] = {0, 10, 100, 1000, 10000};

   // Building Matrix using co-efficient
   // Order or matA is D x D
   D = 2;
   matA.rows = matA.cols = D;
   matA.mat[0][0] = 1;  matA.mat[0][1] = 1;
   matA.mat[1][0] = 1;  matA.mat[1][1] = 0;

   TC = src();

   FOR(tc, 1, TC) {

      // Building matrix using f(1), f(2), f(3) values;
      // Order of matB is D x 1
      matB.rows = 2; matB.cols = 1;
      scanf("%lld %lld", &matB.mat[1][0], &matB.mat[0][0]);

      scanf("%d %d", &N, &numDigits);

      N = N + 1;
      if(N > D) {
         matC = matPow(matA, N - D);
         matC = matMul(matC, matB);
         printf("Case %d: %lld\n", tc, matC.mat[0][0] % mod[numDigits]);
      }
      else {
         printf("Case %d: %lld\n", tc, matB.mat[D - N][0] % mod[numDigits]);
      }
   }

   return 0;
}
