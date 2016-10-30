#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
//using namespace std;

#define MAX 1000

char encoded[MAX], decoded[MAX];

void rev(char str[MAX])
{
	char temp[MAX];
	strcpy(temp, str);

	int j=0;
	for(int i=strlen(temp)-1; i>=0; i--)
		str[j++] = temp[i];
	str[j] = '\0';

}

int convert(char ch)
{
 int temp = (int)ch;
 int value=0;

 while(temp) {
	value *= 10;
	value += temp%10;
	temp /= 10;
 }

 return value;
}

void Encode(char input[MAX])
{
	int i, j, k, value;

	rev(input);

	j=0;
	for(i=0; i<strlen(input); i++) {
		value = (int)input[i];
		while(value) {
		 encoded[j++] = (char)((value%10) + 48);
		 value /= 10;
		}
	}
	encoded[j] = '\0';
}

void Decode(char input[MAX])
{
	int ptr, i, j, ele=0;
	int value=1;

	rev(input);

	for(ptr=0; ptr<strlen(input); ) {
		value = input[ptr] - 48;
		ptr++;

		value = value*10 + (input[ptr]-48);
		ptr++;
		if(!(value>=32 && value<=99)) {
			value = value*10 + (input[ptr]-48);
			ptr++;
		}
		decoded[ele++] = (char)value;
	}
	decoded[ele] = '\0';
}


int main()
{
	char str[MAX];

	while(gets(str)) {
		if(isdigit(str[0])) {
			Decode(str);
			cout << decoded << "\n";
		}
		else {
			Encode(str);
			cout << encoded << "\n";
		}
	}
	 //cout << convert('z');
	//rev(str);

	//cout << str;

return 0;
}