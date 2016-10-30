/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
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
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int N, R;
double pi[21];
double probA[21];
double probB;

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;

    tc = 0;
    while(scanf("%d %d", &N, &R) != EOF) {
        if(N == 0 && R == 0) break;
        FOR(i, 0, N-1) {
            scanf("%lf", &pi[i]);
            probA[i] = 0.0;
        }

        probB = 0.0;
        FOR(subset, 0, ((1 << N)-1)) {
            if(__builtin_popcount(subset) == R) {
                double temp = 1.0;
                FOR(i, 0, N-1) {
                    if(TEST_BIT(subset, i)) temp *= pi[i];
                    else temp *= (1 - pi[i]);
                }

                FOR(i, 0, N-1) if(TEST_BIT(subset, i)) probA[i] += temp;

                probB += temp;
            }
        }

        printf("Case %d:\n", ++tc);

        FOR(i, 0, N-1)
            printf("%.6lf\n", probA[i]/probB + EPS);
    }

    return 0;
}

