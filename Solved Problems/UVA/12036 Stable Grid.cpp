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

int grid[101][101];
MII m;
MII::iterator mi;

int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> N;

        FOR(i, 1, N)
            FOR(j, 1, N) {
                cin >> grid[i][j];
                m[grid[i][j]]++;
            }
        bool isStable = true;

        for(mi=m.begin(); mi != m.end(); mi++)
            if(mi->second > N) {
                isStable = false;
                break;
            }

        cout << "Case " << tc << ": ";
        if(isStable) cout << "yes\n";
        else cout << "no\n";

        m.clear();
    }

	return 0;
}
