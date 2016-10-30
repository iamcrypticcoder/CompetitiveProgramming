// This is Kadane Algorithm to find 2-D Maximum Sum in O(n^3) complexity.
// The main Fact of this algorithm is finding 1-D Maximum Sum in O(n) complexity.

#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

int table[101][101];		

int main()
{
	int n,i,j,k;
	int row, col;
	int maxSum, sum, ref;

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	while(cin >> row >> col && row && col) {

		FOR(i, 1, row) {
			FOR(j, 1, col) {
				cin >> table[i][j];
				table[i][j] == 0 ? table[i][j] = 1 : table[i][j] = 0;

				if(table[i][j]) table[i][j] += table[i-1][j];	
			}
		}
/*	
		FOR(j, 1, row) {
			FOR(i, 1, col)
				cout << table[j][i] << " ";
			cout << "\n";
		}
*/
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


return 0;
}
