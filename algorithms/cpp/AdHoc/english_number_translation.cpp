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

#define MAX 10000

map<int, string> m;
LL billion  = 1000000000;
LL million  = 1000000;
LL thousand = 1000;
LL hundred  = 100;
LL twenty   = 20;
LL ten      = 10;

void Init()
{
   m[0] = "Zero";
   m[1] = "One";
   m[2] = "Two";
   m[3] = "Three";
   m[4] = "Four";
   m[5] = "Five";
   m[6] = "Six";
   m[7] = "Seven";
   m[8] = "Eight";
   m[9] = "Nine";
   m[10] = "Ten";
   m[11] = "Eleven";
   m[12] = "Tweleve";
   m[13] = "Thirteen";
   m[14] = "Fourteen";
   m[15] = "Fifteen";
   m[16] = "Sixteen";
   m[17] = "Seventeen";
   m[18] = "Eighteen";
   m[19] = "Nineteen";
   m[20] = "Twenty";
   m[30] = "Thirty";
   m[40] = "Fourty";
   m[50] = "Fifty";
   m[60] = "Sixty";
   m[70] = "Seventy";
   m[80] = "Eighty";
   m[90] = "Ninety";
   m[100] = "Hundred";
   m[1000] = "Thousand";
   m[1000000] = "Million";
   m[1000000000] = "Billion";
}

string Translate(LL num)
{
    LL x, rem;
    string ret;

    if(num >= billion) {
        x = num / billion;
        rem = num % billion;
        ret = Translate(x) + " Billion";
        if(rem) ret += " and " + Translate(rem);
    }
    else if(num >= million) {
        x = num / million;
        rem = num % million;
        ret = Translate(x) + " Million";
        if(rem) ret += " and " + Translate(rem);
    }
    else if(num >= thousand) {
        x = num / thousand;
        rem = num % thousand;
        ret = Translate(x) + " Thousand";
        if(rem) ret += " and " + Translate(rem);
    }
    else if(num >= hundred) {
        x = num / hundred;
        rem = num % hundred;
        ret = Translate(x) + " Hundred";
        if(rem) ret += " and " + Translate(rem);
    }
    else if(num > twenty) {
        x = (num / 10) * 10;
        num %= 10;
        ret = m[x];
        if(num) ret += " " + Translate(num);
    }
    else if(num >= ten) {
        ret = m[num];
    }
    else {
        ret = m[num];
    }

    return ret;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    Init();

    cout << Translate(123456789);

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
