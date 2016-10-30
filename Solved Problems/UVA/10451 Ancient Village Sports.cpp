#include <iostream>
#include <math.h>

using namespace std;

#define PI 2*acos(0.0)

int main()
{
	int num_of_side;
	double area_poly, r_out, area_out, r_in, area_in, theta;


	for(int i=0; cin >> num_of_side >> area_poly; i++) {
		if(num_of_side <3) break;
		theta = (2*PI)/num_of_side;
		r_out = sqrt( (2*area_poly)/(num_of_side*sin(theta)) );

//	printf("%f\n", r_out);
	printf("Case %d: ",i+1);
	area_out = PI*r_out*r_out;
	printf("%.5f ", area_out-area_poly);
	
	r_in = r_out * cos(theta/2);
	area_in = PI*r_in*r_in;
//	printf("%f ", area_in);
	printf("%.5f\n", area_poly-area_in);
	}
return 0;
}