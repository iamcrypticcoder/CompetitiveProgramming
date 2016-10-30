#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9


#define PI 2*acos(0.0)
#define EPS 1e-6
#define TO_DEG 57.29577951
#define SQR(x) ((x)*(x))



// --------------------------------POINT -------------------------------------
class POINT {
public:
	double X, Y;
	POINT(double a, double b);
	POINT() {}
};

POINT::POINT(double a, double b)
{
	X = a;	Y = b;
}


double DISTANCE_OF_POINT(POINT p1, POINT p2)
{
	return sqrt(SQR(p1.X - p2.X) + SQR(p1.Y - p2.Y));
}
// ----------------------------------------------------------------------

int NH;			// Num of hole
POINT D, G, ans;
vector<POINT> hole;

int main()
{	
	double a, b, c, d;
	double dG, dD;
	int i;
	bool isFound;

	while(cin >> NH) {
		cin >> a >> b >> c >> d;
		G = POINT(a, b);
		D = POINT(c, d);

		FOR(i, 1, NH) {
			cin >> a >> b;
			hole.push_back(POINT(a,b));
		}
		isFound = 0;	
		FOR(i, 0, NH-1) {
			dG = DISTANCE_OF_POINT(G, hole[i]);
			dD = DISTANCE_OF_POINT(D, hole[i]);

			if(dG*2 <= dD) {
				ans = hole[i];
				isFound = 1;
				break;
			}
		}
		if(isFound) printf("The gopher can escape through the hole at (%0.3lf,%0.3lf).\n", ans.X, ans.Y);
		else printf("The gopher cannot escape.\n");

		hole.clear();
	}
	return 0;
}
