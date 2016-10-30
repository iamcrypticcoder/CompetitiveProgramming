#include<iostream>
#include<math.h>
#include <vector>
//#include <conio.h>

using namespace std;

#define SQR(x) (x)*(x)

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


class RECTANGLE {
public:	
	POINT UpperLeft, LowerRight;
};
	

class CIRCLE {
public:
	POINT Center;
	double Radius;
};

class TRIANGLE {
public:
	POINT P1, P2, P3;
};


class FIGURE {
public:
	char Value;
	RECTANGLE rect;
	CIRCLE circle;
	TRIANGLE tangle;


};

double EvaluateArea(POINT P1, POINT P2, POINT P3)
{
	return fabs(0.5 * ( P1.X*(P2.Y - P3.Y) + P2.X*(P3.Y - P1.Y) + P3.X*(P1.Y - P2.Y)));
}

bool IS_POINT_INSIDE(POINT UpperLeft, POINT LowerRight, POINT p)
{
	return ( (p.X>UpperLeft.X && p.X<LowerRight.X) &&  (p.Y<UpperLeft.Y && p.Y>LowerRight.Y));
}


bool IS_POINT_INSIDE(POINT Center, double Radius, POINT P)
{
	return ( (SQR(P.X-Center.X) + SQR(P.Y-Center.Y)) < SQR(Radius) );
}

bool IS_POINT_INSIDE(POINT P1, POINT P2, POINT P3, POINT P)
{
	double a1, a2, a3, total;

	a1 = EvaluateArea(P1, P2, P);
	a2 = EvaluateArea(P2, P3, P);
	a3 = EvaluateArea(P3, P1, P);
	total = EvaluateArea(P1, P2, P3);


	if ( fabs(a1 + a2 + a3 - total) <= 0.000001)
//	if( (a1+a2 +a3 - total) == 0.0)
		return true;
	else 
		return false;
}



int main()
{
	
	char ch;
	int num_of_rect = 0, i,j;
	bool Is_match;

	RECTANGLE R;
	CIRCLE C;
	TRIANGLE T;

	FIGURE fig;
	POINT point;
	vector<FIGURE> FIG;
	vector<POINT> v_point;


	while( cin >> ch)
	{
		if(ch == 'r') {
			fig.Value = 'r';
			scanf("%lf %lf %lf %lf", &R.UpperLeft.X, &R.UpperLeft.Y, &R.LowerRight.X, &R.LowerRight.Y);
			fig.rect = R;
			FIG.push_back(fig);
		}
		else if(ch == 'c') {
			fig.Value = 'c';
			scanf("%lf %lf %lf", &C.Center.X, &C.Center.Y, &C.Radius);
			fig.circle = C;
			FIG.push_back(fig);
		}
		else if(ch == 't') {
			fig.Value = 't';
			scanf("%lf %lf %lf %lf %lf %lf", &T.P1.X, &T.P1.Y, &T.P2.X, &T.P2.Y, &T.P3.X, &T.P3.Y);
			fig.tangle = T;
			FIG.push_back(fig);
		}
		else if(ch == '*') break;
	}

	while(cin >> point.X >> point.Y)
	{
		if(point.X == 9999.9 && point.Y == 9999.9)	break;

		v_point.push_back(point);
	}


	for(i=0; i< v_point.size(); i++) {
		Is_match = false;

		for(j=0; j< FIG.size(); j++) {
			if(FIG[j].Value == 'r' && IS_POINT_INSIDE(FIG[j].rect.UpperLeft, FIG[j].rect.LowerRight, v_point[i]) == true) {
				cout << "Point " << i+1 << " is contained in figure " << j+1 << endl;
				Is_match = true;
			}
			else if(FIG[j].Value == 'c' && IS_POINT_INSIDE(FIG[j].circle.Center, FIG[j].circle.Radius, v_point[i]) == true) {
				cout << "Point " << i+1 << " is contained in figure " << j+1 << endl;
				Is_match = true;
			}
			else if(FIG[j].Value == 't' && IS_POINT_INSIDE(FIG[j].tangle.P1, FIG[j].tangle.P2, FIG[j].tangle.P3, v_point[i]) == true) {
				cout << "Point " << i+1 << " is contained in figure " << j+1 << endl;
				Is_match = true;
			}
		}
		if(Is_match == false)
			cout << "Point " << i+1 << " is not contained in any figure" << endl;
	}

return 0;
}