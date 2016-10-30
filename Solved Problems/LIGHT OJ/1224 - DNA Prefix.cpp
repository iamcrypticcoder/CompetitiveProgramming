/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
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

struct TrieNode {
   int prefixes;
   int length;
   TrieNode* edges[4];

   TrieNode() {
      prefixes = 0;
      length = 0;
      for(int i=0; i<4; i++) edges[i] = NULL;
   }
};
TrieNode* trieRoot;
string word, prefix;

int maxAns = -INF;

int numericValue(char ch)
{
   if(ch == 'A') return 0;
   else if(ch == 'C') return 1;
   else if(ch == 'G') return 2;
   else if(ch == 'T') return 3;

}
void addWord(TrieNode* vertex, int index)
{
   if(index == word.length()) {
      vertex->prefixes++;
      if(vertex->length && vertex->prefixes >= 1) {
         maxAns = max(maxAns, vertex->length * vertex->prefixes);
      }
   }
   else {
      vertex->prefixes++;
      if(vertex->length && vertex->prefixes >= 1) {
         maxAns = max(maxAns, vertex->length * vertex->prefixes);
      }
      int k = numericValue(word[index]);
      if(vertex->edges[k] == NULL) {
         TrieNode* newNode = new TrieNode();
         newNode->length = vertex->length + 1;
         vertex->edges[k] = newNode;
      }
      addWord(vertex->edges[k], index+1);
   }
}

void freeTrie(TrieNode* vertex)
{
   if(vertex == NULL) return;
   else {
      FOR(i, 0, 3)
         if(vertex->edges[i] != NULL) freeTrie(vertex->edges[i]);
   }
   free(vertex);
}

int N;

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   cin >> TC;

   FOR(tc, 1, TC) {
      N = src();

      trieRoot = new TrieNode();
      trieRoot->length = 0;

      maxAns = -INF;
      FOR(i, 1, N) {
         cin >> word;
         addWord(trieRoot, 0);
      }
      freeTrie(trieRoot);

      printf("Case %d: %d\n", tc, maxAns);
   }

   return 0;
}
