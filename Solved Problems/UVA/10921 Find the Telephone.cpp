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


char Determine(char ch)
{
	if(ch <= 'C')	return '2';
	else if(ch <= 'F') return '3';
	else if(ch <= 'I') return '4';
	else if(ch <= 'L') return '5';
	else if(ch <= 'O') return '6';
	else if(ch <= 'S') return '7';
	else if(ch <= 'V') return '8';
	else if(ch <= 'Z') return '9';
}


int main()
{
	char input[31], result[31];
	int ptr;

	int i, j;

	while(cin >> input)
	{
		ptr = 0;
		for(i=0; i<strlen(input); i++) {
			if(input[i] >= 'A' && input[i] <= 'Z')
				result[ptr++] = Determine(input[i]);
			else result[ptr++] = input[i];
		}
		result[ptr] = '\0';

		cout << result << "\n";

	}


	return 0;
}