                    My First Solution when I was a little
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

long prime[5000];
long total_prime=2;

int Is_prime(long num)
{
	long root = sqrt(num);
	for(int i=0; prime[i] <= root; i++)
		if(!(num % prime[i]))
			return 0;
	return 1;
}


void PRIME_NUM_GENERATOR()
{
	long num;
	int Is_p, i;
	long ele = 2;

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



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);    
 long num;
 long prm;
 long temp;
 long prime_fact[31];

 int ele, i;
 PRIME_NUM_GENERATOR();

 //printf("%ld", prime[4500]);


 while(cin >> num && num != 0) {
	 cout << num << " = ";
	 if(num < 0){
		 cout << "-1 x ";
		 num *= -1;
	 }
	ele = 0;
	if(Is_prime(num) == 1)
		prime_fact[ele] = num;
//	temp = sqrt(num);
	for(prm=0; prime[prm] <= sqrt(num); ) {
		if(!(num%prime[prm])) {
		num = num / prime[prm];
		//cout << prime[prm];
		prime_fact[ele++] = prime[prm];
	}
		else 
			prm++;
	}
	
	if(Is_prime(num) == 1)
		prime_fact[ele++] = num;

	for(i=0; i<ele-1; i++)
		cout << prime_fact[i] << " x ";
	cout << prime_fact[i] << endl;

 }

return 0;
}



/*
#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAX_PRIME 1000101
typedef vector<int> VI;
bool Flag[MAX_PRIME];

struct powerPrime {
	int p, a;					// Every powerPrime is in the form p^a
};								// That is A number is represented in this form --  p1^a1 * p2^a2 * p3^a3

class MPrime {
public:
	VI Prime;
	MPrime();
	void Sieve();
	bool IsPrime(long long num);
	VI Factorize(long long num);
	vector<powerPrime> FactorizeAsPower(long long num);
	void PrintPrime();
};

MPrime::MPrime()
{
	Sieve();
}

void MPrime::Sieve() {
	int i, j;
	for(i = 2; i*i<=MAX_PRIME;) {
		for(j = i+i; j<=MAX_PRIME; j+= i) 
			Flag[j] = 1;
		for(++i; Flag[i]; i++);
	}
	Prime.push_back(2);
	for(i = 3; i<MAX_PRIME; i += 2)  // i+=2 ?? there is no consecutive prime except 2,3
		if(Flag[i] == 0) 
			Prime.push_back(i);
}

bool MPrime::IsPrime(long long num)
{
	if(num == 1 || num == 0) return 0;
	if(num <= MAX_PRIME) return (!Flag[num]);
	int root = sqrt((double)num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

vector<int> MPrime::Factorize(long long num)
{
	vector<int> F;
	
	if(IsPrime(num)) {
		F.push_back(num);
		return F;
	}

	for(int i=0; ; i++) {
		if( !(num % Prime[i])) {
			while(!(num % Prime[i])) {
				num /= Prime[i];
				F.push_back(Prime[i]);
			}
			if(IsPrime(num) || num == 1) break;
		}
	}
	
	if(IsPrime(num)) F.push_back(num);

	return F;
}

// Dont input 1 in this function. It will crash.
vector<powerPrime> MPrime::FactorizeAsPower(long long num)
{
	vector<powerPrime> F;
	powerPrime powP;
	long long power;
	
	if(IsPrime(num)) {
		powP.p = num;
		powP.a = 1;
		F.push_back(powP);
		return F;
	}

	for(int i=0; ; i++) 
		if( !(num % Prime[i]) ) {
			power = 0;
			while(!(num % Prime[i])) {
				num /= Prime[i];
				power++;
			}
			powP.p = Prime[i];
			powP.a = power;
			F.push_back(powP);

			if(IsPrime(num) || num == 1) break;
		}
		
	if(IsPrime(num)) {
		powP.p = num;
		powP.a = 1;
		F.push_back(powP);
	}
	return F;
}

void MPrime::PrintPrime() {
	int i;
	printf("Total prime numbers between 1 and 1000000 is: %d\n",Prime.size());
	for(i = 0; i<Prime.size(); i++) { // printing 1st 100 primes
		printf("%d ",Prime[i]);
	}
	puts("");
}

int main()
{
	MPrime P;					// 10^6

	int input, temp;

	while(cin >> input)
	{	
		if(input == 0) break;
		
		temp = abs(input);

		VI fact = P.Factorize(temp);

		cout << input << " =";

		if(input < 0) {
			cout << " -1 ";

			for(int i=0; i<fact.size(); i++) {
				cout << "x " << fact[i];
				if(i != fact.size()-1) cout << " ";
			}
		}
		else {
			cout << " " << fact[0] << " ";
			for(int i=1; i<fact.size(); i++) {
				cout << "x " << fact[i];
				if(i != fact.size()-1) cout << " ";
			}			
		}
		cout << "\n";

	
	}

	return 0;
}
*/
