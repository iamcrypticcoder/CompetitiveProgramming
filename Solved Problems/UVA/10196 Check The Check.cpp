/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.019
    Rank :      2503
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

char grid[9][9];

bool inGrid(int i, int j)
{
    return ( i >= 1 && i <= 8 && j >= 1 && j <= 8 );
}

bool isCheckedByPawn(int i, int j, int kingType)
{
    return kingType == WHITE ? (grid[i-1][j+1] == 'p' || grid[i-1][j-1] == 'p') :
                               (grid[i+1][j-1] == 'P' || grid[i+1][j+1] == 'P');
}

bool isCheckedByRook(int i, int j, int kingType)
{
    char rook = kingType == WHITE ? 'r' : 'R';

    // UP, RIGHT, DOWN, LEFT
    FOR(d, 0, 3) {
        int k = i + dx[d];
        int l = j + dy[d];
        while(inGrid(k, l)) {
            if(grid[k][l] == rook) return true;
            if(grid[k][l] != '.') break;
            k += dx[d];
            l += dy[d];
        }
    }

    return false;
}

bool isCheckedByBishop(int i, int j, int kingType)
{
    char bishop = (kingType == WHITE) ? 'b' : 'B';

    // UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
    FOR(d, 4, 7) {
        int k = i + dx[d];
        int l = j + dy[d];
        while(inGrid(k, l)) {
            if(grid[k][l] == bishop) return true;
            if(grid[k][l] != '.') break;
            k += dx[d];
            l += dy[d];
        }
    }
    return false;
}

bool isCheckedByQueen(int i, int j, int kingType)
{
    char queen = (kingType == WHITE) ? 'q' : 'Q';

    // UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
    FOR(d, 0, 7) {
        int k = i + dx[d];
        int l = j + dy[d];
        while(inGrid(k, l)) {
            if(grid[k][l] == queen) return true;
            if(grid[k][l] != '.') break;
            k += dx[d];
            l += dy[d];
        }
    }

    return false;
}

bool isCheckedByKing(int i, int j, int kingType)
{
    char queen = (kingType == WHITE) ? 'k' : 'K';

    // To all directions
    FOR(d, 0, 7) {
        int k = i + dx[d];
        int l = j + dy[d];
        if(grid[k][l] == queen) return true;
    }

    return false;
}

bool isCheckedByKnight(int i, int j, int kingType)
{
    char knight = (kingType == WHITE) ? 'n' : 'N';

    // To all directions
    FOR(d, 0, 7) {
        int k = i + dxKnightMove[d];
        int l = j + dyKnightMove[d];
        if(inGrid(k, l) && grid[k][l] == knight) return true;
    }

    return false;
}

bool isWhiteKingChecked(int i, int j)
{
    return (isCheckedByPawn(i, j, WHITE) ||
            isCheckedByRook(i, j, WHITE) ||
            isCheckedByBishop(i, j, WHITE) ||
            isCheckedByQueen(i, j, WHITE) ||
            isCheckedByKing(i, j, WHITE) ||
            isCheckedByKnight(i, j, WHITE)
            );
}
bool isBlackKingChecked(int i, int j)
{
    return (isCheckedByPawn(i, j, BLACK) ||
            isCheckedByRook(i, j, BLACK) ||
            isCheckedByBishop(i, j, BLACK) ||
            isCheckedByQueen(i, j, BLACK) ||
            isCheckedByKing(i, j, BLACK) ||
            isCheckedByKnight(i, j, BLACK)
            );
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    PI whiteKingPos, blackKingPos;

    tc = 1;
    while(1) {

        bool isEmpty = true;

        FOR(i, 1, 8)
            FOR(j, 1, 8) {
                cin >> grid[i][j];
                if(grid[i][j] != '.') isEmpty = false;
                if(grid[i][j] == 'k') blackKingPos = PI(i, j);
                else if(grid[i][j] == 'K') whiteKingPos = PI(i, j);
        }
        getchar();
        if(isEmpty) break;

        bool b = isBlackKingChecked(blackKingPos.first, blackKingPos.second);
        bool w = isWhiteKingChecked(whiteKingPos.first, whiteKingPos.second);

        if(b) printf("Game #%d: black king is in check.\n", tc++);
        else if(w) printf("Game #%d: white king is in check.\n", tc++);
        else printf("Game #%d: no king is in check.\n", tc++);

    }

    //cout << isCheckedByPawn(whiteKingPos.first, whiteKingPos.second, WHITE);
    //cout << isCheckedByRook(whiteKingPos.first, whiteKingPos.second, WHITE);
    //cout << isCheckedByBishop(whiteKingPos.first, whiteKingPos.second, WHITE);
    //cout << isCheckedByQueen(whiteKingPos.first, whiteKingPos.second, WHITE);

    return 0;
}

