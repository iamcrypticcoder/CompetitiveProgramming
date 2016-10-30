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

struct NODE {
    PII label;
    int dist;

    bool operator < ( const NODE &b ) const {
        return dist > b.dist;
    }
};

int ROW, COL;
VVI dist;
priority_queue<NODE> minQ;
VVI cost;

bool on_grid(PII p)
{
    if( p.first >= 1 && p.first <= ROW && p.second >= 1 && p.second <= COL) return true;
    return false;
}

void DIJKSTRA(PII s)
{
    dist = VVI(ROW + 1);
    FOR(i, 1, ROW)
        dist[i] = VI(COL + 1, INF);

    NODE u, v;

    dist[s.first][s.second] = cost[s.first][s.second];
    u.label = s;
    u.dist = cost[s.first][s.second];

    minQ.push(u);

    while( !minQ.empty() ) {
        u = minQ.top(); minQ.pop();

        if(u.label.first == ROW && u.label.second == COL) {
            while( !minQ.empty() ) minQ.pop();
            return;
        }

        // For i, j-1
        v.label.first = u.label.first;
        v.label.second = u.label.second-1;
        if( on_grid(v.label) && u.dist + cost[v.label.first][v.label.second] < dist[v.label.first][v.label.second]) {
            dist[v.label.first][v.label.second] = u.dist + cost[v.label.first][v.label.second];
            v.dist = dist[v.label.first][v.label.second];
            minQ.push(v);
        }

        // For i, j+1
        v.label.first = u.label.first;
        v.label.second = u.label.second+1;
        if( on_grid(v.label) && u.dist + cost[v.label.first][v.label.second] < dist[v.label.first][v.label.second]) {
            dist[v.label.first][v.label.second] = u.dist + cost[v.label.first][v.label.second];
            v.dist = dist[v.label.first][v.label.second];
            minQ.push(v);
        }

        // For i-1, j
        v.label.first = u.label.first-1;
        v.label.second = u.label.second;
        if( on_grid(v.label) && u.dist + cost[v.label.first][v.label.second] < dist[v.label.first][v.label.second]) {
            dist[v.label.first][v.label.second] = u.dist + cost[v.label.first][v.label.second];
            v.dist = dist[v.label.first][v.label.second];
            minQ.push(v);
        }

        // For i+1, j
        v.label.first = u.label.first+1;
        v.label.second = u.label.second;
        if( on_grid(v.label) && u.dist + cost[v.label.first][v.label.second] < dist[v.label.first][v.label.second]) {
            dist[v.label.first][v.label.second] = u.dist + cost[v.label.first][v.label.second];
            v.dist = dist[v.label.first][v.label.second];
            minQ.push(v);
        }
    }
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> ROW >> COL;

        cost = VVI(ROW+1, VI(COL+1));

        FOR(i, 1, ROW)
            FOR(j, 1, COL)
                cin >> cost[i][j];

        DIJKSTRA(PII(1,1));

        cout << dist[ROW][COL] << "\n";
    }

	return 0;
}
