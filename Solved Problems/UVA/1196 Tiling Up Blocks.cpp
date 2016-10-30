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
typedef vector<int> VI;
typedef pair<int, int> PII;



int N;
vector<PII> boxes;
VI L;
int lisLength;

void LDS()
{
   int i, j;

   L = VI(N+1, 1);

   lisLength = 1;

   FOR(i, 1, boxes.SZ-1) FOR(j, i+1, boxes.SZ-1)
      if(boxes[j].ff <= boxes[i].ff && boxes[j].ss <= boxes[i].ss) {
         if(L[i] + 1 > L[j] ) {
            L[j] = L[i] + 1;
            if(L[j] > lisLength) {
               lisLength = L[j];
            }
         }
      }
}

bool comp(PII a, PII b)
{
   if(a.ff == b.ff) return a.ss > b.ss;
   return a.ff > b.ff;
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   while(scanf("%d", &N) != EOF) {
      if(N == 0) {
         printf("*\n");
         break;
      }

      boxes = vector<PII>(N + 1);

      FOR(i, 1, N) {
         cin >> boxes[i].ff >> boxes[i].ss;
      }

      sort(boxes.begin()+1, boxes.end(), comp);

     // FOR(i, 1, boxes.SZ-1) cout << boxes[i].ff << " " << boxes[i].ss << "\n";
      LDS();

      printf("%d\n", lisLength);
   }

   return 0;
}
