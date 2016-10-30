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
#define EPS 1e-9
#define PI (2*acos(0.0))
#define TO_RAD (PI/180)
#define TO_DEG (180/PI)

#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

VS dic;

int degree(int a, int b)
{
    int L = min(dic[a].size(), dic[a].size());
    int ret = 0;
    FOR(i, 0, L-1) {
        if(dic[a][i] != dic[b][i]) break;
        ret++;
    }
    return ret;
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int QUERY, N, u, v;

    cin >> TC;

    FOR(tc, 1, TC) {
        scanf("%d", &N);

        dic = VS(N+1);

        FOR(i, 1, N) {
            cin >> dic[i];
        }

        scanf("%d", &QUERY);

        //cout << "Case " << tc << ":\n";
        printf("Case %d:\n", tc);
        FOR(i, 1, QUERY) {
            scanf("%d %d", &u, &v);
            //cout << degree(u, v) << "\n";
            printf("%d\n", degree(u, v));
        }

    }

	return 0;
}
