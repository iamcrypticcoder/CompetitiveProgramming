/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
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

#define MAX 1000

int N;                  // Number of matrix to multiply
int a[MAX+7];           // dimension array consist of N+1 elements
int DP[MAX+7][MAX+7];   // DP table
int track[MAX+7][MAX+7];// Track table

int mcmTD(int i, int j) {
    if(DP[i][j] != -1) return DP[i][j];

    if(i == j) return DP[i][j] = 0;
    if(i + 1 == j) {
        track[i][j] = i;
        return DP[i][j] = a[i] * a[i+1] * a[j+1];
    }

    int ret = INF;
    FOR(k, i, j-1) {
        int c = a[i] * a[k+1] * a[j+1];
        int q = mcmTD(i, k) + c + mcmTD(k+1, j);
        if(q < ret) {
            ret = q;
            track[i][j] = k;
        }
    }
    return DP[i][j] = ret;
}

int mcmBU()
{
    int i, j, k, q, spanSize = 2;
    FOR(i, 0, N) DP[i][i] = 0;

    FOR(spanSize, 2, N) {
        FOR(i, 0, N-spanSize+1) {
            j = i + spanSize - 1;
            DP[i][j] = INF;
            FOR(k, i, j-1) {
                q = DP[i][k] + DP[k+1][j] + a[i] * a[k+1] * a[j+1];
                if(q < DP[i][j]) {
                    DP[i][j] = q;
                    track[i][j] = k;
                }
            }
        }
    }
    return DP[0][N-1];
}

void printSolution(int i, int j)
{
	if(i==j) cout << i;
	else {
		cout << '(';
		printSolution(i, track[i][j]);
		printSolution(track[i][j]+1, j);
		cout << ')';
	}
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    while(cin >> N) {
        FOR(i, 0, N) cin >> a[i];

        /*
        memset(DP, -1, sizeof DP);
        cout << mcmTD(0, N-1) << " ";
        printSolution(0, N-1);
        cout << endl;
        */

        cout << mcmBU() << " ";
        printSolution(0, N-1);
        cout << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
Input:
3
10 30 5 60
4
40 20 30 10 30
4
10 20 30 40 30
2
10 20 30

Output:
4500 ((01)2)
26000 ((0(12))3)
30000 (((01)2)3)
6000 (01)
**/
