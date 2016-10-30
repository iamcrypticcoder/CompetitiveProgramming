#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define MAX 1000


typedef struct {
	string word;
	int doller;
} WORD;

WORD word[MAX + 1];
int totalWord, totalJob;


int comp(const void *a, const void *b)
{
	if( ((WORD*)a)->word < ((WORD*)b)->word )
		return -1;
	else if( ((WORD*)a)->word > ((WORD*)b)->word )
		return 1;
	else return 0;
}


int BinarySearch(string key)
{
  int low = 1, high = totalWord, mid;

  while(low <= high) {
	  mid = (low+high)/2;
	  if(key < word[mid].word)
		  high = mid - 1;
	  else if(key > word[mid].word)
		  low = mid + 1;
	  else return mid;
  }

  return 0;	
}


int main()
{
	string str;
	int doller;
	int i, j, k;
	int hayPoint, loc;

	cin >> totalWord >> totalJob;

	FOR(i, 1, totalWord) {
		cin >> str >> doller;
		word[i].word = str;
		word[i].doller = doller;
	}

	qsort(word+1, totalWord, sizeof(WORD), comp);

	FOR(i, 1, totalJob) {
		hayPoint = 0;
		while(cin >> str && str != ".") 
			if((loc = BinarySearch(str)) != 0) 
				hayPoint += word[loc].doller;	

		cout << hayPoint << "\n";			
	}

	return 0;
}