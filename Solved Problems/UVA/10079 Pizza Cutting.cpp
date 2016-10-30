#include <iostream>
#include <stdio.h>
//#include <vector>

using namespace std;

int main()
{
	int i;
	long long piece;
	long long N;

	while(cin >> N && N >=0) {
		piece = 1 + (N*(N+1))/2;
		//cout << piece << "\n";
		//printf("%.\n", piece);
		cout << piece << "\n";
	}

return 0;
}
