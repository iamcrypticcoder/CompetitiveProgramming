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

int main()
{
	freopen("E:/input.txt", "r", stdin);
	freopen("E:/output.txt", "w", stdout);


	int TC, tc;
	int amp, freq;

	int i, j, f;

	cin >> TC;

	for(tc=1; tc<=TC; tc++) {
		cin >> amp >> freq;

		for(f=1; f<=freq; f++) {

			for(i=1; i<=amp; i++) {
				for(j=1; j<=i; j++)
					cout << i;
				cout << "\n";
			}

			for(i = amp-1; i>=1; i--) {
				for(j=1; j<= i; j++)
					cout << i;
				cout << "\n";
			}
			if(f != freq)cout << "\n";
		}
		if(tc != TC) cout << "\n";


	}


	return 0;
}
