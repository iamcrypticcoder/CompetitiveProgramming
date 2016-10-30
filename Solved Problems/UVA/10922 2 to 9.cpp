#include <iostream>
#include <string.h>

using namespace std;

char input[1001];

int main()
{
	int sum, temp, deg;
	int i, j;

	bool isMultiple;

	while(cin >> input) 
	{
		if(strcmp(input, "0") == 0) break;

		sum = temp = deg = 0;
		isMultiple = 0;

		for(i=0; i<strlen(input); i++)
			sum += (input[i] - '0');
		
		if(sum % 9 == 0) {
			isMultiple = 1;
			deg++;
		}

		if(sum != 9 && isMultiple) 
		{
			while(sum != 9) {
				temp = sum;
				sum = 0;
				while(temp) {
					sum += temp%10;
					temp /= 10;
				}
				deg++;
			}
		}

		if(isMultiple)
			cout << input << " is a multiple of 9 and has 9-degree "<< deg << ".\n";
		else 
			cout << input << " is not a multiple of 9.\n";
	}

	return 0;
}