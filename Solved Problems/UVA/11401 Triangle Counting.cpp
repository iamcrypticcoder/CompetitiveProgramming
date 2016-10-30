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

ULL DP[1000001];

ULL sum(ULL n)
{
    return n*(n+1)/2;
}

void Cal()
{
    DP[4] = 1;

    FOR(i, 5, 1000000) {
        DP[i] = DP[i-1] + 2*sum(i/2 - 1);
        if(i % 2 == 0) DP[i] -= (i/2 - 1);
    }
}

int main()
{
  //  READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
	int N;

    Cal();

    while(scanf("%d", &N) != EOF) {
        if(N < 3) break;

        printf("%llu\n", DP[N]);
    }
    return 0;
}

