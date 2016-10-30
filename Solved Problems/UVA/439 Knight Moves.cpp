/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.045
    Rank :      2637
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

#define MAX 8           // Chessboard contains 8 rows and 8 columns

int dist[MAX][MAX];

bool onGrid(int a, int b)
{
    if(a >= 0 && a <= 7 && b >= 0 && b <= 7) return true;
    return false;
}

int BFS(PII src, PII dest)
{
    PII u, v;
    queue<PII> Q;

    FOR(i, 0, 7) FOR(j, 0, 7) dist[i][j] = INF;

    Q.push(src);
    dist[src.first][src.second] = 0;

    while( !Q.empty() ) {
        u = Q.front(); Q.pop();

        if(u == dest) {
            while(!Q.empty()) Q.pop();
            break;
        }

        int curDist = dist[u.first][u.second] + 1;

        // For all possible knight moves
        FOR(i, 0, 7) {
            v.first = u.first + dxKnightMove[i];
            v.second = u.second + dyKnightMove[i];

            if(onGrid(v.first, v.second)) {
                if(curDist < dist[v.first][v.second]) {
                    Q.push(v);
                    dist[v.first][v.second] = curDist;
                }
            }
        }
    }
    return dist[dest.first][dest.second];
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string str1, str2;
    PII src, dest;

    while(cin >> str1 >> str2) {
        src.first = (int) (str1[0] - 'a');
        src.second = (int) (str1[1] - '1');

        dest.first = (int) (str2[0] - 'a');
        dest.second = (int) (str2[1] - '1');

        printf("To get from %s to %s takes %d knight moves.\n", str1.c_str(), str2.c_str(), BFS(src, dest));
    }
    return 0;
}
