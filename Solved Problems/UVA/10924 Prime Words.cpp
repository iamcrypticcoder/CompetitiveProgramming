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


bool isPrime(int num)
{
	int root = (int) sqrt((double)num);
	
	for(int i=2; i<=root; i++)
		if(num % i == 0)
			return 0;
	return 1;
}

int main()
{
	char input[21];
	int value = 0;

	while(cin >> input)
	{
		value=0;
		for(int i=0;  i < strlen(input); i++) {
			if(input[i] >= 'a' && input[i] <= 'z')
				value += (input[i] - 'a' + 1);
			else if(input[i] >= 'A' && input[i] <= 'Z')
				value += (input[i] - 'A' + 27);
		}

		if(isPrime(value))
			cout << "It is a prime word.\n";
		else 
			cout << "It is not a prime word.\n";


	}


	return 0;
}