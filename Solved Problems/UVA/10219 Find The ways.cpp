#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

double fact(unsigned long x)
{
	unsigned long i;
	double f=1.0;

	for(i=1; i<=x; i++)
		f *= i;
	return f;
}

int main()
{
 double deno, nume=1.0;
 unsigned long i, start, N, M;

 while(cin >> N >> M) {
	 if(N == 0 && M == 0) break;
 	nume = 1.0;

	start = M > N-M ? M+1 : N-M+1;


	for(i=start; i<=N; i++)
		nume *= i;


	deno = fact(M < N-M ? M : N-M);

	//printf("%ld things taken %ld at a time is %.0lf exactly.\n", N, M, nume/deno);
	printf("%.0lf\n", floor(log10(nume/deno))+1+1E-10 );
 }
return 0;
}