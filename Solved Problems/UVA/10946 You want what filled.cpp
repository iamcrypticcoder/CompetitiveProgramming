#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define MAX_DIMENSION 50
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

char GRID[MAX_DIMENSION+1][MAX_DIMENSION+1];
char color[MAX_DIMENSION+1][MAX_DIMENSION+1];

int x, y;
vector<pair<char, int> > result;

int FloodFill(int i, int j, char ch);

void DFS()
{
    int i, j, c;

    FOR(i, 1, x)
        FOR(j, 1, y) {
            if(GRID[i][j] >= 'A' && GRID[i][j] <= 'Z') {
                if(color[i][j] == WHITE) {
                    int count = FloodFill(i, j, GRID[i][j]);
                    result.push_back(pair<char, int>(GRID[i][j], count));
                }
            }
        }
}

int FloodFill(int i, int j, char ch)
{
    int ret = 1;
    color[i][j] = GRAY;

// Remember it should not consider diagonally but it was not mentioned anywhwre in problem description.

 //   if(GRID[i-1][j-1] == ch && color[i-1][j-1] == WHITE)    ret += FloodFill(i-1, j-1, ch);
    if(GRID[i-1][j]   == ch && color[i-1][j]   == WHITE)    ret += FloodFill(i-1, j, ch);
 //   if(GRID[i-1][j+1] == ch && color[i-1][j+1] == WHITE)    ret += FloodFill(i-1, j+1, ch);
    if(GRID[i][j-1]   == ch && color[i][j-1]   == WHITE)    ret += FloodFill(i, j-1, ch);
    if(GRID[i][j+1]   == ch && color[i][j+1]   == WHITE)    ret += FloodFill(i, j+1, ch);
//    if(GRID[i+1][j-1] == ch && color[i+1][j-1] == WHITE)    ret += FloodFill(i+1, j-1, ch);
    if(GRID[i+1][j]   == ch && color[i+1][j]   == WHITE)    ret += FloodFill(i+1, j, ch);
//    if(GRID[i+1][j+1] == ch && color[i+1][j+1] == WHITE)    ret += FloodFill(i+1, j+1, ch);

    color[i][j] = BLACK;

    return ret;
}

bool CompFunction(pair<char, int> a, pair<char, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else return a.second > b.second;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int i, j , k;

    int tc = 1;
    while(cin >> x >> y) {
        if(x == 0 && y == 0) break;
        FOR(i, 1, x)
            FOR(j, 1, y) {
                cin >> GRID[i][j];
                color[i][j] = WHITE;
            }

        DFS();
        sort(result.begin(), result.end(), CompFunction);

        cout << "Problem " << tc++ << ":\n";
        FOR(i, 0, result.size()-1) {
            cout << result[i].first << " " << result[i].second << "\n";
        }

        result.clear();

    }

	return 0;
}
