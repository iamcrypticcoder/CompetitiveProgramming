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

#define MAX_LEN 10000

int P[MAX_LEN];

string preProcess(string str)
{
    string ret = "^";
    int len = str.length();

    if(len == 0) return "^$";

    for(int i=0; i < len; i++) {
        ret += "#" + str.substr(i, 1);
    }
    ret.append("#$");

    return ret;
}

/**
** DESCRIPTION:
** Given a string, this method counts all palindrome substirngs
**
** COMPLEXITY:  Time Complexity O(N) and Space complexity O(N)
**
** INPUT:
** A string
**
** OUTPUT:
** Number of palindrome substrings exist in the given string
**
** CONDITION(S):
**
** RELIABILITY:
**
** NOTE:
**/
string manacherLongestPalinSubstring(string S)
{
    int i, j;
    string T = preProcess(S);
    int len = T.length();
    int C = 0, R = 0;

    for(i = 1; i < len-1; i++) {
        int iMirror = 2*C - i;  // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R - i, P[iMirror]) : 0;

        // Attempt to expand palindrome centered at i
        while(T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if(i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for(i = 1; i < len-1; i++) {
        if(P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    return S.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}

/**
** DESCRIPTION:
** Given a string, this method counts all palindrome substirngs
**
** COMPLEXITY:  Time Complexity O(N) and Space complexity O(N)
**
** INPUT:
** A string
**
** OUTPUT:
** Number of palindrome substrings exist in the given string
**
** CONDITION(S):
**
** RELIABILITY: SRM-607
**
** NOTE:
**/
int countPalinSubstrings(string S)
{
    int i, j;
    string T = preProcess(S);
    int len = T.length();
    int C = 0, R = 0;
    int ret = 0;

    for(i = 1; i < len-1; i++) {
        int iMirror = 2*C - i;  // equals to i' = C - (i-C)

        P[i] = (R > i) ? min(R - i, P[iMirror]) : 0;

        // Attempt to expand palindrome centered at i
        while(T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;

        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if(i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        ret += (P[i]+1) / 2;
    }
    //FOR(i, 1, len-2) cout << P[i]+1 << " " << endl;

    return ret;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    string str;

    while(cin >> str) {
        memset(P, 0, sizeof P);
        cout << countPalinSubstrings(str) << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
INPUT
-------
bcacb
bcac
topcoder
zaz
12212321

OUTPUT
-------
bcacb
cac
t
zaz


**/
