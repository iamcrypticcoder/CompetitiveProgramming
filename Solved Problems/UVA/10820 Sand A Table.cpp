#include <iostream>
#include <math.h>

using namespace std;

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

int DP[50001];

void Precalculate()
{
    DP[0] = 1;
    DP[1] = 1;      // Why 1 ? Because for 1 We should know only Ans(1, 1).

    for(int i=2; i<=50000; i++) {
        DP[i] = DP[i-1] + 2 * PHI_FUNC(i);
    }
}

int main()
{
    int N;

    Precalculate();

    while(cin >> N ) {
        if(N == 0) break;
        cout << DP[N] << "\n";
    }


    return 0;
}
