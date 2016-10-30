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


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;



int main()
{
	int start, end, oddSum;
		
	int TC, tc;

	cin >> TC;

	for(tc=1; tc <= TC ; tc++) 
	{
		cin >> start >> end;

		if(start % 2 == 0) {
			oddSum = (++start);
		}
		else 
			oddSum = start;
		
		start += 2;
		while(start <= end) {
			oddSum += start;
			start += 2;
		}
		cout << "Case " << tc << ": " << oddSum << "\n";
	}

	return 0;
}