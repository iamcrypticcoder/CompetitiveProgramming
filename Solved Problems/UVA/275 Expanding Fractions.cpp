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


	while(scanf("%d %d", &dividend, &dividor) && dividor != 0) {

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

		printf(".");
	if(reminder == 0) {
		for(x=1, length=2; x<t; x++, length++) {
			printf("%d", q[x]);
			if(length == 1) {
				printf("\n");
				length = 0;
			}
		}
		if(length > 50)
			printf("This expansion terminates.\n\n");
		else
			printf("\nThis expansion terminates.\n\n");

	}
	else {
		for(x=1, length = 2; x<start_index; x++, length++) {
			printf("%d", q[x]);
				if(length == 50) {
					length = 0;
					printf("\n");
				}
		}
	
		for(x=start_index, rep_len=1; x<=end_index; x++, length++, rep_len++) {
				printf("%d", q[x]);
				if(length == 50) {
					length = 0;
					printf("\n");
				}
		}
		if(length == 1)
			printf("The last %d digits repeat forever.\n\n", rep_len-1);
		else
			printf("\nThe last %d digits repeat forever.\n\n", rep_len-1);
	}

	}

return 0;
}