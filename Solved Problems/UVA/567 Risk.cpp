
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

int dist[21][21];

void Init()
{
    FOR(i, 1, 20) {
        FOR(j, 1, 20)
            dist[i][j] = INF;
        dist[i][i] = 0;
    }

}
void FloydWarshall()
{
    FOR(k, 1, 20)
        FOR(i, 1, 20)
            FOR(j, 1, 20)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    int n, N, temp;
    int node, s, t;

    tc = 1;
    while(scanf("%d", &n) != EOF) {
        Init();
        FOR(node, 1, 19) {
            if(node != 1) scanf("%d", &n);

            FOR(j, 1, n) {
                scanf("%d", &temp);
                dist[node][temp] = dist[temp][node] = 1;
            }
        }

        FloydWarshall();

        printf("Test Set #%d\n", tc++);
        scanf("%d", &N);
//        cout << "Test Set #" << tc++ << "\n";
//        cin >> N;

        FOR(i, 1, N) {
            cin >> s >> t;
  //          printf("%2d to %2d: %d\n", s, t, dist[s][t]);
            printf("%2d to %2d: %d\n", s, t, dist[s][t]);
        }
        printf("\n");
    }

	return 0;
}
