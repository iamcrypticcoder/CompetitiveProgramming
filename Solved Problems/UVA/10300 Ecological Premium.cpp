#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;



int main()
{
	int tc, TC;
	long long numFarmer, size, noAnimal, degree, ans;

	cin >> TC;

	while(TC--) {
		cin >> numFarmer;

		ans = 0;
		while(numFarmer--) {
			cin >> size >> noAnimal >> degree;
			ans += (size * degree);
		}
		cout << ans << endl;

	}

	return 0;
}