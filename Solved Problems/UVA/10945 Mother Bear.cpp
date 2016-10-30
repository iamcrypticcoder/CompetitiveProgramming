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



int main()
{
	char input[10001];
	char str[10001];
	int ptr, beg, end, mid, len;
	bool isPalindrome;

	int i;

	while(gets(input)) {
		
		if(strcmp(input, "DONE") == 0) break;

		for(i=0, ptr = 0; i<strlen(input); i++)
			if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
				str[ptr++] = tolower(input[i]);
		str[ptr] = '\0';

//		cout << input << endl;
//		cout << str << endl;

		beg = 0;
		len = strlen(str);
		end = strlen(str)-1;

		if(len % 2)
			mid = len/2 - 1;
		else 
			mid = len/2;
			
		isPalindrome = true;
		for(i=0; i<= mid; i++, beg++, end--) {
			if(str[beg] != str[end])
				isPalindrome = false;
		}

		if(isPalindrome)
			cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";

	
	}

	return 0;
}