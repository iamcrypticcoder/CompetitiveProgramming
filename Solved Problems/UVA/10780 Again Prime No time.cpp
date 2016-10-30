#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

#define INF 99999999

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
	bool IsPrime(int num);
	VI Factorize(int num);
	vector<powerPrime> FactorizeAsPower(int num);
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

vector<powerPrime> MPrime::FactorizeAsPower(int num)
{
	vector<powerPrime> F;
	powerPrime powP;
	int power;
	
	int i;
	for( i=0; !(IsPrime(num)) && num != 1; i++ ) {
		power = 0;
		for( ; !(num%Prime[i]) ; ) {
			num /= Prime[i];
			power++;
		}
		if(power > 0) {
			powP.p = Prime[i];
			powP.a = power;
			F.push_back(powP);
		}
	}
	if(IsPrime(num) || (num == 1 && F.size()==0)) {
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
	
	int i, j, k;
	int TC, tc;
	int m ,n;
	int ans, freq;
	vector<powerPrime> F;
	
	cin >> TC;

	for(tc=1; tc<=TC; tc++) {
		cin >> m >> n;

		F = P.FactorizeAsPower(m);

		ans = INF;
		for(i=0; i<F.size(); i++) {
			freq = FREQ_OF_PRIME(F[i].p, n);
			ans = min(ans, freq/F[i].a);
		}

//		for(i=0; P.Prime[i] <= n; i++)
//			cout << totalPrime[P.Prime[i]] << " ";
		cout << "Case " << tc << ":\n";
		
		if(ans == 0)
			cout << "Impossible to divide\n";
		else 
			cout << ans << "\n";
	}

	return 0;
}
