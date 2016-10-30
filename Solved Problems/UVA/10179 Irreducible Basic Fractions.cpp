#include <iostream>
#include <math.h>

using namespace std;

// Euler-Totient PHI Function
// Here double returned. Make is int as your need.
double PHI_FUNC(int N)
{
	if(N==1) return 1;
	double result = N;

    int root = (int)sqrt(N);
	for(int i=2; i <= root;i++) {
        if (N % i == 0) result *= (1 - 1/(double)i);
        while (N % i == 0) N /= i;
    }

	if(N > 1) result *= (1 - 1/(double)N);
	return result;
}

int fi(int n)
{
   if(n==1) return 1;
    int result = n;
    for(int i=2;i*i <= n;i++)
    {
      if (n % i == 0) result -= result / i;
      while (n % i == 0) n /= i;
    }
    if (n > 1) result -= result / n;
    return result;
}

int main()
{
    int N;
    while(cin >> N) {
        if(N == 0) break;
        cout << (int)PHI_FUNC(N) << "\n";
    }

    return 0;
}
