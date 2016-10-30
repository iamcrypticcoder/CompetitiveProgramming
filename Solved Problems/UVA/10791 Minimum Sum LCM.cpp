#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAX_PRIME 1000001
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
int main() {
	 
	 MPrime P;
	 vector<powerPrime> F;
	 
	 int N;
	 int sum;
	 int tc;


	 for(tc=1 ; ; tc++)
	 {
		  cin >> N;
		  if(N == 0) break;
		  if(N == 1) {
				cout << "Case " << tc << ": ";
			  cout << 2 << "\n";
			  continue;
		  }
		  if(N == 2147483647) {
				cout << "Case " << tc << ": ";
			  cout << "2147483648" << "\n";
			  continue;
		  }
		  F = P.FactorizeAsPower(N);
	
		  sum = 0;
		  for(int i=0; i<F.size(); i++) {	
//	 		  cout << F[i].p << "^" << F[i].a << " ";	
			  sum += (int)pow((double)F[i].p, (double)F[i].a);					
		  }

		  if(F.size() == 1) sum += 1;

		  cout << "Case " << tc << ": ";
		  if(P.IsPrime(N)) 
				cout << N+1 << "\n";
		  else {
				cout << sum << "\n";

		  }

	 }
	 return 0;
}
