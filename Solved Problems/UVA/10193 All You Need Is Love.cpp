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

// This function converts any base num to decimal num and and return the 10-base number as int 
int toDecimal(string num, int base)
{
	int ret = 0, i;
	ret = num[0] - '0';
	for(i = 1; i<num.size(); i++)
		ret = ( ret *= base) + num[i]-'0';
	return ret;
}

int GCD(int a, int b)	{	return b==0 ? a : GCD(b, a%b); }

string S1, S2;

int main()
{
	int TC, gcd;

	cin >> TC;

	FOR(i,1, TC) {
		cin >> S1 >> S2;
		gcd = GCD( toDecimal(S1, 2),toDecimal(S2, 2) );
		if (gcd == 1)	cout << "Pair #" << i << ": Love is not all you need!\n";
		else	cout << "Pair #" << i << ": All you need is love!\n";
	}

	return 0;
}