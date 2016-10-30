#include <iostream>

using namespace std;

int main()
{
	int n, i, t_case;
	int h[51], sum, avg, moves;

	for(t_case =1; cin >> n && n != 0; t_case++) {
		sum = moves = 0;

		for(i=0; i<n; i++) {
			cin >> h[i];
			sum += h[i];
		}

		avg = sum / n;
		for(i=0; i<n; i++)
			if(h[i] > avg)
				moves += h[i] - avg;


		cout << "Set #" << t_case << "\n";
		cout << "The minimum number of moves is " << moves << ".\n\n";

	}

return 0;
}