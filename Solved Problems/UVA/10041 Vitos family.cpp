#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int street[500];
	int num_of_home, t_case;
	int minimal_dist = 0, middle_index, i, j;
	
	cin >> t_case;
	
	for(j=1; j<=t_case; j++) {
	minimal_dist = 0;
	
	cin >> num_of_home;
	for(i=0; i<num_of_home; i++)
		cin >> street[i];

	register int a, b;
	int temp;

	for(a=1; a < num_of_home; ++a) {
	 temp = street[a];
	 for(b=a-1; (b >=0) && (temp < street[b]); b--)
		street[b+1] = street[b];
	 street[b+1] = temp;
	}

	if(!(num_of_home%2))
		middle_index = ceil((double)(num_of_home-1)/2);
	else 
		middle_index = ceil((double)num_of_home/2)-1;

	for(i=0; i<middle_index; i++)
		minimal_dist += street[middle_index] - street[i];
	for(i=num_of_home-1; i>=middle_index; i--)
		minimal_dist += street[i] - street[middle_index];


	cout << minimal_dist << endl;
	}
	

return 0;
}