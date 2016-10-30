/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.019
    Rank :      113
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

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int n, m, temp;
    int pDisttributon[11];

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d %d", &n, &m);
        queue<PI> Q;
        memset(pDisttributon, 0, sizeof(pDisttributon));
        FOR(i, 0, n-1) {
            cin >> temp;
            Q.push(PI(i, temp));
            pDisttributon[temp]++;
        }

        int printTime = 0;
        while(1) {
            PI job = Q.front(); Q.pop();
            bool hasHigherJob = false;
            FOR(i, job.second+1, 9) if(pDisttributon[i]) hasHigherJob = true;

            if(hasHigherJob) {
                Q.push(job);
            } else {
                printTime++;
                pDisttributon[job.second]--;
                if(job.first == m) break;
            }
        }

        printf("%d\n", printTime);
    }

    return 0;
}

