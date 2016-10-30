#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

struct X {
	char ch;
	int freq;
};


unsigned long prime[4000];
unsigned long total_prime=2;

int Is_prime(unsigned long num)
{
	unsigned long root = sqrt(num);
	if(num == 1) return 0;
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

	for(num = 4; num <=3500; num++) {
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
	int t_case, Is_empty;
	char input[2002];
	struct X done[62];
	struct X prime_freq_set[62];
	unsigned long ele=0, i, j, k, p=0, Is_done;
	unsigned long freq = 0;

	PRIME_NUM_GENERATOR();


	cin >> t_case;

	for(k=1; k<=t_case && cin >> input; k++) {
	p=0;
	ele =0;
	freq = 0;
	Is_empty = 1;

	for(i=0; i<strlen(input); i++) {
		Is_done = 0;
		freq = 0;
		for(j=0; j<ele; j++)
			if(input[i] == done[j].ch) {
				Is_done = 1;
				break;
			}

		if(Is_done == 0) {
			for(j=i; j<strlen(input); j++)
				if(input[i] == input[j])
					freq++;
			done[ele].ch = input[i];
			done[ele++].freq = freq;
			if(Is_prime(freq)) {
				prime_freq_set[p].ch = input[i];
				prime_freq_set[p++].freq = freq;
				Is_empty = 0;
			}


		}
	}

	register int a, b;
	char temp_ch;
	int temp_int;

	for(a=1; a <p; ++a) {
		temp_ch = prime_freq_set[a].ch;
		for(b=a-1; (b >=0) && (temp_ch < prime_freq_set[b].ch); b--) {
			prime_freq_set[b+1].ch = prime_freq_set[b].ch;
		}
		prime_freq_set[b+1].ch = temp_ch;
	}

	printf("Case %d: ", k);
	if(Is_empty) cout << "empty\n";
	else {
		for(i=0; i<p;i++)
			printf("%c", prime_freq_set[i].ch);
		printf("\n");
	}

	}


//getch();
return 0;
}

// -----------------------------------------------------------------------------
// New Solution

#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

#define MAX_PRIME 1000001
typedef vector<int> VI;
bool Flag[MAX_PRIME];
class MPrime {
public:
	VI Prime;
	MPrime();
	void Sieve();
	bool IsPrime(int num);
	VI Factorize(int num);
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

bool MPrime::IsPrime(int num)
{
	if(num == 1 || num == 0) return 0;
	if(num <= MAX_PRIME) return (!Flag[num]);
	int root = sqrt((double)num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

void MPrime::PrintPrime() {
	int i;
	printf("Total prime numbers between 1 and 1000000 is: %d\n",Prime.size());
	for(i = 0; i<Prime.size(); i++) { // printing 1st 100 primes
		printf("%d ",Prime[i]);
	}
	puts("");
}

int table[123];


int main() 
{
	MPrime P;

	int tc, TC;
	int i, j;

	string mainStr;
	bool is_Empty;

	cin >> TC;

	for(tc=1; tc<=TC; tc++) 
	{
		memset(table, 0, sizeof(table));

		cin >> mainStr;
		
		for(i=0; i<mainStr.size(); i++)
			table[mainStr[i]] += 1;
		
		cout << "Case " << tc <<": ";
		is_Empty = true;

		for(i=1; i<= 122; i++) 
			if(P.IsPrime(table[i])) {
				cout << (char)i;
				is_Empty = false;
			}
		if(is_Empty)
			cout << "empty\n";
		else 
			cout << "\n";
	}

	return 0;
}
