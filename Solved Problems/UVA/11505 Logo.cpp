/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.068
    Rank :      332
*/
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define PI 2*acos(0.0)
#define TO_DEG 57.29577951

int main()
{
    freopen("input.txt", "r", stdin);

    int TC, tc;
    int N;
    string cmd;
    double val;

    cin >> TC;

    for(tc = 1; tc <= TC; tc++) {
        cin >> N;

        double x = 0;
        double y = 0;
        double theta = 0;

        for(int i=1; i <= N; i++) {
            cin >> cmd >> val;

            if(cmd == "fd") {
                x += val * cos(theta);
                y += val * sin(theta);
            } else if(cmd == "lt") {
                val = fmod(val, 360);
                theta += (val * (PI/180));
            } else if(cmd == "rt") {
                val = fmod(val, 360);
                theta -= (val * (PI/180));
            } else {
                x -= val * cos(theta);
                y -= val * sin(theta);
            }
        }

        printf ("%0.lf\n", round(sqrt(x * x + y * y)));
    }

    return 0;
}
