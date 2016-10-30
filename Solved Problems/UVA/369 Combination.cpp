#include <iostream>
#include <stdio.h>

using namespace std;

double fact(unsigned long x)
{
	unsigned long i;
	double f=1.0;

	for(i=1; i<=x; i++)
		f *= i;
	return f;
}

double nCr(int N, int R)
{
	int start, i;
	double nume, deno;

	nume = 1.0;

	start = R > N-R ? R+1 : N-R+1;

	for(i=start; i<=N; i++)
		nume *= i;

	deno = fact(R < N-R ? R : N-R);

	return (nume/deno);   
}

int main()
{
 double deno, nume=1.0;
 unsigned long i, start, N, M;

 while(cin >> N >> M) {
	 if(N == 0 && M == 0) break;
/* 	nume = 1.0;

	start = M > N-M ? M+1 : N-M+1;

//	cout << start << "\n";

	for(i=start; i<=N; i++)
		nume *= i;

//	printf("%.0lf\n", nume);

	deno = fact(M < N-M ? M : N-M);
//	printf("%.0lf\n", deno);

	//printf("%.0lf", nume/deno);

*/
	printf("%ld things taken %ld at a time is %.0lf exactly.\n", N, M, nCr(N,M));
	// printf("%lf", fact(50));
 }
return 0;
}
