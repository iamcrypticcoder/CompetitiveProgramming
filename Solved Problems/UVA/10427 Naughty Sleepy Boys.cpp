#include<stdio.h>
#include <math.h>

unsigned long a[8][2] = { 
	{788888889, 100000000},
	{68888889, 10000000},
	{5888889, 1000000},
	{488889, 100000},
	{38889, 10000},
	{2889, 1000},
	{189, 100},
	{9, 10}
  };

int main()
{
  unsigned long num;
  unsigned long test_case;
  unsigned long j;
  unsigned long i,l, m, x;
  unsigned long curr_num, exp_digit, exp_num, nth_digit;
  
  unsigned long temp;


  for(test_case =0; scanf("%ld", &num) != EOF && num<100000000 && test_case <11000; test_case++) {
 
  if(num <10)
   printf("%ld\n", num);

  else {
	for(i=0 ; i<8; i++)
		if(num > a[i][0]) {
			temp = num - a[i][0];
			break;
		}

	m = temp / (floor(log10(a[i][1])) +1);
	exp_num = a[i][1] + m;
	exp_digit = temp % ((unsigned long)floor(log10(a[i][1])) + 1);

	if(exp_digit == 0) {
	 exp_num--;
	 exp_digit = (unsigned long)floor(log10(a[i][1])) + 1;
	}

	for(j=(unsigned long)floor(log10(a[i][1])) + 1; j>=exp_digit; j--) {
		nth_digit = exp_num %10;
		exp_num /=10;
	}

	printf("%ld\n", nth_digit);
  }
  }

 return 0;

}