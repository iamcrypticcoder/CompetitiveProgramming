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
	int s, b, r1, c1, r2, c2;

	int TC, tcase;
	string str;

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	

	cin >> TC;

	while(TC--) {
		cin >> s >> b;

		FOR(i, 1, s)
			FOR(j, 1, s)
				table[i][j] = 1;

		FOR(i, 1, b) {
			cin >> r1 >> c1 >> r2 >> c2;

			FOR(j, r1, r2)
				FOR(k, c1, c2)
					table[j][k] = 0;
		}

		FOR(i, 1, s)
			FOR(j, 1, s)
				if(table[i][j]) table[i][j] += table[i-1][j]; 

		row = col = s;
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
