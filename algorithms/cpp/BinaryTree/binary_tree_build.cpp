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

struct Node {
    int key;
    Node* parent = NULL;
    Node* left = NULL;
    Node* right = NULL;

    Node() {}
    Node(int key) {
        this->key = key;
    }
    Node(Node* parent, int key) {
        this->parent = parent;
        this->key = key;
    }
};

void preOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    list.push_back(n->key);
    preOrderRecursive(n->left, list);
    preOrderRecursive(n->right, list);
}
vector<int> preOrderRecursive(Node *root) {
    vector<int> list;
    preOrderRecursive(root, list);
    return list;
}

void inOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    inOrderRecursive(n->left, list);
    list.push_back(n->key);
    inOrderRecursive(n->right, list);
}
vector<int> inOrderRecursive(Node *root) {
    vector<int> list;
    inOrderRecursive(root, list);
    return list;
}

void postOrderRecursive(Node* n, vector<int> &list) {
    if (NULL == n) return;
    postOrderRecursive(n->left, list);
    postOrderRecursive(n->right, list);
    list.push_back(n->key);
}
vector<int> postOrderRecursive(Node *root) {
    vector<int> list;
    postOrderRecursive(root, list);
    return list;
}

int main() {

}