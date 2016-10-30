#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

#define SQR(x) ((x)*(x))
#define PI 2 * acos(0.0)

int main()
{
    double a, b, c, s, radiusInner, radiusOuter;
    double areaTri, areaInner, areaOuter;
    double roses, violets, sunflowers;

    while(cin >> a >> b >> c) {
        s  = (a+b+c) / 2;

        areaTri = sqrt(fabs(s*(s-a)*(s-b)*(s-c)));
        radiusInner = areaTri / s;
        radiusOuter = (a * b * c) / (4 * areaTri);

        roses = PI * SQR(radiusInner);
        violets = areaTri - roses;
        sunflowers = PI * SQR(radiusOuter) - areaTri;

        printf("%.4lf %.4lf %.4lf\n", sunflowers, violets, roses);

    }

    return 0;
}
