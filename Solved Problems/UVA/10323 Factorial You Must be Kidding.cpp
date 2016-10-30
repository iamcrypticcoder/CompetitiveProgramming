#include <iostream>
#include <vector>

using namespace std;


double fact(int num)
{
	if (num == 1) return 1;
	else return (num*fact(num-1));
}

void Process(int n)
{
	if(!(n % 2)) cout << "Underflow!\n";
	else cout << "Overflow!\n";
}


int main()
{
	int input;
	double ans;

	while(cin >> input) {
		if(input < 0) 
			Process(input);
		else if(input > 13) 
			cout << "Overflow!\n";
		else if(input < 8) 
			cout << "Underflow!\n";
		else 
			printf("%.0lf\n", fact(input));
	}
return 0;
}