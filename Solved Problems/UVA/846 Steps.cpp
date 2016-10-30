#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

// This funtion returns the value of x of a two-degree polynomial ax^2 + bx + c = 0.
// is isPositive = true return positive value and vice-versa.
double UnknownXTwoDeg(double a, double b, double c, bool isPositive)
{
	double ans1, ans2;
															
	ans1 = ( (-b + sqrt(b*b - 4*a*c)) ) / (2*a);
	ans2 = ( (-b - sqrt(b*b - 4*a*c)) ) / (2*a);

	if(isPositive)
		return ans1 > 0 ? ans1 : ans2;
	else return ans1 < 0 ? ans1 : ans2;
}

int main()
{
	int x, y, TC;
	double diff, n;
	int int_n;

	int minStep;

	cin >> TC;

	while(TC-- && cin >> x >> y) {

		diff = (double)y - x;
		if(diff == 0.00) {
			cout << "0\n";
			continue;
		}

		n = UnknownXTwoDeg(1.0, 1.0, (-1)*diff, true);
		
		int_n = (int)n;

		if(floor(n) == n)
			minStep = 2*n;
		else {
			if(diff > int_n*(int_n+1) + (int_n+1) )
				minStep = 2*(int_n+1);
			else
				minStep = 2*int_n+1;
		}

		cout << minStep << "\n";
	}
	return 0;
}