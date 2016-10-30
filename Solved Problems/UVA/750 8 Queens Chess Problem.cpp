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

int solNum = 1;
int temp[10], sol[100][10], taken[10], left_diag[20], right_diag[20];

void NQueen(int col)
{
   if(col == 9)
      memcpy(sol[solNum++], temp, sizeof temp);
   else {
      for(int row=1; row < 9; row++) {
         if( !taken[row] && !left_diag[row+col] && !right_diag[row-col+8]) {
            taken[row] = left_diag[row+col] = right_diag[row-col+8] = true;
            temp[col] = row;
            NQueen(col+1);
            taken[row] = left_diag[row+col] = right_diag[row-col+8] = false;
         }
      }
   }
}

void showSolution()
{
   FOR(i, 1, solNum-1) {
      printf("%d ", i);
      FOR(j, 1, 8) printf("%d ", sol[i][j]);
      cout << endl;
   }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int r, c;

	memset(taken, 0, sizeof taken);
	memset(left_diag, 0, sizeof left_diag);
	memset(right_diag, 0, sizeof right_diag);

	NQueen(1);

	TC = src();

	FOR(tc, 1, TC) {
	   if(tc > 1) printf("\n");

      scanf("%d %d", &r, &c);
      printf("SOLN       COLUMN\n");
      printf(" #      1 2 3 4 5 6 7 8\n\n");

      int n = 0;
      FOR(i, 1, solNum-1) {
         if(sol[i][c] == r) {
            printf("%2d     ", ++n);
            FOR(j, 1, 8)
               printf(" %d", sol[i][j]), printf(j == 8 ? "\n" : "");
         }
      }

	}



   return 0;
}
