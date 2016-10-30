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

bool isVowel(char ch)
{
  if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
  return 0;
}

bool isOk(string a, string b)
{
 int i;
 
 if(a.size() != b.size()) return 0;
 
 for(i = 0; i < a.size(); i++) {
  if(isVowel(a[i]) != isVowel(b[i])) return 0;
  if(!isVowel(a[i]) && a[i] != b[i]) return 0;  
 }
 
 return 1;

}


int main()
{
 string real, mutated;
 int TC;
 
 cin >> TC;
 
 FOR(i, 1, TC) {
  cin >> real >>  mutated;
  if(isOk(real, mutated))   cout << "Yes\n";
  else cout << "No\n";
 }

	return 0;
}
