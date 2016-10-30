#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

// This function converts a 10 base number to any base and return the number as string
string toBase(int num, int base)
{
	string ret;

	if(num == 0) return "0";
	while(num != 0) {
		ret += num%base + '0';
		num /= base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	int input;
	string binary;
	int totalOne;

	while(cin >> input && input != 0)
	{
		binary = toBase(input, 2);

		totalOne = 0;
		for(int i=0; i<binary.size(); i++)
			if(binary[i] == '1')
				totalOne++;

		cout << "The parity of " << binary << " is " << totalOne << " (mod 2).\n";
	
	}



	
	return 0;
}