
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>        // For memset function
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
    int elev, floor, dist;

    bool operator < ( const NODE &b ) const {
        return dist > b.dist;
    }
};

struct ELEV {
    int time;
    bool floors[100];
};
typedef vector<ELEV> VE;

int N, K;
VVI dist;
priority_queue<NODE> minQ;
VE elev;

void DIJKSTRA(int s)        // s means start floor
{
    dist = VVI(6, VI(100, INF));
    FOR(i, 1, N)
        dist[i][0] = 0;

    NODE u, v;

    u.dist = 0;
    u.floor = 0;

    FOR(i, 1, N) {
        if( elev[i].floors[0] == true ) {
            u.elev = i;
            minQ.push(u);
        }
    }

    while( !minQ.empty() ) {
        u = minQ.top();  minQ.pop();

        //cout << u.dist << " " << u.elev << " " << u.floor << "\n";

        FOR(i, 0, 99) {
            if( elev[u.elev].floors[i]) {
                int newDist = u.dist + elev[u.elev].time * abs(i - u.floor);
                if( newDist < dist[u.elev][i] ) {
                    v.dist = dist[u.elev][i] = newDist;
                    v.elev = u.elev;
                    v.floor = i;
                    minQ.push(v);
                }
            }
        }

        FOR(i, 1, N) {
            if(u.elev != i) {
                if( elev[i].floors[u.floor] ) {
                    v.elev = i;
                    v.dist = u.dist + 60;
                    v.floor = u.floor;
                    if( v.dist < dist[i][v.floor] ) {
                        dist[i][v.floor] = v.dist;
                        minQ.push(v);
                    }
                }
            }
        }
    }

}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int u, v;

    string line;

    while(cin >> N >> K) {

        elev = VE(6);

        FOR(i, 1, N)
            cin >> elev[i].time;

        getchar();

        FOR(i, 1, N) {
            getline(cin , line);
            stringstream ss(line);

            while( ss >> u ) {
                elev[i].floors[u] = true;
            }
        }

        DIJKSTRA(0);

        int minDist = INF;

        FOR(i, 1, N)
            if( dist[i][K] < minDist ) minDist = dist[i][K];

        if(minDist == INF)
            cout << "IMPOSSIBLE\n";
        else cout << minDist << "\n";
    }


    return 0;
}
