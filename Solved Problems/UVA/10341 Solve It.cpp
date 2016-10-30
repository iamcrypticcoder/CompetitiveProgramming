#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define EPS 1e-8

int p, q, r, s, t, u;

double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

void Bisection()
{
    double xL = 0.0;
    double xU = 1.0;
    double xR = 0.5;

    double a = f(xL);
    double b = f(xU);
    if( (a > 0 && b > 0) || (a < 0 && b < 0) ) {
        cout << "No solution\n";
        return;
    }
    else if(a == 0.0) {
        printf("0.0000\n"); return;
    }
    else if(b == 0.0) {
        printf("1.0000\n"); return;
    }

    while( xU - xL >= EPS) {

        if(f(xL)*f(xR) < 0)
            xU = xR;
        else if(f(xL)*f(xR) > 0)
            xL = xR;

        xR = (xL + xU) / 2;
    }

    printf("%.4lf\n", xR);

}

int main()
{
    while(cin >> p >> q >> r >> s >> t >> u)
    {
        Bisection();
    }
}
