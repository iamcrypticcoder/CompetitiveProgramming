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

#define MAX 1001

string X, Y;

int m, n, C[MAX][MAX];


int FindLCS()
{
	int i,j;
	m = X.length();
	n = Y.length();
	
	for (i=1;i<=m;i++) C[i][0]=0;
	for (j=0;j<=n;j++) C[0][j]=0;
	
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++) {
			if (X[i-1]==Y[j-1]) 
				C[i][j]=C[i-1][j-1]+1;
	
			else if (C[i-1][j] >= C[i][j-1]) 
				C[i][j] = C[i-1][j];
			
			else 
				C[i][j] = C[i][j-1];
			
		}
	return C[m][n];

}


int main()
{


	while(getline(cin, X)) {
		getline(cin, Y);

		cout << FindLCS() << "\n";
	}
	return 0;
}