/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 1,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/

#include <iostream>
#include <cstring>

using namespace std;


char table[100] = "`1234567890-=	QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	char input[100];
	int i, j;
	int Is_Capital;

	
	
	while(gets(input)) {

	for(i=0; i<strlen(input); i++) {
		if(input[i] == ' ') { cout << input[i]; continue; }
		
		for(j=0;j<47; j++) 
			if(input[i] == table[j]) {
			cout << table[j-1];
				break;
			}
	}
	cout << "\n";
	}
		



return 0;
}