#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>


using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

char valueToChar(int value)
{
    if(value >= 10)
        return (char)('A' + value - 10);
    return ((char)(value + 48));
}
// This function converts a 10 base number to any base and return the number as string
// 10 = A, 11 = B, 12 = C ...... 25 = Z
string toBase(LL num, int base)
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

string hexToBin(string hexNum)
{
    map<char, string> M;
    M.insert(pair<char, string>('0',"0000"));
    M.insert(pair<char, string>('1',"0001"));
    M.insert(pair<char, string>('2',"0010"));
    M.insert(pair<char, string>('3',"0011"));
    M.insert(pair<char, string>('4',"0100"));
    M.insert(pair<char, string>('5',"0101"));
    M.insert(pair<char, string>('6',"0110"));
    M.insert(pair<char, string>('7',"0111"));
    M.insert(pair<char, string>('8',"1000"));
    M.insert(pair<char, string>('9',"1001"));
    M.insert(pair<char, string>('A',"1010"));
    M.insert(pair<char, string>('B',"1011"));
    M.insert(pair<char, string>('C',"1100"));
    M.insert(pair<char, string>('D',"1101"));
    M.insert(pair<char, string>('E',"1110"));
    M.insert(pair<char, string>('F',"1111"));

    string ret;

    for(int i=0; i<hexNum.size(); i++)
        ret += M[hexNum[i]];

    return ret;
}

string decNum;
string binNum;
int oneInDec, numInHex;

int main()
{
    int tc, TC, i, j, k;

    cin >> TC;

    while(TC--) {
        cin >> decNum;

        binNum = toBase(atoi(decNum.c_str()), 2);
        oneInDec = 0;
        FOR(i, 0, binNum.size()-1)
            if(binNum[i] == '1')oneInDec++;

        binNum = hexToBin(decNum);
        numInHex = 0;
        FOR(i, 0, binNum.size()-1)
            if(binNum[i] == '1')numInHex++;

        cout << oneInDec << " " << numInHex << "\n";

    }

	return 0;
}
