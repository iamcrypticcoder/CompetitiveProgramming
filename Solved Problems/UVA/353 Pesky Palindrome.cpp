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


using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

bool isPalindrome(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    if(temp == str) return true;
    return false;
}


int main()
{
    string mainStr;
    VS palins;

    while( cin >> mainStr) {
        for(int idx = 0; idx < mainStr.size(); idx++)
            for(int len = 1; len <= mainStr.size() - idx; len++) {
                string subString = mainStr.substr(idx, len);
                if(isPalindrome(subString)) {
                    if(find(palins.begin(), palins.end(), subString) == palins.end())
                        palins.push_back(subString);
                }
            }
        cout << "The string '" << mainStr << "' contains " << palins.size() << " palindromes.\n";
        palins.clear();
    }

	return 0;
}
