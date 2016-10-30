/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 1.472
    Rank : 470
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
typedef pair<string, int> PSI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

#define MAX_WORD 25144

string sStr, eStr;
VS dic;
int nodeNum;
MSI nodeMap;
MSI::const_iterator msi_it;
bool visited[MAX_WORD];
int parent[MAX_WORD];
string words[MAX_WORD];

void BFS(int s, int e)
{
   string uStr, vStr;
   int u, v;
   queue<int> Q;

   parent[s] = s;
   visited[s] = true;
   Q.push(s);

   while( !Q.empty() ) {
      u = Q.front(); Q.pop();

      if(u == e) break;

      uStr = dic[u];

      FOR(i, 0, uStr.SZ-1) {
         vStr = uStr;
         FOR(j, 0, 25) {
            vStr[i] = (char)('a' + j);
            msi_it = nodeMap.find(vStr);
            if(vStr != uStr && msi_it != nodeMap.end() && visited[msi_it->ss] == false) {
               parent[msi_it->ss] = u;
               Q.push(msi_it->ss);
               visited[msi_it->ss] = true;
            }
         }
      }
   }
}

void PrintPath(int s, int e)
{
   if(s != e) PrintPath(s, parent[e]);
   cout << dic[e] << "\n";
}


int main()
{
   READ("input.txt");
   WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   string word;

   nodeNum = -1;
   while(getline(cin, word)) {
      if(word.SZ == 0) break;
      dic.PB(word);
      nodeMap[word] = (++nodeNum);
   }

   tc = 1;
   while(cin >> sStr >> eStr) {
      if(tc > 1) printf("\n");

      if(nodeMap.find(eStr) == nodeMap.end() || nodeMap.find(sStr) == nodeMap.end()) {
         printf("No solution.\n");
      }
      else {
         memset(parent, -1, sizeof parent);
         memset(visited, false, sizeof visited);
         int si = nodeMap[sStr];
         int ei = nodeMap[eStr];
         BFS(si, ei);
         if(parent[ei] == -1) printf("No solution.\n");
         else PrintPath(si, ei);
      }

      tc++;
   }

   return 0;
}
