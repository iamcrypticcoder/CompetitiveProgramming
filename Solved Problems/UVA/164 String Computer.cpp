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

#define MAX 100

string X, Y;
int COST[MAX][MAX], TRACK[MAX][MAX];

int FindCost()
{
	int m, n;
	int i, j;
	int mincost;

	m = X.length();		n = Y.length();

	COST[0][0] = TRACK[0][0] = 0;

	for(i=1; i<=n; i++) {
		COST[0][i] = i;
		TRACK[0][i] = 3;
	}
	for(i=1; i<=m; i++) {
		COST[i][0] = i;
		TRACK[i][0] = 2;
	}

	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++) {
			if(X[i-1] == Y[j-1]) {
				COST[i][j] = COST[i-1][j-1];
				TRACK[i][j] = 1;
			}
			else {
				mincost = min(COST[i-1][j-1], min(COST[i][j-1],COST[i-1][j]));
				if(mincost == COST[i-1][j-1]) {
					COST[i][j] = COST[i-1][j-1] + 1;
					TRACK[i][j] = 1;
				}
				else if(mincost == COST[i-1][j]) {
					COST[i][j] = COST[i-1][j] + 1;
					TRACK[i][j] = 2;
				}
				else {
					COST[i][j] = COST[i][j-1] + 1;
					TRACK[i][j] = 3;
				}
			}
		}

	return COST[m][n];
}

bool isTracked = 0;

void PrintOp(int i, int j) 
{
	if(TRACK[i][j] == 0 || isTracked) return;
	if(TRACK[i][j] == 1) {
		PrintOp(i-1, j-1);
		if(isTracked) return;
		if(COST[i][j] != COST[i-1][j-1]) {
			printf("C%c%02d", Y[j-1], i);
//			cout << "Replace " << i << "," << Y[j-1] << "\n";
			X.replace(i-1, 1, 1, Y[j-1]);
			isTracked = 1;
		}

	}
	else if(TRACK[i][j] == 2) {
		PrintOp(i-1, j);
		if(isTracked) return;
		printf("D%c%02d", X[i-1], i);
		X.erase(i-1, 1);
		isTracked = 1;
	}
	else {
		PrintOp(i, j-1);
		if(isTracked) return;
		printf("I%c%02d", Y[j-1], j);
//		cout << "Insert " << j << "," << Y[j-1] << "\n";
		X.insert(j-1, 1, Y[j-1]);
		isTracked = 1;
	}
	
}


void show()
{
	for(int i=0; i<=X.length(); i++) {
		for(int j=0; j<=Y.length(); j++)
			cout << COST[i][j] << " ";
		cout << "\n";
	}
	cout << "\n\n";

	for(int i=0; i<=X.length(); i++) {
		for(int j=0; j<=Y.length(); j++)
			cout << TRACK[i][j] << " ";
		cout << "\n";
	}
	cout << "\n\n";

}
int main()
{
	int cmd, totalCost;
/*	
	X.erase(0,1);
	cout << X << "\n";
	X.insert(2, 1, 'z');
	cout << X << "\n";
	X.replace(2,1,1, 'l');
	cout << X << "\n";
*/

	while(cin >> X && X != "#") {
		cin >> Y;

		totalCost = FindCost();

		for(cmd = 1; cmd <= totalCost; cmd++) {
			FindCost();
//		show();

			isTracked = 0;
			PrintOp(X.length(), Y.length());
//		cout << X << "\n";
		}
		cout << "E\n";
	}
	return 0;
}
