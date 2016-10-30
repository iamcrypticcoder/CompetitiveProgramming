#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include<conio.h>

using namespace std;

unsigned long ele = 0;
unsigned long ugly[5842];

char suffix [4][3] = {"st", "nd", "rd", "th"};

void Ini()
{
	double i, j, k, l, temp;
	unsigned long m;

	for(i = 0; i<=20; i++)
		for(j =0; j<=15; j++)
			for(k=0; k<=25; k++)
				for(l=0; l<=30; l++) {
					temp = pow(7.0,i) * pow(5.0,j) * pow(3.0,k) * pow(2.0, l);
					if(temp <= 2000000000)
						ugly[ele++] = temp;
				}
	
	unsigned long a, b;


	for(a=1; a <ele; ++a) {
		 temp = ugly[a];
	 for(b=a-1; (b >=0) && (temp < ugly[b]); b--)
		ugly[b+1] = ugly[b];
		ugly[b+1] = temp;
	}

}

int main()
{
	int nth, s_value;

	Ini();
//	for(int i=0; i<ele; i++)
//		cout << ugly[i] << "\n";

	while(scanf("%d", &nth) && nth !=0) {
		s_value = 0;
		if(s_value==0 && (nth == 11 || nth == 12 || nth == 13))
			s_value = 3;
		else if(s_value==0  && (nth%100 == 11 || nth%100 == 12 || nth%100 == 13))
			s_value = 3;
		else if(s_value == 0 && nth%10 == 1)
			s_value = 0;
		else if(s_value == 0 && nth%10 == 2)
			s_value = 1;
		else if(s_value == 0 && nth%10 == 3)
			s_value = 2;
		else s_value = 3;

		printf("The %d%s humble number is %ld.\n", nth, suffix[s_value], ugly[nth-1]);
	}


return 0;
}
