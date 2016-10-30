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

int digitValue(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return ch - 55;
    else if(ch >= 'a' && ch <= 'z')
        return ch - 87;
    else if(ch >= '0' && ch <= '9')
        return ch - '0';
}
// This function converts any base num to decimal num and and return the 10-base number as int
int toDecimal(string num, int base)
{
    int i, ret = 0;
    if(num.size() == 0) return ret;
    ret = digitValue(num[0]);

    for(i=1; i<num.size(); i++)
        ret = (ret *= base) + digitValue(num[i]);
    return ret;

/*
	int ret = 0, i;
	ret = num[0] - '0';
	for(i = 1; i<num.size(); i++)
		ret = ( ret *= base) + num[i]-'0';
	return ret;
*/
}

string hexToBinary(string hexNum)
{
    map<char, string> hexMap;
    hexMap['0'] = "0000";
    hexMap['1'] = "0001";
    hexMap['2'] = "0010";
    hexMap['3'] = "0011";
    hexMap['4'] = "0100";
    hexMap['5'] = "0101";
    hexMap['6'] = "0110";
    hexMap['7'] = "0111";
    hexMap['8'] = "1000";
    hexMap['9'] = "1001";
    hexMap['A'] = "1010";
    hexMap['B'] = "1011";
    hexMap['C'] = "1100";
    hexMap['D'] = "1101";
    hexMap['E'] = "1110";
    hexMap['F'] = "1111";

  //  cout << hexMap['D'];

    string ret = "";

    for(int i=0; i<hexNum.size(); i++) {
        ret += hexMap[hexNum[i]];
  //      cout << ret << "\n";
    }

    reverse(ret.begin(), ret.end());

    while(ret.size() != 13 ) {
        ret += "0";
 //       cout << ret << "\n";
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    int TC, tc;
    string hex1, hex2;
    char op;


    cin >> TC;

    while(TC--) {
        cin >> hex1 >> op >> hex2;

        cout << hexToBinary(hex1) << " " << op << " " << hexToBinary(hex2) << " = ";
        if(op == '+')
            cout << toDecimal(hex1, 16) + toDecimal(hex2, 16) << "\n";
        else if(op == '-')
            cout << toDecimal(hex1, 16) - toDecimal(hex2, 16) << "\n";
    }

    return 0;
}
