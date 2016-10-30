#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

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
	unsigned long ele = 2;

	prime[0] = 2;
	prime[1] = 3;

	for(num = 4; num <=35000; num++) {
		Is_p = 1;
		for(i =0; prime[i] <= sqrt(num); i++) 
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

unsigned long Calc_divisor(unsigned long num)
{
	unsigned long count=0;
	unsigned long ele=0, divisor = 1;
	
	if(num == 1) return 1;
	
	for( ; Is_prime(num) != 1;) {
		
		if(num % prime[ele] == 0) {
			num /= prime[ele];
			count++;
		}
		else {
			ele++;
			divisor = divisor * (count + 1);
			count=0;
		}
	}
	if(num == prime[ele])
		divisor *= count+2;
	else {
		divisor *= count+1;
		divisor *= 2;
	}

return divisor; 
}


int main()
{
	unsigned long temp;
	unsigned long t_case, max_divisor, max_dividend;
	unsigned long lower[20], higher[20], divisor[20];
	unsigned long i, j;
	int k;

	PRIME_NUM_GENERATOR();
	scanf("%ld", &t_case);

	for(k=0; k< t_case; k++)
				scanf("%ld %ld", &lower[k], &higher[k]);

	for(k = 0; k< t_case;  k++) {
		//scanf("%ld %ld", &lower[k], &higher[k]);
		max_divisor = 0;
		max_dividend = 0;

		for(i = lower[k]; i<=higher[k]; i++) {
			temp = Calc_divisor(i);
			if(temp > max_divisor) {
				max_divisor = temp;
				max_dividend = i;
			}
		}
		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n", lower[k], higher[k], max_dividend, max_divisor);
	}


 return 0;
}
	
