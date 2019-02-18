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

#define MAX 101

bool DP[MAX][MAX];

/**
** DESCRIPTION:
** Given a string, this method counts all palindrome substirngs
**
** COMPLEXITY:  Time Complexity O(N^2) and Space Complexity O(N^2)
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
** NOTE: For big N this DP solution will fail cause we need N^2 space that is impossible.
**/
int countPalinSubstrings(string str)
{
    int i, j, k, spanSize;
    int len = str.length();
    int ret = len;

    for(i = 0; i < len; i++) DP[i][i] = true;       // Each characters are palindrome
    for(i = 0; i < len-1; i++) {                    // For length 2 substrings
        if(str[i] == str[i+1]) {
            DP[i][i+1] = true;
            ret++;
        }
    }

    // This is for length 3 to len substirngs
    for(spanSize = 3; spanSize <= len; spanSize++) {
        for(i = 0; i <= len - spanSize; i++) {
            j = i + spanSize - 1;
            if(str[i] == str[j] && DP[i+1][j-1]) {
                DP[i][j] = true;
                ret++;
            }
        }
    }

    return ret;
}

/**
** DESCRIPTION:
** Given a string, this method counts all palindrome substirngs
**
** COMPLEXITY:  Time Complexity O(N^2) and no space needed
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
int countPalinSubstringsGreedy(string str)
{
    int i, j, k, l, r, center;
    int len = str.length();
    int ret = 0;

    // Each index is considered as center of palindrome
    for(center = 0; center < len; center++) {

        // This segment for ODD length palindromes
        l = center; r = center;
        while(l >= 0 && r <= len-1 && str[l] == str[r]) {
            l--; r++;
            ret++;
        }

        // This segment for EVEN length palindromes
        l = center; r = center+1;
        while(l >= 0 && r <= len-1 && str[l] == str[r]) {
            l--; r++;
            ret++;
        }
    }
    return ret;
}

int main()
{
    //READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string str;

    while(cin >> str) {
        cout << countPalinSubstrings(str) << " " << countPalinSubstringsGreedy(str) << endl;
    }

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
7
5
8
4


**/
