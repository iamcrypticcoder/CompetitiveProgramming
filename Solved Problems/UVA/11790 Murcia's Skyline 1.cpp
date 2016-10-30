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

#define FOR(i, L, U) for(int i=L; i<=U; i++)


#define MAX 10001

int A[MAX], L[MAX], W[MAX];
int N;

void Init()
{
	int i;
	for(i=1; i<=N; i++) {
		L[i] = W[i];
	}
}

int LIS()
{
	int i, j;

	Init();

	int maxWidth = 0;


	for(i = 1; i <= N; i++) {
		for(j = i+1; j <= N; j++) {
			if(A[j] > A[i])
				if(L[i] + W[j] > L[j]) {
					L[j] = L[i] + W[j];
					if(L[j] > maxWidth) maxWidth = L[j];
				}
		}
		if(L[i] > maxWidth) maxWidth = L[i];
	}
	return maxWidth;
}

int LDS()
{
	int i, j;

	Init();

	int maxWidth = 0;

	for(i = 1; i <= N; i++) {
		for(j = i+1; j <= N; j++) {
			if(A[j] < A[i])
				if(L[i] + W[j] > L[j]) {
					L[j] = L[i] + W[j];
					if(L[j] > maxWidth) maxWidth = L[j];
				}
		}
		if(L[i] > maxWidth) maxWidth = L[i];
	}

	return maxWidth;
}


int main()
{
	int TC, tcase;

	int i, j;
	int LISlength, LDSlength;

	list<int> I;
	list<int> D;

	cin >> TC;

	FOR(tcase, 1, TC) {
		cin >> N;
		for(i=1; i<=N; i++)
			cin >> A[i];
		for(i=1; i<=N; i++)
			cin >> W[i];

		LISlength = LIS();
//		cout << LISlength << "\n";
		LDSlength = LDS();
//		cout << LDSlength << "\n";

		cout << "Case " << tcase << ". ";
		if(LISlength >= LDSlength)
			printf("Increasing (%d). Decreasing (%d).\n", LISlength, LDSlength);
		else
			printf("Decreasing (%d). Increasing (%d).\n", LDSlength, LISlength);
	}


	return 0;
}

