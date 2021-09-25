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

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

const int MAXC = 26;

struct TrieNode {
    TrieNode* parent = NULL;            // Keep parent reference to remove
    TrieNode* children[MAXC] = {NULL};  // number of alphabets
    bool isKey = false;                 // Indicate a key node
    int keyCount = 0;                   // Keep count of keys below including itself
    TrieNode() {}
    TrieNode(bool isKey) {
        this->isKey = isKey;
    }
};

int childCount(TrieNode* node) {
    int ret = 0;
    for (int i = 0; i < MAXC; i++)
        ret += (NULL == node->children[i] ? 0 : 1);
    return ret;
}

// Complexity: O(length of key)
bool insertKey(TrieNode* root, string key) {
    int len = key.length();
    TrieNode* node = root;
    node->keyCount++;
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (NULL == node->children[index]) {
            node->children[index] = new TrieNode();
            node->children[index]->parent = node;
        }
        node = node->children[index];
        node->keyCount++;
    }
    node->isKey = true;
    return true;
}

// Complexity: O(length of key)
bool searchKey(TrieNode* root, string key) {
    int len = key.length();
    TrieNode* node = root;
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (NULL == node->children[index]) return false;
        node = node->children[index];
    }
    return node->isKey;
}

bool removeKey(TrieNode* root, string key) {
    int len = key.length();

    // If the given key isn't a key
    if (false == searchKey(root, key))
        return false;

    TrieNode* node = root;
    node->keyCount--;
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (NULL == node->children[index]) return false;
        node = node->children[index];
        node->keyCount--;
    }

    // if key node has any other child mark isLeaf == false and return
    if (childCount(node) > 0) {
        node->isKey = false;
        return true;
    }

    // Going bottom to top checking is current node has any child.
    // If no child exist current node should be null
    for (int i = len-1; i >= 0; i--) {
        if (childCount(node) > 0) break;
        int index = key[i] - 'a';
        node->parent->children[index] = NULL;
        node = node->parent;
    }
    return true;
}

int countKeysWithPrefix(TrieNode* root, string prefix) {
    int len = prefix.length();
    TrieNode* node = root;
    for (int i = 0; i < len; i++) {
        int index = prefix[i] - 'a';
        if (NULL == node->children[index]) return false;
        node = node->children[index];
    }
    return node->keyCount;
}

void findKeysRecursive(TrieNode* node, string curStr, vector<string>& output) {
    if (node->isKey) output.push_back(curStr);
    for (int i = 0; i < MAXC; i++) {
        if (NULL != node->children[i]) {
            curStr.push_back(i + 'a');
            findKeysRecursive(node->children[i], curStr, output);
            curStr.pop_back();
        }
    }
}

vector<string> findKeysWithPrefix(TrieNode* root, string key) {
    int len = key.length();
    TrieNode* node = root;
    for (int i = 0; i < len; i++) {
        int index = key[i] - 'a';
        if (NULL == node->children[index]) return vector<string>();
        node = node->children[index];
    }

    vector<string> output = vector<string>();
    findKeysRecursive(node, key, output);

    return output;
}

int main() {
    ios::sync_with_stdio(true);

    //READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();

    string keys[] = {"ma", "man", "max", "much", "mouse", "min", "multi"};

    TrieNode* trie1 = new TrieNode();

    for (auto str : keys) {
        insertKey(trie1, str);
    }
    for (auto str : keys) {
        cout << "Search " << str << ": " << searchKey(trie1, str) << endl;
    }
    cout << endl;

    cout << "countKeysWithPrefix() : " << "\"\" = " << countKeysWithPrefix(trie1, "") << endl;
    cout << "countKeysWithPrefix() : " << "m = " << countKeysWithPrefix(trie1, "m") << endl;
    cout << "countKeysWithPrefix() : " << "ma = " << countKeysWithPrefix(trie1, "ma") << endl;
    cout << "countKeysWithPrefix() : " << "much = " << countKeysWithPrefix(trie1, "much") << endl;
    cout << endl;

    cout << "Keys with prefix : \"\" : ";
    vector<string> output = findKeysWithPrefix(trie1, "");
    for (auto s : output) cout << s << " ";
    cout << endl;

    cout << "Keys with prefix : m : ";
    output = findKeysWithPrefix(trie1, "m");
    for (auto s : output) cout << s << " ";
    cout << endl;

    cout << "Keys with prefix : ma : ";
    output = findKeysWithPrefix(trie1, "ma");
    for (auto s : output) cout << s << " ";
    cout << endl;

    cout << "Keys with prefix : mu : ";
    output = findKeysWithPrefix(trie1, "mu");
    for (auto s : output) cout << s << " ";
    cout << endl << endl;

    removeKey(trie1, "max");
    cout << "Search \"max\": " << searchKey(trie1, "max") << endl;

    cout << "countKeysWithPrefix() : " << "\"\" = " << countKeysWithPrefix(trie1, "") << endl;
    cout << "countKeysWithPrefix() : " << "m = " << countKeysWithPrefix(trie1, "m") << endl;
    cout << "countKeysWithPrefix() : " << "ma = " << countKeysWithPrefix(trie1, "ma") << endl;
    cout << "countKeysWithPrefix() : " << "much = " << countKeysWithPrefix(trie1, "much") << endl;

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}

/**
OUTPUT:

Search ma: 1
Search man: 1
Search max: 1
Search much: 1
Search mouse: 1
Search min: 1
Search multi: 1

countKeysWithPrefix() : "" = 7
countKeysWithPrefix() : m = 7
countKeysWithPrefix() : ma = 3
countKeysWithPrefix() : much = 1

Keys with prefix : "" : ma man max min mouse much multi
Keys with prefix : m : ma man max min mouse much multi
Keys with prefix : ma : ma man max
Keys with prefix : mu : much multi

Search "max": 0
countKeysWithPrefix() : "" = 6
countKeysWithPrefix() : m = 6
countKeysWithPrefix() : ma = 2
countKeysWithPrefix() : much = 1

**/
