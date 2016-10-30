#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

char inverse (char ch)
{
	if(ch == ')') return '(';
	if(ch == ']') return '[';
}

void clear()
{
	while(!(s.empty()))
		s.pop();
}

int main()
{
//	freopen("E:\\input.txt", "r", stdin);
//	freopen("E:\\output.txt", "w", stdout);
	char str[200];
	bool Is_yes;
	int tc, i;
	bool Is_first = 1;
//	stack<char> s;

	cin >> tc;

	while(tc-- >=0 && cin.getline(str, 130)) {
		if(Is_first) { Is_first = 0; continue; }
		Is_yes = 1;
		clear();

		for(i=0; i<strlen(str); i++) {

			if(str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			else if(s.size() != 0 && inverse(str[i]) == s.top())
				s.pop();
			else { Is_yes = 0; break; }
		}
		if(s.size() == 0 && Is_yes == 1)	cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;

}