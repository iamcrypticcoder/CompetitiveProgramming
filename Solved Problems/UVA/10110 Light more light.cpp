#include <iostream>
#include <cmath>

using namespace std;



int main()
{
	unsigned int input, k;

	while(cin >> input && input != 0) {
		k = (unsigned int)sqrt(input);
		if(k*k == input)
			cout << "yes\n";
		else 
			cout << "no\n";
	}
	
}