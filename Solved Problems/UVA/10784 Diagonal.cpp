#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


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
		
	int TC, tc;
	int i, j;
	double ans, input;

//	cout << UnknownXTwoDeg(5, -6, -8, false);


	for(tc=1;  ; tc++) 
	{
		cin >> input;
		if(input == 0) break;
											// If number of sides = n then number of diagonal = (n*n - 3*n)/2
		ans = UnknownXTwoDeg(1, -3, -2*input, true);

		ans = ceil(ans);

		cout << "Case " << tc << ": " << (long long)ans << "\n";

	}

	return 0;
}