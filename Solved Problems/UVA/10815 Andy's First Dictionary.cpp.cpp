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

string input, line, word;
map<string, bool> msb;
map<string, bool>::iterator It;

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int i, j, k;
    int TC, tc;

    input = "";
    while(getline(cin, line)) {
        if(line.SZ != 0) {
            FOR(i, 0, line.SZ-1)
                if( isalpha(line[i]))
                    line[i] = tolower(line[i]);
                else line[i] = ' ';
            input += (" " + line);
        }
    }

    stringstream ss(input);

    while( ss >> word) {
        if(msb.find(word) == msb.end())
            msb[word] = true;
    }

    for(It = msb.begin(); It != msb.end(); It++)
        cout << (*It).first << "\n";

    msb.clear();
	return 0;
}
