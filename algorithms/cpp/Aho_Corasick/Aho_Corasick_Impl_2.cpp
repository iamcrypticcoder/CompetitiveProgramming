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

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

struct TrieNode {
    int parent;                 // Reference node number as per trie implementation
    map<char, int> children;    // Children node number map as per trie implementation
    bool isKey;                 // Denote a complete key as per trie implementation
    int failNode;               // failure value as per Aho algo
    vector<int> keyIds;         // Contains key ids as per Aho algo
    bool read;                  // If words of this node already read before

    TrieNode() : parent(-1), isKey(false), failNode(0), read(false) {}
    TrieNode(int p) : parent(p), isKey(false), failNode(0), read(false) {}
};

int root = 1;                   // Root node denoted 1
int nodes = 1;                  // Total nodes at present
vector<TrieNode> trie(2);       // Node 0 will be unused
vector<string> keys;

void insert(string key, int keyId) {
    int node = root;
    for (char& ch : key) {
        int& nextNode = trie[node].children[ch];
        if (nextNode == 0) {
            nextNode = ++nodes;
            trie.emplace_back(node);
        }
        node = nextNode;
    }
    trie[node].isKey = true;
    trie[node].keyIds.push_back(keyId);
}

int findFailNode(int u, char ch) {
    int f = trie[u].failNode;
    while (f && !trie[f].children.count(ch))
        f = trie[f].failNode;
    return f ? trie[f].children[ch] : root;
}

void bfs() {
    trie[root].failNode = 0;           // Fail node for root is 0

    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        auto it = trie[u].children.begin();
        while (it != trie[u].children.end()) {
            char ch = it->first;
            int v = it->second;
            trie[v].failNode = findFailNode(u, ch);
            Q.push(v);
            it++;
        }
    }
}

// Complexity: O(sum of all lengths * alphabet size)
void buildMatchingMachine(vector<string> keys) {
    for (int i = 0; i < keys.size(); i++) insert(keys[i], i);
    bfs();
}

int findNextNode(int curNode, char ch) {
    int ans = curNode;
    while (ans && !trie[ans].children.count(ch))
        ans = trie[ans].failNode;
    return ans ? trie[ans].children[ch] : root;
}

// Return found keys and their start position
vector<pair<int, int>>  searchKeys(string text) {
    int n = text.length();
    vector<pair<int, int>> ret;
    int node = root;
    for (int i = 0; i < n; i++) {
        node = findNextNode(node, text[i]);
        for (int t = node; t && !trie[t].read; t = trie[t].failNode) {
            trie[t].read = true;
            vector<int> keyIds = trie[t].keyIds;
            for (int k = 0; k < keyIds.size(); k++) {
                ret.push_back({keyIds[k], i - keys[keyIds[k]].length() + 1});
            }
        }
    }

    return ret;
}

int main() {
    keys.emplace_back("he");
    keys.emplace_back("she");
    keys.emplace_back("his");
    keys.emplace_back("hers");
    keys.emplace_back("");
    keys.emplace_back("a");
    keys.emplace_back("s");
    keys.emplace_back("x");
    keys.emplace_back("xy");
    keys.emplace_back("xyz");

    buildMatchingMachine(keys);
    printf("Failure Function Values as per Aho Algorithm:\n");
    for (int i = 0; i <= nodes; i++) printf("%d %d\n", i, trie[i].failNode);

    string text = "ashishers";
    vector<pair<int, int>> result = searchKeys(text);
    printf("Found keys ids and start positions: \n");
    for (int i = 0; i < result.size(); i++)
        printf("Key \"%s\" found at index %d\n", keys[result[i].first].c_str(), result[i].second);
        //printf("%d %d\n", result[i].first, result[i].second);

    return 0;
}