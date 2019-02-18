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

#define MAX 100000
#define M_SIZE (2 * (1 << 17))

int N;
// lg(100000) = 16.60 = 17
int M[M_SIZE + 7];
int A[MAX + 7];

void processSegmentTree(int node, int l, int r)
{
    if(l == r) M[node] = l;
    else {
        processSegmentTree(2 * node, l, (l+r) / 2);
        processSegmentTree(2 * node + 1, (l+r) / 2 + 1, r);
        if(A[M[2 * node]] <= A[M[2 * node+1]])
            M[node] = M[2 * node];
        else M[node] = M[2 * node + 1];
    }
}

int query(int node, int l, int r, int i, int j)
{
    // If the current interval doesn't intersect, the query interval return -1
    if(i > r || j < l) return -1;

    //if the current interval is included in the query interval return M[node]
    if (l >= i && r <= j) return M[node];

    // Compute the minimum position in the left and right part of the interval
    int p1 = query(2 * node, l, (l + r) / 2, i, j);
    int p2 = query(2 * node + 1, (l + r) / 2 + 1, r, i, j);

    // return the position where the overall minimum is
    if (p1 == -1)
        return M[node] = p2;
    if (p2 == -1)
        return M[node] = p1;
    if (A[p1] <= A[p2])
        return M[node] = p1;
    return M[node] = p2;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    while(cin >> N) {
        FOR(i, 0, N-1) cin >> A[i];

        processSegmentTree(1, 0, N-1);
        cout << M[1] << " " << M[2] << " " << M[3] << endl;
        cout << A[query(1, 0, N-1, 1, 7)] << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}


/**
Input:
10
2 4 3 1 6 7 8 9 1 7

Output:


**/
