#include <iostream>
#include <stdio.h>

using namespace std;

int region[101];
int N=99, m;

void Refresh()
{
	for(int i=1; i <= N; i++)
		region[i] = i;
	region[1] = 0;
}

int Is_full_cutted()
{
	int i;
	for(i=1; i<= N;i++) {
		if(i == 13)
			continue;
		if(region[i] != 0)
			return 0;
	}
	return 1;

}

int main()
{
	int Is_break = 0;
	int i, j, num, m;
	int full_break=0, start, diff;
	
	
	while(scanf("%d", &N) && N != 0) {
//	for(N=13; N<100; N++) {
	full_break=0;
	m=0;
	for(diff=1; diff < 300 && full_break == 0; diff++) {
		Refresh();
		start = 2;
		
		while(1) {
			for(i=0, j=start; i<diff; j++) {
				if(j > N) j=1;

				if(region[j] == 0)
					continue;
				else
					i++;
			}
			j = j-1;
			if(j==13 && Is_full_cutted() == 1) {
				full_break=1;
				m = diff;
				break;
			}
			else if(j==13 && Is_full_cutted() == 0)
				break;
			region[j] = 0;
			start  = j+1;
		}
	}
	cout << m << endl;
	}
	
}
