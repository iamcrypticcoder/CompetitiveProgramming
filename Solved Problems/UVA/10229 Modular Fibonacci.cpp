#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;

int N, M;
VI mod;
int range, dividor;

void setrange(int M)
{
	range = 3; dividor = 2;
	for(int i=1; i<M; i++) {
		range = range << 1;
		dividor = dividor << 1;
	}
}

void initMOD()
{
	if(!mod.empty()) mod.clear();

	mod.push_back(1);		mod.push_back(1);
		
	for(int i=2; i<range; i++)
		mod.push_back((mod[i-1]+mod[i-2])%dividor);
}

int main()
{
	int nth;
	
	while(cin >> N >> M) {
		if(N == 0 || M == 0) {
			cout << "0\n";
			continue;
		}
		setrange(M);
		initMOD();
		nth = (N-1)%range;
		cout << mod[nth] << "\n";
	}

	return 0;
}