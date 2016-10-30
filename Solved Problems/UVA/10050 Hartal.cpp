#include <iostream>

using namespace std;

bool Day[3651];

void SetHoliday()
{
	int i;
	for(i=0; i<3651; i++)
		Day[i] = 0;
/*	for(i=6 ; i<3651; i = i+7) 
		Day[i] = Day[i+1] = 1;*/
}


int main()
{
	int tc,P, N, lost_day;
	int i, j, k, temp;
	int H[101];

	cin >> tc;

	for(i=0; i<tc; i++) {
		lost_day = 0;
		SetHoliday();
		cin >> N;
		cin >> P;

		for(j=0; j<P; j++)
			cin >> H[j];
/*
		for(j=0; j<P; j++) {
			temp  = H[j];
			for(k=1; temp<=N; k++, temp = H[j]*k) {
				if(Day[temp] != 1) {
					lost_day++;
					Day[temp] = 1;
				}
			}
		}*/
		for(j=0; j<P; j++) {
			temp  = H[j];
			for(k=1; temp<=N; k++, temp = H[j]*k) {
				if(temp % 7 == 0 || (temp+1) % 7 == 0 || Day[temp] == 1)
					continue;
				else {
					lost_day++;
					Day[temp] = 1;
				}
			}
		}
	
		cout << lost_day << "\n";
	}

	return 0;
}