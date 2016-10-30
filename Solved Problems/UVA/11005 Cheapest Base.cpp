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


char valueToChar(int value)
{
    if(value >= 10)
        return (char)('A' + value - 10);
    return ((char)(value + 48));
}
// 10-BASE to ANY BASE
// This function converts a 10 base number to any base and return the number as string
// 10 = A, 11 = B, 12 = C ...... 25 = Z
string toBase(LL num, int base)
{
	string ret;

	if(num == 0) return "0";
	while(num != 0) {
		ret += valueToChar(num%base);
		num /= base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

map<char, int> cost;
VI cheapestBases;
int noQuery, N;
int temp, c;
int cheapestCost;
string baseStr;

int printCost(string str)
{
   int ret = 0;
   FOR(i, 0, str.SZ-1) ret += cost[str[i]];
   return ret;
}
int main()
{
   READ("input.txt");
   WRITE("output.txt");
   int i, j, k;
   int TC, tc;

  // cout << toBase(100, 36);
   cin >> TC;

   FOR(tc, 1, TC) {
      if(tc > 1) cout << endl;

      FOR(i, 0, 35) {
         cin >> c;
         cost[symbols[i]] = c;
      }

      cin >> noQuery;

      cout << "Case " << tc << ":\n";
      FOR(i, 1, noQuery) {
         cin >> N;
         cheapestCost = INF;
         FOR(j, 2, 36) {
            temp = printCost(toBase(N, j));
            if(temp < cheapestCost) {
               cheapestBases.clear();
               cheapestBases.PB(j);
               cheapestCost = temp;
            }
            else if(temp == cheapestCost) cheapestBases.PB(j);
         }

         sort(cheapestBases.begin(), cheapestBases.end());

         cout << "Cheapest base(s) for number " << N << ":";
         FOR(j, 0, cheapestBases.SZ-1) cout << " " << cheapestBases[j];
         cout << endl;

         cheapestBases.clear();
      }
      cost.clear();

   }

   return 0;
}
