#include <iostream>
//#include <conio.h>

using namespace std;

char set[21][2] = {
			{'A','A'},
			{'E', '3'},
			{'H', 'H'},
			{'I', 'I'},
			{'J', 'L'},
			{'M', 'M'},
			{'O', 'O'},
			{'S', '2'},
			{'T', 'T'},
			{'U', 'U'},
			{'V', 'V'},
			{'W', 'W'},
			{'X', 'X'},
			{'Y', 'Y'},
			{'Z', '5'},
			{'1', '1'},
			{'8', '8'},
};


char MIRROR(char ch)
{
	int i, j;

	for(i=0; i<17; i++) {
		if(ch == set[i][0])
			return set[i][1];
		else if(ch == set[i][1])
			return set[i][0];
	}
	return '0';
}


bool IS_PALINDROME(char str[])
{
	char temp[20];
	int i, j=0;

	for(i= strlen(str)-1; i>=0; i--)
		temp[j++] = str[i];

	temp[j] = '\0';

	if(strcmp(temp, str) == 0)
		return true;
	else 
		return false;
}

bool IS_MIRRORED(char str[])
{
	char temp[20];
	int i, j=0;

	for(i=strlen(str)-1; i>=0; i--)
		temp[j++] = MIRROR(str[i]);
	
	temp[j] = '\0';

	if(strcmp(temp, str) == 0)
		return true;
	else 
		return false;
}


int main()
{
	bool P, M;
	char string[50];


	while(gets(string)) {

	P = IS_PALINDROME(string);
	M = IS_MIRRORED(string);

	if(P  && M)
		cout << string <<" -- is a mirrored palindrome.\n\n";
	else if(P)
		cout << string << " -- is a regular palindrome.\n\n";
	else if(M)
		cout << string <<  " -- is a mirrored string.\n\n";
	else 
		cout << string <<  " -- is not a palindrome.\n\n";
	}

//	cout << IS_MIRRORED("2A3MEAS");
	
//	cout << MIRROR('A');
return 0;
}