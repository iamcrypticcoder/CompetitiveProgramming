/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.025
    Rank :      284
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
typedef pair<int, int> PI;
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

int P, Q;
string str;

// This function converts any base num to decimal num and and return the 10-base number as int
int charToValue(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return ch - 55;
    else if(ch >= 'a' && ch <= 'z')
        return ch - 87;
    else if(ch >= '0' && ch <= '9')
        return ch - '0';
}
// ANY BASE TO DECIMAL
LL toDecimal(string num, int base)
{
    LL i, ret = 0;
    if(num.size() == 0) return ret;
    ret = charToValue(num[0]);

    for(i=1; i<num.size(); i++)
        ret = (ret *= base) + charToValue(num[i]);
    return ret;
}

int main()
{
    //READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> P >> Q;

        str = "";
        if((double)P/2 <= Q) {                      // If we have enough 0's
            if(P & 1) {                     // If P is ODD
                str = "01";
                P = P - 1;
                Q = Q - 1;
                P /= 2;

                FOR(i, 1, P) {
                    str = str + "101";
                }
            } else {
                Q = P / 2;
                FOR(i, 1, Q) {
                    str = str + "101";
                }
            }
        } else {
            FOR(i, 1, Q) str += "101";
            FOR(i, 1, P-(2*Q)) str += '1';
        }

        //cout << str << endl;
        cout << toDecimal(str, 2) << endl;
    }

    return 0;
}

