#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

struct QUERY {
    int ID, period, outTime;

    bool operator < (const QUERY &b) const
    {
        if(outTime == b.outTime)
            return ID > b.ID;
        return outTime > b.outTime;
    }
};


int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    string str, line;
    int K;

    scanf("%d", &TC);
    //cin >> TC;
    priority_queue<QUERY> prioQ;
    QUERY q;
    while(getline(cin, line)) {
        if(line == "#") break;
        stringstream ss(line);

        ss >> str;
        ss >> q.ID;
        ss >> q.period;
        q.outTime = q.period;
        prioQ.push(q);
    }
    cin >> K;

    FOR(i, 1, K) {
        q = prioQ.top(); prioQ.pop();
        cout << q.ID << "\n";
        q.outTime += q.period;
        prioQ.push(q);
    }


    return 0;
}

