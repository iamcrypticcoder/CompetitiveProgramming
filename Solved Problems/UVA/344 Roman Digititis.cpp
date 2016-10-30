#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int multiple[9] = {1, 4, 5, 9, 10, 40, 50, 90, 100};
int DP[101][6];

										//   1  5  10  50  100
										//   i, v, x,  l,  c
void Init()
{
	memset(DP, 0, sizeof(DP));

	DP[1][1] = 1;
	DP[2][1] = 2;
	DP[3][1] = 3;
	DP[4][1] = 1;	DP[4][2] = 1;	
	DP[5][2] = 1;

	DP[10][3] = DP[9][3] = DP[9][1] = 1;
	DP[50][4] = DP[40][4] = DP[40][3] = 1;
	DP[100][5] = DP[90][5] = DP[90][3] = 1;

	int num, mul, i, rem, div;

	for(num = 6; num <= 100 ; num++) {
		if(num == 9 || num == 10 || num == 40 || num == 50 || num == 90 || num == 100) continue;

		for(i = 8; i>=0; i--) 
			if(multiple[i] < num)
				break;
	
		mul = multiple[i];
		div = num / mul;	
		rem = num % mul;

		for(i = 1; i<=5; i++) 
			DP[num][i] = DP[mul][i]*div + DP[rem][i];
	}

}

int main()
{
	int input;
	int IVXLC[6];

	Init();
/*
	for(int i=1; i<=30; i++) {
		printf("%d %d %d %d %d\n", DP[i][1], DP[i][2], DP[i][3], DP[i][4], DP[i][5]);

	}
*/
	while(cin >> input && input != 0) {
		
		memset(IVXLC, 0, sizeof(IVXLC));

		for(int i=1; i<=input; i++) {
			IVXLC[1] += DP[i][1];
			IVXLC[2] += DP[i][2];
			IVXLC[3] += DP[i][3];
			IVXLC[4] += DP[i][4];
			IVXLC[5] += DP[i][5];
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", input, IVXLC[1], IVXLC[2], IVXLC[3], IVXLC[4], IVXLC[5]);
	}
	return 0;
}