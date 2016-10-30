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

#define MAXN 101

string X, Y;
int m, n;
int c[MAXN][MAXN];         // c[] is used to calculate the length.
string pre[MAXN][MAXN];    // pre[] is used to store LCS string

void LCS()
{
   m = X.size();
   n = Y.size();

   FOR(i, 1, m) c[i][0] = 0;
   FOR(j, 0, n) c[0][j] = 0;

   FOR(i, 1, m) FOR(j, 1, n) {
      if (X[i-1]==Y[j-1]) {
         c[i][j] = c[i-1][j-1] + 1;
         pre[i][j] = pre[i-1][j-1] + X[i-1];
      }
      else if(c[i-1][j] > c[i][j-1]) {
         c[i][j] = c[i-1][j];
         pre[i][j] = pre[i-1][j];
      }
      else if(c[i-1][j] < c[i][j-1]) {
         c[i][j] = c[i][j-1];
         pre[i][j] = pre[i][j-1];
      }
      else {
         c[i][j] = c[i][j-1];
         pre[i][j] = min(pre[i-1][j], pre[i][j-1]);
      }
   }
}

void Print()
{
   FOR(i, 1, m) {
      FOR(j, 1, n)
         cout << c[i][j] << " ";
      cout << "\n";
   }

}
int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   scanf("%d", &TC);

   FOR(tc, 1, TC) {
      cin >> X >> Y;

      LCS();
      //Print();
      printf("Case %d: ", tc);

      if(pre[m][n].size() == 0) cout << ":(\n";
      else cout << pre[m][n] << "\n";
   }

   return 0;
}
