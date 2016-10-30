/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
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

#define MAX_LEN 1000000

int Y, P;
int a[MAX_LEN+7];

int lowerBound(int l, int r, int x)
{
    while(l < r) {
        int mid = l + (r-l)/2;
        if(x > a[mid]) l = mid + 1;
        else r = mid;
    }
    if(x > a[l]) return l+1;
    return l;
}

int upperBound(int l, int r, int x)
{
    while(l < r) {
        int mid = l + (r-l)/2;
        if(x < a[mid]) r = mid;
        else l = mid + 1;
    }
    if(x == a[l]) return l+1;
    return l;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    while(scanf("%d", &Y) == 1) {
        P = src();
        FOR(i, 0, P-1) scanf("%d", &a[i]);

        int maxPope = 0, firstPope, lastPope;
        for(i = 1; i <= a[P-1]-Y+1; i++) {
            j = i + Y - 1;

            //int low = lower_bound(a, a+P, i) - a;
            //int high = upper_bound(a, a+P, j) - a;
            int low = lowerBound(0, P-1, i);
            int high = upperBound(0, P-1, j);

            if(high - low > maxPope) {
                maxPope = high - low;
                firstPope = a[low];
                lastPope = (high > P-1 || a[high] > j) ? a[high-1] : a[high];
            }
        }
        printf("%d %d %d\n", maxPope, firstPope, lastPope);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
