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

string Process(string s)
{
   string ret = "";

   FOR(i, 0, s.SZ-1) {
      if(isalpha(s[i])) ret += s[i];
   }
   return ret;
}

bool isSqrNum(int num)
{
   int a = (int)sqrt(num);

   return (SQR(a) == num);
}

bool isPalindrome(string s)
{
   int mid;
   if(s.SZ % 2 == 0) mid = s.SZ / 2 - 1;
   else mid = s.SZ / 2;

   int i, j;
   for(i=0, j=s.SZ-1; i <= mid;  i++, j--)
      if(s[i] != s[j]) return false;
   return true;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   string line;

   TC = src();
   getchar();

   FOR(tc, 1, TC) {
      getline(cin, line);

      line = Process(line);

      printf("Case #%d:\n", tc);
      if(isSqrNum(line.SZ)) {
         if(isPalindrome(line)) printf("%d\n", (int)sqrt(line.SZ));
         else printf("No magic :(\n");
      }
      else printf("No magic :(\n");


   }

   return 0;
}
