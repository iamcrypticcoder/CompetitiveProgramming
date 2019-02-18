/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
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

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 1000000000
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// 26 small letters + 26 capital letters = 52
#define ALPHABET_SIZE (26)

struct TrieNode {
    int value;
    TrieNode *childs[ALPHABET_SIZE];
};

struct MTrie {
    TrieNode *root;
    int wordCount;
};

/**
*   small   'a' to 'z'
*   code     0  to  25
*   capital 'A' to 'Z'
*   code     26 to  51
*   digits  '0' to '9'
*   code     52 to  61
**/
/*
inline int charIndex(char ch)
{
    if(ch >= 'a' && ch <= 'z') return ch - 'a';
    else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
    else return ch - '0' + 52;
}
*/
inline int charValue(char ch)
{
    return ch - 'a';
}

TrieNode* getNewTrieNode()
{
    TrieNode *node = NULL;

    node = (TrieNode *) malloc(sizeof(TrieNode));

    if(node) {
        node->value = 0;
        for(int i=0; i < ALPHABET_SIZE; i++) node->childs[i] = NULL;
    }
    return node;
}

void trieInit(MTrie *trie)
{
    trie->root = getNewTrieNode();
    trie->wordCount = 0;
}

/*
    If not present, inserts key into trie
    If the key is prefix of trie node, just marks leaf node
*/
void trieInsert(MTrie *trie, char key[])
{
    int keyLength = strlen(key);
    TrieNode *node = trie->root;
    trie->wordCount++;

    for(int level = 0; level < keyLength; level++) {
        int index = charValue(key[level]);
        if( !node->childs[index] ) node->childs[index] = getNewTrieNode();
        node = node->childs[index];
    }

    // Marking last node as leaf
    node->value = trie->wordCount;
}

// Return true if key is found, false otherwise
bool trieSearch(MTrie *trie, char key[])
{
    int keyLength = strlen(key);
    TrieNode *node = trie->root;

    for(int level = 0; level < keyLength; level++) {
        int index = charValue(key[level]);
        if( !node->childs[index] ) return false;
        node = node->childs[index];
    }

    return (node->value);
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};

    MTrie trie;

    trieInit(&trie);

    for(i = 0; i < ARRAY_SIZE(keys); i++)
        trieInsert(&trie, keys[i]);

    printf("Total keys added into trie: %d", trie.wordCount);

    string str;
    while(cin >> str) {
        const char *c = str.c_str();
        if(trieSearch(&trie, const_cast<char*>(str.c_str()))) printf("Found\n");
        else printf("Not Found\n");
    }

    return 0;
}
