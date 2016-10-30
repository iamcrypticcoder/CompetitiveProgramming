#include <iostream>
#include <vector>

using namespace std;

char num1[201], num2[201];
vector<int> N1, N2, ANS;

void Assign()
{
	int i;

	for(i=0; i<strlen(num1); i++)
		N1.push_back(num1[i] - '0');

	for(i=0; i<strlen(num2); i++)
		N2.push_back(num2[i] - '0');

}

void Add()
{
	int i, j, carry = 0,temp;

	if(N1.size() <= N2.size()) {
		for(i=0; i<N1.size(); i++) {
			temp = N1[i] + N2[i] + carry;
			ANS.push_back(temp % 10);
			carry = temp /10;
		}

		for(i=i; i< N2.size(); i++) {
			temp = N2[i] + carry;
			ANS.push_back(temp%10);
			carry = temp / 10;
		}
		if(carry) ANS.push_back(carry);
	}
	else {
		for(i=0; i<N2.size(); i++) {
			temp = N1[i] + N2[i] + carry;
			ANS.push_back(temp % 10);
			carry = temp / 10;
		}

		for(i=i; i< N1.size(); i++) {
			temp = N1[i] + carry;
			ANS.push_back(temp%10);
			carry = temp / 10;
		}
		if(carry) ANS.push_back(carry);
	}
}

void SHOW()
{
	int i, Is_ok = 0;

	for(i=0; i<ANS.size(); i++) {
		if(ANS[i] != 0) Is_ok = 1;
		
		if(Is_ok == 1)
			cout << ANS[i];
	}

}

int main()
{
	int t_case, i;

	scanf("%d", &t_case);

	for(i=0; i<t_case; i++) {
		
			N1.clear();
	N2.clear();
	ANS.clear();
		scanf("%s %s", num1, num2);

		Assign();
		Add();
	
		SHOW();
		cout << "\n";
	}


return 0;
}