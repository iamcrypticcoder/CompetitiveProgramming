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

int R, C;
int dp[11][101];
int track[11][101];
VI sol;

void DP()
{
   FORD(j, C-1, 1) FOR(i, 1, R) {

      int index[3];
      if((index[0] = i-1) == 0) index[0] = R;
      index[1] = i;
      if((index[2] = i+1) == R+1) index[2] = 1;

      int m = min(min(dp[index[0]][j+1], dp[index[1]][j+1]), dp[index[2]][j+1]);

      sort(index, index+3);

      FOR(k, 0, 2)
         if(dp[index[k]][j+1] == m) {
            track[i][j] = index[k];
            dp[i][j] += m;
            break;
         }
   }
}

void PrintDp()
{
   FOR(i, 1, R) {
      FOR(j, 1, C) cout << dp[i][j] << " ";
      cout << "\n";
   }
}

void PrintTrack()
{
   FOR(i, 1, R) {
      FOR(j, 1, C) cout << track[i][j] << " ";
      cout << "\n";
   }
}

void TrackSolution(int i, int j)
{
   if(j == C+1) return;
   sol.PB(i);
   TrackSolution(track[i][j], j+1);
}

int main()
{
   READ("input.txt");
   WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   while(scanf("%d %d", &R, &C) != EOF) {

      FOR(i, 1, R) FOR(j, 1, C) scanf("%d", &dp[i][j]);

      DP();
      //PrintDp();
      //PrintTrack();

      // Findind Smallest value in first column
      int s, m = INF;
      FOR(i, 1, R) {
         if(dp[i][1] < m) {
            m = dp[i][1];
            s = i;
         }
      }

      // Tracking solution from track table
      TrackSolution(s, 1);

      printf("%d", sol[0]);
      FOR(i, 1, sol.SZ-1) printf(" %d", sol[i]);
      printf("\n%d\n", m);

      sol.clear();
   }

   return 0;
}
