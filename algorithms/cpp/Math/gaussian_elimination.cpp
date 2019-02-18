#include <stdio.h>

int n;
int numEqu;
double equ[100][101];

void forwardSubstitution() {
	int i, j, k, max;
	float t;
	for (i = 0; i < numEqu; ++i) {
		max = i;
		for (j = i + 1; j < numEqu; ++j)
			if (equ[j][i] > equ[max][i])
				max = j;

		for (j = 0; j < numEqu + 1; ++j) {
			t = equ[max][j];
			equ[max][j] = equ[i][j];
			equ[i][j] = t;
		}

		for (j = numEqu; j >= i; --j)
			for (k = i + 1; k < numEqu; ++k)
				equ[k][j] -= equ[k][i]/equ[i][i] * equ[i][j];

		for (k = 0; k < numEqu; ++k) {
			for (j = 0; j < numEqu + 1; ++j)
				printf("%.2lf\t", equ[k][j]);
			printf("\n");
		}
		printf("\n");

	}
}

void reverseElimination() {
	int i, j, k;
	for (i = numEqu - 1; i >= 0; --i) {
		equ[i][numEqu] = equ[i][numEqu] / equ[i][i];
		equ[i][i] = 1;
		for (j = i - 1; j >= 0; --j) {
			equ[j][numEqu] -= equ[j][i] * equ[i][numEqu];
			equ[j][i] = 0;
		}

		for (k = 0; k < numEqu; ++k) {
			for (j = 0; j < numEqu + 1; ++j)
				printf("%.2lf\t", equ[k][j]);
			printf("\n");
		}
		printf("\n");

	}
}

void gauss() {
	int i, j;

	forwardSubstitution();
	reverseElimination();

	for (i = 0; i < numEqu; ++i) {
		for (j = 0; j < numEqu + 1; ++j)
			printf("%.2lf\t", equ[i][j]);
		printf("\n");
	}
}

int main() {
    freopen("input.txt", "r", stdin);
	int i, j;

	scanf("%d", &numEqu);
	for (i = 0; i < numEqu; ++i)
		for (j = 0; j < numEqu + 1; ++j)
			scanf("%lf", &equ[i][j]);

	gauss();

	return 0;
}

