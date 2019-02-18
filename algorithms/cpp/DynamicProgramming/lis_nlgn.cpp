
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

typedef vector<int> VI;

#define INF 99999999

int Sorted[1000001];			// For security I use int data type but using int may be accept.

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

int LIS(VI v, VI &position)
{
	int pos, maxLength;
	int total = v.size();
	int i, j, k, temp;

	FOR(i, 0, total) Sorted[i] = INF;

	maxLength = 0;
	position.clear();

	FOR(i, 0, total-1) {
		temp = v[i];

		pos = FindPos(temp, 1, total);

		Sorted[pos] = temp;
		position.push_back(pos);
		if(pos > maxLength) maxLength = pos;
	}

	return maxLength;
}

/*
VI ConstructLIS(VI v, VI position, int lisLength)
{
	int i, j, k;
	int tempPos = 1;
	int curNum = v[0];

	VI ret;
	ret.push_back(curNum);

	for(i=1; i<v.size(); i++)
	{
		if(position[i] == tempPos && v[i] < curNum) {
				curNum = v[i];
				tempPos = position[i];
				ret.pop_back();
				ret.push_back(curNum);
		}
		else if(position[i] > tempPos && v[i] > curNum) {
				curNum = v[i];
				tempPos = position[i];
				ret.push_back(curNum);
		}

		if(tempPos == lisLength) break;
	}

	return ret;
}
*/

VI ConstructLIS(VI v, VI position, int lisLength)
{
	int i, j, k;
	int tempPos = lisLength;
	int curNum = INF;

	VI ret;
	for(i=v.size()-1; i>=0 && tempPos!= 0; i--)
		if(position[i] == tempPos) {	//v[i] < curNum
			curNum = v[i];
			ret.push_back(curNum);
			tempPos--;
		}
	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    VI v, position, lis;
	int i;
    int temp, totalNum;

	cin >> totalNum;

	FOR(i, 1, totalNum) {
		cin >> temp;
		v.push_back(temp);
	}

	int lisLength = LIS(v, position);
   FOR(i, 0, position.size()-1) cout << position[i] << " ";
	lis = ConstructLIS(v, position, lisLength);

	cout << lisLength << "\n\n";

	FOR(i, 0, lis.size()-1)
		cout << lis[i] << "\n";

    return 0;
}



/*
#include <vector>
#include <cstdio>

using namespace std;

// Finds longest strictly increasing subsequence. O(n log k) algorithm.
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;

	if (a.empty()) return;

	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++)
	{
		// If next element a[i] is greater than last element of current longest subsequence a[b.back()],
		// just push it at back of "b" and continue
		if (a[b.back()] < a[i])
		{
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

		// Binary search to find the smallest element
		// referenced by b which is just bigger than a[i]
		// Note : Binary search is performed on b (and not a).
		// Size of b is always <=k and hence contributes O(log k) to complexity.
		for (u = 0, v = b.size()-1; u < v;)
		{
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}

		// Update b if new value is smaller then previously referenced value
		if (a[i] < a[b[u]])
		{
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v])
		b[u] = v;
}

// Example of usage:

int main()
{
	int a[] = { 1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7 };
	vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
	// seq : Input Vector
	vector<int> lis;
	// lis : Vector containing indexes of longest subsequence

	find_lis(seq, lis);

    //Printing actual output
	for (size_t i = 0; i < lis.size(); i++)
	printf("%d ", seq[lis[i]]);
   printf("\n");

	return 0;
}
*/
