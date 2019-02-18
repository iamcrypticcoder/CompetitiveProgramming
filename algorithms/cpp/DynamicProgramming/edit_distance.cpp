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
int cost[MAX+7][MAX+7];
// '3' denotes insert, '2' denotes remove, '1' denotes replace
int track[MAX+7][MAX+7];

int editDistTD(int m, int n)
{
    if(cost[m][n] != -1) return cost[m][n];

    if(m == 0 && n == 0) {
        track[m][n] = 0;
        return cost[m][n] = 0;
    }

    if(m == 0) {
        track[m][n] = 3;
        return cost[m][n] = n;
    }
    if(n == 0) {
        track[m][n] = 2;
        return cost[m][n] = m;
    }

    if(s1[m-1] == s2[n-1]) {
        track[m][n] = 1;
        return cost[m][n] = editDistTD(m-1, n-1);
    }

    int minCost = min(editDistTD(m, n-1), min(editDistTD(m-1, n), editDistTD(m-1,n-1)));

    if(minCost == cost[m-1][n-1]) track[m][n] = 1;
    else if(minCost == cost[m-1][n]) track[m][n] = 2;
    else track[m][n] = 3;

    return cost[m][n] = 1 + minCost;
}

int editDistBU()
{
    int m = s1.length(), n = s2.length(), minCost;

    cost[0][0] = track[0][0] = 0;

    FOR(i, 1, m) {
        cost[i][0] = i;
        track[i][0] = 2;
    }

    FOR(i, 1, n) {
        cost[0][i] = i;
        track[0][i] = 3;
    }

    FOR(i, 1, m) FOR(j, 1, n) {
        if(s1[i-1] == s2[j-1]) {
            cost[i][j] = cost[i-1][j-1];
            track[i][j] = 1;
        } else {
            minCost = min(cost[i-1][j-1], min(cost[i-1][j], cost[i][j-1]));
            if(minCost == cost[i-1][j-1]) {
                cost[i][j] = cost[i-1][j-1] + 1;
                track[i][j] = 1;
            } else if(minCost == cost[i-1][j]) {
                cost[i][j] = cost[i-1][j] + 1;
                track[i][j] = 2;
            } else {
                cost[i][j] = cost[i][j-1] + 1;
                track[i][j] = 3;
            }
        }
    }
    return cost[m][n];
}

void printOps(int i, int j)
{
    if(track[i][j] == 0) return;
	if(track[i][j] == 1) {
		printOps(i-1, j-1);
		if(cost[i][j] != cost[i-1][j-1]) cout << "Replace " << s2[j-1] << " on " << s1[i-1] << "\n";
	} else if(track[i][j] == 2) {
		printOps(i-1, j);
		cout << "Delete " << s1[i-1] << " " << i << "\n";
	} else {
		printOps(i, j-1);
		cout << "Insert " << s2[j-1] << " " << j << "\n";
	}
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
        memset(cost, -1, sizeof(cost));
        cout << editDistTD(s1.length(), s2.length()) << endl;
        //cout << editDistBU() << endl;
        printOps(s1.length(), s2.length());
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
