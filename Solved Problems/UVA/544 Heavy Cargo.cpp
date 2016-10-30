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

MSI nodeMap;
int N, R;
int dist[201][201];

void Floyd()
{
    FOR(i, 1, N)    dist[i][i] = 0;

    FOR(k, 1, N)
        FOR(i, 1, N)
            FOR(j, 1, N)
                dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string s1, s2, s, d;
    int c;

    tc = 1;
    while(cin >> N >> R) {
        if(N == 0 && R == 0) break;
  //      if(tc > 1) cout << "\n";

        FOR(i, 1, N)    FOR(j, 1, N)    dist[i][j] = -INF;

        int nodeNum = 0;
        FOR(i, 1, R) {
            cin >> s1 >> s2 >> c;
            if(nodeMap.find(s1) == nodeMap.end()) nodeMap[s1] = ++nodeNum;
            if(nodeMap.find(s2) == nodeMap.end()) nodeMap[s2] = ++nodeNum;

            dist[nodeMap[s1]][nodeMap[s2]] = c;
            dist[nodeMap[s2]][nodeMap[s1]] = c;
        }

        cin >> s >> d;

        Floyd();

        cout << "Scenario #" << tc++ << "\n";
        cout << dist[nodeMap[s]][nodeMap[d]] << " tons\n\n";

        nodeMap.clear();
    }

	return 0;
}
