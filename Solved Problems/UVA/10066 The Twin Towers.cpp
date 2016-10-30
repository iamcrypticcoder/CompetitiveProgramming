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

#define MAX 101

VI X, Y, LCS;
int m, n, c[MAX][MAX];

int FindLCS()
{
	int i, j;

	m = X.size();
	n = Y.size();
	
	for (i=1;i<=m;i++) c[i][0]=0;
	for (j=0;j<=n;j++) c[0][j]=0;
	
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++) {
			if (X[i-1]==Y[j-1]) 
				c[i][j]=c[i-1][j-1]+1;
			else if (c[i-1][j]>=c[i][j-1]) 
				c[i][j]=c[i-1][j];
			else 
				c[i][j]=c[i][j-1];
		}
	return c[m][n];
}

int main()
{
	int temp, TC = 0;
	int N1, N2;

	while(cin >> N1 >> N2 && N1 != 0 && N2 != 0) {
		while(N1--) { 
			cin >> temp;
			X.push_back(temp);
		}
		while(N2--) { 
			cin >> temp;
			Y.push_back(temp);
		}
	
		cout << "Twin Towers #" << ++TC << "\n";
		cout << "Number of Tiles : " << FindLCS() << "\n\n";

		X.clear();
		Y.clear();
	}
		
	return 0;
}