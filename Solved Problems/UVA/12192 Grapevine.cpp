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

#define MAX_NM 500

int N, M, Q;
int h[MAX_NM+7][MAX_NM+7];
int L, U;

int solution()
{
    int ret = 0, temp;
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    FOR(i, 0, N-1) {
        int low = lower_bound(h[i], h[i] + M, L) - h[i];
        if(low < M) {
            x1 = i, y1 = low;
            FORD(j, N-1, 0) {
                int low = upper_bound(h[j], h[j] + M, U) - h[j];
                if(low < M) low = (h[j][low] == U) ? low : low-1;
                if(low == M) {
                    x2 = j, y2 = M-1;
                    temp = (x1 == x2 && y1 == y2) ? 1 : min(x2-x1+1, y2-y1+1);
                    ret = max(ret, temp);
                    break;
                } else {
                    if(low >= y1 && j >= i) {
                        x2 = j, y2 = low;
                        temp = (x1 == x2 && y1 == y2) ? 1 : min(x2-x1+1, y2-y1+1);
                        ret = max(ret, temp);
                    }
                }
            }
        }
    }

    /*
    int ret = 0, temp;
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    FOR(i, 0, N-1) {
        int low = lower_bound(h[i], h[i] + M, L) - h[i];
        if(low < M) {
            x1 = i, y1 = low;
            break;
        }
    }

    if(x1 == -1 && y1 == -1) return 0;

    FORD(i, N-1, 0) {
        int low = upper_bound(h[i], h[i] + M, U) - h[i];
        if(low < M) low = (h[i][low] == U) ? low : low-1;
        if(low == M) {
            x2 = i, y2 = M-1;
            temp = (x1 == x2 && y1 == y2) ? 1 : min(x2-x1+1, y2-y1+1);
            ret = max(ret, temp);
            break;
        } else {
            if(low >= y1) {
                x2 = i, y2 = low;
                temp = (x1 == x2 && y1 == y2) ? 1 : min(x2-x1+1, y2-y1+1);
                ret = max(ret, temp);
            }
        }
    }
*/
    /*
    int ret;
    if(x1 == x2 && y1 == y2) ret = 1;
    else ret = min(x2-x1+1, y2-y1+1);
        */
    return ret;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    double cl = clock();

    while(scanf("%d %d", &N, &M) == 2) {
        if(N == 0 && M == 0) break;

        FOR(i, 0, N-1) FOR(j, 0, M-1) scanf("%d", &h[i][j]);
        Q = src();
        FOR(i, 0, Q-1) {
            scanf("%d %d", &L, &U);
            int ans = solution();
            printf("%d\n", ans);
        }
        printf("-\n");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
