// Do you know what is MINIMAL. MINIMAL means maximun of all minimuns.
// Accepted 0.128
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

#define MAX 1001

char grid[MAX][MAX];


int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int i, j, k;
    int TC, tc;
    int DIM;
    int minimal, minimum;
    bool isFound;

    while(cin >> DIM) {

        FOR(i, 1, DIM)
            FOR(j, 1, DIM)
                cin >> grid[i][j];


        minimal = -1;
        FOR(i, 1, DIM)
            FOR(j, 1, DIM) {
                if(grid[i][j] == '1') {
                    minimum = INF;
                    FOR(k, 1, DIM)
                        FOR(l, 1, DIM)
                            if(grid[k][l] == '3') {
                                minimum = min(minimum, abs(i-k) +  abs(j-l));
    //                            if(minimum == 4) cout << i << " " << j << " " << k << " " << l << "\n";
                            }
                }
                minimal = max(minimal, minimum);
            }

        cout << minimal << "\n";
    }
	return 0;
}


/*
// This code got TLE. Used BFS for shortest path.
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

VVI dist;
queue<pair<int, int> > Q;

int DIM;
char grid[1001][1001];
int minimum, minimal;

bool on_grid(pair<int, int> p)
{
    return (p.first >= 1 && p.first <= DIM && p.second >= 1 && p.second <= DIM);
}

int BFS(int si, int sj)
{
    pair<int, int> u, v;
    int cur_dist;

    dist = VVI(1001);
    FOR(i, 1, 1000)
        dist[i] = VI(1000, INF);

    dist[si][sj] = 0;
    while( !Q.empty() ) Q.pop();
    Q.push(make_pair(si, sj));

    while( !Q.empty() ) {
        u = Q.front();  Q.pop();

        if(grid[u.first][u.second] == '3') {
            minimum = dist[u.first][u.second];
            break;
        }

        cur_dist = dist[u.first][u.second] + 1;

        v = u;
        v.second -= 1;
        if(on_grid(v) && cur_dist < dist[v.first][v.second]) {
            dist[v.first][v.second] = cur_dist;
            Q.push(v);
        }

        v = u;
        v.second += 1;
        if(on_grid(v) && cur_dist < dist[v.first][v.second]) {
            dist[v.first][v.second] = cur_dist;
            Q.push(v);
        }

        v = u;
        v.first -= 1;
        if(on_grid(v) && cur_dist < dist[v.first][v.second]) {
            dist[v.first][v.second] = cur_dist;
            Q.push(v);
        }

        v = u;
        v.first += 1;
        if(on_grid(v) && cur_dist < dist[v.first][v.second]) {
            dist[v.first][v.second] = cur_dist;
            Q.push(v);
        }

    }

}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int i, j, k;
    int TC, tc;

    while(cin >> DIM) {

        FOR(i, 1, DIM)
            FOR(j, 1, DIM)
                cin >> grid[i][j];

        minimal = -1;
        FOR(i, 1, DIM)
            FOR(j, 1, DIM)
                if(grid[i][j] == '1') {
                    BFS(i, j);
                    if(minimum == INF) cout << i << " " << j << "\n";
                    minimal = max(minimal, minimum);
                }

        cout << minimal << "\n";
    }

	return 0;
}
*/
