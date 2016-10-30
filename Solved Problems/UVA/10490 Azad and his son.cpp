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
typedef vector<double> VD;
typedef vector<string> VS;


bool isPrime(int num)
{
	int root = (int)sqrt((double)num);
	int i;

	FOR(i, 2, root)
		if(num % i == 0)
			return 0;
	return 1;

}

bool ans[32];

int main()
{
	long long numUsingFormula, input, temp;
	
	ans[2] = ans[3] = ans[5] = ans[7] = ans[13] = ans[17] = ans[19] = ans[31] = true;
	
	while(cin >> input && input != 0)
	{
		if(isPrime(input)==0)
			cout << "Given number is NOT prime! NO perfect number is available.\n";
		else if(isPrime(input)) {
			if(ans[input] == true) {
				numUsingFormula = (1 << (input-1));
				numUsingFormula *= ( (1 << input) - 1 );
				cout << "Perfect: " << numUsingFormula << "!\n"; 
			}
			else cout << "Given number is prime. But, NO perfect number is available.\n";
		}
	}


	return 0;
}