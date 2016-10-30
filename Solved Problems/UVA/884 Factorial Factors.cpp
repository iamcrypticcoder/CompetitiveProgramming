#include<stdio.h>
#include<math.h>
#include<time.h>
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
	bool IsPrime(int num);
	VI Factorize(int num);
	int FactorizeAsPower(int num);
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
int MPrime::FactorizeAsPower(int num)
{
	vector<powerPrime> F;
	powerPrime powP;
	int power;
	
    int ret;

	if(IsPrime(num)) {
		powP.p = num;
		powP.a = 1;
		F.push_back(powP);
		return 1;
	}

	ret =0;
	
	for(int i=0; ; i++) 
		if( !(num % Prime[i]) ) {
			power = 0;
			while(!(num % Prime[i])) {
				num /= Prime[i];
				power++;
			}
             ret += power;
			powP.p = Prime[i];
			powP.a = power;
			F.push_back(powP);

			if(IsPrime(num) || num == 1) break;
		}
		
	if(IsPrime(num)) {
		powP.p = num;
		powP.a = 1;
		F.push_back(powP);
		ret++;
	}
	return ret;
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

/*

int main() {
	MPrime P;
	
	int input;

	int root, ans, temp;

	int i, j, k;

//	while(scanf("%i64", &input) != EOF)
    input = 2;
	while(input <= 1e6)
	{
		root = (int)sqrt((double)input);

		ans = 0;
		for(i=0; ; i++) {
			ans += (temp = FREQ_OF_PRIME(P.Prime[i], input) );
			if(temp < 2) {
				i++;
				break;
			}
		}

		while(P.Prime[i] <= input) {
			ans++; i++;
		}

		cout << ans << "\n";

        input++;
	}

   return 0;
}


*/

int DP[1000001];
   MPrime P;

void Process()
{
   int i, j, k;

   DP[2] = 1;


   vector<int> F;

   for(i=3; i<=1e6; i++)
   {
	   if(P.IsPrime(i)) {
		  DP[i] = DP[i-1] + 1;   
	      continue;
	   }
       
	   DP[i] = DP[i-1] + P.FactorizeAsPower(i);;

   }


}


int main()
{
	
	int input;

	int root, ans, temp;

	int i, j, k;

//	time_t start = time(NULL);
    Process();

//	time_t end = time(NULL);

//	cout << (double)(end - start);
	
	while(scanf("%d", &input) != EOF)
	{
        
		
		cout << DP[input] << "\n";

        input++;
	}

   return 0;

}
