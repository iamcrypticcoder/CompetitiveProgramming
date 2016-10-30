#include <cstdio>
#include <cmath>
#include <iostream>
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

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

VS dict;
string puzzle;
unsigned char puzzleTable[27];

unsigned char table[1001][27];

void Parse(string temp)
{
	int i, j;
	
	memset(puzzleTable, 0, sizeof(puzzleTable));

	for(i=0; i<temp.size(); i += 2)
		puzzleTable[temp[i]-'a'+1]++;
}

int main()
{
	string temp;
	int i, j;
	int matched, count = 0;
	bool isOk;

	memset(table, 0, sizeof(table));

	while(true) {
		cin >> temp;
		if(temp == "#") break;
		dict.push_back(temp);
		for(i=0; i<temp.size(); i++)
			table[count][temp[i]-'a'+1]++;
		count++;
	}

	getline(cin, temp);
	while(getline(cin, temp) && temp != "#") {
		Parse(temp);
		count = 0;
		for(i=0; i<dict.size(); i++) {
			isOk = 1;
			for(j=0; j<dict[i].size(); j++)
				if(table[i][dict[i][j]-'a'+1] != 0) 
					if(puzzleTable[dict[i][j]-'a'+1] < table[i][dict[i][j]-'a'+1] ) {
						isOk = 0;
						break;
					}
			if(isOk) count++;
		}
		cout << count << "\n";
	}

	return 0;
}