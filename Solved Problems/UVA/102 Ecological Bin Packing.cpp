#include <iostream>
#include <stdio.h>
using namespace std;

unsigned long b[3][3];
unsigned long B[3][3];

int permu[6][3] = {
	{0, 2, 1},
	{0, 1, 2},
	{2, 0, 1},
	{2, 1, 0},
	{1, 0, 2},
	{1, 2, 0},
};

char str[6][4] = {"BCG","BGC", "CBG", "CGB", "GBC", "GCB" };


int value(int n)
{
	if(n>2) return (n-3);
	return n;
}


int main()
{
	int i, j, choice;
	unsigned long min_move= 4123456789, temp;

	while(scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld", &b[0][0], &b[0][1], &b[0][2], &b[1][0], &b[1][1], &b[1][2], &b[2][0], &b[2][1], &b[2][2]) == 9) {
	min_move= 4123456789;
	choice = 10;

	for(i =0; i<3; i++)
		for(j =0; j<3; j++)
			B[i][j] = b[value(i+1)][j] + b[value(i+2)][j];

	for(i = 0; i<6; i++) {
			temp = B[0][permu[i][0]] + B[1][permu[i][1]] + B[2][permu[i][2]];
			if(temp < min_move) {
				choice = i;
				min_move = temp;
			}
	}

   cout << str[choice] << " ";
   cout << min_move << "\n";

	}

return 0;
}
