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

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define MAX 25

int order;
int mat[MAX+1][MAX+1];
int DP[MAX+1][MAX+1];

int Process()
{
	int i, j, k;
	int L, row, col;
	int Area = 0;

	Area = mat[1][1];

	for(row=1; row <= order; row++)
		for(col=1; col <= order; col++) {
			DP[row][col] = mat[row][col];

			for(j = col+1; j <= order; j++) {
				DP[row][j] = DP[row][j-1] + mat[row][j];
				if(DP[row][j] == (j-col+1) && DP[row][j] > Area)
					Area = DP[row][j];
			}
			for(j=row+1; j <= order; j++) {
				DP[j][col] = DP[j-1][col] + mat[j][col];
				if(DP[j][col] == (j-row+1) && DP[j][col] > Area)
					Area = DP[row][j];
			}

			for(i = row+1; i<= order; i++)
				for(j=col+1; j <= order; j++) {
					DP[i][j] = DP[i][j-1] + DP[i-1][j] - DP[i-1][j-1] + mat[i][j];
					if(DP[i][j] == (i-row+1)*(j-col+1) && DP[i][j] > Area)
						Area = DP[i][j];
				}

			FOR(j, col, order)
				if(DP[row][j] == (j-col+1) && DP[row][j] > Area)
					Area = DP[row][j];
			FOR(j, row, order)
				if(DP[j][col] == (j-row+1) && DP[j][col] > Area)
					Area = DP[j][col];
		}
	return Area;
}

void Show()
{
	int i, j;
	FOR(i, 1, order) {
		FOR(j, 1, order)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
}

int invert(int a)
{
  if(a == 1) return 0;
  else return 1;
}

int main()
{
//	freopen("E:\\input.txt", "r", stdin);
//	freopen("E:\\output.txt", "w", stdout);
	int TC;
	int i, j, k, Area;
	string str;

	cin >> TC;

		getline(cin, str);
//		getline(cin, str);
		order = 0;
		FOR(i, 1, TC) {
			order = 0;
			getline(cin, str);
			getline(cin, str);
			order = str.size();
			FOR(j, 0, str.size()-1)
				mat[1][j+1] = str[j] - '0';

			FOR(j, 2, order) {
				getline(cin, str);
				FOR(k, 0, str.size()-1)
					mat[j][k+1] = str[k] - '0';
			}

         Show();
			Area = Process();
//			Show();
			cout << Area << "\n";
			if(i != TC) cout << "\n";
		}

	return 0;
}

// --------------------------------------Using Kadane --------------------------

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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

int table[101][101];

int main()
{
	int n,i,j,k;
	int row, col;
	int maxSum, sum, ref;

	int TC, tcase;
	string str;

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);


	cin >> TC;
	getline(cin, str);
	getline(cin, str);

	while(TC--) {
		row = 0;
		while(getline(cin, str) && str.size() != 0) {
			row++;
			col = str.size();

			FOR(i, 0, str.size()-1) {
				table[row][i+1] = str[i] - '0';
				if(table[row][i+1]) table[row][i+1] += table[row-1][i+1];
			}
		}

		maxSum = 0;

		FOR(i, 1, row)
			FOR(j, 1, col) {
				if(table[i][j] == 0) continue;
				ref = table[i][j];
				sum = ref;

				FOR(k, j+1, col) {
					if(table[i][k] < ref) break;
					else sum += ref;
				}
				for(k=j-1; k>=0; k--) {
					if(table[i][k] < ref) break;
					else sum += ref;
				}

				if(sum > maxSum) maxSum = sum;
			}

		cout << maxSum << "\n";
		if(TC) cout << "\n";

	}
/*
	FOR(i, 1, row) {
		FOR(j, 1, col)
			cout << table[i][j] << " ";
		cout << "\n";
	}
*/

return 0;
}
