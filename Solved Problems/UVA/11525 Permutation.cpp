#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

typedef long long LL;
typedef vector<int> VI;

VI v;

int main()
{
    int i, j, k;
    int TC, tc;
    int K, S;

    scanf("%d", &TC);

    while(TC--) {               // Dont convert this WHILE loop to FOR. GET TLE.
        scanf("%d", &K);

        FOR(i, 1, K)
            v.PB(i);

        scanf("%d", &S);
        printf("%d", v[S]);       // Since vector index start 0 I do not add 1
        v.erase(v.begin() + S);

        FOR(i, 2, K) {
            scanf("%d", &S);
            printf(" %d", v[S]);
            v.erase(v.begin() + S);
        }
        printf("\n");
    }

	return 0;
}
