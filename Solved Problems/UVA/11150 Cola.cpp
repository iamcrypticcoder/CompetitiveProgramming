#include <iostream>

using namespace std;

int main()
{
	int input = 9, carry;
	int temp;
	int a,b;
	int total;
	int max=0;

	while(cin >> input) {
		max = 0;
	for(carry=0; carry<3; carry++) {
		temp = input+carry;
		total = input;
		for(; temp >= 3;) {
			a = temp % 3;
			b = temp / 3;
			temp = a + b;
			total += b;;
		}
		if( b >= carry && total > max)
			max = total;
	}


	cout << max << "\n";
	//cout << b << "\n";
	}
}