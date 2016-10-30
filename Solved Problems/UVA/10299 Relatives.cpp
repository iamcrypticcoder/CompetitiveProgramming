#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

#define MAX 1000000

typedef vector<int> VI;


VI Prime;
bool Flag[MAX];

void Sieve() {
	int i, j;
	for(i = 2; i*i<=MAX;) {
		for(j = i+i; j<=MAX; j+= i)
			Flag[j] = 1;

		for(++i; Flag[i]; i++);
	}
	Prime.push_back(2);
	for(i = 3; i<MAX; i += 2)  // i+=2 ?? there is no consecutive prime except 2,3
		if(Flag[i] == 0)
			Prime.push_back(i);
}

bool IsPrime(int num)
{
	if(num == 1) return 0;
	if(num <= MAX) return (!Flag[num]);
	int root = sqrt(num);
	for(int i=0; Prime[i]<root; i++)
		if(num % Prime[i] == 0)
			return 0;
	return 1;
}

void PrintPrime() {
	int i;
	printf("Total prime numbers between 1 and 1000000 is: %d\n",Prime.size());
	for(i = 0; i<1000; i++) { // printing 1st 100 primes
		printf("%d ",Prime[i]);
	}
	puts("");
}

// Accepted Code
int fi(int n)
	{
		if(n==1) return 0;
       int result = n;
       for(int i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }

// Accepted Code
double fi2(int n)
{
	if(n==1) return 0;
	double result = n;

	for(int i=2;i*i <= n;i++) {
    if (n % i == 0) result *= (1 - 1/(double)i);
    while (n % i == 0) n /= i;
  }
	if(n > 1) result *= (1 - 1/(double)n);
	return result;
}




int main() {
//	freopen("E:\\output.txt", "w", stdout);


	Sieve();
//	PrintPrime();

	VI PrimeFact, p;
	int num, i, j, k;

	while(cin >> num && num != 0) {

//	cout << fi(num) << "\n";

	printf("%.0lf\n", fi2(num));

	}
	return 0;
}

