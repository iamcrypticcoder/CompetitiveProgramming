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

#define MAX_DIMENSION 100
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
typedef struct {
    char name;
    int state;
} language;

language lang[26];                          // lang[0] denotes 'a'

int FloodFill(int i, int j, char ch);
void DFS()
{
    int i, j, c;

    FOR(i, 1, x)
        FOR(j, 1, y) {
            if(GRID[i][j] >= 'a' && GRID[i][j] <= 'z') {
                if(color[i][j] == WHITE) {
                    FloodFill(i, j, GRID[i][j]);
                    lang[GRID[i][j]-97].name = GRID[i][j];
                    lang[GRID[i][j]-97].state++;
                }
            }
        }
}

int FloodFill(int i, int j, char ch)
{
    int ret = 1;
    color[i][j] = GRAY;

    if(GRID[i-1][j]   == ch && color[i-1][j]   == WHITE)    ret += FloodFill(i-1, j, ch);
    if(GRID[i][j-1]   == ch && color[i][j-1]   == WHITE)    ret += FloodFill(i, j-1, ch);
    if(GRID[i][j+1]   == ch && color[i][j+1]   == WHITE)    ret += FloodFill(i, j+1, ch);
    if(GRID[i+1][j]   == ch && color[i+1][j]   == WHITE)    ret += FloodFill(i+1, j, ch);

    color[i][j] = BLACK;

    return ret;
}

int compFunc(const void *a, const void *b)
{
    if(((language*)a)->state == ((language*)b)->state)
        return ((language*)a)->name - ((language*)b)->name;
    return ((language*)b)->state - ((language*)a)->state;
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int TC, tc;
    int i, j , k;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        FOR(i, 1, x)
            FOR(j, 1, y) {
                cin >> GRID[i][j];
                color[i][j] = WHITE;
            }

        DFS();
        qsort(lang, 26, sizeof(language), compFunc);

        cout << "World #" << tc << "\n";

        FOR(i, 0, 26) {
            if(lang[i].state != 0) cout << lang[i].name << ": " << lang[i].state << "\n";
            lang[i].state = 0;
        }


    }

	return 0;
}
