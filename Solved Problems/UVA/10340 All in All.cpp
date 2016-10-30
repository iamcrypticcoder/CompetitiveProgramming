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

#define FOR( i, L, U ) for( i=L ; i<=U ; i++ )

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;



int main()
{
	string S, T;

	int i, j, ptr;
	bool found;

	int s, t; 

	while(cin >> S)
	{
		cin >> T;
		s = S.size();
		t = T.size();

		ptr = 0;
		found = true;
		FOR(i, 0, s-1) {
			while(T[ptr] != S[i]) {
				ptr++;
				if(ptr > t-1) {
					found = false;
					break;
				}
			}
			if(!found) break;
			else ptr++;
		}
		if(found) cout << "Yes\n";
		else cout << "No\n";

	}

	return 0;
}