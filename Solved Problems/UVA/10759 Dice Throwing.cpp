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

#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

ULL GCD(ULL a,ULL b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2


ULL space[25];
ULL DP[25][151];

int count()
{
    DP[1][0] = 6;
    DP[1][1] = 6;
    DP[1][2] = 5;
    DP[1][3] = 4;
    DP[1][4] = 3;
    DP[1][5] = 2;
    DP[1][6] = 1;


    FOR(n, 2, 24) {
        FOR(x, 0, 150) {
            ULL ans = 0;
            FOR(i, 1, 6) {
                if(x - i <= 0) ans += DP[n-1][0];
                else ans += DP[n-1][x-i];
            }
            DP[n][x] = ans;
        }
    }


}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    ULL n, x;

    space[1] = 6;
    FOR(i, 2, 24) {
        space[i] = 6 * space[i-1];
    }

    count();
    //cout << DP[3][9];

    while(scanf("%llu %llu", &n, &x) != EOF) {
        if(n == 0 && x == 0) break;

        if(DP[n][x] == 0) printf("0\n");
        else if(space[n] == DP[n][x]) printf("1\n");
        else {
            ULL g = GCD(space[n], DP[n][x]);

            printf("%llu/%llu\n", DP[n][x]/g, space[n]/g);
        }
    }

    return 0;
}


/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : .008
    Rank : 290
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

ULL GCD(ULL a,ULL b){   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a,int b) {   return a / GCD(a, b) * b;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

int numDice, value;
ULL space[25];
ULL DP[25][151];

ULL ways(int N, int X)
{
   if(DP[N][X] != -1) return DP[N][X];
   if(N == 1) {
      if(X == 0) return DP[N][0] = 6;
      else if (X < 7) return DP[N][X] = 6 - X + 1;
      else return DP[N][X] = 0;
   }

   ULL ret = 0;
   FOR(i, 1, 6) {
      if( X - i <= 0) ret += ways(N-1, 0);
      else ret += ways(N-1, X - i);
   }

   return DP[N][X] = ret;
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   space[1] = 6;
   FOR(i, 2, 24) {
     space[i] = 6 * space[i-1];
   }

   FOR(i, 0, 24) FOR(j, 0, 150) DP[i][j] = -1;
   ways(24, 150);

   while(scanf("%d %d", &numDice, &value) == 2) {
      if(numDice == 0 && value == 0) break;

      if(DP[numDice][value] == -1) ways(numDice, value);

      if(DP[numDice][value] == 0) printf("0\n");
      else if(space[numDice] == DP[numDice][value]) printf("1\n");
      else {
         ULL w = DP[numDice][value];
         ULL g = GCD(space[numDice], w);

         printf("%llu/%llu\n", w/g, space[numDice]/g);
      }
   }

   return 0;
}
