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

/**
 * Given a binary tree, find height of binary tree aka max depth
 * @return
 */
int treeHeight(Node* n) {
    if (NULL == n) return 0;
    return max(treeHeight(n->left), treeHeight(n->right)) + 1;
}
/**
 * Find maximum level sum in Binary Tree
 * https://www.geeksforgeeks.org/find-level-maximum-sum-binary-tree/
 */
int maxLevelSum(Node* root) {
    int ret = INT_MIN;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        int sum = 0;
        while (size--) {
            Node* n = q.front(); q.pop();
            sum += n->key;
            if (NULL != n->left) q.push(n->left);
            if (NULL != n->right) q.push(n->right);
        }
        ret = max(ret, sum);
    }
    return ret;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(root, 2);
    root->right = new Node(root, -5);
    root->left->left = new Node(root->left, -1);
    root->left->right = new Node(root->left, 3);
    root->right->left = new Node(root->right, -2);
    root->right->right = new Node(root->right, 6);

//                      4
//                    /   \
//                   2    -5
//                  / \    /\
//                -1   3 -2  6


    cout << "maxLevelSum() : " << maxLevelSum(root) << endl;
}