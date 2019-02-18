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

#define MAX_NODE 10001
#define NUM_OF_CHAR 256       // natually 256 characters are available
#define BIG_PRIME 37

string txt, pat;

// This function returns (a^b) mod m.
LL BigMod (LL a, LL n, LL b)
{
	if (n == 1 ) return a % b;
	LL ans = BigMod(a,n / 2 ,b);
	ans = (ans * ans) % b;
	if (n % 2 == 1 ) return ans * a % b;
	return ans; return ans;
}

void RobinKarp(int Q)
{
    int i, j, k;
    int N = txt.length();
    int M = pat.length();
    int hashPat = 0;        // Hash value for Pattern
    int hashTxt = 0;        // Hash value for each m length substring of txt
    int d = NUM_OF_CHAR;
    int h = (int) BigMod(d, M-1, Q);
    cout << h << endl;

    // Calculate the hash value of pattern and first window of text
    for(i = 0; i < M; i++) {
        hashPat = (d*hashPat + pat[i]) % Q;
        hashTxt = (d*hashTxt + txt[i]) % Q;
    }
    cout << hashPat << endl;

    // Checking hash of all substring of length M
    for(i = 0; i <= N-M; i++) {
        cout << hashTxt << " ";
        // Checking hash value of current window
        if(hashPat = hashTxt) {
            // Check for characters one by one
            for(j = 0; j < M; j++) {
                if(txt[i+j] != pat[j]) break;
            }
            if(j == M) printf("Pattern found at index %d \n", i);
        }

        // Calulate hash value for next window of text
        if(i < N-M) {
            hashTxt = ( d * (hashTxt - txt[i]*h) + txt[i+M] ) % Q;
            if(hashTxt < 0) hashTxt += Q;
        }
    }
}

int main()
{
    //READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    getline(cin, txt);
    while(getline(cin, pat)) {
        RobinKarp(BIG_PRIME);
    }
    return 0;
}


