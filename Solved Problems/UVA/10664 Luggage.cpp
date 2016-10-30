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

#define WHITE 0
#define GRAY 1
#define BLACK 2

int POT1, POT2;
VI v;

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string line;
    int temp;

    cin >> TC;
    getchar();

    FOR(tc, 1, TC) {
        getline(cin, line);
        stringstream ss(line);
        while(ss >> temp)
            v.PB(temp);

        sort(v.begin(), v.end(), greater<int>());
       // cout << v[0];

        POT1 = POT2 = 0;
        FOR(i, 0, v.SZ-1) {
            if(POT1 == POT2)
                POT1 += v[i];
            else if(POT1 < POT2)
                POT1 += v[i];
            else POT2 += v[i];
        }

        if(POT1 == POT2) cout << "YES\n";
        else cout << "NO\n";

        v.clear();
    }

	return 0;
}
