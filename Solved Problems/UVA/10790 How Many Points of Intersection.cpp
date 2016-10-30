#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;



int main()
{
	long long a,b, ans;
	int tc;

	for(tc = 1; cin >> a >> b && a != 0 && b != 0; tc++)
	{
		ans = ( a*(a-1) ) / 2;
		ans *= ( ( b*(b-1) ) / 2 );

		cout << "Case " << tc << ": "; 
		cout << ans << "\n";

	}

	return 0;
}