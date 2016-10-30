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
#include <stack>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
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


int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
	int n;
	int ans[3]; // 0 for Q, 1 for S, 2 for PQ;
    int cmd[1001], x[1001];
    int fromQ, fromS, fromPQ;
    //scanf("%d", &TC);
    //cin >> TC;

	while( scanf("%d", &n) != EOF) {
        ans[0] = ans[1] = ans[2] = 1;
        queue<int> Q;
        stack<int> S;
        priority_queue<int> pQ;

        FOR(i, 1, n)
            cin >> cmd[i] >> x[i];
        FOR(i, 1, n) {
            if(cmd[i] == 1) {
                Q.push(x[i]);
                S.push(x[i]);
                pQ.push(x[i]);
            }
            else {
                if(!Q.empty()) { fromQ = Q.front(); Q.pop(); }
                else fromQ = -1;
                if(!S.empty()) { fromS = S.top(); S.pop(); }
                else fromS = -1;
                if(!pQ.empty()) { fromPQ = pQ.top(); pQ.pop(); }
                else fromPQ = -1;

                if(x[i] != fromQ) ans[0] = 0;
                if(x[i] != fromS) ans[1] = 0;
                if(x[i] != fromPQ) ans[2] = 0;
            }
        }


        if(ans[0] + ans[1] + ans[2] >= 2)
            cout << "not sure\n";
        else if(ans[0] + ans[1] + ans[2] == 1) {
            if(ans[0]) cout << "queue\n";
            if(ans[1]) cout << "stack\n";
            if(ans[2]) cout << "priority queue\n";
        }
        else cout << "impossible\n";
        //cout << Q.size() << " " << S.size() << " " << pQ.size() << "\n";
        //while(!Q.empty()) Q.pop();
        //while(!S.empty()) S.pop();
        //while(!pQ.empty()) pQ.pop();
        //cout << Q.size() << " " << S.size() << " " << pQ.size() << "\n";
	}

    return 0;
}

