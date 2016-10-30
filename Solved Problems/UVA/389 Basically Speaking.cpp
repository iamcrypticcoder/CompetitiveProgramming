#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

char valueToChar(int value)
{
    if(value >= 10)
        return (char)('A' + value - 10);
    return ((char)(value + 48));
}
// This function converts a 10 base number to any base and return the number as string
string toBase(int num, int base)
{
	string ret;

	if(num == 0) return "0";
	while(num != 0) {
		ret += valueToChar(num%base);
		num /= base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

// This function converts any base num to decimal num and and return the 10-base number as int
int charToValue(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return ch - 55;
    else if(ch >= 'a' && ch <= 'z')
        return ch - 87;
    else if(ch >= '0' && ch <= '9')
        return ch - '0';
}
int toDecimal(string num, int base)
{
    int i, ret = 0;
    if(num.size() == 0) return ret;
    ret = charToValue(num[0]);

    for(i=1; i<num.size(); i++)
        ret = (ret *= base) + charToValue(num[i]);
    return ret;
}
// ---------------------------------------------------------------------------------------

bool isInBase(string num, int base)
{
    for(int i=0; i<num.size(); i++)
        if(charToValue(num[i]) >= base) return false;
    return true;
}

int main()
{
    int TC, tc;
    string num, ans;
    int from, to;

    while(cin >> num >> from >> to) {
        int decValue = toDecimal(num, from);
        ans = toBase(decValue, to);

        if(ans.size() > 7) {
            printf("%7s\n", "ERROR");
        }
        else {
            printf("%7s\n", ans.c_str());
        }
    }
    return 0;
}
