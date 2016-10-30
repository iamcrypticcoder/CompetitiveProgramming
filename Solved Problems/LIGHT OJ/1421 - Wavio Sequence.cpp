#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for( i=L ; i<=U; i++ )

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef vector<int> VI;

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define INF 999999999

int Sorted[100005];

int FindPos(int key, int lowerBound, int upperBound)
{
	int low = lowerBound;
	int high = upperBound;
	int mid, ret;

	while(low <= high) {

		mid = (low + high) / 2;

		if(key < Sorted[mid]) {
			ret = mid;
			high = mid - 1;
		}
		else if(key > Sorted[mid]) low = mid + 1;

		else return mid;
	}

	return ret;
}

int LIS(VI v, VI &position, bool isReverse)
{
	int pos, maxLength;
	int total = v.size();
	int i, j, k, temp;

	FOR(i, 0, total) Sorted[i] = INF;

	maxLength = 0;
	position.clear();
	if(isReverse) reverse(v.begin(), v.end());
	FOR(i, 0, total-1) {
		temp = v[i];

		pos = FindPos(temp, 1, total);

		Sorted[pos] = temp;
		position.push_back(pos);
		if(pos > maxLength) maxLength = pos;
	}
	if(isReverse) reverse(position.begin(), position.end());

	return maxLength;
}

int main()
{
   READ("input.txt");
 //  WRITE("output.txt");

	int i, j, k, temp;
   int TC, tc;
//	int input[] = {1, 2, 3, 1, 2, 3, 4};
//	VI v = VI(input, input + sizeof(input)/sizeof(input[0]));

	int N;
	VI LtoRpos, RtoLpos, v;
	int maxLength;

   TC = src();

	FOR(tc, 1, TC) {
      N = src();

		FOR(i, 1, N) {
			temp = src();
			v.push_back(temp);
		}

		LIS(v, LtoRpos, false);
		LIS(v, RtoLpos, true);
/*
		FOR(i, 0, LtoRpos.size()-1)
			cout << LtoRpos[i] << " ";
		cout << "\n";
		FOR(i, 0, RtoLpos.size()-1)
			cout << RtoLpos[i] << " ";
*/
		maxLength = -1;
		FOR(i, 0, LtoRpos.size()-1)
			if(MIN(LtoRpos[i], RtoLpos[i]) > maxLength) maxLength = MIN(LtoRpos[i], RtoLpos[i]);

      printf("Case %d: %d\n", tc, 2*maxLength - 1 );

		//cout << "Case " << tc << ": " << 2*maxLength - 1 << "\n";

		v.clear();
	}


	return 0;
}
