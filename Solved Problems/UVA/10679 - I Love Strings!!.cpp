/*
        Problem Link : https://uva.onlinejudge.org/external/106/10679.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.160
        Rank : 588
        Complexity:
*/

#define _CRT_SECURE_NO_WARNINGS

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
#include <limits.h>
#include <algorithm>

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

#define EPS             1e-9
#define SQR(x)          ((x)*(x))
#define INF             2000000000
#define TO_DEG          57.29577951
#define PI              2*acos(0.0)

#define ALL_BITS                                ((1 << 31) - 1)
#define NEG_BITS(mask)                          (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)                       (mask & (1 << i))
#define ON_BIT(mask, i)                         (mask |= (1 << i))
#define OFF_BIT(mask, i)                        (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                         (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)                (x & (x-1))

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
typedef map<uint, uint> MUU;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline int srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline int srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_L 1000

struct TrieNode {
    int parent;                 // Reference node number as per trie implementation
    map<char, int> children;    // Children node number map as per trie implementation
    bool isKey;                 // Denote a complete key as per trie implementation
    int failNode;               // failure value as per Aho algo
    vector<int> words;          // Contains words as per Aho algo
    bool read;                  // If words of this node already read before

    TrieNode() : parent(-1), isKey(false), failNode(0), read(false) {}
    TrieNode(int p) : parent(p), isKey(false), failNode(0), read(false) {}
};

string text;
int Q;
vector<string> keys;
bool result[1007];

int root = 1;
int nodes = 1;
vector<TrieNode> trie(2);   // Node 0 is unused

void insert(string key, int wordId) {
    int node = root;
    for (int i = 0; i < key.length(); ++i) {
        char ch = key[i];
        int &nextNode = trie[node].children[ch];
        if (nextNode == 0) {
            nextNode = ++nodes;
            trie.emplace_back(node);
        }
        node = nextNode;
    }
    trie[node].isKey = true;
    trie[node].words.push_back(wordId);
}

int findFailNode(int u, int ch) {
    int f = trie[u].failNode;               // f means failure as per Aho algorithm
    while (f && !trie[f].children.count(ch))
        f = trie[f].failNode;
    return f ? trie[f].children[ch] : root;
}

void bfs() {
    // Fail node for root is 0
    trie[0].failNode = 0;

    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        map<char, int>::iterator it = trie[u].children.begin();
        while (it != trie[u].children.end()) {
            int ch = it->first;
            int v = it->second;
            trie[v].failNode = findFailNode(u, ch);
            Q.push(v);
            it++;
        }
    }
}

int findNextNode(int curNode, int ch) {
    int ans = curNode;
    while (ans && !trie[ans].children.count(ch))
        ans = trie[ans].failNode;
    return ans ? trie[ans].children[ch] : root;
}

void searchWords() {
    memset(result, false, sizeof result);
    int node = root;
    for (int i = 0; i < text.length(); ++i) {
        node = findNextNode(node, text[i]);
        for (int tmp = node; tmp && !trie[tmp].read; tmp = trie[tmp].failNode) {
            trie[tmp].read = true;
            FOR(k, 0, trie[tmp].words.size()-1) {
                result[trie[tmp].words[k]] = true;
            }
        }
    }
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    string word;

    TC = srcUInt();
    getchar();
    FOR(tc, 1, TC) {
        nodes = 1;
        trie = vector<TrieNode>(2);
        getline(cin, text);
        Q = srcInt();
        getchar();
        FOR(q, 0, Q-1) {
            getline(cin, word);
            insert(word, q);
        }
        bfs();

        searchWords();

        FOR(i, 0, Q-1) printf("%s\n", result[i] ? "y" : "n");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
