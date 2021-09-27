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

int GCD(int a,int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)   {   return a/GCD(a,b)*b;                }

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

string s1, s2;
int c[MAX+7][MAX+7];    // c[] is used to calculate the length.
// '3' denotes left, '2' denotes up, '1' denotes upper-left
int track[MAX+7][MAX+7];    // b[] is used to trace the LCS.

int lcsTD(int m, int n)
{
    if(c[m][n] != -1) return c[m][n];

    if(m == 0 || n == 0) {
        return c[m][n] = 0;
    }

    if(s1[m-1] == s2[n-1]) {
        track[m][n] = 1;
        return c[m][n] = 1 + lcsTD(m-1, n-1);
    }

    int maxVal = max(lcsTD(m-1, n), lcsTD(m, n-1));
    if(maxVal == c[m-1][n]) track[m][n] = 2;
    else track[m][n] = 3;

    return c[m][n] = maxVal;
}

int lcsBU()
{
    int m = s1.length(), n = s2.length(), maxVal;
    FOR(i, 0, m) c[i][0] = 0;
    FOR(i, 0, n) c[0][i] = 0;

    FOR(i, 1, m) FOR(j, 0, n) {
        if(s1[i-1] == s2[j-1]) {
            c[i][j] = c[i-1][j-1] + 1;
            track[i][j] = 1;        // From upper-left
        } else if(c[i-1][j] >= c[i][j-1]) {
            c[i][j] = c[i-1][j];
            track[i][j] = 2;		 // From north/up
        } else {
            c[i][j] = c[i][j-1];
			track[i][j] = 3;		 // From west/left
        }
    }
    return c[m][n];
}

void printLCS(int i,int j) {
	if (i==0 || j==0) return;
	if (track[i][j]==1) {
		printLCS(i-1,j-1);
		printf("%c",s1[i-1]);
	}
	else if (track[i][j]==2)
		printLCS(i-1,j);
	else
		printLCS(i,j-1);
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    while(cin >> s1 >> s2) {
        memset(c, -1 ,sizeof c);
        int lcsLength = lcsTD(s1.length(), s2.length());
        printf("LCS Length = %d\n", lcsLength);
        //cout << lcsBU() << endl;
        string result;
        printLCS(s1.length(), s2.length(), result);
        printf("LCS String = %s\n", result.c_str());
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
