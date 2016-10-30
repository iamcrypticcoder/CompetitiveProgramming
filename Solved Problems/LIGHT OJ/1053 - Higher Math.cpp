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

#define SQR(x) ((x)*(x))


int main()
{
   // READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    int a, b, c, Max;

    scanf("%d", &TC);
   // cin >> TC;

    FOR(tc, 1, TC) {
        scanf("%d %d %d", &a, &b, &c);

        printf("Case %d: ", tc);
        a = SQR(a);
        b = SQR(b);
        c = SQR(c);

        if(a == b + c)
            printf("yes\n");
        else if(b == a + c)
            printf("yes\n");
        else if(c == a + b)
            printf("yes\n");
        else printf("no\n");




    }

    return 0;
}

