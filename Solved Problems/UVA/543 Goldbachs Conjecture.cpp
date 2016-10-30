#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAX_PRIME 1000000
typedef vector<int> VI;
bool Flag[MAX_PRIME];
class MPrime {
public:
	VI Prime;
	int TotalPrime;

	MPrime();
	void Sieve();
	bool IsPrime(int num);
	VI Factorize(int num);
	void PrintPrime();
};

MPrime::MPrime()
{
	Sieve();
	TotalPrime = Prime.size();
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
	if(num == 1) return 0;
	if(num <= MAX_PRIME) return (!Flag[num]);
	int root = sqrt(num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

vector<int> MPrime::Factorize(int num)
{
	vector<int> F;
	for(int i=0; !(IsPrime(num)) && num != 1; i++) 
		for( ; !(num%Prime[i]) ; ) {
			num /= Prime[i];
			F.push_back(Prime[i]);
		}
	if(IsPrime(num) || (num == 1 && F.size()==0))	F.push_back(num);
	return F;
}

void MPrime::PrintPrime() {
	int i;
	printf("Total prime numbers between 1 and 1000000 is: %d\n",Prime.size());
	for(i = 0; i<1000; i++) { // printing 1st 100 primes
		printf("%d ",Prime[i]);
	}
	puts("");
}

int main() {
	MPrime P;
	int num;

//	P.PrintPrime();
//	cout << P.Prime[10];
	while(cin >> num && num != 0) {
//	for(num=224662; num<=1000000; num+=2) {
		for(int i = 0; i<P.TotalPrime; i++) {
			if(P.IsPrime(num-P.Prime[i])) {
				cout << num << " = ";
				cout << P.Prime[i] << " + " << num-P.Prime[i] << "\n";
				break;
			}
		}
	}
return 0;
}
