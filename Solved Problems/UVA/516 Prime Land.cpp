/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/


#include<stdio.h>
#include<math.h>
#include<vector>
#include<sstream>
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

int main() {
	MPrime P;

	vector<powerPrime> F;
	
	stringstream ss;
	string line;

	int actualNum, p, a;

	while(getline(cin, line)) {
		if(line == "0") break;

		ss.clear();
		ss.rdbuf()->str(line);

		actualNum = 1;
		while(ss >> p >> a)
			actualNum *= (int)pow((double)p, (double)a);

		F = P.FactorizeAsPower(actualNum-1);

		for(int i=F.size()-1; i > 0; i--)
			cout << F[i].p << " " << F[i].a << " ";

		cout << F[0].p << " " << F[0].a << "\n";
	}


	return 0;
}