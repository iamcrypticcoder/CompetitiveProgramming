

#include <iostream>
#include <math.h>
#include <stdio.h>

#define EPS 1e-11

using namespace std;

unsigned long prime[4000];
unsigned long total_prime=2;

int Is_prime(unsigned long num)
{
	unsigned long root = sqrt((double)num);
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

	for(num = 4; num <=20000; num++) {
		Is_p = 1;
		for(i =0; prime[i] <= sqrt((double)num); i++)
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

char rem[10001];

int main()
{
	unsigned long a, b, i;
	double actual_prime, gen_prime;

	PRIME_NUM_GENERATOR();

	while(scanf("%ld %ld", &a, &b) == 2) {
		actual_prime = gen_prime = 0;

		for(i=a; i<=b; i++) {
			if(rem[i] == 1)
				actual_prime++;
			else if(rem[i] == 2) continue;

			else {
				if(Is_prime(i*i+i+41))	{	actual_prime++;	rem[i] = 1;	}
				else rem[i] = 2;
			}
		}
				printf("%.2lf\n", ((actual_prime/(b-a+1)) * 100)+EPS);
	}

return 0;
}



/*
 * UVa 10200 (AC)
 * Author: chchwy
 * Last Modified: 2009.11.22
 
 #include<iostream>
 using namespace std;
 
 bool isPrime(int p){
 if(p%2==0)
 return false;
 
 for(int i=3;i*i<=p;i+=2)
 if(p%i==0)
 return false;
 return true;
 }
 
 char p[10000]; //0??1??2???
 
 int main(){
 
	int a,b;
	while(scanf("%d %d",&a,&b)==2){

		int counter=0;
		for(int i=a;i<=b;++i){
			//look for table first
			if(p[i]==1){
			counter++;
			}
			else if(p[i]==2)
			{
				continue;
			}
			else
			{ 
				int num = i*i + i + 41;
				if( isPrime(num) )
				{
					counter++;
					p[i]=1;
				}
				else
				{
					p[i]=2;
				}
		}
	}
	double result =  (double)counter/(b-a+1)*100 ;
	printf("%.2lf\n", result+0.00000005);
	}
 return 0;
 } 
*/