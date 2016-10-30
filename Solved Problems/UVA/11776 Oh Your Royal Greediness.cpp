/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.032
    Rank :      25
    Complexity: n*lg(n)
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

#define MAX 1000

struct Task {
    int s, e;       // start time and end time respectively

    /*
    bool operator < (const Task &b) const {
        if(s == b.s) return e < b.e;
        return s < b.s;
    }
    */
};

bool compTask(Task a, Task b)
{
    if(a.s == b.s) return a.e < b.e;
    return a.s < b.s;
}

int N;
Task tasks[MAX+1];
PQ<int, vector<int>, greater<int> > pq;

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    tc = 1;
    while(scanf("%d", &N) == 1) {
        if(N == -1) break;
        if(N == 0) {
            printf("Case %d: %d\n", tc++, 0);
            continue;
        }
        FOR(i, 0, N-1) scanf("%d %d", &tasks[i].s, &tasks[i].e);

        sort(tasks, tasks + N, compTask);

        pq = PQ<int, vector<int>, greater<int> >();
        pq.push(tasks[0].e);
        int numberPeople = 1;
        FOR(i, 1, N-1) {
            int endTime = pq.top();

            if(tasks[i].s > endTime) {
                pq.pop();
                pq.push(tasks[i].e);
            } else {
                numberPeople++;
                pq.push(tasks[i].e);
            }
        }

        printf("Case %d: %d\n", tc++, numberPeople);
    }

    return 0;
}


