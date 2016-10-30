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


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

// bool a[32], b[32], c[32], d[32];
unsigned int a, b, c, d;
string A, B;


// This function convert a string to Decimal Integer.
unsigned int toInteger(string str)
{
	unsigned int ret = 0, i;
	ret = str[0] - '0';

	for(i = 1; i<=str.size()-1; i++)
		ret = (ret *= 10)+(str[i] - '0');
	return ret;
}

// This function converts a 10 base number to any base and return the number as string
string toBase(unsigned int num, unsigned int base)
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


int toDecimal(string num, int base)
{
	int ret = 0, i;
	ret = num[0] - '0';
	for(i = 1; i<num.size(); i++)
		ret = ( ret *= base) + num[i]-'0';
	return ret;
}

void showBinaryNumner(string s)
{
	int i;
	for(i=1; i <= 31-s.size(); i++)
		cout << '0';
	for(i=0; i < s.size(); i++)
		cout << s[i];
	
}
int main()
{
 int TC;
 int i, j, k;
 unsigned int up = 1 << 31;
 
 cin >> TC;

 FOR(i, 1, TC) {
   cin >> A >> B;
   a = toDecimal(A, 2);
   b = toDecimal(B, 2);
   
   cout << A << " " << B << "\n";
   
   while( b != 0 && b < up) {
     c = a ^ b;
     d = a & b;
     a = c;
     b = 2*d;
     A = toBase(a, 2);
     B = toBase(b, 2);
     
	  showBinaryNumner(A);
	  cout << " ";
	  if(b >= up) cout << "overflow";
	  else showBinaryNumner(B);
	  if(b != 0 && b < up)cout << "\n";
	  //     cout << A << " " << B << "\n";
   }
   if(i < TC)cout << "\n\n";
	else cout << "\n";
 }
   
    
	return 0;
}
