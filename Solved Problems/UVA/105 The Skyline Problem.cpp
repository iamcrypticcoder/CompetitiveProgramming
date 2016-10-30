#include <stdio.h>
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

#define MAX_BUILDING 10001

int Height[MAX_BUILDING];


void Init()
{
	for(int i=0; i<=MAX_BUILDING; i++)
		Height[i] = 0;
}

int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

	VI V;
	int i, j, k, temp;
	int xLeft, height, xRight;
	int mostLeft = 10001, mostRight = 0;

	while(cin >> xLeft >> height >> xRight) {
		mostLeft = min(mostLeft, xLeft);
		mostRight = max(mostRight, xRight);
		for(i = xLeft; i < xRight; i++)
			if(height > Height[i])
				Height[i] = height;
	}

	V.push_back(mostLeft);
	V.push_back(Height[mostLeft]);
	temp = Height[mostLeft];

	for(i = mostLeft ; i <= mostRight ; i++)
		if(Height[i] != temp) {
			V.push_back(i);
			V.push_back(Height[i]);
			temp = Height[i];
		}

		for( i = 0; i < V.size()-1; i++)
			cout << V[i] << " ";
		cout << V[i] << endl;

	return 0;
}
