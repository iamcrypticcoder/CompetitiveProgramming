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

string table[51];


bool Comp(string a, string b)
{
	for(int i = 0; i<a.size(); i++) {
		if(b[i] > a[i])
			return 0;
		else if(a[i] > b[i])
			return 1;
	}
		
}

int main()
{
	int N;

	string temp1, temp2, temp;

	int i, j;

	while(cin >> N && N != 0)
	{
		for(i=1; i<=N; i++)
			cin >> table[i];

		for(i=1; i < N; i++) 
			for(j=1; j <= N - i; j++) {
				temp1 = table[j] + table[j+1];
				temp2 = table[j+1] + table[j];

				if(!Comp(temp1, temp2))
				{
					temp = table[j];
					table[j] = table[j+1];
					table[j+1] = temp;
				}
			}

		for(i=1; i<=N; i++)
			cout << table[i];
		cout << "\n";


	}
	


	return 0;
}