#include <iostream>
#include <math.h>

using namespace std;

int NUM_OF_DIVISORS(int N)
{
    if(N == 1) return 1;
    int ret = 1;

    int root = (int)sqrt(N);
    for(int i=2; i<=root; i++)
        if(N % i == 0) {
            int power = 0;
            while(N % i == 0) {
                power++;
                N /= i;
            }
            ret *= (power+1);
        }
    if(N > 1) ret *= 2;

    return ret;
}

int PHI_FUNC(int N)
{
	if(N==1) return 0;
	int result = N;

    int root = (int)sqrt(N);
	for(int i=2; i <= root; i++) {
		if (N % i == 0) result -= result / i;
		while (N % i == 0) N /= i;
	}
	if (N > 1) result -= result / N;
	return result;
}


int main()
{
    int N;

    while(cin >> N) {
        if(N == 1) cout << "0\n";
        else cout << N - PHI_FUNC(N) - NUM_OF_DIVISORS(N) + 1 << "\n";

    }

    return 0;
}
