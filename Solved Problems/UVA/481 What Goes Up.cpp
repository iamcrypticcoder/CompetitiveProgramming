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

typedef vector<long long> VI;

#define INF 999999999999

long long Sorted[1000001];			// For security I use long long data type but using int may be accept.

long long FindPos(long long key, long long lowerBound, long long upperBound)
{
	long long low = lowerBound;
	long long high = upperBound;
	long long mid, ret;

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

long long LIS(VI v, VI &position)
{
	long long pos, maxLength;
	long long total = v.size();
	long long i, j, k, temp;

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
VI ConstructLIS(VI v, VI position, long long lisLength)
{
	long long i, j, k;
	long long tempPos = 1;
	long long curNum = v[0];

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

VI ConstructLIS(VI v, VI position, long long lisLength)
{
	long long i, j, k;
	long long tempPos = lisLength;
	long long curNum = INF;

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
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    VI v, position, lis;
	 long long i;
    long long temp;

    
    while(cin >> temp)
    {
		v.push_back(temp);   
    }


	long long lisLength = LIS(v, position);
	
	lis = ConstructLIS(v, position, lisLength);

	cout << lisLength << "\n-\n";

	FOR(i, 0, lis.size()-1)
		cout << lis[i] << "\n";

    return 0;    
}
