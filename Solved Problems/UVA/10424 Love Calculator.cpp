#include <stdio.h>
#include <string.h>


int main()
{
	char name1[25], name2[25];
	int value1=0, value2=0;
	int i, temp_value;
	float ratio;

	while(gets(name1)) {
	value1=0; value2=0;
	ratio = 0.0;
	
	gets(name2);
	//scanf("%s", name2);

	for(i = 0; i< strlen(name1); i++) {
		if(name1[i] >= 'a' && name1[i] <= 'z')
			value1 += name1[i] - 96;
		else if(name1[i] >= 'A' && name1[i] <= 'Z')
			value1 += name1[i] - 64;
	}
	for(i = 0; i< strlen(name2); i++) {
		if(name2[i] >= 'a' && name2[i] <= 'z')
			value2 += name2[i] - 96;
		else if(name2[i] >= 'A' && name2[i] <= 'Z')
			value2 += name2[i] - 64;
	}

	while(value1 > 9) {
		temp_value = 0;
		while(value1 > 9) {
			temp_value += value1 % 10;
			value1 /= 10;
		}
		temp_value += value1;
		value1 = temp_value;
	}

	while(value2 > 9) {
		temp_value = 0;
		while(value2 > 9) {
			temp_value += value2 % 10;
			value2 /= 10;
		}
		temp_value += value2;
		value2 = temp_value;
	}

	if((float)value1 / value2 <= 1.0)
		ratio = (float)value1 / value2;
	else
		ratio = (float)value2 / value1;

	//cout << value1 << " " << value2 << " " << ratio*100;
	printf("%0.2f %%\n", ratio*100);
	}

	return 0;
}
