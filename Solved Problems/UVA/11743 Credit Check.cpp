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


int value(string str)
{
 int i,j, ret = 0, d;
 
  for(i=0; i<=str.size(); i = i + 5) {
   j = i+2;
   d = (str[i] - '0') * 2;
   while(d) {   ret += d%10;  d /= 10;    }
   ret += str[i+1] - '0';
   
   d = (str[j] - '0') * 2;  
   while(d) {  ret += d%10;   d /= 10;    }
   ret += str[j+1] - '0';
  }
  return ret; 
}

int main()
{
 string card;
 int N, val;
 
 cin >> N;
  getline(cin, card);
  
 FOR(i, 1, N) {
  getline(cin, card);
  val = value(card);
// cout << val << " ";
  if(val % 10 == 0) 
   cout << "Valid\n";
  else 
   cout << "Invalid\n";
  }

	return 0;
}
