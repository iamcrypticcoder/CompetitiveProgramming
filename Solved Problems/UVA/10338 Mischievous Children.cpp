#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

double fact(int n)
{
	if(n==0) return 1;
	else return n*fact(n-1);
}

int main()
{
	int tc, length, i, j, k, l=1, count;
	char str[22];
	double ans;
	
	cin >> tc;
	bool Is_first = 1;

	while(tc-- && l++) {
		if(Is_first) {
			gets(str);	gets(str); Is_first = 0;
		}
		else gets(str);
		length = strlen(str);
		ans = fact(length);

		for(i=0; i<length; i++) {
			count = 0;
			for(j=i;j<length; j++)
				if(str[i] == str[j]) count++;
			if(count>1) ans /= count;
		}
		cout << "Data set "<< l-1 <<": ";
		printf("%.0lf\n", ans);
	}

return 0;
}