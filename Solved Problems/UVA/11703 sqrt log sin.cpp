//11703  	sqrt log sin

#include <iostream>
#include <cmath>

using namespace std;

unsigned long X[1000000];

void Process()
{
	unsigned long i;
	
	X[0] = 1;

	for(i=1; i<=1000000; i++)
		X[i] = (X[(long)floor(i-sqrt(i))] + X[(long)floor(log(i))] + X[(long)floor(i * sin(i) * sin(i))]) % 1000000;

}

int main()
{
	long I;

	Process();

	while(cin >> I && I > -1) {
		//if(I < 0) break;
		cout << X[I] << endl;
	//	printf("%lf", X[I]);
	}
return 0;
}