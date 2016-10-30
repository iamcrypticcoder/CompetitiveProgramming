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
    int temp;
    bitset<8> b[3];
    string line1, line2, str;

    cin >> TC;
    getline(cin, line1);

    FOR(tc, 1, TC) {
        getline(cin, line1);
        getline(cin, line2);

        FOR(i, 0, line1.size()-1)
            if(line1[i] == '.') line1[i] = ' ';
        FOR(i, 0, line2.size()-1)
            if(line2[i] == '.') line2[i] = ' ';

        stringstream ss(line1);
        i = 0;
        while(ss >> temp) {
            b[i++] = bitset<8>(temp);
        }
        bool ans = true;
        stringstream ss2(line2);
        i = 0;
        while(ss2 >> str) {
            if(str != b[i++].to_string()) {
                ans = false;
                break;
            }
        }

        cout << "Case " << tc << ": ";
        if(ans) cout << "Yes\n";
        else cout << "No\n";

    }

	return 0;
}
