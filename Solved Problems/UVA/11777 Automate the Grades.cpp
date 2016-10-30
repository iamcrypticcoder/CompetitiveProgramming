#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

int T1, T2, F, A, C[3];
int totalMark;

int sort_function( const void *a, const void *b)
{
	 return( strcmp((char *)b,(char *)a));
}

int avg()
{
	qsort(C, 3, sizeof(C[0]), sort_function);
	return (C[0]+C[1])/2;
}

int main()
{
	int TC, i;
	char grade;

	cin >> TC;

	for(i=1; i<=TC; i++) {
		cin >> T1 >> T2 >> F >> A >> C[0] >> C[1] >> C[2];
		totalMark = T1 + T2 + F + A + avg();

		if(totalMark >= 90)
			grade = 'A';
		else if(totalMark >= 80 && totalMark < 90)
			grade = 'B';
		else if(totalMark >= 70 && totalMark < 80)
			grade = 'C';
		else if(totalMark >= 60 && totalMark < 70)
			grade = 'D';
		else if(totalMark < 60)
			grade = 'F';

		cout << "Case " << i  << ": " << grade << "\n";

	}

	return 0;
}