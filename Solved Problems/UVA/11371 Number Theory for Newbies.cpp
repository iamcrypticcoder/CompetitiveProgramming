#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2


int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    int i, j;
    string str;
    LL minN, maxN;

    while( getline( cin, str) ) {
        sort(str.begin(), str.end());

        minN = maxN = 0;
        int countZero = 0;
        for(i=str.SZ-1; i>=0; i--) {
            maxN = maxN * 10 + (str[i] - '0');
            if( str[i] == '0') countZero++;
        }

        for(i=0; i<str.SZ; i++)
            if( str[i] != '0') {
                minN = str[i] - '0';
                i = i+1;
                break;
            }

        FOR(j, 1, countZero)
            minN = minN * 10;

        for(; i<str.SZ; i++)
            minN = minN * 10 + (str[i] - '0');

        int k = (maxN - minN) / 9;

        cout << maxN << " - " << minN << " = ";
        cout << maxN - minN << " = " << "9 * " << k << "\n";


    }

    return 0;
}
