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


typedef long long LL;


#define WHITE 0
#define GRAY 1
#define BLACK 2


inline int src() { int ret; scanf("%d", &ret); return ret; }

int A, B, C;
int x, y, z;


int main()
{
 //   READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   cin >> TC;

   FOR(tc, 1, TC) {
      cin >> A >> B >> C;

      bool is_found = false;
      for(x = -100; x <= 100; x++) {
         for(y = -100; y <= 100; y++) {
            z = A - (x + y);

            if((x * y * z) == B && (x != y && y != z && z != x)) {
               if(SQR(x) + SQR(y) + SQR(z) == C) {
                  is_found = true;
                  break;
               }
            }
         }
         if(is_found) break;
      }

      if(is_found) printf("%d %d %d\n", x, y, z);
      else printf("No solution.\n");
   }

   return 0;
}
