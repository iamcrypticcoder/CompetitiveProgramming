
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
pair<int, int> II;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    int a[3][3];
}STATE;

int stateToInt(STATE s)
{
    int ret = 0;
    FOR(i, 0, 2)
        FOR(j, 0, 2)
            ret = ((ret * 10) + s.a[i][j]);
    return ret;
}
STATE intToState(int n)
{
    STATE ret;
    FORD(i, 2, 0)
        FORD(j, 2, 0) {
            ret.a[i][j] = n % 10;      n/=10;
        }
    return ret;
}

map<int, int> parent;          // to store parent
map<int, string> work;         // to store works
queue<int> Q;

void BFS()
{
    int ui, vi, temp;
    STATE u, v;

    parent[123456789] = -1;
    Q.push(123456789);

    while( !Q.empty() ) {
        ui = Q.front();     Q.pop();
        u = intToState(ui);

 //       cout << ui << "\n";

        // For Horizontal Move
        FOR(row, 0, 2) {
            v = u;
            temp = v.a[row][0];
            v.a[row][0] = v.a[row][1];
            v.a[row][1] = v.a[row][2];
            v.a[row][2] = temp;
            vi = stateToInt(v);
            if(parent.find(vi) == parent.end()) {
                parent[vi] = ui;
                work[vi] = string("H") + char(row+'1');
                Q.push(vi);
            }
        }
        // For Vertical Move
        FOR(col, 0, 2) {
            v = u;
            temp = v.a[2][col];
            v.a[2][col] = v.a[1][col];
            v.a[1][col] = v.a[0][col];
            v.a[0][col] = temp;
            vi = stateToInt(v);
            if(parent.find(vi) == parent.end()) {
                parent[vi] = ui;
                work[vi] = string("V") + char(col+'1');
                Q.push(vi);
            }
        }

    }
}

int main()
{
  //  READ("input.txt");
  //  WRITE("output.txt");

    int i, j;
    STATE s;
    int si, temp;

    BFS();

    while(cin >> s.a[0][0]) {
        if(s.a[0][0] == 0) break;
        cin >> s.a[0][1] >> s.a[0][2] >> s.a[1][0] >> s.a[1][1] >> s.a[1][2];
        cin >> s.a[2][0] >> s.a[2][1] >> s.a[2][2];
        temp = si = stateToInt(s);

        int dist = 0;
        string path = "";

        if(parent.find(temp) == parent.end()) {
            cout << "Not solvable\n";
            continue;
        }

        while(parent[temp] != -1) {
            dist++;
            path += work[temp];
            temp = parent[temp];
        }

        cout << dist << " " << path << "\n";
    }
    return 0;
}
