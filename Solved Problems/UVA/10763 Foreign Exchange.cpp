#include <iostream>
#include <math.h>
#include <stdio.h>
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
typedef pair<int, int> II;
typedef map<II, int> MIIi;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int CANDIDATE;
MIIi m;

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int u, v;

    while(cin >> CANDIDATE) {
        if(CANDIDATE == 0) break;

        FOR(i, 1, CANDIDATE) {
            cin >> u >> v;
            II ii = II(u, v);
            m[ii]++;
        }

        bool isPos = true;
        for(MIIi::iterator it = m.begin(); it != m.end(); it++) {
            II ii1 = it->first;
            II ii2 = II(ii1.second, ii1.first);

            if(m[ii1] != m[ii2]) {
                isPos = false;
                break;
            }
        }

        if(isPos == true)
            cout << "YES\n";
        else cout << "NO\n";

        m.clear();
    }

    return 0;
}

