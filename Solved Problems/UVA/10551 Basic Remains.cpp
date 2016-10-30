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


int base, mod;
string num, temp;

int main()
{
	int i;
	int N, length;
	
	while(cin >> base && base != 0 && cin >> num >> temp) {
		length = num.size();
		mod = toDecimal(temp, base);
		N = num[0] - '0';
		N = N % mod;
		for(i=1; i<length; i++) {
			N *= base;
			N += (num[i] - '0');
			N %= mod;
		}
		cout << toBase(N, base) << "\n";

		num.clear();
		temp.clear();
	}
	return 0;
}