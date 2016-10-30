// Remember critical input are 1,2,3. For these answer will be DEFICIENT.

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;



int main()
{
	
	int input, root, sum;

	int i, j;

	cout << "PERFECTION OUTPUT\n";

	while(cin >> input) {

		if(input == 0) {
			cout << "END OF OUTPUT\n";
			break;
		}

		if(input <= 3) {
			printf("%5d  DEFICIENT\n", input);
			continue;
		}
		
		root = (int)sqrt((double)input);
		
		sum = 1;
		for(i=2; i<root; i++)
			if(input % i == 0)
				sum += (i + input / i);
		if(input % root == 0) {
			if(input / root == root) sum += root;
			else sum += (root + input / root);
		}

		if(sum == input) printf("%5d  PERFECT\n", input);
		else if(sum > input) printf("%5d  ABUNDANT\n", input);
		else if(sum < input) printf("%5d  DEFICIENT\n", input);

	}


	return 0;
}