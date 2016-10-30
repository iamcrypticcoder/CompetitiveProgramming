#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)


int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int m, n;


    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> m >> n;
        int temp = m*n;
        cout  << "Case " << tc << ": ";

        if(m == 1) {
            cout << n << "\n";
            continue;
        }
        if(n == 1) {
            cout << m << "\n";
            continue;
        }

        if(m == 2 || n == 2) {
            int ans = (m*n)/8 * 4;
            if((m*n)%8 > 4) ans += 4;
            else ans += (m*n)%8;
            cout << ans << "\n";
            continue;
        }

        if(temp % 2 ==0)
            cout << (m*n)/2 << "\n";
        else cout << (m*n)/2+1 << "\n";

    }


    return 0;
}

