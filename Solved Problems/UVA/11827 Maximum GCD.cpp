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

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )
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
typedef map<string, string> MSS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int GCD(int a, int b) { return b == 0 ? a : GCD(b, a%b); }

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string line;
    VI v;
    int g, maxGcd, temp;

    cin >> TC;
    getchar();

 //   cout << GCD(0, 5);

    FOR(tc, 1, TC) {
        getline(cin, line);
        stringstream ss(line);

        while(ss >> temp)
            v.PB(temp);

        maxGcd = 1;
        FOR(i, 0, v.SZ-1)
            FOR(j, i+1, v.SZ-1)
                if( (g = GCD(v[i], v[j])) > maxGcd )
                    maxGcd = g;

        cout << maxGcd << "\n";

        v.clear();
    }


	return 0;
}
