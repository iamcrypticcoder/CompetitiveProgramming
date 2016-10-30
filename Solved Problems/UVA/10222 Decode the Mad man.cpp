#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

string table = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";

string input, output;

char search(char ch)
{
	int i=0;
	for(i = 0; i< table.size(); i++)
		if(ch == table[i])
			return table[i-2];
}

int main()
{
	int i;

	while(getline(cin, input)) {
		for(i=0; i<input.size(); i++) {
			if(input[i] == ' ') output += ' ';
	//		if(input[i] == '\') output += '\';
			else output += search(tolower(input[i]));
		}
		cout << output << "\n";
		output.clear();
	}

	return 0;
}