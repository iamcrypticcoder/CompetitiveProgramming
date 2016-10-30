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

int grid[201][201];
int DP[201][201];

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int N;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d", &N);

        FOR(i, 1, 2*N-1) {
            if(i <= N) {
                FOR(j, 1, i)
                    scanf("%d", &grid[i][j]);
            }
            else {
                FOR(j, 1, N - (i-N))
                    scanf("%d", &grid[i][j]);
            }
        }

        DP[1][1] = grid[1][1];
        FOR(i, 2, 2*N-1) {
            if( i <= N ) {
                FOR(j, 1, i)
                    DP[i][j] = grid[i][j] + max(DP[i-1][j], DP[i-1][j-1]);
            }
            else {
                FOR(j, 1, N - (i-N))
                    DP[i][j] = grid[i][j] + max(DP[i-1][j], DP[i-1][j+1]);
            }
        }

        //cout << "Case " << tc << ": " << DP[2*N-1][1] << "\n";
        printf("Case %d: %d\n", tc, DP[2*N-1][1]);
    }

    return 0;
}

