/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
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

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

int MW, N;
int W[101], V[101];        /** Assuming number of items not more than 100 **/
int C[1000][101];          /** Assuming MW = 1000. This is for max VALUE we can get. **/
bool T[1000][101];         /** This is Track Table to get which elements are selected. **/
VI sol;

/**
** The rows are weights
** The columns are items
**
**/
int ZeroOneKnapsack()
{
   FOR(w, 0, MW) {
      C[w][0] = 0;
   }
   FOR(i, 0, N) {
      C[0][i] = 0;
   }

   memset(T, false, sizeof T);

   FOR(w, 0, MW) FOR(i, 1, N) {
      if(W[i] > w) {                /** if the weight of the item > knapsask weight **/
         C[w][i] = C[w][i-1];
      }
      else {
         if(C[w-W[i]][i-1] + V[i] > C[w][i-1]) {           /** if item choosen **/
            C[w][i] = C[w-W[i]][i-1] + V[i];
            T[w][i] = true;
         }
         else C[w][i] = C[w][i-1];                      /** if not choosen **/
      }
   }
   return C[MW][N];
}


int topDownKnapsack(int w, int n)
{
    if(C[w][n] != -1) return 0;
    if(w == 0 || n == 0) return (C[w][n] = 0);

    if(W[n] > w) return (C[w][n] = topDownKnapsack(w, n-1));

    int choosen = topDownKnapsack(w-W[n], n-1) + V[n];
    int notChoosen = topDownKnapsack(w, n-1);

    if(choosen > notChoosen) {
        T[w][n] = true;
    }
    return C[w][n] = max(choosen, notChoosen);
}

void GenerateSolution(int w, int i)
{
   if(w == 0 || i == 0) return;
   if(T[w][i] == 0) GenerateSolution(w, i-1);      // Not Chosen
   else {                                          // Chosen
      //sol.PB(i);                                   // For Bottom up approach
      GenerateSolution(w - W[i], i-1);
      sol.PB(i);                                   // For Top down approach
   }
}

void PrintC()
{
   cout << "  ";
   FOR(i, 0, N) cout << i << " ";
   cout << endl;

   FOR(i, 0, MW) {
      cout << i << " ";
      FOR(j, 0, N) cout << C[i][j] << " ";
      cout << "\n";
   }
   cout << endl;
}

void PrintT()
{
   cout << "  ";
   FOR(i, 0, N) cout << i << " ";
   cout << endl;

   FOR(i, 0, MW) {
      cout << i << " ";
      FOR(j, 0, N) cout << T[i][j] << " ";
      cout << "\n";
   }
   cout << endl;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    while(cin >> N >> MW) {
        double cl = clock();
        cl = clock() - cl;

        FOR(i, 1, N) cin >> W[i] >> V[i];


        //cout << ZeroOneKnapsack() << "\n";
        /*
        PrintC();
        PrintT();
        sol.clear();
        GenerateSolution(MW, N);
        FOR(i, 0, sol.SZ-1) cout << sol[i] << " " ;
        cout << endl;
        */


        memset(C, -1, sizeof C);
        cout << topDownKnapsack(MW, N) << endl;
        GenerateSolution(MW, N);
        FOR(i, 0, sol.SZ-1) cout << sol[i] << " " ;
        cout << endl;

        fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
    }

    return 0;
}

/**

INPUT:


OUTPUT:

**/




