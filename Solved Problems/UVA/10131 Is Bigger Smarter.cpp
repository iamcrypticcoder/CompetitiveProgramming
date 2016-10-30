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

#define MAX_ELE 1001

vector<PII> eles, sorted;
int L[MAX_ELE], P[MAX_ELE];
int total, parent;
int lisLength;
VI sol;

void LIS()
{
   int i, j;

   FOR(i, 0, 1000) {
      L[i] = 1;
      P[i] = 0;
   }

   parent = lisLength = 0;

   FOR(i, 1, sorted.SZ-1)
      FOR(j, i+1, sorted.SZ-1)
         if(sorted[j].ff > sorted[i].ff && sorted[j].ss < sorted[i].ss) {
            if(L[i] + 1 > L[j]) {
               L[j] = L[i] + 1;
               P[j] = i;
               if(L[j] > lisLength) {
                  lisLength = L[j];
                  parent = j;
               }
            }
         }
}

void PrintLIS(int n)
{
   if(n == 0) return;
   PrintLIS(P[n]);
   sol.PB(n);
   //printf("%d\n", n);
}

bool comp(PII a, PII b)
{
   if(a.ff == b.ff) return a.ss > b.ss;
   return a.ff < b.ff;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int w, iq;

   eles.PB(PII(123456, 123456));     // To start index at 1.
   sorted.PB(PII(123456, 123456));
   while(scanf("%d %d", &w, &iq) != EOF) {
      eles.PB(PII(w, iq));
      sorted.PB(PII(w, iq));
   }
   sort(sorted.begin()+1, sorted.end(), comp);
   LIS();
   printf("%d\n", lisLength);
   PrintLIS(parent);

   FOR(i, 0, sol.SZ-1) {
      FOR(j, 1, eles.SZ-1)
         if(sorted[sol[i]].ff == eles[j].ff && sorted[sol[i]].ss == eles[j].ss) {
            printf("%d\n", j);
            break;
         }
   }

   return 0;
}
