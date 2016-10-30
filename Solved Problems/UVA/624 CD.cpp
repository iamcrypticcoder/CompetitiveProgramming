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

#define MAXN 2001

int MW, N;
int W[MAXN];
int C[MAXN][MAXN];
bool T[MAXN][MAXN];
VI sol;

int ZeroOneKnapsack()
{
   FOR(w, 0, MW) C[w][0] = 0;
   FOR(i, 0, N) C[0][i] = 0;

   memset(T, false, sizeof T);

   FOR(w, 0, MW) FOR(i, 1, N) {
      if( W[i] > w) C[w][i] = C[w][i-1];           // Too heavy. not taken
      else {
         if(C[w-W[i]][i-1] + W[i] > C[w][i-1]) {    // Taken
            C[w][i] = C[w-W[i]][i-1] + W[i];
            T[w][i] = true;
         }
         else C[w][i] = C[w][i-1];                 // Not Taken
      }
   }
   return C[MW][N];
}

void GenerateSolution(int w, int i)
{
   if(w == 0 || i == 0) return;
   if(T[w][i] == 0) GenerateSolution(w, i-1);      // Not Chosen
   else {                                          // Chosen
      sol.PB(i);
      GenerateSolution(w - W[i], i-1);
   }
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
    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   while(cin >> MW >> N) {
      FOR(i, 1, N) cin >> W[i];

      ZeroOneKnapsack();
      sol.clear();
      GenerateSolution(MW, N);

      FOR(i, 0, sol.SZ-1) cout << W[sol[i]] << " ";
      cout << "sum:" << C[MW][N] << "\n";
   }


   return 0;
}

// Old Code......................

#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define MAXN 2001

int TRACK[21];
int C[21][MAXN];
int P[MAXN], NEW[MAXN];
int N, num_of_track;


void ZeroOneKnapsack()
{
  int i, j;
  FOR(i, 0, 20)   C[i][0] = 0;
  FOR(j, 0, MAXN-1) C[0][j] = 0;

  memset(P, 0, sizeof(P));

  for(i = 1; i <= num_of_track; i++)
    for(j = 1; j<= N; j++) {
      if(TRACK[i] > j)
        C[i][j] = C[i-1][j];
		else {
        C[i][j] = max(C[i-1][j], C[i-1][j - TRACK[i]] + TRACK[i]);
	 	  if(P[C[i][j]] == 0) {
		     P[C[i][j]] = C[i][j] - TRACK[i];
			  NEW[C[i][j]] = TRACK[i];
		  }
	   }
	 }
}

void PrintSolution(int n)
{
	cout << NEW[n] << " ";
	if(P[n] == 0) return;
	PrintSolution(P[n]);
}


void show()
{
	int i,j;
	FOR(i, 1, num_of_track) {
		FOR(j, 1, N)
			cout << C[i][j] << "  ";
		cout << "\n";
	}
}

void showPredessor()
{
	int i;
	for(i = 1; i<=N; i++)
		cout << i << " " << P[i] << "\n";

}

int comp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int main()
{
    int i,j;

    while(cin >> N) {
      cin >> num_of_track;

      FOR(i, 1, num_of_track)
        cin >> TRACK[i];
		qsort(TRACK+1, num_of_track, sizeof(TRACK[1]), comp);

      ZeroOneKnapsack();

		PrintSolution(C[num_of_track][N]);
		cout << "sum:" <<C[num_of_track][N] << "\n";

//		showPredessor();

//		cout << "\n";
//		show();


    }


	return 0;
}

