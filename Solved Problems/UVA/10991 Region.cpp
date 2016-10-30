#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


#define SQR(x) ((x)*(x))
#define PI (2*acos(0.0))
#define TO_DEG (180/PI)


int main()
{
    int TC, tc;
    double r1, r2, r3;
    double a, b, c, s, AREA;        // Length of three 3 edge of triangle
                                    // s is semi-perimeter, A is area of triangle

    double  A, B, C;                 // Three angle of triangle.
    cin >> TC;

    while(TC--) {
        cin >> r1 >> r2 >> r3;
        a = r1 + r2;
        b = r1 + r3;
        c = r2 + r3;

        s = (a + b + c) / 2;

        AREA = sqrt(fabs(s * (s-a) * (s-b) * (s-c)));

//        C = acos(.0823495);
//        cout << (SQR(a) + SQR(b) - SQR(c)) / (2*a*b) << "\n";
 //       cout << (SQR(a) + SQR(c) - SQR(b)) / (2*a*c) << "\n";
 //       cout << (SQR(b) + SQR(c) - SQR(a)) / (2*b*c) << "\n";

        C = acos( (SQR(a) + SQR(b) - SQR(c)) / (2*a*b) );
        B = acos( (SQR(a) + SQR(c) - SQR(b)) / (2*a*c) );
        A = acos( (SQR(b) + SQR(c) - SQR(a)) / (2*b*c) );

        // Now minus arc area from three circles;

        AREA -= (PI*SQR(r1) * C / (2*PI));
        AREA -= (PI*SQR(r2) * B / (2*PI));
        AREA -= (PI*SQR(r3) * A / (2*PI));

        printf("%.6f\n", AREA);
    }

    return 0;
}
