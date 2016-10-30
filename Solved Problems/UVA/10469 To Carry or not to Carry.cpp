// Both code are accepted. 

/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> bin1;
vector<bool> bin2;
vector<bool> bin_ans;

bool XOR(bool a, bool b)
{
	return (a|b && (!(a&b)));
}

void SHOW(vector<bool> v)
{
	for(int i=0; i<v.size(); i++)
		cout << v[i];
}

unsigned long ADD()
{
	int lowest,highest, i;
	unsigned long ans=0;
	lowest = bin1.size() < bin2.size() ? bin1.size() : bin2.size();

	for(i=0; i<lowest; i++)
		bin_ans.push_back(XOR(bin1[i], bin2[i]));
	
	if(lowest == bin1.size()) {
		for(i= lowest; i<bin2.size(); i++)
		 bin_ans.push_back(bin2[i]);
	}
	else {
		for(i= lowest; i<bin1.size(); i++)
			bin_ans.push_back(bin1[i]);
	}

	for(i=bin_ans.size()-1; i>=0; i--)
		if(bin_ans[i] == 1)
			ans += (unsigned long)pow(2.0,i);

	return ans;
}

int main()
{
	unsigned long num1, num2, temp, result;
	int i=0;

	while(scanf("%ld %ld", &num1, &num2) != EOF) {
		bin1.clear();
		bin2.clear();
		bin_ans.clear();

		temp = num1;
		for(;temp != 0;) {
			bin1.push_back(temp % 2);
			temp /= 2;
		}

		temp = num2;
		for(;temp != 0;) {
			bin2.push_back(temp % 2);
			temp /= 2;
		}


//		SHOW(bin1);
//		cout << "\n";
//		SHOW(bin2);

		result = ADD();
  
//		cout << "\n";
//		SHOW(bin_ans);
		cout <<result << "\n";
	}	

return 0;
}
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	unsigned int num1, num2, result;

	while(cin >> num1 >> num2) {
		result = num1 ^ num2;
		cout << result << "\n";
	}


	return 0;
}