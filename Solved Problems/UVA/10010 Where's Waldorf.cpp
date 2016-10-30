/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
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
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_LEN 1000001

int M, N, K;
char grid[51][51];
string p;
bool isFound;

void findWord(int x, int y)
{
    FOR(i, 0, 7) {
        int nx = x;
        int ny = y;
        int ptr = 0;
        while(nx >= 0 && nx < M && ny >= 0 && ny < N && ptr < p.length() && tolower(p[ptr]) == grid[nx][ny]) {
            nx += dx[i];
            ny += dy[i];
            ptr++;
        }
        if(ptr == p.length()) {
            isFound = true;
            break;
        }
    }
}

PII solution()
{
    PII loc;
    isFound = false;
    FOR(i, 0, M-1) {
        if(isFound) break;
        FOR(j, 0, N-1) {
            if(tolower(p[0]) == grid[i][j]) findWord(i, j);
            if(isFound) {
                loc = make_pair(i, j);
                break;
            }
        }
    }
    return loc;
}


int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> M >> N;

        FOR(i, 0, M-1) FOR(j, 0, N-1) {
            cin >> grid[i][j];
            grid[i][j] = tolower(grid[i][j]);
        }

        cin >> K;

        FOR(i, 1, K) {
            cin >> p;

            PII loc = solution();

            cout << loc.first + 1 << " " << loc.second + 1 << endl;
        }

        if(tc < TC) cout << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
