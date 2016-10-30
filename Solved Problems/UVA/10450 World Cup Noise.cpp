#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

#define ALPHA (1+sqrt(5))/2
#define BETA  (1-sqrt(5))/2


typedef vector<int> VI;
typedef vector<double> VD;


double fib(unsigned int n)
{
	return (pow(ALPHA,(double)n)-pow(BETA,(double)n))/sqrt(5);
}


int main()
{
	int input, TC;
	
	cin >> TC;

	for(int i=1; i<=TC; i++) { 
		cin >> input;
		printf("Scenario #%d:\n%.0lf\n\n",i, fib(input+2));
	}

	return 0;
}