#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAX_PRIME 1000101


typedef vector<long long> VI;
bool Flag[MAX_PRIME];

struct powerPrime {
	long long p, a;					// Every powerPrime is in the form p^a
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

vector<long long> MPrime::Factorize(long long num)
{
	vector<long long> F;
	for(long long i=0; !(IsPrime(num)) && num != 1; i++) 
		for( ; !(num%Prime[i]) ; ) {
			num /= Prime[i];
			F.push_back(Prime[i]);
		}
	if(IsPrime(num) || (num == 1 && F.size()==0))	F.push_back(num);
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


int main() {
	MPrime P;
	vector<powerPrime> F;
	
	int tc, TC;
	long long l, w, L, W, K, maxdiff;

//	F = P.FactorizeAsPower(1);

//	for(int i=0; i<F.size(); i++) 	
//		cout << F[i].p << "^" << F[i].a << " ";		


	cin >> TC;

//	for(tc=1, K = 1e12-1; K >= 1e11; tc++, K--) {
	for(tc=1; tc <= TC; tc++) {

		cin >> K;
//		K = 999999999967;
//		cout << K << "\n";

		if(P.IsPrime(K) || K == 1) {
			cout << "Case " << tc << ": " << "Impossible\n";
			continue;
		}

		F = P.FactorizeAsPower(K);

		if(F.size() == 1) {
			cout << "Case " << tc << ": " << "Impossible" << "\n";
			continue;
		}

		maxdiff = 0;
		for(int i=0; i<F.size(); i++) {	
//			cout << F[i].p << "^" << F[i].a << " ";		

			l =  K / F[i].p;		w = (long long)pow((double)F[i].p, (double)F[i].a);

			if(l - w > maxdiff) {
				L = l;
				W = w;
				maxdiff = l - w;
			}
		}

		cout << "Case " << tc << ": " << L << " " << W << "\n";

	}

	return 0;
}


// 0.244 second + rank 13;

#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAX_PRIME 1000101

typedef vector<int> VI;

bool Flag[MAX_PRIME];
VI Prime;


void Sieve() {
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

bool IsPrime(long long num)
{
	if(num == 1 || num == 0) return 0;
	if(num <= MAX_PRIME) return (!Flag[num]);
	int root = (int)sqrt((double)num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

void PrintPrime() {
	int i;
	printf("Total prime numbers between 1 and 1000000 is: %d\n",Prime.size());
	for(i = 0; i<Prime.size(); i++) { // printing 1st 100 primes
		printf("%d ",Prime[i]);
	}
	puts("");
}


int main() 
{
	Sieve();

	int tc, TC, totalFactor;
	long long power;
	long long K, l,w, L, W, maxdiff, num;	

	cin >> TC;

//	for(tc=1, K = 1e12-1; K >= 1e11; tc++, K--) {
	for(tc=1; tc <= TC; tc++) {
		cin >> K;	
//		cout << K << "\n";

		if(IsPrime(K) || K == 1) {
			cout << "Case " << tc << ": " << "Impossible\n";
			continue;		
		}

		maxdiff = 0;
		num = K;
		totalFactor = 0;
		for(int i=0; ; i++) 
			if( !(num % Prime[i]) ) {
				power = 0;
				while(!(num % Prime[i])) {
					num /= Prime[i];
					power++;
				}
				l =  K / Prime[i];		w = (long long)pow((double)Prime[i], (double)power);			
				
				if( l - w > maxdiff ) {
					L = l;
					W = w;
					maxdiff = l - w;
				}
				totalFactor++;
				if(IsPrime(num) || num == 1) break;
			}
			
		if(IsPrime(num)) {
			l = K / num;				w = num;
			if(l - w > maxdiff) {
				L = l;
				W = w;
				maxdiff = l - w;
			}
			totalFactor++;
		}

		if(totalFactor < 2) cout << "Case " << tc << ": " << "Impossible\n";
		else cout << "Case " << tc << ": " << L << " " << W << "\n";
	}
	return 0;
}


// 0.224 + rank 12



#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

#define MAX_PRIME 1000101

bool Flag[MAX_PRIME];
//VI Prime;

int Prime[78504 + 1];
int ele = 0;

void Sieve() {
	int i, j;
	for(i = 2; i*i<=MAX_PRIME;) {
		for(j = i+i; j<=MAX_PRIME; j+= i) 
			Flag[j] = 1;
		for(++i; Flag[i]; i++);
	}
//	Prime.push_back(2);
	Prime[ele++] = 2;
	for(i = 3; i<MAX_PRIME; i += 2)  // i+=2 ?? there is no consecutive prime except 2,3
		if(Flag[i] == 0) {
			//Prime.push_back(i);
			Prime[ele++] = i;
		}
}

bool IsPrime(long long num)
{
	if(num == 1 || num == 0) return 0;
	if(num <= MAX_PRIME) return (!Flag[num]);
	int root = (int)sqrt((double)num);
	for(int i=0; Prime[i]<=root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

void PrintPrime() {
	int i;
	printf("Total prime numbers between 1 and 1000000 is: %d\n",ele);
	for(i = 0; i<ele; i++) { // printing 1st 100 primes
		printf("%d ",Prime[i]);
	}
	puts("");
}


int main() 
{
	Sieve();

	int tc, TC, totalFactor;
	long long power;
	long long K, l,w, L, W, maxdiff, num;	

	cin >> TC;

//	for(tc=1, K = 1e12-1; K >= 1e11; tc++, K--) {
	for(tc=1; tc <= TC; tc++) {
		cin >> K;	
//		cout << K << "\n";

		if(IsPrime(K) || K == 1) {
			cout << "Case " << tc << ": " << "Impossible\n";
			continue;		
		}

		maxdiff = 0;
		num = K;
		totalFactor = 0;
		for(int i=0; ; i++) 
			if( !(num % Prime[i]) ) {
				power = 0;
				while(!(num % Prime[i])) {
					num /= Prime[i];
					power++;
				}
				l =  K / Prime[i];		w = (long long)pow((double)Prime[i], (double)power);			
				
				if( l - w > maxdiff ) {
					L = l;
					W = w;
					maxdiff = l - w;
				}
				totalFactor++;
				if(IsPrime(num) || num == 1) break;
			}
			
		if(IsPrime(num)) {
			l = K / num;				w = num;
			if(l - w > maxdiff) {
				L = l;
				W = w;
				maxdiff = l - w;
			}
			totalFactor++;
		}

		if(totalFactor < 2) cout << "Case " << tc << ": " << "Impossible\n";
		else cout << "Case " << tc << ": " << L << " " << W << "\n";
	}
	return 0;
}



// 0.220 + rank list 12