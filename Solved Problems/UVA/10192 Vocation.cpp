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

#define MAX 105

char X[MAX], Y[MAX];
int i, j, m, n, c[MAX][MAX], b[MAX][MAX];

int LCSlength()
{
	m=strlen(X);
	n=strlen(Y);
	
	for (i=1;i<=m;i++) c[i][0]=0;
	for (j=0;j<=n;j++) c[0][j]=0;
	
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++) {
			if (X[i-1]==Y[j-1]) {
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1; // from north west 
			}
			else if (c[i-1][j]>=c[i][j-1]) {
				c[i][j]=c[i-1][j];
				b[i][j]=2; // from north 
			}
			else {
				c[i][j]=c[i][j-1];
				b[i][j]=3; // from west
			}
		}
	return c[m][n];

}

int main()
{
	int TC = 0;

	while(gets(X) && strcmp(X, "#") != 0) {
		gets(Y);
		cout << "Case #" << ++TC << ": you can visit at most "<< LCSlength() << " cities.\n";
	}
	
	return 0;
}
