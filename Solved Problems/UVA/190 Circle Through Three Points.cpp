#include <iostream>
#include <math.h>

using namespace std;

#define PI 2*acos(0.0)
#define EPS 1e-6
#define TO_DEG 57.29577951
#define SQR(x) ((x)*(x))

class POINT;
class LINE;

double DISTANCE_OF_POINT(POINT p1, POINT p2);
bool IntersectionPoint(LINE l1, LINE l2, POINT &ip);
bool IS_PARALLEL(LINE l1, LINE l2);
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


// -------------------------------- LINE ----------------------------------------------

class LINE {
public:
	double A, B, C;										// I represent the line as Ax + by = C.

	LINE() { }
	LINE(POINT p1, POINT p2);
	LINE(double a, double b, double c);
//	LINE Bisector(LINE)
	void ShowLine();
};

LINE::LINE(double a, double b, double c)
{
	A = a;		B=b;		C=c;	
}

LINE::LINE(POINT p1, POINT p2)
{
/*
	A = p2.Y - p1.Y;
	B = p1.X - p2.X;
	C = A*p1.X + B*p1.Y;
*/

	if(p1.X == p2.X) {
		A = 1;
		B = 0;
		C = -p1.X;
	}
	else {
		B = 1;
		A = -(p1.Y - p2.Y)/(p1.X - p2.X);
		C = -(B * p1.Y) - (A * p1.X);
	}

	if(A == -0.0) A = fabs(A);
	if(B == -0.0) B = fabs(B);
	if(C == -0.0) C = fabs(C);

}

void LINE::ShowLine()
{
	cout << A << " " << B << " " << C << endl;
}

// ------------------------------- LINE SEGMENT ----------------------------------------
class LINE_SEGMENT {
public:
	POINT P1, P2;
	LINE L;

	LINE_SEGMENT() { };
	LINE_SEGMENT(POINT _p1, POINT _p2);

	LINE Bisector();

};

LINE_SEGMENT::LINE_SEGMENT(POINT _p1, POINT _p2)
{
	P1 = _p1;
	P2 = _p2;
	L = LINE(P1, P2);
}

LINE LINE_SEGMENT::Bisector()
{
	LINE ret;
	POINT c;
	c.X = (P1.X + P2.X) / 2;
	c.Y = (P1.Y + P2.Y) / 2;
	
	ret.A = -(this->L.B);
	ret.B = this->L.A;
	ret.C = -(ret.A*c.X + ret.B*c.Y);


	if(ret.A == -0.0) ret.A = fabs(ret.A);
	if(ret.B == -0.0) ret.B = fabs(ret.B);
	if(ret.C == -0.0) ret.C = fabs(ret.C);

	return ret;
}


// ------------------------------ CIRCLE -----------------------------------------------

class CIRCLE {
public:
	POINT center;
	double radius;

	CIRCLE() { }
	CIRCLE(POINT _center, double _radius);
	CIRCLE(POINT a, POINT b, POINT c);
};

CIRCLE::CIRCLE(POINT _center, double _radius)
{
	center = _center;
	radius = _radius;
}

CIRCLE::CIRCLE(POINT a, POINT b, POINT c)
{
	LINE_SEGMENT LS1(a, b), LS2(b, c);
	LINE L1, L2;
	POINT p;

	L1 = LS1.Bisector();
	L2 = LS2.Bisector();
	
//	L1.ShowLine();
//	L2.ShowLine();
	
	if(IntersectionPoint(L1, L2, p)) {
		center = p;
		radius = DISTANCE_OF_POINT(p,a); 
	//	cout << "\n" << p.X << " " << p.Y << " " << radius;	
	}
}

double DISTANCE_OF_POINT(POINT p1, POINT p2)
{
	return sqrt(SQR(p1.X - p2.X) + SQR(p1.Y - p2.Y));
}

bool IS_PARALLEL(LINE l1, LINE l2)
{
	return ( (fabs(l1.A - l2.A)) <= EPS && (fabs(l1.B - l2.B)) <= EPS);
}

bool IntersectionPoint(LINE l1, LINE l2, POINT &ip)
{
	if(IS_PARALLEL(l1, l2) == true) {
	//	cout << "Parallel";
		return 0; 
	}	
/*
	double det = (l1.A*l2.B - l2.A*l1.B);
	double a = (l1.B*l2.C - l2.B*l1.C);
	double b = (l1.C*l2.A - l2.C*l1.A);
*/
	ip.X = (l1.B*l2.C - l2.B*l1.C) / (l1.A*l2.B - l2.A*l1.B);
	ip.Y = (l1.C*l2.A - l2.C*l1.A) / (l1.A*l2.B - l2.A*l1.B);
	return 1;
}



int main()
{
	double a, b, c, d, e, f, constant;
	POINT P1, P2, P3;
	CIRCLE C;
	char sign1, sign2, sign3;

	while(cin >> a >> b >> c >> d >> e >> f) {
		P1 = POINT(a, b);
		P2 = POINT(c, d);
		P3 = POINT(e, f);
		
		C = CIRCLE(P1, P2, P3);
		sign1 = (C.center.X >= 0.0) ? '-' : '+';
		sign2 = (C.center.Y >= 0.0) ? '-' : '+';
		constant = SQR(C.center.X) + SQR(C.center.Y) - SQR(C.radius);
		sign3 = (constant < 0) ? '-' : '+';

		printf("(x %c %0.3lf)^2 + (y %c %0.3lf)^2 = %0.3lf^2\n", sign1, fabs(C.center.X), sign2, fabs(C.center.Y), C.radius);
		printf("x^2 + y^2 %c %0.3lfx %c %0.3lfy %c %0.3lf = 0\n\n", sign1, fabs(C.center.X)*2, sign2, fabs(C.center.Y)*2, sign3, fabs(constant));
		
	}
	return 0;
}