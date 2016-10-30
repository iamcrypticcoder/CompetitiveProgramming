#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> VString; 

map<string, int> M;
VString List;

int nop, amount, nor, each;
char people[11][13];
char name[13], donor[13], receiver[13];

string temp;

void Print()
{
	VString::iterator p = List.begin();

	for(; p != List.end(); p++)
		cout << *p << " " << M[string(*p)] << "\n";
//	cout << "\n";
}

int main()
{
	int i, j, k, l;
	int tc=0;

//	freopen();

	while(cin >> nop) {
		if(tc++) cout << "\n";
		M.clear();	List.clear();
		for(i=1; i<=nop; i++) {
			cin >> name;
			M.insert(pair<string, int> (string(name), 0));
			List.push_back(string(name));
		}
		for(i=1; i<=nop; i++) {
			amount = each = 0;
			cin >> donor >> amount >> nor;
			if(amount && nor){
				amount = amount/nor*nor;
				each = amount/nor;
				M[string(donor)] -= amount;
			}
			for(j=1; j<=nor; j++) {
				cin >> receiver;
				M[string(receiver)] += each;
			}
		}
	Print();
	}

	return 0;
}
