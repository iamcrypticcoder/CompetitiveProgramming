#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

string toTernary(int num)
{
    string ret;
    if(num == 0) return string("0");
    while(num) {
        ret += (num % 3) + '0';
        num /= 3;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int input;

    while(cin >> input) {
        if(input < 0) break;

        cout << toTernary(input) << "\n";
    }

    return 0;
}
