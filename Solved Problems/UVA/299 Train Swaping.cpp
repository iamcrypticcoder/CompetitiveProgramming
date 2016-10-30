#include <iostream>

using namespace std;

int trains[51];

int main()
{
	int tc, L;
	int i, j, k, l;
	unsigned long swaps;

	cin >> tc;

	for(i=0; i<tc; i++) {
		swaps = 0;
		cin >> L;

		for(j=0; j<L; j++)
			cin >> trains[j];

		// bubble sort begin
		int b, t, a;

		for(a=1; a<=L; a++)

		for(b=L-1; b>=a; b--) {
			if(trains[b-1] > trains[b]) {
				t = trains[b-1];
				trains[b-1] = trains[b];
				trains[b] = t;
				swaps++;
			}
		}
		// end
	
	//	for(j=0; j<L; j++)
	//		cout << trains[j] << " ";
		cout << "Optimal train swapping takes " << swaps << " swaps.\n";
	}
	return 0;
}