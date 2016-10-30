#include <cstdio>
#include <cmath>
#include <iostream>
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

const int PRIME = 131071;

string str;

/*
void masud()
{
	int i;
	for(i=1; i<=10000; i++)
		str += '1';
}
*/

int main()
{	
	int i, N, length;
	char ch;

//	masud();

	while(cin >> ch && ch != '#') {
		str += ch;
		while(cin >> ch && ch != '#') 
			str += ch;
	
		length = str.size();
		N = str[0] - '0';
		for(i=1; i<length; i++) {
			N *= 2;
			N += str[i] - '0';
			if(N >= PRIME) N %= PRIME;
		}
		if(N == 0)	cout << "YES\n";
		else cout << "NO\n";
		str.clear();
	}

	return 0;
}