#include <iostream>

using namespace std;

int main()
{
	char line[200];
	int pair = 1;

	while(gets(line)) {
		for(int i=0; i<strlen(line); i++) {
			if(line[i] == '"' && pair == 1) {
				cout << "``";
				pair = 2;
				continue;
			}
			else if(line[i] == '"' && pair == 2) {
				cout << "''";
				pair = 1;
				continue;
			}
			cout << line[i];
		}
		cout << endl;
	}
}