#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

unsigned long prime[6000];
unsigned long total_prime=2;


bool Is_prime(unsigned long num)
{
	if(num == 1) return 0;
	unsigned long root = sqrt(num);
	for(int i=0; prime[i] <= root; i++)
		if(!(num % prime[i]))
			return 0;
	return 1;
}

void PRIME_NUM_GENERATOR()
{
	unsigned long num, root;
	int Is_p, i;
	unsigned long ele = 2;

	prime[0] = 2;
	prime[1] = 3;

	for(num = 4; num <=50000; num++) {
		if(Is_prime(num)) 
			prime[ele++] = num;
	}
	total_prime = ele;
}



int main()
{
	unsigned long temp, L, U, i, j ,k, l, min, max, min_i, max_i;
	vector<unsigned long> v;

	PRIME_NUM_GENERATOR();

	while(cin >> L >> U) {
		v.clear();
		for(i = L; i<=U; i++)
			if(Is_prime(i))
				v.push_back(i);

		if(v.size() == 1) {
			cout << "There are no adjacent primes.\n";
			continue;
		}

		min = v[1] - v[0];
		max = v[1] - v[0];
		min_i = max_i = 0;
		
		for(i=1; i<v.size()-1; i++) {
			if(v[i+1] - v[i] < min) {
				min_i = i;
				min = v[i+1] - v[i];
			}
			if(v[i+1] - v[i] > max) {
				max_i = i;
				max = v[i+1] - v[i];
			}
		}

		cout << v[min_i] << "," << v[min_i+1] << " are closest, ";
		cout << v[max_i] << "," << v[max_i+1] << " are most distant.\n";
			//if()
	}
//	for(temp = 0; temp < total_prime; temp++)
//		cout << prime[temp] << "\n";

 return 0;
}
	
