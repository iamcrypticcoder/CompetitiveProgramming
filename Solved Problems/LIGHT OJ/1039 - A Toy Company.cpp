/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/
/*
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
typedef pair<string, int> PSI;
typedef map<string, bool> MSB;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

string sStr, eStr;
int numForbid;
bool forbid[51][4][27];
MSI dist;
MSI::const_iterator msi_it;

bool isForbid(string u)
{
   FOR(i, 0, numForbid-1) {
      if(forbid[i][0][u[0]-'a'] && forbid[i][1][u[1]-'a'] && forbid[i][2][u[2]-'a']) return true;
   }

   return false;
}


void BFS(string s)
{
   string u, v;

   queue<string> Q;

   Q.push(s);
   dist[s] = 0;


   while( !Q.empty() ) {
      u = Q.front();  Q.pop();

      if(v == eStr) break;

      FOR(i, 0, 2) for(int j=-1; j<=1; j+=2) {
         v = u;
         v[i] += j;
         if(v[i] < 'a') v[i] = 'z';
         else if(v[i] > 'z') v[i] = 'a';

         if(!isForbid(v)) {
            msi_it = dist.find(v);
            if(msi_it == dist.end()) {
               dist[v] = dist[u] + 1;
               Q.push(v);
            }
         }
      }
   }
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   string tStr;

   TC = src();

   FOR(tc, 1, TC) {

      cin >> sStr >> eStr;

      numForbid = src();

      memset(forbid, false, sizeof forbid);
      FOR(i, 0, numForbid-1) {
         FOR(part, 0, 2) {
            cin >> tStr;
            FOR(j, 0, tStr.SZ-1)
               forbid[i][part][tStr[j] - 'a'] = true;
         }
      }

      if(isForbid(sStr) || isForbid(eStr) ) printf("Case %d: -1\n", tc);
      else {
         BFS(sStr);
         msi_it = dist.find(eStr);
         if(msi_it == dist.end()) printf("Case %d: -1\n", tc);
         else printf("Case %d: %d\n", tc, msi_it->second);
      }

      dist.clear();
   }



   return 0;
}
*/
/*
    Solved By : Kazi Mahbubur Rahman
                Level-3, Term-2
                Department of CSE
                Khulna University of Engineering and Technology
                Khulna - 9203
    Time : 0.487
    Memory :
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

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2


int n;
string sWord, fWord;
bool forbid[51][3][26];
int dist[26][26][26];

bool isForbid(string s)
{
   FOR(i, 0, n-1)
      if(forbid[i][0][s[0]-'a'] && forbid[i][1][s[1]-'a'] && forbid[i][2][s[2]-'a']) return true;
   return false;
}

void BFS()
{
    string u, v;

    queue<string> Q;

    u = sWord;
    dist[sWord[0] - 'a'][sWord[1] - 'a'][sWord[2] - 'a'] = 0;
    Q.push(u);

    while( ! Q.empty() ) {
        u = Q.front();  Q.pop();

        for(int i=0; i<=2; i++)
            for(int j=-1; j<=1; j+=2) {
                v = u;
                v[i] = u[i] + j;
                if(v[i] < 'a') v[i] = 'z';
                else if(v[i] > 'z') v[i] = 'a';
                if(!isForbid(v)) {
                    if(dist[u[0]-'a'][u[1]-'a'][u[2]-'a'] + 1 < dist[v[0]-'a'][v[1]-'a'][v[2]-'a']) {
                        dist[v[0]-'a'][v[1]-'a'][v[2]-'a'] = dist[u[0]-'a'][u[1]-'a'][u[2]-'a'] + 1;
                        Q.push(v);
                    }
                }
            }
    }


}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    string a, b, c;

    scanf("%d", &TC);

    FOR(tc, 1 ,TC) {
        cin >> sWord >> fWord;
        scanf("%d", &n);

        memset(forbid, false, sizeof(forbid));
        FOR(i, 0, n-1) {
            cin >> a >> b >> c;
            FOR(j, 0, a.SZ-1)
                forbid[i][0][a[j] - 'a'] = true;
            FOR(j, 0, b.SZ-1)
                forbid[i][1][b[j] - 'a'] = true;
            FOR(j, 0, c.SZ-1)
                forbid[i][2][c[j] - 'a'] = true;
        }

        FOR(i, 0, 25)   FOR(j, 0, 25)   FOR(k, 0, 25)   dist[i][j][k] = INF;

        if(isForbid(sWord) || isForbid(fWord)) {
            printf("Case %d: -1\n", tc);
            continue;
        }

        if(sWord == fWord) {
            printf("Case %d: 0\n", tc);
            continue;
        }

        BFS();

  //      cout << dist['w'- 'a']['a'-'a']['t'-'a'] << "\n";

        if(dist[fWord[0]-'a'][fWord[1]-'a'][fWord[2]-'a'] != INF)
            printf("Case %d: %d\n", tc, dist[fWord[0]-'a'][fWord[1]-'a'][fWord[2]-'a']);
        else printf("Case %d: -1\n", tc);
    }

    return 0;
}

