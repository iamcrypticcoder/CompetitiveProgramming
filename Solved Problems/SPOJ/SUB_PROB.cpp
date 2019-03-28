/*
	Problem Link: https://www.spoj.com/problems/SUB_PROB/
    Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
	Time : 0.01
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
#include <unordered_set>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS         1e-9
#define SQR(x)         ((x)*(x))
#define INF         2000000000
#define TO_DEG         57.29577951
#define PI             2*acos(0.0)

#define ALL_BITS                    ((1 << 31) - 1)
#define NEG_BITS(mask)                (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)            (mask & (1 << i))
#define ON_BIT(mask, i)                (mask |= (1 << i))
#define OFF_BIT(mask, i)            (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)    (x & (x-1))

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<uint, uint> PUU;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<uint> VU;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

ULL GCD(ULL a, ULL b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAXN 1000
#define MAX_NODE 2000*1000/
#define MAXC 26

struct TrieNode {
    int parent;
    map<int, int> children;
    bool isKey;
    int failNode;
    vector<int> words;
    bool read;

    TrieNode() : parent(-1), isKey(false), failNode(0), read(false) {}
    TrieNode(int p) : parent(p), isKey(false), failNode(0), read(false) {}
};


int root = 1;
int nodes = 1;
TrieNode trie[1 << 17];
//vector<TrieNode> trie(2);   // Node 0 is unused

int N;
char text[100000+7];
char word[2000 + 7];
bool result[MAXN + 7];

int charValue(char ch) {
    return ch - 'a';
}

void insert(char *key, int wordId) {
    int len = strlen(key);
    int node = 1;
    for (int i = 0; i < len; ++i) {
        int ch = charValue(key[i]);
        int &nextNode = trie[node].children[ch];
        if (nextNode == 0) {
            nextNode = ++nodes;
            trie[nextNode].parent = node;
            //trie.emplace_back(node);
        }
        node = nextNode;
    }
    trie[node].isKey = true;
    trie[node].words.push_back(wordId);
}

int findFailNode(int u, int ch) {
    int failNode = trie[u].failNode;
    while (failNode && !trie[failNode].children.count(ch))
        failNode = trie[failNode].failNode;
    return failNode ? trie[failNode].children[ch] : root;
}

void bfs() {
    // Fail node for root is 0
    trie[0].failNode = 0;

    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        map<int, int>::iterator it = trie[u].children.begin();
        while (it != trie[u].children.end()) {
            int ch = it->first;
            int v = it->second;
            trie[v].failNode = findFailNode(u, ch);
            Q.push(v);
            it++;
        }
    }
}

int findNextNode(int node, int ch) {
    int answer = node;
    while (answer && !trie[answer].children.count(ch))
        answer = trie[answer].failNode;
    return answer ? trie[answer].children[ch] : root;
}

void searchWords(char *text) {
    int len = strlen(text);
    int node = 1;
    for (int i = 0; i < len; ++i) {
        int ch = charValue(text[i]);
        node = findNextNode(node, ch);
        for (int tmp = node; tmp && !trie[tmp].read; tmp = trie[tmp].failNode) {
            trie[tmp].read = true;
            FOR(k, 0, trie[tmp].words.size()-1) {
                //cout << trie[tmp].words[k] << " ";
                result[trie[tmp].words[k]] = true;
            }
            //cout << endl;
        }
    }
}

int main()
{
    READ("input.txt");
    
    int i, j;
    int TC, tc;
    double cl = clock();

    scanf("%s", &text);
    N = srcInt();
    getchar();
    FOR(i, 0, N-1) {
        scanf("%s", &word);
        insert(word, i);
    }
    bfs();
    searchWords(text);
    FOR(i, 0, N-1) printf("%s\n", result[i] ? "Y" : "N");

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
