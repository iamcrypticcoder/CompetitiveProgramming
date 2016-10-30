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

long long a[100001];

int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int K, C, N;
    LL sum;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> K >> C >> N >> a[1];

        FOR(i, 2, N)
            a[i] = (K * a[i-1] + C) % 1000007;

        sort(a+1, a+1+N);

        sum = 0;
        FOR(i, 1, N) {
            sum += (((i - 1) - (N - i)) * a[i]);
        }

        cout << "Case " << tc << ": ";
        cout << sum << "\n";
    }

	return 0;
}
