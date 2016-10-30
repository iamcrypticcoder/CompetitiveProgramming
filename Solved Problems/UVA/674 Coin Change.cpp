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

#define MAXTOTAL 10000
long long nway[MAXTOTAL+1];
int coin[5] = { 50,25,10,5,1 };

void Init()
{
	int i;
	for(i=0; i<=MAXTOTAL; i++)
		nway[i] = 0;

}

int main()
{
	int i,j,n,v,c;
	while(cin >> n) {
	Init();
	v = 5;
	nway[0] = 1;
	for (i=0; i<v; i++) {
		c = coin[i];
		for (j=c; j<=n; j++)
			nway[j] += nway[j-c];	
	}
	printf("%lld\n",nway[n]);
	}
	return 0;
}