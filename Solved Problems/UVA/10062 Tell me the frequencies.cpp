#include <iostream>
#include <stdio.h>
using namespace std;

int done[100][2];

int main()
{
	int i, j, k, l, a, b,t, t2;
	char mainstr[1001];
	int ascci;
	int ele, freq;

	bool Is_done = 0;
		
		while(gets(mainstr)) {

		ele = 0;
		for(i=0; i<strlen(mainstr); i++) {
			Is_done = 0;
			freq = 0;

			ascci = (int)mainstr[i];

			for(j=0; j<ele; j++)
				if(ascci == done[j][0]) {
					Is_done = 1;
					break;
				}

			if(Is_done == 0) {
				for(j=i; j<strlen(mainstr); j++)
					if((int)mainstr[j] == ascci)
						freq++;

				done[ele][0] = ascci;
				done[ele++][1] = freq;
			}
		}

		for(a=1; a<=ele; a++)
			for(b= ele-1; b>=a; b--) {
				if(done[b-1][1] > done[b][1]) {
					t = done[b-1][1];
					t2 = done[b-1][0];

					done[b-1][1] = done[b][1];
					done[b-1][0] = done[b][0];

					done[b][1] = t;
					done[b][0] = t2;

				}
				else if(done[b-1][1] == done[b][1] && done[b-1][0] < done[b][0]) {
					t = done[b-1][0];
					done[b-1][0] = done[b][0];
					done[b][0] = t;
				}
			}

		for(i=0 ;i<ele; i++)
			cout << done[i][0] << " " << done[i][1] << "\n";
		cout << "\n";

		}
return 0;
}

/*
for(i=0; i<strlen(whole_str); i++) {
		
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

			done[ele].ch = whole_str[i];
			done[ele++].freq = freq;
		}
	}*/
/*
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
*/