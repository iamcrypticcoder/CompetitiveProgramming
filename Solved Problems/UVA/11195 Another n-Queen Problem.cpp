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

int GCD(int a,int b) {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a,int b) {   return a / GCD(a, b) * b;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

int N;
int solNum = 0;
int temp[16], sol[16][400000][16], taken[16], left_diag[40], right_diag[40];
bool bad[16][16];
int totalSol[16];

void NQueen(int col)
{
   if(col == N+1)
      memcpy(sol[N][++solNum], temp, sizeof temp);
   else {
      for(int row=1; row < N+1; row++) {
         if( !taken[row] && !left_diag[row+col] && !right_diag[row-col+N] && !bad[row][col]) {
            taken[row] = left_diag[row+col] = right_diag[row-col+N] = true;
            temp[col] = row;
            NQueen(col+1);
            taken[row] = left_diag[row+col] = right_diag[row-col+N] = false;
         }
      }
   }
}

void showSolution(int N)
{
   FOR(i, 1, totalSol[N]) {
      printf("%d ", i);
      FOR(j, 1, N) printf("%d ", sol[N][i][j]);
      cout << endl;
   }
}

void GenAllSol()
{
   FOR(n, 4, 14) {
      N = n;
      memset(taken, 0, sizeof taken);
      memset(left_diag, 0, sizeof left_diag);
      memset(right_diag, 0, sizeof right_diag);
      solNum = 0;
      NQueen(1);
      totalSol[n] = solNum;
   }
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   string line;

   GenAllSol();
   //cout << totalSol[14];
   //showSolution(8);

   tc = 1;
   while(scanf("%d", &N) != EOF) {
      getline(cin, line);
      if(N == 0) break;

      memset(bad, false, sizeof bad);
      FOR(i, 1, N) {
         getline(cin, line);
         FOR(j, 0, line.SZ-1)
            if(line[j] == '*') bad[i][j+1] = true;
      }

      int c = 0;
      FOR(i, 1, totalSol[N]) {
         bool isPos = true;
         FOR(j, 1, N) {
            int row = sol[N][i][j];
            int col = j;
            if(bad[row][col] == true) {
               isPos = false;
               break;
            }
         }
         if(isPos == true) c++;
      }

      printf("Case %d: %d\n", tc++, c);
   }

   return 0;
}
