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

char letter(char code)
{
   switch(code) {
      case '0': return 'O';
      case '1': return 'I';
      case '2': return 'Z';
      case '3': return 'E';
      case '4': return 'A';
      case '5': return 'S';
      case '6': return 'G';
      case '7': return 'T';
      case '8': return 'B';
      case '9': return 'P';
   }
   return ' ';
}

string decode(string str)
{
   FOR(i, 0, str.SZ-1) {
      if(str[i] >= '0' && str[i] <= '9') str[i] = letter(str[i]);
   }
   return str;
}
int main()
{
    READ("input.txt");
    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   cin >> TC;
   getline(cin, line);

   FOR(tc, 1, TC) {
      if(tc > 1) cout << "\n";
      while(getline(cin, line)) {
         if(line.SZ == 0) break;
         line = decode(line);
         cout << line << "\n";
      }

   }

   return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

int main()
{
       READ("input.txt");
    WRITE("output.txt");

    int test;
    char mess[80000];

cin>>test;
getchar();

    for(int t=1;t<=test;t++)
    {
        gets(mess);

        for(int i=0;mess[i]!='\0';i++)
        {
            if(mess[i]=='3')
            cout<<"E";
            else if(mess[i]=='0')
            cout<<"O";
            else if(mess[i]=='1')
            cout<<"I";
            else if(mess[i]=='4')
            cout<<"A";
            else if(mess[i]=='9')
            cout<<"P";
            else if(mess[i]=='8')
            cout<<"B";
            else if(mess[i]=='5')
            cout<<"S";
            else if(mess[i]=='7')
            cout<<"T";
            else if(mess[i]=='2')
            cout<<"Z";
            else if(mess[i]=='6')
            cout<<"G";
            else
            cout<<mess[i];
        }
    cout<<endl;
    }
return 0;
}

*/
