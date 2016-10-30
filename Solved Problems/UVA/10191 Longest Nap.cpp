#include <cstdio>
#include <cmath>
#include <iostream>
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

struct TIME {
	int sTime;
	int eTime;
};

struct TIME s[101];

int comp(const void *x, const void *y)
{
    return  ( ((TIME*)x)->sTime - ((TIME*)y)->sTime );
}

int main()
{
//	freopen("E:\\input.txt", "r", stdin);
//	freopen("E:\\output.txt", "w", stdout);

	int totalTask, longest, napStart, napEnd, Day = 1;
	int hh, mm;
	string str;

	while(cin >> totalTask) {
        if(totalTask == 0) {
	      cout << "Day #" << Day++ << ": the longest nap starts at 10:00 and will last for 8 hours and 0 minutes.\n";
		  continue;
        }
		FOR(i, 1, totalTask) {
			scanf("%d:%d", &hh, &mm);
			s[i].sTime = hh*60 + mm;
			scanf("%d:%d", &hh, &mm);
			s[i].eTime = hh*60 + mm;
			getline(cin, str);
		}
		
		qsort(s+1, totalTask, sizeof(TIME), comp);
		
		napStart = 600;	napEnd = s[1].sTime;
		longest = napEnd - napStart;

		FOR(i, 2, totalTask) 
			if(s[i].sTime - s[i-1].eTime > longest) {			
				napStart = s[i-1].eTime;
				napEnd = s[i].sTime;
				longest = napEnd - napStart;
			}
		if(1080-s[totalTask].eTime > longest) {
			napStart = s[totalTask].eTime;
			napEnd = 1080;
			longest = napEnd - napStart;
		}

		cout.fill('0');
		cout << "Day #" << Day++ << ": the longest nap starts at " << napStart/60 << ":" << setw(2) << napStart%60 << " and will last for ";

		if(longest >= 60)			cout << longest/60 << " hours and " << longest%60 << " minutes.\n";
		else cout << longest << " minutes.\n";
	
	}

	return 0;
}
