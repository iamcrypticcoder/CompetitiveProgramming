/*
// Time : 0.064
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

int A[101][101];
int S[101][101];

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int N;
   int maxSum = -1;

   while(scanf("%d", &N) != EOF) {

      FOR(i, 1, N) FOR(j, 1, N) scanf("%d", &A[i][j]);

      FOR(i, 1, N) FOR(j, 1, N)
         S[i][j] = S[i-1][j] + S[i][j-1] + A[i][j] - S[i-1][j-1];
/*
      FOR(i, 1, N) {
         FOR(j, 1, N)
            printf("%d ", S[i][j]);
         printf("\n");
      }


      FOR(i, 1, N) FOR(j, 1, N) FOR(k, i, N) FOR(l, j, N) {
            int sum = S[k][l] - S[k][j-1] - S[i-1][l] + S[i-1][j-1];
            maxSum = max(maxSum, sum);
      }

      printf("%d\n", maxSum);
   }

   return 0;
}
*/

// ---------------------------------------- USING KADANE O(n^3)--------------------------------------------

// This is Kadane Algorithm to find 2-D Maximum Sum in O(n^3) complexity.
// The main Fact of this algorithm is finding 1-D Maximum Sum in O(n) complexity.

#include<iostream>
#include<algorithm>

using namespace std;

int a[101][101];		//globally declared,all are initialized by 0

int main()
{
	int n,i,j,k;
//	int row, col;
	int N;

	//freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	while( cin >> N && N) {

		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
				cin >> a[i][j];
				a[i][j] += a[i-1][j];		//adding a column,a[n][1]. Computes sum of each column
                                       //contains sum of all values of column 1 up to row n
			}
		}
      cout << a[N][N] << "\n";
		long max = a[1][1], temp;

		for(i=1; i<=N; i++) {
			for(j=i; j<=N; j++) {
				temp = 0;

				for(k=1; k<=N; k++) {
					temp += (a[j][k] - a[i-1][k]);
					if(temp > max)
						max = temp;
					if(temp < 0) temp = 0;
				}
			}
		}

		cout << max << endl;


	}

return 0;
}
// -----------------------------------------------------------------------------
