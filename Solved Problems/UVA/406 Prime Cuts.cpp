#include <stdio.h>
#include <math.h>

unsigned long prime[4000];
unsigned long total_prime=2;


int Is_prime(unsigned long num)
{
	unsigned long root = sqrt(num);
	for(int i=0; prime[i] <= root; i++)
		if(!(num % prime[i]))
			return 0;
	return 1;
}

void PRIME_NUM_GENERATOR()
{
	unsigned long num;
	int Is_p, i;
	unsigned long ele = 3;

	prime[1] = 1;
	prime[2] = 2;

	for(num = 3; num <=2000; num++) {
		Is_p = 1;
		for(i =2; prime[i] <= sqrt(num); i++) 
			if(!(num % prime[i])) {
				Is_p = 0;
				break;
			}
		if(Is_p) {
			prime[ele++] = num;
			total_prime++;
		}
	}
}

int main()
{

	unsigned long N=13, C=7;
	int start_index,end_index, temp, j, i;

	PRIME_NUM_GENERATOR();

/*	for(i=1; i<100; i++)
		printf("%ld		", prime[i]);
	printf("\n%ld		", total_prime);*/

	while(scanf("%ld %ld", &N, &C) != EOF) {	
	
		for(i=1; prime[i] <= N; i++)
			;
		i--;

		temp = (!(i%2)) ? temp = C*2 : temp = C*2 -1;
		printf("%ld %ld:", N, C);

		if(temp >=i) {
			for(int j =1; j<=i; j++)
				printf(" %ld", prime[j]);
		}
		else {
			start_index = (i-temp)/2 + 1;
			end_index = start_index + temp;

			for(j=start_index; j<end_index; j++)
				printf(" %ld", prime[j]);
		}
		printf("\n\n");
	}
			 
return 0;
}