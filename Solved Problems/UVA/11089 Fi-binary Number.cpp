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

#define PQ priority_queue
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

LL fib[50];
int totalFib;

void GenerateFib()
{
    fib[1] = 1;
    fib[2] = 2;
    totalFib = 2;

    FOR(i, 3, 50) {
        fib[i] = fib[i-1] + fib[i-2];
        totalFib++;
        if(fib[i] > 1e9) break;
    }

}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int i, n;

    GenerateFib();

   // cout << fib[49];

    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> n;

        for(i = 44; i >= 1; i--) {
            if(n >= fib[i]) break;
        }

        //cout << "Case " << tc << ": ";
        cout << "1";
        bool zeroPlaced = 1;
        n -= fib[i];
        for(--i; i>=1; i--) {
            if(n >= fib[i]) {
                n -= fib[i];
                cout << "1";
            }
            else cout << "0";
        }
        cout << "\n";
    }

    return 0;
}

