#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int v=5, t=12;
	double a, s;
	
	while(scanf("%d %d", &v, &t)!= EOF) {
		if(t == 0) {
			printf("0\n");
			continue;
		}
		a = (double) v/t;

		s = v*t + a * (t*t);

		printf("%.0lf\n", s);
	}

return 0;

}