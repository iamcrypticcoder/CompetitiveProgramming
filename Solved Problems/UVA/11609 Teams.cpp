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

LL BigMod (LL a, LL n, LL b)
{
    if (n == 1 ) return a % b;
    LL ans = BigMod(a,n / 2 ,b);
    ans = (ans * ans) % b;
    if (n % 2 == 1 ) return ans * a % b;
    return ans; return ans;
}


int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    int N;
    scanf("%d", &TC);
  //  cout << BigMod(2, 1, 7);

	FOR(tc, 1, TC) {
        scanf("%d", &N);

        LL ans;
        if( N == 1 ) ans = 1;
        else ans = ((N % 1000000007) * BigMod(2, N-1, 1000000007)) % 1000000007;

        printf("Case #%d: %lld\n", tc, ans);
	}

    return 0;
}

