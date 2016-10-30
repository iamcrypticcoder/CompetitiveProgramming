#include <iostream>
#include <math.h>
//#include <conio.h>

using namespace std;

#define PI 2*acos(0.0)

#define THETA (PI/180)*120

int main()
{
	float x = 0.3, M, N, a, b, c, area_sqr, one_fouth;

	while(cin >> x) {
	
		area_sqr = x*x;
		one_fouth = (PI*x*x) / 4;

		M  = (PI*x*x*THETA)/(2*PI)  - 0.5*x*x*sin(THETA);
		N  = one_fouth - M;

		a = area_sqr - M - 2*N;
		b = N - a;
		c = M - 2*b - a;

		printf("%0.3f %0.3f %0.3f\n", c, 4*b, 4*a);
	}

return 0;
}