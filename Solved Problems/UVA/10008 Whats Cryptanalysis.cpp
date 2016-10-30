//#include<conio.h>
#include<ctype.h>
#include<iostream>
#include<string.h>

using namespace std;

struct X{
	char ch;
	int freq;
};

int sort_function( const void *a, const void *b)
{
   return( strcmp((char *)a,(char *)b) );
}

int Sequential_Search(char *items, int count, char key)
{	
	register int t;

	for(t=0; t<count; t++)
		if(key == items[t]) return 1;
	return 0;
}

void STR_UPR(char *str)
{
  int i; 
	for (i=0; i<strlen(str); i++)
   {
      str[i] = toupper(str[i]);
   }

}

int main()
{
	char line[300], whole_str[3000] = "";
	struct X done[53];

	int N, i, Is_done;
	unsigned long ele=0, freq, max_freq=0, j;

	cin >> N;

	for(i=0; i<=N; i++) {
		cin.getline(line, ' ');
		strcat(whole_str, line);
	}

//	cout << whole_str;
//	cout << strlen(whole_str);
	STR_UPR(whole_str);

	for(i=0; i<strlen(whole_str); i++) {
		if(!(isalpha(whole_str[i])))
			continue;
		
		Is_done = 0;
		freq = 0;
		for(j=0; j<ele; j++)
			if(whole_str[i] == done[j].ch) {
				Is_done = 1;
				break;
			}

		if(Is_done == 0) {
			for(j=i; j<strlen(whole_str); j++)
				if(whole_str[i] == whole_str[j])
					freq++;
				if(freq > max_freq)
					max_freq = freq;
			done[ele].ch = whole_str[i];
			done[ele++].freq = freq;
		}
	}
//	cout << "\n\n";

//	for(i=0; i<ele; i++)
//		cout << done[i].ch << " " <<done[i].freq << endl;

// BUBBLE SORT IS BEGAN.

	int a, b, t;
	char ch;

	for(a=1; a<=ele; a++)
		for(b=ele-1; b>=a; b--) {
			if(done[b-1].freq < done[b].freq) {
				t = done[b-1].freq;
				ch = done[b-1].ch;

				done[b-1].ch = done[b].ch;			
				done[b-1].freq = done[b].freq;

				done[b].ch = ch;
				done[b].freq = t;
			}
			else if(done[b-1].freq == done[b].freq && done[b-1].ch > done[b].ch) {
				ch = done[b-1].ch;
				done[b-1].ch = done[b].ch;
				done[b].ch = ch;
			}
		}
// BUBBLE SORT ENDED.

		for(i=0; i<ele; i++)
		cout << done[i].ch << " " <<done[i].freq << endl;


//getch();
return 0;
}

