#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

unsigned long prime[4000];
unsigned long total_prime=2;

int Is_prime(unsigned long num)
{
	unsigned long root = sqrt(num);
	for(int i=0; prime[i] <= root; i++)
		if(!(num % prime[i]))
			return 0;
	return 1;
}


void PRIME_NUM_GENERATOR()
{
	unsigned long num;
	int Is_p, i;
	unsigned long ele = 2;

	prime[0] = 2;
	prime[1] = 3;

	for(num = 4; num <=35000; num++) {
		Is_p = 1;
		for(i =0; prime[i] <= sqrt(num); i++) 
			if(!(num % prime[i])) {
				Is_p = 0;
				break;
			}
		if(Is_p) {
			prime[ele++] = num;
			total_prime++;
		}
	}
}

int main()
{
	PRIME_NUM_GENERATOR();

	unsigned long num, i, prm, j, main_num, temp_num;
	int last_index,len;

	vector<int> P[25];

	while(cin >> main_num && main_num != 0) {

		for(num=2; num<=main_num; num++) {
		temp_num = num;
		for(i=0,prm = prime[i]; prm <= sqrt(temp_num) && Is_prime(temp_num)==0; ) {
			if(temp_num % prm == 0) {
				temp_num = temp_num / prm;
			//	cout << prm << " ";
				for(j=0;j<25; j++) 
					if(P[j].size() == 0 || P[j][0] == prm) {
						P[j].push_back(prm);
						break;
					}
			}
			else
				prm = prime[++i];
		}
	//	cout << temp_num << endl ;
		for(j=0;j<25; j++)  
			if(P[j].size() == 0 || P[j][0] == temp_num) {
				P[j].push_back(temp_num);
				break;
			}
		
		}

		for(i=24; i>=0; i--)
			if(P[i].size() != 0) {
				last_index = i;
				break;
			}

		printf("%3ld! =", main_num);

		for(i=0, len=1; i<=last_index; i++, len++)  {
			cout.width(3);
			cout.setf(ios::right);
			cout << P[i].size();
			if(len == 15 && i+1 <= last_index) {
				cout << endl;
				cout << "      ";
			}
		}

		cout << endl;

		for(i=0; i<25; i++)
			P[i].clear();
	}

	return 0;
}