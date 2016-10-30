#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.141592653589793

struct POINT {
	double x;
	double y;
};


struct EQUATION {
	double a;
	double b;
	double c;
};

int main()
{
	struct POINT P[3];
	double G, F, C, H, K, R;
	char sign_G, sign_F, sign_C, sign_H, sign_K;
	int i;


	while(cin >> P[0].x >> P[0].y) {
	for(i=1; i<3; i++)
		cin >> P[i].x >> P[i].y;

	struct EQUATION E[3];

	for(i=0; i<3; i++) {
	E[i].a = 2 * P[i].x;
	E[i].b = 2 * P[i].y;
	E[i].c = P[i].x * P[i].x + P[i].y * P[i].y;
	}
	struct EQUATION EQN[2];

	for(i=0; i<2; i++) {
		EQN[i].a = E[i].a - E[i+1].a;
		EQN[i].b = E[i].b - E[i+1].b;
		EQN[i].c = -(E[i].c - E[i+1].c);
	}

	G = (EQN[1].b * EQN[0].c - EQN[0].b * EQN[1].c) / (EQN[0].a * EQN[1].b - EQN[1].a * EQN[0].b);
	
	F = (EQN[0].a * EQN[1].c - EQN[1].a * EQN[0].c) / (EQN[0].a * EQN[1].b - EQN[1].a * EQN[0].b);

	C = (-E[0].a * G) + (-E[0].b * F) + (-E[0].c);

	H = G;	K = F;
	R = sqrt(G*G + F*F -C);

	printf("%.2lf\n", 2*PI*R);

	}
	return 0;
}