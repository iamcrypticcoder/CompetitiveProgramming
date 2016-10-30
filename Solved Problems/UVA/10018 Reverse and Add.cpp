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

inline int src() { int ret; scanf("%d", &ret); return ret; }

unsigned int N;
unsigned int minIt, resPalin;

unsigned int Reverse(unsigned int N)
{
   unsigned int ret = 0;

   while(N) {
      ret = ret * 10 + (N % 10);
      N /= 10;
   }
   return ret;
}

unsigned int ReverseAndAdd(unsigned int N)
{
   unsigned int count = 0;
   unsigned int n1, n2;
   //bool isFirst = true;

   n1 = N;
   n2 = Reverse(n1);
   while(n1 != n2) {
      //isFirst = false;
      count++;
      n1 = n1 + n2;
      n2 = Reverse(n1);
   }
   resPalin = n1;
   return count;
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   TC = src();

   FOR(tc, 1, TC) {
      N = src();

      minIt = ReverseAndAdd(N);
      printf("%u %u\n", minIt, resPalin);
   }

   return 0;
}



#include <iostream>
#include <math.h>

using namespace std;

unsigned long multiply[11][2] = {
	{0, 0},
	{1, 1},
	{2, 10},
	{3, 100},
	{4, 1000},
	{5, 10000},
	{6, 100000},
	{7, 1000000},
	{8, 10000000},
	{9, 100000000},
	{10,1000000000}
};


bool IS_PALINDROME(unsigned long num, unsigned long *rev_num)
{
	int num_of_digits, i;
	unsigned long temp_num = num,temp_rev=0;

	num_of_digits = floor(log10(temp_num)) + 1;

	for(i=num_of_digits; i>=1; i--) {
		temp_rev += (temp_num % 10)*multiply[i][1];
		temp_num = temp_num /10;
	}

	*rev_num = temp_rev;


	if(num == temp_rev)
		return 1;
	else return 0;

}

int main()
{

	unsigned long num=195, rev_num;
	int N, i, iteration;


	cin >> N;
	for(i=0; i<N && cin >> num; i++) {
		rev_num = 0;
		iteration =1;
		IS_PALINDROME(num, &rev_num);
		num += rev_num;
		while(IS_PALINDROME(num, &rev_num) != 1) {
			iteration++;
			num += rev_num;
		}
		cout << iteration << " " <<num << "\n";
	}


return 0;
}


