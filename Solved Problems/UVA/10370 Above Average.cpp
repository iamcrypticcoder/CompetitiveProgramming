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
	int N;
	double grade[1001];

	double sum, avg, percent;
	int aboveAvg;
		
	int TC, tc;
	int i, j;

	cin >> TC;

	for(tc=1; tc <= TC ; tc++) 
	{
		cin >> N;

		sum = 0;
		for(i=0; i<N; i++) {
			cin >> grade[i];
			sum += grade[i];
		}
		avg = sum / N;

		aboveAvg = 0;
		for(i=0; i<N; i++) 
			if(grade[i] > avg)
				aboveAvg++;
		
		percent = ((double)aboveAvg / N) * 100;

		printf("%.3lf%%\n", percent);

	}

	return 0;
}