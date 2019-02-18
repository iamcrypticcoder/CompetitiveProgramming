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
#define MOD 1000007

VVI stirling1, stirling2;

void generateStirling2()
{
    stirling2 = VVI(MAX+1);
    FOR(n, 0, MAX) stirling2[n] = VI(n+1);

    stirling2[0][1] = 1;

    FOR(n, 1, MAX) {
        stirling2[n][0] = 0;
        stirling2[n][1] = 1;
        stirling2[n][n] = 1;
    }

    FOR(n, 3, MAX)
        FOR(k, 2, n-1)
            stirling2[n][k] = (k * stirling2[n-1][k] + stirling2[n-1][k-1]) % MOD;
}

void generateStirling1()
{
    stirling1 = VVI(MAX+1);
    FOR(n, 0, MAX) stirling1[n] = VI(n+1);

    stirling1[0][1] = 1;

    FOR(n, 1, MAX) {
        stirling1[n][0] = 0;
        stirling1[n][n] = 1;
    }

    FOR(n, 2, MAX)
        FOR(k, 1, n-1)
            stirling1[n][k] = ((n-1) * stirling1[n-1][k] + stirling1[n-1][k-1]) % MOD;
}

void printStirling2()
{
    FOR(n, 0, 9) {
        FOR(k, 0, n)
            cout << stirling2[n][k] << "\t";
        cout << "\n";
    }
}

void printStirling1()
{
    FOR(n, 0, 9) {
        FOR(k, 0, n)
            cout << stirling1[n][k] << "\t";
        cout << "\n";
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    //generateStirling2();
    //printStirling2();

    //generateStirling1();
    //printStirling1();

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
