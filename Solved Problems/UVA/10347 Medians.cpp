#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


#define SQR(x) ((x)*(x))
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-3

double m1, m2, m3;                 // These are the three medians

double T, a, b, c, s, area;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


  while(cin >> m1 >> m2 >> m3) {
     T = (4 * ( SQR(m1)+SQR(m2)+SQR(m3) ) ) / 3;

     a = sqrt( (2 * (T - 2*SQR(m1))) / 3 );
     b = sqrt( (2 * (T - 2*SQR(m2))) / 3 );
     c = sqrt( (2 * (T - 2*SQR(m3))) / 3 );

 //    printf("%.3lf %.3lf %.3lf\n", a, b, c);

     if(a+b > c && b+c > a && c+a > b) {
       s = 0.5 * (a+b+c);
       area = sqrt(fabs(s*(s-a)*(s-b)*(s-c)));
       if(area <= EPS)                              // Got WA 3 times cause if area == 0 then print -1.000
                                                    // Its not said in problem description
            cout << "-1.000\n";
       else printf("%.3lf\n", area);
     }
     else {
       cout << "-1.000\n";
     }
  }


	return 0;
}
