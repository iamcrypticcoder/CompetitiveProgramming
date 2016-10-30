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

//---------------------------- GLOBAL VARIABLES ----------------------------

#define MAX_NODE 27

int N, M;
bool G1[MAX_NODE][MAX_NODE];
bool G2[MAX_NODE][MAX_NODE];


int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   char ch1, ch2;
   int u, v;

   cin >> TC;

   FOR(tc, 1, TC) {
      if(tc > 1) cout << endl;

      memset(G1, false, sizeof G1);
      memset(G2, false, sizeof G2);

      cin >> N;
      FOR(i, 1, N) {
         cin >> ch1 >> ch2;
         u = ch1 - 'A' + 1;
         v = ch2 - 'A' + 1;
         G1[u][v] = G1[v][u] = true;
      }

      cin >> M;
      FOR(i, 1, M) {
         cin >> ch1 >> ch2;
         u = ch1 - 'A' + 1;
         v = ch2 - 'A' + 1;
         G2[u][v] = G2[v][u] = true;
      }


      FOR(k, 1, 26)
         FOR(i, 1, 26)
            FOR(j, 1, 26) {
               G1[i][j] = G1[j][i] = G1[i][j] || (G1[i][k] && G1[k][j]);
               G2[i][j] = G2[j][i] = G2[i][j] || (G2[i][k] && G2[k][j]);
            }

      /*
      FOR(i, 1, 10) {
         FOR(j, 1, 10)
            cout << G1[i][j];
         cout << endl;
      }
      cout << endl;

      FOR(i, 1, 10) {
         FOR(j, 1, 10)
            cout << G2[i][j];
         cout << endl;
      }
      */

      bool isEqual = true;
      FOR(i, 1, 26) {
         FOR(j, 1, 26) {
            if(G1[i][j] != G2[i][j]) {
               isEqual = false;
               break;
            }
         }
         if(isEqual == false) break;
      }

      if(isEqual) cout << "YES\n";
      else cout << "NO\n";

   }



   return 0;
}
