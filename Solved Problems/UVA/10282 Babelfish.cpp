// Here a solution using Binary Search
// Both this code are accepted.

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

#define MAX 100000

typedef struct {
  string eng, foreign;
} WORD;

WORD word[MAX + 1];
int totalWord = 0;



void SetWord(string s, int index)
{
  string temp;
  int i;
  
  for(i=0; i<s.size() && s[i] != ' '; i++)
    temp += s[i];
  word[index].eng = temp;
  temp.clear();
  
  i++;
  for(; i<s.size(); i++)
    temp += s[i];
  word[index].foreign = temp;
}

int comp(const void *a, const void *b)
{ 
	if( ((WORD*)a)->foreign < ((WORD*)b)->foreign )
		return -1;
  else if(((WORD*)a)->foreign > ((WORD*)b)->foreign)
		return 1;
  else return 0;
}


int BinarySearch(string key)
{
	int low = 0, high = totalWord, mid;

	while(low <= high) {
		mid = (low+high)/2;
		if(key < word[mid].foreign)
			high = mid-1;
		else if(key > word[mid].foreign)
			low = mid + 1;
		else return mid;
	}

	return 0;
}


int main()
{
   int i, j, loc;
   
   string str;
   
	for(totalWord = 0; getline(cin, str) && str.size() != 0; ) 
     SetWord(str, ++totalWord);
   
	qsort(word + 1, totalWord, sizeof(WORD), comp);

   while(getline(cin, str)) {
		loc = BinarySearch(str);
		if(loc == 0) 
			cout << "eh\n";
		else cout << word[loc].eng << "\n";
	}

 
	return 0;
}


// Here is a solution using map....................................

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

#define MAX 100000

map<string, string> M;
int totalWord;


void SetWord(string s, int index)
{
  string eng, foreign;
  int i;
  
  for(i=0; i<s.size() && s[i] != ' '; i++)
    eng += s[i]; 

  i++;
  for(; i<s.size(); i++)
    foreign += s[i];
	
  M[foreign] = eng;

  eng.clear();
  foreign.clear();
}


int main()
{
   int i, j, loc;
   
   string str;
   
	for(totalWord = 0; getline(cin, str) && str.size() != 0; ) 
     SetWord(str, ++totalWord);


   while(getline(cin, str)) {
		if(M[str] != "")
			cout << M[str] << "\n";
		else cout << "eh\n";
	}

 
	return 0;
}

