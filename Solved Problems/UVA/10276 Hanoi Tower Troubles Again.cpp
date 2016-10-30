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

typedef	vector<int> VI;
typedef	vector< vector<int> > VII;

bool isSquare(int num)
{
	int root = (int)sqrt((double)num);
	if(root*root == num) return 1;
	return 0;
}

int main()
{
	int TC;

	VI pegs[50];
	int num, emptyIndex, numPegs;
	bool isPlaced;

	int i, j, k;

	cin >> TC;

	while(TC--) {
		
		cin >> numPegs;

		for(num = 1; ; num++) {
			
			isPlaced = false;
//			cout << pegs[i].size();

			for(i=0; i< numPegs; i++) {
				if(pegs[i].size() == 0) {
					pegs[i].push_back(num);
					isPlaced = true;
					break;
				}
				else if( isSquare(pegs[i][pegs[i].size()-1] + num) ) {
					pegs[i].push_back(num);
					isPlaced = true;
					break;
				}
			}
			if(isPlaced == false) break;
		}
		cout << num-1 << "\n";
		
		for(i=0; i<50; i++) pegs[i].clear();

	}

	return 0;
}