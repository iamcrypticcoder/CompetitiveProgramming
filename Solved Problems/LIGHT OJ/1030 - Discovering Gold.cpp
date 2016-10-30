/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 0.001
    Rank : 3
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

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int N;
int cave[1001];
double E[1001];

void Expectation()
{
    E[N] = cave[N];
    E[N-1] = cave[N] + cave[N-1];

    FORD(i, N-2, 1) {
        int prob = N - i > 6 ? 6 : N - i;
        double sum = 0.0;
        for(int j=i+1, k=1; j<=N && k<=6; j++, k++) {
            sum += E[j];
        }
        E[i] = cave[i] + sum / prob;
    }
}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d", &N);

        FOR(i, 1, N) {
            scanf("%d", &cave[i]);
        }

        Expectation();

        printf("Case %d: %.9lf\n", tc, E[1]);

    }

    return 0;
}

