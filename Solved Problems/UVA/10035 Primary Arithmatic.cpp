#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
	unsigned long num1, num2, max_digit, num_of_carry, carry, sum, i;

	while(scanf("%ld %ld", &num1, &num2)) {

		if(num1 == 0 && num2 == 0) break;

		max_digit = num1 >= num2 ? floor(log10(num1))+1 : floor(log10(num2))+1;
		carry = 0;
		num_of_carry = 0;
		for(i = 1; i<= max_digit; i++) {
			sum = num1%10 + num2%10 + carry;
			sum /= 10;
			num1 /=10;
			num2 /=10;
			carry = sum;
			if(carry)
				num_of_carry++;
		}
		if(num_of_carry > 1)
			printf("%ld carry operations.\n", num_of_carry);
		else if(num_of_carry == 1)
			printf("%ld carry operation.\n", num_of_carry);
		else if(num_of_carry == 0)
			printf("No carry operation.\n");
	}
return 0;
}
