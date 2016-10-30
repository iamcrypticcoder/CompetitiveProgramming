#include<stdio.h>
#include<string.h>


int main()
{
	char coded[200];
	int i;

	while(gets(coded)) {
	for(i = 0; i < strlen(coded); i++)
		printf("%c", coded[i] - 7);
	printf("\n");
	}
return 0;
}