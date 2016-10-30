#include <iostream>
#include <stdio.h>
#include <math.h>
//#include <conio.h>
#include <vector>

using namespace std;

unsigned long prime[7000];
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

	for(num = 4; num <=47000; num++) {
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


vector<unsigned long> PRIME_FACT(unsigned long num)
{
	vector<unsigned long> factor;
	int ele=0;
	
	for( ; Is_prime(num) != 1;) {
			if(num % prime[ele] == 0) {
				num /= prime[ele];
				factor.push_back(prime[ele]);
			}
			else 
				ele++;
	}

	factor.push_back(num);

	return factor;
}


unsigned long FREQ_OF_PRIME(unsigned long prime, unsigned long fact)
{
	unsigned long count=0;
	unsigned long temp=fact;
	int i, j;


	for(i=1; ; i++) {
		temp = fact;
		for(j=1; j<=i; j++) {
			temp /= prime;
		}
		if(temp == 0) break;
		else	count += temp;
	}

	return count;
}


int main()
{
	PRIME_NUM_GENERATOR();

	unsigned long temp, num, fact, M;
	unsigned long i, ele=0, j;
	unsigned long freq, prime;
	vector<unsigned long> factor;
	bool divisible = true;
	
//	cout << FREQ_OF_PRIME(2, 1073741824);

	
	while(scanf("%ld %ld", &fact, &M) != EOF) {
		divisible = true;

		if(M == 0) {
			printf("%ld does not divide %ld!\n", M, fact);
			continue;
		}
		else if( M == 1) {
			printf("%ld divides %ld!\n", M, fact);
			continue;
		}


	factor = PRIME_FACT(M);

	if(factor[factor.size()-1] > fact)
		divisible = false;
	else {
		prime = factor[0];
		
		freq=0;
		for(j=0; j<factor.size(); j++) {
			if(prime == factor[j])
				freq++;
			else {
				if(freq > FREQ_OF_PRIME(prime, fact)) {
					divisible = false;
					break;
				}

				prime = factor[j--];
			//	cout << freq << " ";
	
				freq=0;
			}
		}
		if(freq > FREQ_OF_PRIME(prime, fact))
			divisible = false;
		//cout << freq << " ";

	}
	

//	freq = FREQ_OF_PRIME(3, 20);

//	cout << freq << " ";

		if(divisible == true)
			printf("%ld divides %ld!\n", M, fact);
		else
			printf("%ld does not divide %ld!\n", M, fact);

//		for(i=0; i<factor.size(); i++)
//		cout << factor[i] << " ";
}

//	for(i=0; i<factor.size(); i++)
	//	cout << factor[i] << " ";

 return 0;
}
	
