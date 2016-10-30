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

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }


string line;
int high, low;
int cur;
bool is_odd = true;

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   bool is_odd = true;

   high = 11;
   low = 0;
   while(getline(cin, line)) {
      if(line == "0") break;

      if(is_odd) cur = atoi(line.c_str());
      else if(!is_odd) {
         if(line == "too high" && cur <= high) high = cur;
         else if(line == "too low" && cur >= low) low = cur;
         else if(line == "right on") {
            if(cur <= low || cur >= high || low >= high) cout << "Stan is dishonest\n";
            else cout << "Stan may be honest\n";

            high = 11; low = 0;
         }
      }
      is_odd = !is_odd;
   }
   return 0;
}
