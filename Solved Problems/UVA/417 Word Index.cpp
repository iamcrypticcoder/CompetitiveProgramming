#include <iostream>
#include <string>

using namespace std;

int list1[26], list2[26], list3[26];

struct MAP {
	string word;
};


struct MAP map[83682]; 

bool Is_Valid(string str)
{
	for(int i=0; i<str.size()-1; i++)
		if(str[i] > str[i+1])
			return 0;
	return 1;
}


int main()
{
/*	int i, j, k, l, m, n, o;
	int sum1, sum2, sum3;

	i = j = k = l = m = n = o = 0;
	sum1 = sum2 = sum3 = 0;

	for(i=24, j=1; i>=1; i--) {
		list1[j] = (i*(i+1))/2;
		cout << list1[j] << "\n";
		sum1 += list1[j];
		j++;
	}
	cout << sum1 << "\n\n";

	for(i=1; i<=23; i++) {
		for(j=i+1; j<=24; j++)
			list2[i] += list1[j];
		cout << list2[i] << "\n";
		sum2 += list2[i];	
	}
	cout << sum2 << "\n\n";


	for(i=1; i<=22; i++) {
		for(j=i+1; j<=23; j++)
			list3[i] += list2[j];
		cout << list3[i] << "\n";
		sum3 += list3[i];	
	}
	cout << sum3;
*/

	int i, j, k, l, m, n, o;
	int sum1, sum2, sum3;

	string str, input;
	int v1, v2, v3, v4, v5;

	i = j = k = l = m = n = o = 0;
	sum1 = sum2 = sum3 = 0;
	v1 = 1;
	v2 = 27;
	v3 = 352;
	v4 = 2952;
	v5 = 17902;

	for(i='a'; i<= 'z'; i++) {
		str += i;
		map[v1++].word = str;
		for(j= i+1; j<= 'z'; j++) {
			str += j;
			map[v2++].word = str;
			for(k= j+1; k<= 'z'; k++) {
 				str += k;
				map[v3++].word = str;
				for(l= k+1; l<= 'z'; l++) {
					str += l;
					map[v4++].word = str;
					for(m= l+1; m<= 'z'; m++) {
						str += m;
						map[v5++].word = str;
						str.erase(4,1);
					}
				//	cout << v5 << "\n";
					str.erase(3, 1);
				}
				str.erase(2,1);
			//	cout << v4 << "\n";
			}
			str.erase(1,1);
		//	cout << v3 << "\n";
		}
		str.erase(0,1);
	//	cout << v2 << "\n";
	}
//	cout << v1 << "\n";


	while(cin >> input) {
		if(!(Is_Valid(input)))
			cout << 0 << "\n";
		else {
			for(i=1; i<=83681; i++)
				if(input == map[i].word)
					cout << i << "\n";
		}
	}
/*
	for(i=1; i<27; i++) {
		cout << map[i].word << " ";
		cout << i;
	}
	*/	

return 0;
}