/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 1,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/


#include <iostream>
#include <stdio.h>


using namespace std;

char part1[10], part2[10];

char *table[4][2] = {{"kuti", "10000000"},
										{"lakh", "100000"},
										{"hajar","1000"},
										{"shata","100"}
									};
int two_part = 0;


void PRINT(unsigned long num)
{
	unsigned long i;

	for( ; num >99 && num != 0; ) {
		for(i=0; i<4; i++)
			if(num >= atol(table[i][1])) {
				cout << num/atol(table[i][1]) << " " << table[i][0];
				num = num % atol(table[i][1]);
				if(num || two_part == 1) cout << " ";
				break;
			}
	}

	if(num && two_part == 1)
		cout << num << " ";
	else if(num)
		cout << num; 
}

int main()
{
	char num_str[15];
	int i, j, t_case;

  
	for(t_case = 0; scanf("%s", num_str) != EOF; t_case++) {
		two_part = 0;
		if(atol(num_str) == 0) {
			printf("%4d. %ld\n", t_case+1, atol(num_str));
			continue;
		}



	if(strlen(num_str) > 9) {
		two_part = 1;
		for(i=0; i<strlen(num_str)-7; i++)
			part1[i] = num_str[i];
		part1[i] = NULL;

		for(i=strlen(num_str)-7, j=0; i<strlen(num_str); i++)
			part2[j++] = num_str[i];
		part2[j] = NULL;

		printf("%4d. ", t_case+1);
		PRINT(atol(part1));
		two_part = 0;

		if(atol(part2)) cout << "kuti ";
		else cout << "kuti";
		
		PRINT(atol(part2));
		cout << endl;
	}
	else {
		printf("%4d. ", t_case+1);
		PRINT(atol(num_str));
		cout << endl;
	}	
	
	}
 return 0;
}