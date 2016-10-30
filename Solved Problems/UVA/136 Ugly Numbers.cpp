#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include<conio.h>

double ugly[217000];

int main()
{
	unsigned long ele = 0;
	double i, j, k;
	unsigned long m;

	for(i = 0; i<= 15; i++)
		for(j =0; j<=18; j++)
			for(k=0; k<=30; k++)
				ugly[ele++] = pow(5.0,i) * pow(3.0,j) * pow(2.0,k);


/*	for(m=0; m<ele; m++)
		printf("%.0lf	", ugly[m]);
	printf("\n\n");
*/
	unsigned long a, b;
	double temp;

	for(a=1; a <ele; ++a) {
		 temp = ugly[a];
	 for(b=a-1; (b >=0) && (temp < ugly[b]); b--)
		ugly[b+1] = ugly[b];
		ugly[b+1] = temp;
	}

/*	for(m=0; m<ele; m++)
		printf("%.0lf	", ugly[m]);*/
	printf("The 1500'th ugly number is %.0lf.\n", ugly[1499]);
//	printf("\n\nThe 1500'th ugly number is %.0lf.", ugly[1500]);

//	printf("The 1500'th ugly number is %.0lf.", ug0);
   //scanf("%lf", &k);
//	getch();
return 0;

}
