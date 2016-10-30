#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char table[16][10];

char *set[32][2] = { {"negative", "-1"},
		    {"zero", "0"},
		    {"one", "1"},
		    {"two", "2"},
 		    {"three", "3"},
		    {"four", "4"},
		    {"five", "5"},
 		    {"six", "6"},
		    {"seven", "7"},
		    {"eight", "8"},
 		    {"nine", "9"},
		    {"ten", "10"},
		    {"eleven", "11"},
 		    {"twelve", "12"},
		    {"thirteen", "13"},
		    {"fourteen", "14"},
		    {"fifteen", "15"},
		    {"sixteen", "16"},
		    {"seventeen", "17"},
		    {"eighteen", "18"},
		    {"nineteen", "19"},

		    {"twenty", "20"},
		    {"thirty", "30"},
		    {"forty", "40"},
		    {"fifty", "50"},
		    {"sixty", "60"},
		    {"seventy", "70"},
		    {"eighty", "80"},
		    {"ninety", "90"},

		    {"hundred", "100"},
		    {"thousand", "1000"},
		    {"million", "1000000"}
};

long value_of(char word[]) {
	int i=0;
	for(i=0; i<32; i++)
		if(strcmp(set[i][0],word)==0)
			return atol(set[i][1]);
 //return 0;
}


int SEPERATE_WORD(char mainstr[])
{
	char *ptr = mainstr;
	char temp[10];
	int i, ele=0;
	int length;

	for(length=1; length < strlen(mainstr); ) { 
		i=0;
		for( ; *ptr != ' ' && *ptr != NULL; length++) 
			temp[i++] = *ptr++;
        temp[i] = NULL;
		strcpy(table[ele++], temp);
		ptr++;
		length++;
	}
	
return ele;

}


int main()
{
// char mainstr[200] = "negative nine hundred ninety nine million nine hundred ninety nine thousand nine hundred ninety nine";
//char mainstr2[100] = "nine million nine hundred ninety nine thousand";
// char mainstr3[100] = "negative twenty nine";
 char main[100] = "";

 int total_word;
 int max_index, i, m, start_index, Is_neg;

 long exp_num=0;
 long temp[10], max;

 while(gets(main)) {
	total_word =  SEPERATE_WORD(main);
	max_index = 0, start_index = 0, Is_neg = 0;
	exp_num=0;

 for(i = 0; i<10; i++)
	 temp[i] = 0;

 for(m=0; ; m++) {
	max = 0;
	start_index = max_index;
	for(i=max_index; i<total_word; i++)
		if(max < value_of(table[i])) {
			max = value_of(table[i]);
			max_index = i;
		}
	for(i=start_index; i<=max_index; i++) {
		if( strcmp(table[i], "million")==0 || strcmp(table[i], "thousand")==0 || strcmp(table[i], "hundred")==0)
			temp[m] *= value_of(table[i]);
		else if(strcmp(table[i], "negative")==0)
			Is_neg = 1;
		else
			temp[m] += value_of(table[i]);
	}
	max_index++;
	if(total_word == max_index)
		break;
 }

 for(i=0; i<=m; i++)
	exp_num += temp[i];
	 
 if(Is_neg) exp_num *= -1;
	 printf("%ld\n", exp_num);
 }

 //for(i=0; i<m; i++)
//	 printf("%ld", temp[i]);

 //printf("%ld", value_of("negative"));

return 0;
}