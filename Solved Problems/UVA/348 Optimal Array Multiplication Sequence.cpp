#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define INF 999999999
#define MAX 21

int M[MAX][MAX];
char TRACK[MAX][MAX];

VI p;

int MatrixChainOrder()
{
	int i, j, l, k, q;
	int n = p.size()-1;

	for(i = 1; i<= n; i++)
		M[i][i] = 0;

	for(l = 2; l<= n; l++) {
		for(i=1; i <= n-l+1; i++) {
			j = i+l-1;
			M[i][j] = INF;
			for(k = i; k <= j-1; k++) {
				q = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < M[i][j]) {
					M[i][j] = q;
					TRACK[i][j] = k;
				}
			}
		}
	}
	return M[1][n];										
}	

void PrintSolution(int i, int j)
{
	if(i==j) cout << 'A'<< i;
	else {
		cout << '(';
		PrintSolution(i, TRACK[i][j]);
		cout << " x ";
		PrintSolution(TRACK[i][j]+1, j);
		cout << ')';
	}
}


int main()
{
	int tcase;
	int num_of_matrix;
	int temp, m, n;

	tcase = 1;
	while(cin >> num_of_matrix && num_of_matrix != 0) {
		cin >> m >> n;
		p.push_back(m);
		p.push_back(n);

		FOR(i,1, num_of_matrix-1) {
			cin >> m >> n;
			p.push_back(n);
		}

		MatrixChainOrder();
		
		cout << "Case " << tcase++ << ": ";
		PrintSolution(1, num_of_matrix);
		cout << "\n";
	
		p.clear();
	}

	
	return 0;
}