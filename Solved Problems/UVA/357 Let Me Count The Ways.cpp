// I GOT	2 WRONG ANSWER ONLY FOR SPELLING MISTAKES.

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

#define MAXTOTAL 30000

int coin[5] = { 50,25,10,5,1 };
long long nway[MAXTOTAL+1];

int main()
{
	int i,j,n,v,c;
	while(cin >> n) {
		memset(nway, 0, sizeof(nway));
		v = 5;
		nway[0] = 1;
		for (i=0; i<v; i++) {
			c = coin[i];
			for (j=c; j<=n; j++)
				nway[j] += nway[j-c];	
		}
		if(nway[n] == 1) cout << "There is only " << nway[n] << " way to produce " << n << " cents change.\n";
		else {
			cout << "There are "; 
			cout << nway[n];
			//	show(nway[n]);
			cout << " ways to produce " << n << " cents change.";
			cout << "\n";
		}
	}
	return 0;
}
