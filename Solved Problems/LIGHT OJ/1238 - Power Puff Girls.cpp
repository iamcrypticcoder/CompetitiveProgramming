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


int m, n;
char grid[21][21];
char color[21][21];
VVI dist;
PII posA, posB, posC, posH;
int dA, dB, dC;

bool inGrid(PII p)
{
   return (p.ff >= 0 && p.ff < m && p.ss >= 0 && p.ss < n);
}

int BFS(PII s)
{
   PII u, v;
   queue<PII> Q;

   dist = VVI(m, VI(n, INF));
   memset(color, WHITE, sizeof color);

   color[s.ff][s.ss] = GRAY;
   dist[s.ff][s.ss] = 0;
   Q.push(s);

   while(!Q.empty()) {
      u = Q.front(); Q.pop();

      FOR(i, 0, 3) {
         v.ff = u.ff + dx[i];
         v.ss = u.ss + dy[i];

         if(inGrid(v) && grid[v.ff][v.ss] != '#' && grid[v.ff][v.ss] != 'm' && color[v.ff][v.ss] == WHITE) {
            color[v.ff][v.ss] = GRAY;
            Q.push(v);
            dist[v.ff][v.ss] = dist[u.ff][u.ss] + 1;
         }
      }
      color[u.ff][u.ss] = BLACK;
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
      scanf("%d %d", &m, &n);

      getchar();
      FOR(i, 0, m-1) {
         gets(grid[i]);
         FOR(j, 0, n-1) {
            if(grid[i][j] == 'a')
               posA = PII(i, j);
            else if(grid[i][j] == 'b')
               posB = PII(i, j);
            else if(grid[i][j] == 'c')
               posC = PII(i, j);
            else if(grid[i][j] == 'h')
               posH = PII(i, j);
         }
      }

      BFS(posH);

      int ans = max(dist[posA.ff][posA.ss], max(dist[posB.ff][posB.ss], dist[posC.ff][posC.ss]));

      printf("Case %d: %d\n", tc, ans);
   }

   return 0;
}



