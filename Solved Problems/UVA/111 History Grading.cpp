/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :  0.012
    Rank :  1462
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

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999


typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 21

int noEvents;

int M, N;
int X[MAX];       // Store correct order;
int Y[MAX];       // Store student's order;
int C[MAX][MAX];

int LCS()
{
   M = N = noEvents;

   FOR(i, 0, M) C[i][0] = C[0][i] = 0;

   FOR(i, 1, M)
      FOR(j, 1, N) {
         if(X[i-1] == Y[j-1])
            C[i][j] = C[i-1][j-1] + 1;       // form upper-left
         else if(C[i-1][j] >= C[i][j-1])
            C[i][j] = C[i-1][j];
         else C[i][j] = C[i][j-1];
      }
   return C[M][N];
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int t;

   scanf("%d", &noEvents);
   FOR(i, 1, noEvents) {
      scanf("%d", &t);
      X[t-1] = i;
   }

   while(scanf("%d", &t) != EOF) {
      int index = 1;
      Y[t-1] = index++;

      FOR(i, 1, noEvents-1) {
         scanf("%d", &t);
         Y[t-1] = index++;
      }

      int lcsLength = LCS();

      printf("%d\n", lcsLength);
   }


   return 0;
}
