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

#define FOR( i, L, U ) for( i=L ; i<=U ; i++ )

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;


int team[71], table[51], pos[101], cpy[71];
VVI arrange;
	int M, N;

int comp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;

}

int Seq_Search(int num)
{
	int i, ret ;
	FOR(i, 1, M)
		if(num == team[i]) {
			ret = i;
			team[i] = 0;
			break;
		}
	return ret;
}

int main()
{
	int pos, count;
	bool isPossible;
	
	int i, j, k;

	while(cin >> M >> N)
	{		
		if(M == 0 && N == 0) break;

		FOR(i, 1, M) {
			cin >> team[i];
			cpy[i] = team[i];
		}
		FOR(i, 1, N) 
			cin >> table[i];
		

		qsort(team+1, M, sizeof(int), comp);
//		qsort(table+1, N, sizeof(int), comp);



		if(team[1] > N) {
			cout << "0\n";
			continue;
		}

		arrange = VVI(M+1);

		isPossible = true;
	
		FOR(i, 1, M) {
			count = team[i];

			FOR(j, 1, N) {
				if(table[j] > 0) {
					table[j]--;
					arrange[i].push_back(j);
					count--;
				}
				if(count == 0) break;
			}
			if(count != 0) {
				isPossible = false;
				break;
			}
//			FOR(j, 0, arrange[i].size()-1)
//				cout << arrange[i][j] << " ";

		}



		if(isPossible) {
			cout << "1\n";
			
			FOR(i, 1, M) {
				pos = Seq_Search(cpy[i]);

				cout << arrange[pos][0];
				FOR(j, 1, arrange[pos].size()-1)
					cout << " " << arrange[pos][j];
				cout << "\n";
			}

		}
		else cout << "0\n";

		arrange.clear();


		
	}

	return 0;
}