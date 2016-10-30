#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

// --------------------------------POINT -------------------------------------
class POINT {
public:
	double X, Y;
	char label;

	POINT(char l, double a, double b);
	POINT() {}
};

POINT::POINT(char l, double a, double b)
{	
	label = l;
	X = a;	Y = b;
}
// -----------------------------------------------------------------------------

double EvaluateArea(POINT P1, POINT P2, POINT P3)
{
	return fabs(0.5 * ( P1.X*(P2.Y - P3.Y) + P2.X*(P3.Y - P1.Y) + P3.X*(P1.Y - P2.Y)));
}

bool IS_POINT_INSIDE(POINT P1, POINT P2, POINT P3, POINT P)
{
	double a1, a2, a3, total;

	a1 = EvaluateArea(P1, P2, P);
	a2 = EvaluateArea(P2, P3, P);
	a3 = EvaluateArea(P3, P1, P);
	total = EvaluateArea(P1, P2, P3);

	if ( fabs(a1 + a2 + a3 - total) <= 0.000001)
//	if( (a1+a2 +a3 - total) == 0.0)							// why its doesn't work. I dont know.
		return true;
	else 
		return false;
}


// -------------------------------------------------------------------------------
vector<POINT> points;

int main()
{
	int num_of_points;
	int x, y;

	int i, j, k, l;

	POINT P1, P2, P3, P;
	POINT p1, p2, p3;
	POINT tempPoint;
	double area, tempArea;

	bool is_point_inside;
	char label;

	while(cin >> num_of_points && num_of_points != 0)
	{

		for(i=1; i<=num_of_points; i++) {
			cin >> label >> x >> y;
			tempPoint = POINT(label, x, y);
			points.push_back(tempPoint);
		}

		area = 0.0;

		for(i=0; i < points.size()-2; i++) {
			P1 = points[i];
			for(j=1; j < points.size()-1; j++) {
				P2 = points[j];
				for(k=2; k < points.size(); k++) {
					P3 = points[k];

					is_point_inside = false;
					for(l = 0; l<points.size(); l++) {
						if(l == i || l == j || l == k) continue;
						else if(IS_POINT_INSIDE(P1, P2, P3, points[l]) == true) {
							is_point_inside = true;
							break;
						}
					}
					
					if(is_point_inside == false) {
						tempArea = EvaluateArea(P1, P2, P3);

						if(tempArea > area) {
							p1 = P1;	p2 = P2;	p3 = P3;
							area = tempArea;
						}
					}
				}
			}
		}

		cout << p1.label << p2.label << p3.label << endl;
		points.clear();
	}

	return 0;
}