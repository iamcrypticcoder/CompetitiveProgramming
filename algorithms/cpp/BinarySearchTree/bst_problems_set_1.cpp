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
    Node* left = NULL;
    Node* right = NULL;

    Node() {}
    Node(int key) {
        this->key = key;
    }
};

Node *root;
int keyCount;

void bstInit() {
    root = NULL;
    keyCount = 0;
}
Node* minValueNode(Node* n) {
    if (NULL == n) return NULL;

    while(NULL != n && NULL != n->left)
        n = n->left;
    return n;
}
Node* insertNode(Node* n, int key) {
    if (NULL == n) return new Node(key);
    if (key < n->key) n->left = insertNode(n->left, key);
    else n->right = insertNode(n->right, key);
    return n;
}
Node* searchNode(Node* node, int key) {
    if (NULL == node || key == node->key) return node;
    if (key < node->key) searchNode(node->left, key);
    else searchNode(node->right, key);
    return node;
}
Node* deleteNode(Node* node, int key) {
    if (NULL == node) return node;
    if (key < node->key) node->left = deleteNode(node->left, key);
    else if (key > node->key) node->right = deleteNode(node->right, key);
    else {
        // Node with one child or no child
        if (NULL == node->left) return node->right;
        if (NULL == node->right) return node->left;

        Node* temp = minValueNode(node->right);
        node->key = temp->key;

        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}
void preOrderTraverse(Node* node) {
    if (NULL == node) return;
    cout << node->key << " ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}
void inOrderTraverse(Node* node) {
    if (NULL == node) return;
    inOrderTraverse(node->left);
    cout << node->key << " ";
    inOrderTraverse(node->right);
}

// Complexity: O(lg N)
void insertKey(int key) {
    root = insertNode(root, key);
    keyCount++;
}

// Complexity: O(lg N)
bool searchKey(int key) {
    return (NULL != searchNode(root, key));
}

// Complexity: O(lg N)
void deleteKey(int key) {
    deleteNode(root, key);
    keyCount--;
}

/**
 * Given a BST, find minimun value element
 * @return
 */
Node* bstMinValue(Node* n) {
    if (NULL == n) return NULL;
    return (NULL == n->left ? n : bstMinValue(n->left));
}

/**
 * Given a BST, find maximum value element
 */
Node* bstMaxValue(Node* n) {
    if (NULL == n) return NULL;
    return (NULL == n->right ? n : bstMaxValue(n->right));
}

/**
 * Given a BST (with all unique value), Finds LCA of key n1 and n2
 */
Node* findLCA(Node* n, int n1, int n2) {
    if (NULL == n) return n;
    if (n1 < n->key && n2 < n->key) return findLCA(n->left, n1, n2);
    else if (n1 > n->key && n2 > n->key) return findLCA(n->right, n1, n2);
    return n;
}

/**
 * Given a BST, find sum of leaf nodes
 */
int sumOfLeafNodes(Node* n) {
    if (NULL == n) return 0;
    if (NULL == n->left && NULL == n->right) return n->key;
    return sumOfLeafNodes(n->left) + sumOfLeafNodes(n->right);
}

/**
 * Given a BST (with all unique value), count BST nodes that lie in a given range (inclusive)
 * @return
 */
int countNodes(Node* n, int low, int high) {
    if (NULL == n) return 0;
    if (low > high) return 0;
    if (low < n->key && high < n->key) return countNodes(n->left, low, high);
    else if (low > n->key && high > n->key) return countNodes(n->right, low, high);
    else {
        return 1 + countNodes(n->left, low, n->key-1) + countNodes(n->right, n->key+1, high);
    }
}

/**
 * Given a BST (with all unique value), find k-th largest value
 * Idea : Reverse in-order traversal
 * @return
 */
int kthLargest(Node* n, int k, int &cnt) {
    if (NULL == n) return INT_MIN;

    int r = kthLargest(n->right, k, cnt);
    if (r != INT_MIN) return r;

    cnt++;
    if (k == cnt) return n->key;

    int l = kthLargest(n->left, k, cnt);
    if (l != INT_MIN) return l;

    return INT_MIN;
}


int main() {
    int keys[] = {8, 3, 10, 1, 6, 4, 7, 14, 13};
    int cnt = sizeof keys / sizeof (int);
    cout << cnt << endl;

    bstInit();
    cout << "Insert:" << endl;
    for (int i = 0; i < cnt; i++) {
        insertKey(keys[i]);
    }

    preOrderTraverse(root);
    cout << endl;
    inOrderTraverse(root);
    cout << endl;

    cout << "findLCA() : " << findLCA(root, 1, 7)->key << endl;
    cout << "bstMinValue() : " << bstMinValue(root)->key << endl;
    cout << "sumOfLeafNodes() : " << sumOfLeafNodes(root) << endl;
    cout << "countNodes() : " << countNodes(root, 10, 10) << endl;
    cnt = 0;
    cout<< "kthLargest() : " << kthLargest(root, 10, cnt) << endl;

    return 0;
}

