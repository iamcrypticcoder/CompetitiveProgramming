/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
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

char a[205];
int b;

int Mod()
{
    LL ret = 0, s;

    if(a[0] == '-') s = 1;
    else s = 0;

    FOR(i, s, strlen(a)-1) {
        ret = ret*10 + (a[i] - '0');
        ret = ret % b;
    }

    return ret;
}
int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%s %d", &a, &b);
        b = abs(b);

        if(Mod() == 0) printf("Case %d: divisible\n", tc);
        else printf("Case %d: not divisible\n", tc);

    }
    return 0;
}

