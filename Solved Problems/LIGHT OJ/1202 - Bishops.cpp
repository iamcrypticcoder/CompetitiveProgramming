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

int inColor(int i, int j)
{
    if((i+j) % 2 == 0) return BLACK;
    return WHITE;
}


int main()
{
//    READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    int r1, c1, r2, c2;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        printf("Case %d: ", tc);
        if(((r1+c1) & 1) == ((r2+c2) & 1)) {
            if(abs(r1 - r2) == abs(c1 - c2))           // If Diagonal
                printf("1\n");
            else printf("2\n");
        }
        else printf("impossible\n");

    }

    return 0;
}

