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

VS X, Y, LCS;
int m, n, i, j;
int C[MAX][MAX], B[MAX][MAX];

int FindLCS()
{
	m = X.size();
	n = Y.size();
	
	for (i=1;i<=m;i++) C[i][0]=0;
	for (j=0;j<=n;j++) C[0][j]=0;
	
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++) {
			if (X[i-1] == Y[j-1]) {
				C[i][j]=C[i-1][j-1]+1;
				B[i][j]=1; /* from north west */
			}
			else if (C[i-1][j]>=C[i][j-1]) {
				C[i][j]=C[i-1][j];
				B[i][j]=2; /* from north */
			}
			else {
				C[i][j]=C[i][j-1];
				B[i][j]=3; /* from west */
			}
		}
	return C[m][n];

}

void PrintLCS(int i,int j) {
	if (i==0 || j==0) return;
	if (B[i][j]==1) {
		PrintLCS(i-1,j-1);
		//cout << X[i-1] << " ";
		LCS.push_back(X[i-1]);
	}
	else if (B[i][j]==2)
		PrintLCS(i-1,j);
	else
		PrintLCS(i,j-1);
}

void ShowLCS()
{
	int i;
	for(i=0; i < LCS.size()-1; i++)
		cout << LCS[i] << " ";
	cout << LCS[i] << "\n";
}

int main()
{
	string word;
	
	int propose = 1;
	while(cin >> word) {
		if(propose == 1) {
			if(word == "#")
				propose = 2;
			else X.push_back(word);
		}
		else if(propose == 2) {
			if(word == "#") {
				FindLCS();
				PrintLCS(m, n);
				ShowLCS();
				propose = 1;
				X.clear();
				Y.clear();
				LCS.clear();
			}
			else Y.push_back(word);
		}
	}
	return 0;
}