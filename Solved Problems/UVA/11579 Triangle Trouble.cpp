#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))
#define EPS 1e-9

#define MAX 10001

double sides[MAX];

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    int N;
    double s, area;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> N;
        FOR(i, 1, N)
            cin >> sides[i];

        sort(sides+1, sides+N+1);

        area = 0.0;
        FORD(i, N-2, 1) {
            if(sides[i] + sides[i+1] > sides[i+2]) {
                s = (sides[i] + sides[i+1] + sides[i+2]) / 2;
                area = max(area, sqrt(fabs(s*(s-sides[i])*(s-sides[i+1])*(s-sides[i+2]))));
//                printf("%.2lf\n", area);

            }
        }

        if(area < EPS)
            printf("0.00\n");
        else printf("%.2lf\n", area);

    }

    return 0;
}
