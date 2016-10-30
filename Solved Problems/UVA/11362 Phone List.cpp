/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
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

int N;
// Since number may be ten digits long
map<LL, bool> m;
LL number, temp;
vector<LL> numbers;
string numStr;

string convertToString(LL num)
{
   string ret;
   while(num) {
      ret += (num % 10) + '0';
      num /= 10;
   }
   reverse(ret.begin(), ret.end());

   return ret;
}
int main()
{
 //   READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   cin >> TC;

   FOR(tc, 1, TC) {
      cin >> N;

      FOR(i, 1, N) {
         cin >> number;
         m[number] = true;
         numbers.PB(number);
      }
      bool is_consistent = true;
      FOR(i, 0, N-1) {
         if(is_consistent == false) continue;

         numStr = convertToString(numbers[i]);
         temp = 0;
         for(j = 0; j < numStr.SZ-1; j++) {
            temp = (temp *= 10) + (numStr[j] - '0');
            if(m.find(temp) != m.end()) {
               is_consistent = false;
               break;
            }
         }
      }

      if(is_consistent) cout << "YES\n";
      else cout << "NO\n";

      m.clear();
      numbers.clear();
   }

   return 0;
}

*/

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

struct TrieNode {
   int words;
   int prefixes;
   TrieNode* edges[10];

   TrieNode() {
      words = 0;
      prefixes = 0;
      for(int i=0; i<10; i++) edges[i] = NULL;
   }
};
TrieNode* trieRoot;
string word, prefix;

bool is_consistent;

void addWord(TrieNode* vertex, int index)
{
   if(vertex->words >= 1) is_consistent = false;
   if(index == word.length()) {
      if(vertex->prefixes >= 1) is_consistent = false;
      vertex->words++;
   }
   else {
      vertex->prefixes++;
      int k = word[index] - '0';
      if(vertex->edges[k] == NULL) {
         TrieNode* newNode = new TrieNode();
         vertex->edges[k] = newNode;
      }
      addWord(vertex->edges[k], index+1);
   }
}

int countWords(TrieNode* vertex, int index)
{
      int k = word[index] - '0';
      if(index == word.length()) return vertex->words;
      else if(vertex->edges[k] == NULL) return 0;
      else return countWords(vertex->edges[k], index+1);
}

int countPrefixes(TrieNode* vertex, int index)
{
   int k = prefix[index] - '0';
   if(index == prefix.length()) return vertex->prefixes;
   else if(vertex->edges[k] == NULL) return 0;
   else countPrefixes(vertex->edges[k], index+1);
}

int traverse(TrieNode* vertex, int index)
{
   int k = prefix[index] - '0';
   cout << "Traverse " << prefix[index] << endl;
   cout << "P: " << vertex->prefixes << " W: " << vertex->words << endl;
   if(index == prefix.length()) return vertex->prefixes;
   else if(vertex->edges[k] == NULL) return 0;
   else {
      traverse(vertex->edges[k], index+1);
   }
}

void freeTrie(TrieNode* vertex)
{
   if(vertex == NULL) return;
   else {
      FOR(i, 0, 9)
         if(vertex->edges[i] != NULL) freeTrie(vertex->edges[i]);
   }
   free(vertex);
}

int N;
string str;

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;

   cin >> TC;

   FOR(tc, 1, TC) {
      cin >> N;

      is_consistent = true;
      trieRoot = new TrieNode();

      FOR(i, 1, N) {
         cin >> word;
         if(is_consistent == true) addWord(trieRoot, 0);
      }
      //cout << "Case " << tc << ": ";
      cout << (is_consistent ? "YES\n" : "NO\n");
      //prefix = "911"; cout << countPrefixes(trieRoot, 0);

      freeTrie(trieRoot);
   }


   return 0;
}
