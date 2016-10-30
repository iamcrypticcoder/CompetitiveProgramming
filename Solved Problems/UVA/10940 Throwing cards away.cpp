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

int dp[500001];

void Generate()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=2; i<=500000; i *= 2) {
        dp[i] = i;
        dp[i+1] = 2;
    }

    FOR(i, 3, 500000) {
        if( ! dp[i] )
            dp[i] = 2 + dp[i-1];
    }
/*
    FOR(i, 1, 20)
        cout << i << "\t";
    cout << "\n";
    FOR(i, 1, 20)
        cout << dp[i] << "\t";
    cout << "\n";
    */
}

int main()
{
//    READ("input.txt");
 //   WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int input;

    Generate();

    while(cin >> input) {
        if(input == 0) break;

        cout << dp[input] << "\n";

    }
	return 0;
}
