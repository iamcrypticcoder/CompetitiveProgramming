
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

#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

struct ss {
	string str;
	int inv, index;
};

typedef ss DNA;


#define MAX 101

DNA dna[MAX];

void CalculateInv(DNA &dna)
{
	int i, j;
	int inv = 0;
	for(i= 0; i<dna.str.size(); i++)
		for(j= i+1; j<dna.str.size(); j++)
			if(dna.str[j] < dna.str[i])
				inv++;
	dna.inv = inv;
}

int comp(const void *a, const void *b)
{
	int ret;
	if((ret = ((DNA*)a)->inv - ((DNA*)b)->inv) != 0)
		return ret;
	else if(ret == 0)
		return ((DNA*)a)->index - ((DNA*)b)->index;
}


bool operator<(const DNA& x, const DNA& y)
{
return x.inv < y.inv;
}

int main()
{
//	freopen("E:\\output.txt", "w", stdout);

	int TC;
	int s_length, num_of_string;
	string s;
	vector<DNA> set;

	cin >> TC;

	getline(cin, s);
//	getline(cin, s);
//	stable_sort(
	while(TC--) {
//		getline(cin, s);
		cin >> s_length >> num_of_string;

		getline(cin, s);
		FOR(i, 1, num_of_string) {
			getline(cin, s);
			dna[i].str = s;
			dna[i].index = i;
		}
		FOR(i, 1, num_of_string)  {
			CalculateInv(dna[i]);
			set.push_back(dna[i]);
		}

//		qsort(dna+1, num_of_string, sizeof(DNA), comp);
		stable_sort(set.begin(), set.end());

		FOR(i, 0, set.size()-1)
			cout << set[i].str << "\n";
/*
		FOR(i, 1, num_of_string)
			cout << dna[i].str << "\n";
*/
		if(TC > 0)cout << "\n";

		set.clear();
	}

	return 0;
}

