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
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;
typedef map<string, string> MSS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

// if in black position return 1 and vice versa.
bool inColor(int i, int j)
{
    return((i%2 == 0 && j%2 == 0) || (i%2 != 0 && j%2 != 0));
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int t, T, N;
    int r1, r2, c1, c2;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> T >> N;

        FOR(t, 1, T) {
            cin >> r1 >> c1 >> r2 >> c2;

            if(r1 > N || c1 > N || r2 > N || c2 > N)
                cout << "no move\n";
            else if(r1 == r2 && c1 == c2)
                cout << "0\n";
            else if(abs(r1-r2) == abs(c1-c2))           // If diagonal
                cout << "1\n";
            else if(inColor(r1, c1) == inColor(r2, c2))
                cout << "2\n";
            else cout << "no move\n";
        }
    }

 	return 0;
}
