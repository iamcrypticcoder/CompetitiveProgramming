#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <math.h>


using namespace std;

#define PI 2*acos(0.0)
#define R 6440


int main()
{
//	freopen("E:/output.txt", "w", stdout);
		
	int s, a;
	double angle, theta;
	char str[4];

	double arc, chord;

	while(cin >> s >> a >> str) 
	{
		angle = a;
		if(strcmp(str, "min") == 0) 
			angle = (double)a / 60;

		if(angle > 180)  angle = 360 - angle;
		
		theta = (PI * angle) / 180;

		arc = (R + s) * (theta);

		chord = sqrt(2*(1 - cos(theta))) * (R + s);

		printf("%.6lf %.6lf\n", arc, chord);
	}

	return 0;
}