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


// Rotate Horizontal Left
// Up and Down Remain Constant
string rotate_horizontal(string dice)
{
   string ret = dice;

   ret[2] = dice[5];
   ret[3] = dice[2];
   ret[4] = dice[3];
   ret[5] = dice[4];

   return ret;
}

// Rotate Vertical Up
// Left and Right Remain Constant
string rotate_vertical(string dice)
{
   string ret = dice;

   ret[0] = dice[2];
   ret[1] = dice[4];
   ret[2] = dice[1];
   ret[4] = dice[0];

   return ret;
}

// Rotate Clockwise
// Front and Back remain constant
string rotate_clockwise(string dice)
{
   string ret = dice;

   ret[0] = dice[3];
   ret[1] = dice[5];
   ret[3] = dice[1];
   ret[5] = dice[0];

   return ret;
}

string dice1, dice2;
string u, v;
map<string, bool> visited;
queue<string> Q;

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   /*
   cout << rotate_horizontal("123456") << "\n";
   cout << rotate_horizontal("126345") << "\n";
   cout << rotate_horizontal("125634") << "\n";
   cout << rotate_horizontal("124563") << "\n";
   */
   /*
   cout << rotate_vertical("123456") << "\n";
   cout << rotate_vertical("123456") << "\n";
   cout << rotate_vertical("123456") << "\n";
   cout << rotate_vertical("123456") << "\n";
   */
   /*
   cout << rotate_clockwise("123456") << "\n";
   cout << rotate_clockwise("123456") << "\n";
   cout << rotate_clockwise("123456") << "\n";
   cout << rotate_clockwise("123456") << "\n";
   */


   cin >> TC;

   FOR(tc, 1, TC) {

      cin >> dice1 >> dice2;

      Q.push(dice1);
      visited[dice1] = true;

      bool is_equal = false;
      while( !Q.empty() ) {

         u = Q.front(); Q.pop();

         if(u == dice2) {
            is_equal = true;
            while(!Q.empty()) Q.pop();
            break;
         }

         v = rotate_horizontal(u);
         if(visited.find(v) == visited.end()) {
            Q.push(v);
            visited[v] = true;
         }

         v = rotate_vertical(u);
         if(visited.find(v) == visited.end()) {
            Q.push(v);
            visited[v] = true;
         }

         v = rotate_clockwise(u);
         if(visited.find(v) == visited.end()) {
            Q.push(v);
            visited[v] = true;
         }
      }

      if(is_equal) cout <<  "Equal\n";
      else cout << "Not Equal\n";

      visited.clear();

   }

   return 0;
}
