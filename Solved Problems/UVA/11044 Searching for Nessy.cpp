#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    int TC, N, M;

    cin >> TC;

    while(TC--) {
        cin >> N >> M;

        printf("%.0lf\n", ceil((double)(N-2)/3) * ceil((double)(M-2)/3));
    }

    return 0;
}
