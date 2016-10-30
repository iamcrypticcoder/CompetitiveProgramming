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

int GCD(int a,int b) {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a,int b) {   return a / GCD(a, b) * b;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

int N, Q;
char symbols[36][16][43];
int res[16][43];

int code(char ch)
{
   if(isdigit(ch)) return ch - '0' + 26;
   else return ch - 'A';
}
int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   string str, temp;
   char ch;
   int chCode;

   //cout << code('0');
   scanf("%d %d", &N, &Q);
   cin >> str;
   getline(cin, temp);

   FOR(i, 0, N-1) {
      int chCode = code(str[i]);

      FOR(j, 0, 15) {
         getline(cin, temp);
         FOR(k, 0, 42) symbols[chCode][j][k] = temp[k];
      }
      getline(cin, temp);
   }

   FOR(q, 1, Q) {
      printf("Query %d: ", q);

      cin >> str;

      // Overlapping
      memset(res, 0, sizeof res);
      FOR(i, 0, str.size()-1) {
         chCode = code(str[i]);
         FOR(j, 0, 15) FOR(k, 0, 42)
            if(symbols[chCode][j][k] == '*') res[j][k]++;
      }
      // Checking Each Character
      FOR(i, 0, str.size()-1) {
         chCode = code(str[i]);
         bool isPos = false;
         FOR(j, 0, 15) FOR(k, 0, 42)
            if(symbols[chCode][j][k] == '*' && res[j][k] == 1) {
               isPos = true;
               break;
            }
         if(isPos) printf("Y");
         else printf("N");
      }
      printf("\n");
   }

   return 0;
}
