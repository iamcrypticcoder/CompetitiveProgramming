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

int final[27], eqn[27];
bool mark[27];

void Init()
{	
	memset(mark, 0, sizeof(mark));
	for(int i=1; i<=26; i++)
		final[i] = eqn[i] = i;
}

int main()
{
	string org, str;
	int i, j, k;
	
	while(getline(cin, org)) {
		if(org.size() == 0) break;
		Init();	
		
		str = "";
		for(i=0; i<org.size(); i++) {
			if(org[i] == ' ')
				continue;
			str += org[i];
		}

		for(i=0; i<str.size(); i++)											// Increment After
		{
			if(str[i] >= 'a' && str[i] <= 'z' && i < str.size()-2) {
				if(str[i+1] == '+' && str[i+2] == '+') {
					str[i+1] = str[i+2] = '0';
					final[str[i] - 'a' + 1] += 1;
				}
				if(str[i+1] == '-' && str[i+2] == '-') {
					str[i+1] = str[i+2] = '0';
					final[str[i] - 'a' + 1] -= 1;
				}
			}

			if(str[i] >= 'a' && str[i] <= 'z' && i >= 2) {
				if(str[i-1] == '+' && str[i-2] == '+') {
					str[i-1] = str[i-2] = '0';
					eqn[str[i] - 'a' + 1] = (++final[str[i] - 'a' + 1]);
				}
				if(str[i-1] == '-' && str[i-2] == '-') {
					str[i-1] = str[i-2] = '0';
					eqn[str[i] - 'a' + 1] = (--final[str[i] - 'a' + 1]);
				}
			}
		}

		int result = 0;
		bool isPositive = true;

		for(i=0; i<str.size(); i++) {
			if(str[i] >= 'a' && str[i] <= 'z') {
				isPositive == true ? result += eqn[str[i] - 'a' + 1] : result -= eqn[str[i] - 'a' + 1];
				mark[str[i] - 'a' + 1] = true;
			}
			else if(str[i] == '+')
				isPositive = true;
			else if(str[i] == '-')
				isPositive = false;
		}

		cout << "Expression: " << org << "\n";
		cout << "    value = " << result << "\n";
		
		for(i=1; i<27; i++) {
			if(mark[i] == true)
				cout << "    " << (char)('a' + i - 1) << " = " << final[i] << "\n";
		}
			
	}

	return 0;
}