#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define FOR(i, L, U) for(int i=L; i<=U; i++)

#define MAX 1001

int C[MAX][31];
int W[MAX], P[MAX];
int MW[101], maxWeight = 0;
int N;							// Number of Object

void ZeroOneKnapsack()
{
	int i, j;

	for (i=0; i <= N ; i++) C[i][0] = 0;
	for (j=0; j <= maxWeight; j++) C[0][j] = 0;
	
	for (i=1;i <= N; i++)
		for (j=1; j <= maxWeight; j++) {
			if (W[i] > j)
				C[i][j] = C[i-1][j];
			else
				C[i][j] = max(C[i-1][j] , C[i-1][j-W[i]]+P[i]);
		}
}


int main()
{
	int TC;
	int p, w, G;
	int maxValueBought = 0;
	int i;

	cin >> TC;
	while(TC--) {
		cin >> N;
		FOR(i, 1, N)
			cin >> P[i] >> W[i];
		cin >> G;
		FOR(i, 1, G) {
			cin >> MW[i];
			if(maxWeight < MW[i])	maxWeight = MW[i];	
		}
		ZeroOneKnapsack();
		maxValueBought = 0;
		FOR(i, 1, G)
			maxValueBought += C[N][MW[i]];
		
		cout << maxValueBought << "\n";
	}

			

	return 0;
}