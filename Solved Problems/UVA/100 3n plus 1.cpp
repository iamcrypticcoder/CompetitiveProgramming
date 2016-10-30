// Accepted Runtime - 0.560     Brute Force

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define MAX 1000000

int main()
{
	int i;
	int prev, next, up, low;
	unsigned int maxLen, n, len;

	while(cin >> low >> up) {
		prev = low;		next = up;
		maxLen = 0;
		if(up < low) swap(low, up);

		for(i=low; i<=up; i++) {
			len = 0;
			n = i;

			while(n != 1) {
			   n % 2 == 0 ? n /= 2 : n = 3*n+1;
			   len++;
			}
            if(len > maxLen) maxLen = len;
        }

		cout << prev << " " << next << " " << maxLen << "\n";
	}

	return 0;
}
// -----------------------------------------------------------------------------
// Accepted 0.616    Brute Force with function

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define MAX 1000000

unsigned int calLen(unsigned int n)
{
	unsigned int len = 0;

	while(n != 1) {
	   n % 2 == 0 ? n /= 2 : n = 3*n+1;
	   len++;
	}
	return len;
}

int main()
{
	int i;
	int prev, next, up, low;
	unsigned int maxLen, n, len;

	while(cin >> low >> up) {
		prev = low;		next = up;
		maxLen = 0;
		if(up < low) swap(low, up);

		for(i=low; i<=up; i++) {
			len = 0;
			n = i;

			calLen(n);

			if(len > maxLen) maxLen = len;
        }

		cout << prev << " " << next << " " << maxLen << "\n";
	}

	return 0;
}
//------------------------------------------------------------------------------

// Accepted Runtime only 0.048        DP Solution

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define MAX 1000000

unsigned int DP[MAX-1];

void Process()
{
   unsigned int n, i, len;

	DP[1] = 1;

   for(i=2; i<MAX; i++) {
     n = i;  len = 0;
     while(1) {
       n % 2 == 0 ? n /= 2 : n = 3*n+1;
       len++;
       if(n < i) {  DP[i] = DP[n] + len;       break;   }
     }
   }
}


int main()
{
	Process();

	int i;
	int prev, next, up, low;
	unsigned int maxLen;

   cout << DP[10];

	while(cin >> low >> up) {
		prev = low;		next = up;

		maxLen = 0;

		if(up < low) swap(low, up);

		for(i=low; i<=up; i++)
			if(DP[i] > maxLen) maxLen = DP[i];

		cout << prev << " " << next << " " << maxLen << "\n";
	}

	return 0;
}
