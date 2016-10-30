#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char skew_bin[300] = "";
	long dec_num=0;
	double k;
	long i;

   while(gets(skew_bin) && strcmp(skew_bin, "0") !=0) {
		dec_num=0;
		for(i= strlen(skew_bin)-1, k=0; i>=0; i--,k++) {
			if(skew_bin[i] == '0')
				continue;
			dec_num += ((long)pow(2.0,k+1)-1) * ((long)skew_bin[i]-'0');
		}
		printf("%ld\n", dec_num);
	}

return 0;
}