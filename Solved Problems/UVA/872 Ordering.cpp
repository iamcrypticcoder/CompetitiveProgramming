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
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

VC symbol, result;
vector<bool> isUsed;
vector<bool> constrain[26];
int numOrdering;

bool isPossible(char ch)
{
    FOR(i, 0, result.SZ-1)
        if(constrain[ch-'A'][result[i] - 'A']  == true ) return false;
    return true;
}

void BackTrack(int len)
{
    if(len == symbol.SZ) {
        numOrdering++;
        cout << result[0];
        FOR(i, 1, result.SZ-1) cout << " " << result[i];
        cout << "\n";
        return;
    }

    FOR(i, 0, symbol.SZ-1) {
        if(isUsed[i] == false && isPossible(symbol[i])) {
            isUsed[i] = true;
            result.PB(symbol[i]);
            BackTrack(len+1);
            isUsed[i] = false;
            result.pop_back();
        }
    }
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string str, line;
    char ch;

    cin >> TC;
    getline(cin, line);

    FOR(tc, 1, TC) {
        if(tc > 1) cout << "\n";
        getline(cin, line);
        getline(cin, line);
        stringstream ss(line);
        while(ss >> ch)
            symbol.PB(ch);

        isUsed = vector<bool>(26, false);
        FOR(i, 0, 25)
            constrain[i] = vector<bool>(26, false);

        getline(cin, line);
        stringstream ss2(line);
        while(ss2 >> str)
            constrain[str[0] - 'A'][str[2] - 'A'] = true;

        sort(symbol.begin(), symbol.end());
        numOrdering = 0;
        BackTrack(0);

        if(numOrdering == 0)
            cout << "NO\n";

        symbol.clear();
        result.clear();
    }

	return 0;
}
