#include <iostream.h>
#include <stdio.h>
#include <math.h>

double nth_rt(int nth, double num)
{
 double m = (1/(double)nth) * log10(num);
 return pow(10.0, m);
}

double Calc(double num)
{
	double i, ans=1.0, get, nth_root;
	int Is_minas = 0;
	unsigned long temp;

	if(num<0.0) {
		num = num*(-1);
		Is_minas = 1;
	}

	if(Is_minas) {
		for(i=31; i>=2; i= i-2) {
			nth_root = pow(num,1/i)+ 1E-6;
			temp = nth_root;
			get = pow(temp, i);
			if(get == num)
				return i;
		}
	}
	else {
		for(i=31; i>=2; i--) {
			nth_root = pow(num,1/i)+ 1E-6;
			temp = nth_root;
			get = pow(temp, i);
			if(get == num)
				return i;
		}
	}

	return ans;
}

int main()
{
	double num, ans;

	while(cin >> num && num !=0) {
		ans = Calc(num);

		printf("%.0lf\n", ans);
	}

 return 0;
}