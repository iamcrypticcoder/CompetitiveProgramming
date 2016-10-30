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

#define MAXN 1000
#define MOD 10056
VVI stirling2;          // Second kind of stirling number
VI fact;

void GenerateStirling2()
{
    stirling2 = VVI(MAXN+1);
    FOR(n, 0, MAXN)
        stirling2[n] = VI(n+1);

    stirling2[0][1] = 1;

    FOR(n, 1, MAXN) {
        stirling2[n][0] = 0;
        stirling2[n][1] = 1;
        stirling2[n][n] = 1;
    }

    FOR(n, 3, MAXN)
        FOR(k, 2, n-1)
            stirling2[n][k] = ( k * stirling2[n-1][k] + stirling2[n-1][k-1] ) % MOD;
}

void GenerateFact()
{
    fact = VI(MAXN+1);

    fact[0] = 1;

    FOR(n, 1, 1000)
        fact[n] = ( fact[n-1] * n ) % MOD;

}

void PrintStirling2()
{
    FOR(n, 0, MAXN) {
        FOR(k, 0, n)
            cout << stirling2[n][k] << "\t";
        cout << "\n";
    }

}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N, ans;

    GenerateStirling2();
    GenerateFact();

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> N;

        ans = fact[N];
        if(N != 1) ans = ans + 1;

        FOR(k, 2, N-1)
            ans = (ans + stirling2[N][k]*fact[k]) % MOD;

        cout << "Case " << tc << ": " << ans << "\n";

    }



	return 0;
}
