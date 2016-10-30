#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define SQR(x) ((x)*(x))
#define FOR(i, L, U) for(i = (int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(i = (int)U; i>=(int)L; i--)

#define PB push_back
#define SZ size()

#define PI 2*acos(0.0)
#define INF 99999999

#define READ(x) freopen(x, "r", stdin);
#define WRITE(x) freopen(x, "w", stdout);

#define REP(i,a,b) for(int i=int)a);i<=int(b);i++)

typedef long long LL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char,int> MCI;
typedef map<string,int> MSI;


MCI map1, map2;
string output;

int main()
{
  //   READ("input.txt");
  //   WRITE("output.txt");

     int i, j, k;
     int TC, tc;

     string one, two;

     while(getline(cin, one)) {
          getline(cin, two);
  //   while(cin >> one >> two) {
          FOR(i, 0, one.SZ-1)
               map1[one[i]]++;
          FOR(i, 0, two.SZ-1)
               map2[two[i]]++;

          FOR(i, 0, 25) {
               FOR(j, 1, min(map1['a' + i], map2['a' + i]))
                    output.PB('a' + i);
          }

          sort(output.begin(), output.end());

          cout << output << "\n";

          output.clear();
          map1.clear();
          map2.clear();
     }


     return 0;
}
