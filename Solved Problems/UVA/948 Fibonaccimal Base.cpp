/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/

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

VI fib;
int totalFib;

void GenerateFib()
{
	fib.push_back(1);
	fib.push_back(2);

	for(int i=2; fib[i-1] + fib[i-2] <= 1e8; i++) {
		fib.push_back(fib[i-1] + fib[i-2]);
//		cout << fib[i] << "\n";
	}
	totalFib = fib.size();
//	cout << totalFib << "\n";
}

string DecToFibBase(int num)
{
	int  ptr = totalFib - 1;
	string ret;

	bool startFlag = 0;

	while(ptr >= 0) {
		if(fib[ptr] <= num) {
			num -= fib[ptr];
			ret += "1";
			startFlag = true;
		}
		else {
			if(startFlag) ret += "0";
		}
		ptr--;
	}

	return ret;
}

int main()
{
	GenerateFib();

	int TC, tc;
	int N;

	string ans;

	int i, j, k;

	cin >> TC;

	for(tc=1; tc<=TC; tc++) 
	{
		cin >> N;

		ans = DecToFibBase(N);
	
		cout << N << " = " << ans << " (fib)\n";
	}

	return 0;
}
