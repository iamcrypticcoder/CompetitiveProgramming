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
typedef unsigned long long ULL;
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

ULL ncr[31][31];
ULL fact[31];

void Binomial()
{
    ncr[0][0] = 0;

    FOR(i, 1, 30) {
        ncr[0][i] = 0;
        ncr[i][0] = 1;
    }
    ncr[1][1] = 1;

    fact[0] = 1;
    fact[1] = 1;
    FOR(n, 2, 30) {
        fact[n] = n * fact[n-1];
        FOR(k, 1, n)
            ncr[n][k] = ncr[n-1][k-1] + ncr[n-1][k];
    }

}

int main()
{
  //  READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    ULL n, k;

    Binomial();

    //cout << fact[7] * ncr[6][3] - fact[4] * ncr[6][3] * fact[3];
    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> n >> k;

        cout << "Case " << tc << ": ";
        if(k > n) {
            cout << "0\n";
            continue;
        }

        cout << SQR(ncr[n][k]) * fact[k] << "\n";

    }

    return 0;
}

