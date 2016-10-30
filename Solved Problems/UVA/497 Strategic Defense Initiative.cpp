/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

string line;
VI v, position, lis;
int Sorted[1000001];			// For security I use int data type but using int may be accept.
int lisLength;

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
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int temp;

   TC = src();

   getchar();
   getchar();

   tc = 1;
   while(getline(cin, line)) {
      if(tc > 1) printf("\n");
      if(line.SZ == 0) break;
      stringstream ss(line);
      ss >> temp;
      v.PB(temp);
      while(getline(cin, line)) {
         if(line.SZ == 0) break;
         stringstream ss(line);
         ss >> temp;
         v.PB(temp);
      }
      int lisLength = LIS(v, position);
      lis = ConstructLIS(v, position, lisLength);

      printf("Max hits: %d\n", lisLength);

      FOR(i, 0, lis.size()-1)
         cout << lis[i] << "\n";

      v.clear();
      tc++;
   }


   return 0;
}
