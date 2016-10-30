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

double L[1000001];

void GenLog()
{
    L[0] = 0;
    FOR(i, 1, 1000000) {
  //      cout << i << "\n";
        L[i] = L[i-1] + log10(i);
    }
}

int main()
{
  //  READ("input.txt");
//WRITE("output.txt");

    int TC, tc;
    int n, base;

    GenLog();

    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> n >> base;

        double ans = L[n] / log10(base);
        ans = floor(ans) + 1;

        cout << "Case " << tc << ": ";
        printf("%.0lf\n", ans);
    }
    return 0;
}

