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


// This function tells us how many prime P we will get after factorizing N!.
int FREQ_OF_PRIME(int prime, int fact)
{
	int count=0;
	int temp=fact;
	int i, j;

	for(i=1; ; i++) {
		temp = fact / (double)pow((double)prime, (double)i);

		if(temp == 0) break;
		else	count += temp;
	}
	return count;
}

#define FOR( i, L, U ) for( i=L ; i<=U ; i++ )

int main() {
	MPrime P;

	int TC, tc;
	int n, temp;
	int length, tempSum, Sum, lowerIndex, upperIndex, finalLength;
	bool isFound;

	VI seq;

	int i, j, k;

	cin >> TC;

	while(TC--) 
	{
		cin >> n;

		seq = VI(n);

		FOR(i, 0, n-1) {
			cin >> seq[i];
		}

		isFound = false;

		for(length=2; length<=n; length++) {
			FOR(i, 0, n-length) {
				tempSum = 0;

				FOR(j, i, i + length -1)
					tempSum += seq[j];

				if(P.IsPrime(tempSum)) {
					finalLength = length;
					lowerIndex = i;
					upperIndex = i + length -1;
					isFound = true;
				}
				if(isFound) break;
			}
			if(isFound) break;
		}
			
		if(isFound) {
			cout << "Shortest primed subsequence is length " << finalLength << ":";

			FOR(i, lowerIndex, upperIndex)
				cout << " " << seq[i];
			cout << "\n";
		}
		else cout << "This sequence is anti-primed.\n";
			

	}


   return 0;
}
