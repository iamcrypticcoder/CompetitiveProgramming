/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.115
    Rank :      849
    Complexity: O(n^4)
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

#define MAX_NODE 10001

int N, M;
int mat[101][101];
int DP[101][101];

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    char ch;

    while(scanf("%d", &N)) {
        if(N == 0) break;
        scanf("%d", &M);


        FOR(i, 1, N) FOR(j, 1, M) {
            cin >> ch;
            DP[i][j] = ch - '0';

            if(i > 1) DP[i][j] += DP[i-1][j];       // Adding till previous row
            if(j > 1) DP[i][j] += DP[i][j-1];
            if(i > 1 && j > 1) DP[i][j] -= DP[i-1][j-1];
        }
        /*
        FOR(i, 1, N) {
            FOR(j, 1, M) cout << DP[i][j] << " ";
            cout << "\n";
        }
        */

        int countRect = 0;

        // This is a O(n^4) algo.
        FOR(i, 1, N) FOR(j, 1, M) {         // From this point
            FOR(k, i, N) FOR(l, j, M) {     // To this point
                int c = DP[k][l];

                if(i > 1) c -= DP[i-1][l];
                if(j > 1) c -= DP[k][j-1];
                if(i > 1 && j > 1) c += DP[i-1][j-1];

                if(c == (k - i + 1) * (l - j + 1)) countRect++;
            }
        }
        printf("%d\n", countRect);
    }

    return 0;
}

