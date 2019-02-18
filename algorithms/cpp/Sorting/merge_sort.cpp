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

int items[10] = {5, 2, 9, 10, 3, 7, 6, 1, 4, 8};
// Check with 2 element set
//int items[2] = { 2, 1 };
// This is helper array as we know merge sort require twice memory of actual array.
int tmp[MAX];

void mergeSort(int items[], int l, int r)
{
    if(l >= r) return;
    if(l + 1 == r) {
        if(items[l] > items[r]) {
            int t = items[l];
            items[l] = items[r];
            items[r] = t;
        }
        return;
    }

    int m = (l + r) / 2;
    int i = l;
    int j = m + 1;
    int k = l;

    mergeSort(items, l, m);
    mergeSort(items, m+1, r);

    while(i <= m && j <= r) {
        if(items[i] > items[j]) tmp[k++] = items[j++];
        else tmp[k++] = items[i++];
    }

    while(i <= m) tmp[k++] = items[i++];
    while(j <= r) tmp[k++] = items[j++];
    for(i = l; i <= r; i++) items[i] = tmp[i];
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    int c = sizeof(items) / sizeof(int);
    mergeSort(items, 0, c-1);
    FOR(i, 0, c-1) cout << items[i] << " ";

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
