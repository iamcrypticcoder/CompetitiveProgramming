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

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )

#define SQR(x) ((x)*(x))
#define BIT(mask,i) (mask & (1 << i))

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
typedef vector<vector<PII> > VVP;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2


int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string line, cmd, url, currentUrl;
    stack<string> back, forward;

    cin >> TC;
    getline(cin, line);

    FOR(tc, 1, TC) {
        currentUrl = "http://www.lightoj.com/";

        cout << "Case " << tc << ":\n";
        while(getline(cin, line)) {
            stringstream ss(line);

            ss >> cmd;

            if(cmd == "QUIT") {
                while(!forward.empty()) forward.pop();
                while(!back.empty()) back.pop();
                break;
            }

            if(cmd == "VISIT") {
                back.push(currentUrl);
                while(!forward.empty()) forward.pop();
                ss >> url;
                currentUrl = url;
                cout << currentUrl << "\n";
            }
            else if(cmd == "BACK") {
                if(back.empty()) {
                    cout << "Ignored\n";
                }
                else {
                    forward.push(currentUrl);
                    url = back.top();   back.pop();
                    currentUrl = url;
                    cout << currentUrl << "\n";
                }
            }
            else if(cmd == "FORWARD") {
                if(forward.empty()) {
                    cout << "Ignored\n";
                }
                else {
                    back.push(currentUrl);
                    url = forward.top();   forward.pop();
                    currentUrl = url;
                    cout << currentUrl << "\n";
                }
            }
        }
    }

	return 0;
}
