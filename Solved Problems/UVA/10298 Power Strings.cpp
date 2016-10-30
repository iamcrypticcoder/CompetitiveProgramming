// This problem is similar to UVA ID : 455

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
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2


int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int power;
    bool isMatch;
    string line,str;

    while(getline(cin, line)) {
        if(line == ".") break;


        power = 1;
        FOR(len, 1, line.SZ/2) {
            if(line.SZ % len == 0) {
                str = line.substr(0, len);
                isMatch = true;
                for(i = 0; i <= line.SZ - len; i += len)
                    if(str != line.substr(i, len)) {
                        isMatch = false;
                        break;
                    }
                if(isMatch) power = max(power, (int)line.SZ / len);
            }
        }

        cout << power << "\n";


    }

	return 0;
}
