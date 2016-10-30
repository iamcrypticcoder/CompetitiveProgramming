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
#define BLANK 3

string str;
int R, C;
VVI grid;

void trav(int i, int r, int c, char dir)
{
    if(str[i] == 'B') grid[r][c] = BLACK;
    else if(str[i] == 'G') grid[r][c] = GRAY;
    else if(str[i] == 'W') grid[r][c] = WHITE;

    if( i == str.SZ-1 ) return;

    if( dir == 'R') {
        if(c+1 > C-1 || grid[r][c+1] != BLANK)
            trav(i+1, r+1, c, 'D');
        else trav(i+1, r, c+1, dir);
    }
    else if( dir == 'D') {
        if(r+1 > R-1 || grid[r+1][c] != BLANK)
            trav(i+1, r, c-1, 'L');
        else trav(i+1, r+1, c, dir);
    }
    else if( dir == 'L') {
        if(c-1 < 0 || grid[r][c-1] != BLANK)
            trav(i+1, r-1, c, 'U');
        else trav(i+1, r, c-1, dir);
    }
    else if( dir == 'U') {
        if(r-1 < 0 || grid[r-1][c] != BLANK)
            trav(i+1, r, c+1, 'R');
        else trav(i+1, r-1, c, dir);
    }

}

bool isBeau(int R, int C)
{
    if( R == 1 || C == 1) return false;

    grid = VVI(R);
    FOR(i, 0, R-1)
        grid[i] = VI(C, BLANK);

    trav(0, 0, 0, 'R');

    FOR(col, 0, C-1) {
        bool isSame = true;
        FOR(row, 0, R-2)
            if(grid[row][col] != grid[row+1][col]) return false;
    }

    return true;
}

bool Cal()
{
    int N = str.SZ;
    int root = (int)sqrt(N);

    FORD(i, root, 1)
        if( N % i == 0) {
            R = i;
            C = N / i;
            if( isBeau(R, C)) return true;
            R = N / i;
            C = i;
            if( isBeau(R, C) ) return true;
        }
    return false;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> str;

        cout << "Case " << tc << ": ";
        if( Cal() == true ) {
            cout << (R+C) << "\n";
        }
        else cout << "-1\n";
    }
return 0;
}
