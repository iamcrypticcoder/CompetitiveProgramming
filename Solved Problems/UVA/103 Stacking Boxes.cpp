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

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 31

int K, N;
VVI B;
int A[MAX], L[MAX], P[MAX];
int parent, lisLength;
VI lis;

// Return true if a<b end vice-varsa
bool comp(int a, int b)
{
   FOR(i, 0, B[a].SZ-1) if(B[a][i] >= B[b][i]) return false;
   return true;
}

void LIS()
{
   FOR(i, 0, MAX-1) {
      L[i] = 1;
      P[i] = 0;
   }

   parent = 1;
   lisLength = 1;

   FOR(i, 1, K)
      FOR(j, i+1, K)
         if(comp(A[i], A[j]) == true) {
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

void ConstructLIS(int n)
{
   if(n == 0) return;
   ConstructLIS(P[n]);
   lis.PB(A[n]);
}

VVI G;
VI color;
VI topoOrder;

void DFS_Visit(int u)
{
    color[u] = GRAY;

    FOR(i, 0, G[u].SZ-1) {
        int v = G[u][i];
        if(color[v] == WHITE)
            DFS_Visit(v);
    }
    topoOrder.PB(u);
    color[u] = BLACK;
}

void TopoSort()
{
    color = VI(K+1, WHITE);
    topoOrder.clear();
    FOR(i, 1, K) {
        if(color[i] == WHITE)
            DFS_Visit(i);
    }
    reverse(topoOrder.begin(), topoOrder.end());
}


int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   while(scanf("%d %d", &K, &N) != EOF) {
      B = VVI(K+1);
      FOR(i, 1, K) {
         A[i] = i;
         B[i] = VI(N);
         FOR(j, 0, N-1) scanf("%d", &B[i][j]);
         sort(B[i].begin(), B[i].end());
      }

      G = VVI(K+1);
      FOR(i, 1, K) FOR(j, i+1, K) {
         if(comp(i, j) == true) G[i].PB(j);
         else if(comp(j,i) == true) G[j].PB(i);
      }
      TopoSort();


      FOR(i, 0, topoOrder.SZ-1) {
 //        cout << topoOrder[i] << " ";
         A[i+1] = topoOrder[i];
      }
 //     cout << "\n";

/*
      FOR(i, 1, K) cout << A[i] << " ";
      cout << "\n";
*/

      LIS();

      ConstructLIS(parent);

      printf("%d\n", lis.SZ);
      printf("%d", lis[0]);

      FOR(i, 1, lis.SZ-1) printf(" %d", lis[i]);
      printf("\n");

      lis.clear();
      topoOrder.clear();
   }

   return 0;
}
