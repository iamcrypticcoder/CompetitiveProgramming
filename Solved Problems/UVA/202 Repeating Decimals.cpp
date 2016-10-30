#include <iostream>
#include <stdio.h>

int Sequential_Search(int *items, int count, int key)
{	
	register int t;

	for(t=0; t<count; t++)
		if(key == items[t]) return 1;
	return 0;
}

int main()
{
	int dividend = 1, dividor = 397, reminder, integer_part;
	int i, j, k, l, x, t, Is_decimal_used=0;
	int q[3000], r[3000];
	int start_index, end_index, length, rep_len;


	while(scanf("%d %d", &dividend, &dividor) != EOF) {

	integer_part = dividend / dividor;
	reminder = dividend % dividor;

	t=0;		q[0] = dividor+1;		r[0] = reminder;		t=1;
	for( ;reminder != 0 ;) {
		Is_decimal_used = 0;	

		while( reminder < dividor) {
			if(Is_decimal_used == 0) {
				reminder *= 10;
				Is_decimal_used = 1;
			}
			else {
				reminder *= 10;
				q[t] = 0;
				r[t] = dividor+1;
				t++;
			}
		}
		q[t] = reminder / dividor;
		r[t] = reminder % dividor;

		reminder %= dividor;

		if(Sequential_Search(r, t, r[t]) == 1) 
			break;
		
		t++;
	}

	if(reminder != 0) {
		for(j=0; j<t; j++)
			if(r[j] == r[t]) {
				start_index = j+1;
				break;
			}
		end_index = t;


		
		for( ; q[start_index-1] == q[end_index]; ) {
			start_index--;
			end_index--;
		}
	}

// Display Here ////////////////////////////////////////////	

//	printf("%d ", q[t]);
//	printf("%d ", r[end_index]);
	
	printf("%d/%d = %d.", dividend, dividor, integer_part);

	if(reminder == 0) {
		for(x=1; x<t; x++)
			printf("%d", q[x]);
		printf("(0)");
		printf("\n   1 = number of digits in repeating cycle\n\n");
	}
	

	else {
		for(x=1, length = 1; x<start_index; x++, length++)
			printf("%d", q[x]);

		printf("(");
	
		for(x=start_index, rep_len=1; x<=end_index; x++, length++, rep_len++)
			if(length <=50)
				printf("%d", q[x]);
		length <=50 ? printf(")") : printf("...)");
		printf("\n   %d = number of digits in repeating cycle\n\n", rep_len-1);

	}


	}

return 0;
}