#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <map>
#include <string>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

VVI G;
VI line;
VI imp_station;
int found_imp;
bool imp[10001];
VI dist;
VI color;
queue<int> Q;
int N, S;


void BFS(int s)
{
    int u, v;

    dist = VI(N+1, INF);
    color = VI(N+1, WHITE);

    dist[s] = 0;
    color[s] = GRAY;

    while(!Q.empty()) Q.pop();

    Q.push(s);

    found_imp = 0;
    while( ! Q.empty()) {
        u = Q.front();  Q.pop();

        if(imp[u] == true ) found_imp++;
        if(found_imp == imp_station.SZ) break;

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 2;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

int freq[10001];

double findAvg(int s)
{
    double ret = 0.0;

    FOR(i, 0, imp_station.SZ-1) {
        ret +=  dist[imp_station[i]];
    }

    return (ret / (imp_station.SZ-1));
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int u, v;
    double tempD;
    int tempI;

    cin >> TC;

    FOR(tc, 1, TC) {

        cin >> N >> S;

        G = VVI(N+1);

        memset(freq, 0, sizeof(freq));

        FOR(i, 1, S) {
            cin >> u;
            freq[u]++;
            while(cin >> v) {
                if(v == 0) break;
                freq[v]++;
                G[u].PB(v);
                G[v].PB(u);
                u = v;
            }
        }

        memset(imp, false, sizeof(imp));
        FOR(i, 1, N)
            if(freq[i] > 1) {
                imp_station.PB(i);
                imp[i] = true;
            }

        int ans_node = -1;
        double avg = INF;
        FOR(i, 0, imp_station.SZ-1) {
            BFS(imp_station[i]);
            if((tempD = findAvg(imp_station[i])) < avg ) {
                avg = tempD;
                ans_node = imp_station[i];
            }
        }

        cout << "Krochanska is in: " << ans_node << "\n";

        imp_station.clear();
    }


    return 0;
}
