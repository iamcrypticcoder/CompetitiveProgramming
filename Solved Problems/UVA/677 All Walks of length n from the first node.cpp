#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
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

int NODE, LENGTH;
VVI mat;
int len;
bool used[11];
VI path;
bool hasSol;

void BackTrack(int n)
{
    if(path.SZ-1 == LENGTH) {
        hasSol = true;
        cout << "(" << path[0];
        FOR(i, 1, path.SZ-1)
            cout << "," << path[i];
        cout << ")\n";
        return;
    }

    FOR(i, 1, NODE) {
        if(i != n && used[i] == false && mat[n][i] == 1) {
            used[i] = true;
            path.PB(i);
            BackTrack(i);
            path.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int temp;
    string line;

    bool hasNext = true;
    tc = 1;
    while(hasNext) {
        if(tc > 1)
            cout << "\n";

        cin >> NODE >> LENGTH;

        mat = VVI(NODE+1);
        FOR(i, 1, NODE)
            mat[i] = VI(NODE+1);

        FOR(i, 1, NODE)
            FOR(j, 1, NODE)
                cin >> mat[i][j];

        memset(used, false, sizeof(used));
        path.clear();
        path.PB(1);
        used[1] = true;
        hasSol = false;
        BackTrack(1);

        getchar();
        getline(cin, line);
        if(line == "-9999") hasNext = true;
        else hasNext = false;

        if(hasSol == false) cout << "no walk of length " << LENGTH << "\n";

        tc++;
    }

    return 0;
}

